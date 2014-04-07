<?php

function config_admin_wizard_page() {
	$output = array();
	
	$wizards = config_wizard_info_all();
	//dsm($wizards);
	
	/*
	$output[] = array(
	  '#markup' => '<h3>' . t('Wizards') . '</h3>',
	)
	*/
	$progs = array();
	$categories = array(
	  'other' => array(),
	);
	foreach ($wizards AS $name => $wiz) {
		if (isset($wiz['category'])) {
			if (is_array($wiz['category'])) {
				foreach ($wiz['category'] AS $i => $cat) {
					$cat_name = $cat['name'];
					if (!isset($categories[$cat_name])) {
						$categories[$cat_name] = array();
					}
					$categories[$cat_name][] = array(
            'name' => $name,
            'weight' => isset($cat['weight']) ? $cat['weight'] : 0,
          );
				}
			}
			else {
        if (!isset($categories[$wiz['category']])) {
          $categories[$wiz['category']] = array();
        }
	      $categories[$wiz['category']][] = array(
	        'name' => $name,
	        'weight' => isset($wiz['weight']) ? $wiz['weight'] : 0,
	      );				
			}
		}
		else {
			$categories['other'][] = array(
			  'name' => $name,
			  'weight' => isset($wiz['weight']) ? $wiz['weight'] : 0,
			);
		}
		$progs[$name] = config_progress_load($name, null, null, 'last');
	}
	$header = array(
    t('Title'),
    t('Status'),
    t('Ops'),
  );
	$cat_info = config_wizard_category_info_all();
	foreach ($categories AS $cat_name => $in_cat) {
		if (!count($in_cat)) {
			continue;
		}
		uasort($in_cat, 'drupal_sort_weight');
		$rows = array();
		foreach ($in_cat AS $c) {
			$wiz = $wizards[$c['name']];
			$wiz_name = $wiz['name'];
			$status = t('not started');
			if (!empty($progs[$wiz_name])) {
			  $prog = $progs[$wiz_name];
			  if ($prog['finished']) {
			    $account = user_load($prog['uid']);
			    $status = t('finished by !user_name on @date',
			      array(
			        '!user_name' => l($account->name, 'user/' . $account->uid),
			        '@date' => format_date($prog['finished'], 'short'),
			      )
			    );
			  }
			  else {
          $account = user_load($prog['uid']);
          $status = t('started by !user_name on @date',
            array(
              '!user_name' => l($account->name, 'user/' . $account->uid),
              '@date' => format_date($prog['started'], 'short'),
            )
          );
			  }
			}
		  $row = array();
		  $r = check_plain($wiz['title']);
      $r .= '<div class="description">' . filter_xss_admin($wiz['description']) . '</div>';
      $row[] = $r;
      $row[] = $status;
      $row[] = l(t('start'), CONFIG_WIZARD_PAGE_ROOT . 'wizard/' . $wiz['name']);
      $rows[] = $row;
		}
		$markup = '<h3>' . $cat_info[$cat_name]['title'] . '</h3>';
		$markup .= $cat_info[$cat_name]['description'];
	  $output[] = array(
	    '#markup' => $markup,
	  );
    $output[] = array(
      '#theme' => 'table',
      '#header' => $header,
      '#rows' => $rows,
    );
	}
//dsm($output);
	
	return $output;
}

function config_wizard_step_edit_page($wizard, $step_n, $substep_n) {
	$output = array();

	$output = drupal_get_form('config_wizard_step_edit_form', $wizard, $step_n, $substep_n);
	
	return $output;
}

function config_wizard_step_edit_form($form, $form_state, $wizard, $step_n, $substep_n) {
$args = func_get_args();
//dsm($args);
//dsm($wizard);

  $wizard_db = config_wizard_db_load($wizard['name']);
  //$wizard_code = config_wizard_db_code($wizard['name']);
//dsm($wizard_db);


  $astep = config_get_wizard_active_step($wizard, $step_n, $substep_n);
//dsm($astep);
  if (!isset($astep['content'])) {
  	$astep['content'] = array();
  }
  if ($callback = config_get_wizard_step_callback($astep, $step_n, $substep_n)) {
  	$astep['content'] += $callback(array(), array());
  }
//dsm($callback);
  $astep_db = config_get_wizard_active_step($wizard_db, $step_n, $substep_n);
  if (!$astep_db) {
  	$astep_db = array();
  }
//dsm($astep);
//dsm($astep_db);
  $is_sub = isset($astep['substep_i']);
  if ($is_sub) {
  	drupal_set_title(t('Edit substep @step_title > @substep_title',
  	  array(
  	    '@step_title' => $astep['#parent']['title'],
  	    '@substep_title' => $astep['title'],
  	  )
  	));
  } 
  else {
    drupal_set_title(t('Edit step @step_title',
      array(
        '@step_title' => $astep['title'],
      )
    )); 		
  }
  $title = t('Edit @type');
  $form_state['config'] = array(
    'wizard_info' => $wizard,
    'wizard_info_db' => $wizard_db,
    'step_n' => $step_n,
    'substep_n' => $substep_n,
    'active_step' => $astep,
    'active_step_db' => $astep_db,
    'is_substep' => $is_sub,
  );
  $form['step']['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Custom title'),
    '#default_value' => !empty($astep_db['title']) ? $astep_db['title'] : '',
    '#description' => t('Enter a custom title. Leave blank to keep default.'),
  );
  
  if (!isset($astep['content'])) {
  	$astep['content'] = array();
  }
  if (!isset($astep['content']['main'])) {
    $astep['content']['main'] = array(
      '#editable' => 1,
      '#markup' => '', 
    );
  } 
  
  foreach ($astep['content'] AS $name => $value) {
  	if (empty($value['#editable'])) {
  		continue;
  	}
  	$title = (!empty($value['#title'])) ? $value['#title'] : '';
  	if (!$title) {
  		$title = t('Content (@id)',
  		  array(
  		    '@id' => (!empty($value['#name'])) ? $value['#name'] : $name,
  		));
  	}
  	$form['step']['content'][$name] = array(
  	  '#type' => 'textarea',
  	  '#title' => $title,
  	  '#default_value' => $value['#markup'],
  	  '#editable' => 1,
  	);
  	if (isset($value['#weight'])) {
  		$form['step']['content'][$name]['#weight'] = $value['#weight'];
  	}
  }
  $form['#tree'] = TRUE;
  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Update'),
  );
  
  return $form;
}

function config_wizard_step_edit_form_submit($form, $form_state) {
	$values = $form_state['values'];
	$wizard = $form_state['config']['wizard_info'];
	$wizard_db = $form_state['config']['wizard_info_db'];
	$step_n = $form_state['config']['step_n'];
	$substep_n = $form_state['config']['substep_n'];
	$astep = $form_state['config']['active_step'];
	$astep_db = $form_state['config']['active_step_db'];
	$is_sub = $form_state['config']['is_substep'];
//dsm($values);	
	
	$step_db = array();
	if ($values['step']['title']) {
		$step_db['title'] = $values['step']['title'];
	}
	if (isset($values['step']['content']) && is_array($values['step']['content'])) {
		foreach ($values['step']['content'] AS $key => $value) {
			if (trim($value)) {
				if (!isset($step_db['content'])) {
					$step_db['content'] = array();
				}
				$v = array(
				  '#markup' => $value,
				);
				if (isset($form['step']['content'][$key]['#weight'])) {
					$v['#weight'] = $form['step']['content'][$key]['#weight'];
				}
			  if (isset($form['step']['content'][$key]['#editable'])) {
          $v['#editable'] = 1;
        }
				$step_db['content'][$key] = $v;
			}
		}
	}
//dsm($step_db);

	if (count($step_db)) {
		if (!isset($wizard_db['steps'])) {
			$wizard_db['steps'] = array();
		}
		if ($is_sub) {
		  if (!isset($wizard_db['steps'][$step_i])) {
        $wizard_db['steps'][$step_n] = array(
          'steps' => array(),
        );
      }
			$wizard_db['steps'][$step_n]['steps'][$substep_n] = $step_db;
		}
		else {
			$wizard_db['steps'][$step_n] = $step_db;
		}
		config_wizard_db_save($wizard['name'], $wizard_db);
	}
	$path = config_get_wizard_path($wizard, $step_n, $substep_n);
	drupal_goto($path);
}