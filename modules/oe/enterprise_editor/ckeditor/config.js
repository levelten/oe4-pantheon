/**
 * NOTE: changes in this file will require you to clear Drupal's CSS & JS cache
 * for them to take effect.
 */

var Drupal = Drupal || {};

/**
 * Replaces the existing "templates" dialog with a custom implementation.
 *
 * This is necessary to get "dynamic" variables into templates. It checks to see
 * if a template's "html" is a JavaScript function to invoke a callback or else
 * treats it as a string.
 *
 * @see lines 186 - 190
 */
//CKEDITOR.dialog.add("templates",function(e){function t(e,t){var r=CKEDITOR.dom.element.createFromHtml('<a href="javascript:void(0)" tabIndex="-1" role="option" ><div class="cke_tpl_item"></div></a>'),i='<table style="width:350px;" class="cke_tpl_preview" role="presentation"><tr>';e.image&&t&&(i+='<td class="cke_tpl_preview_img"><img src="'+CKEDITOR.getUrl(t+e.image)+'"'+(CKEDITOR.env.ie6Compat?' onload="this.width=this.width"':"")+' alt="" title=""></td>');i+='<td style="white-space:normal;"><span class="cke_tpl_title">'+e.title+"</span><br/>";e.description&&(i+="<span>"+e.description+"</span>");r.getFirst().setHtml(i+"</td></tr></table>");r.on("click",function(){
//  if(typeof e.html==="function"){
//    n(e.html())
//  }else{
//    n(e.html)
//  }});
//return r}function n(t){var n=CKEDITOR.dialog.getCurrent();n.getValueOf("selectTpl","chkInsertOpt")?(e.fire("saveSnapshot"),e.setData(t,function(){n.hide();var t=e.createRange();t.moveToElementEditStart(e.editable());t.select();setTimeout(function(){e.fire("saveSnapshot")},0)})):(e.insertHtml(t),n.hide())}function r(e){var t=e.data.getTarget(),n=s.equals(t);if(n||s.contains(t)){var r=e.data.getKeystroke(),i=s.getElementsByTag("a"),o;if(i){if(n){o=i.getItem(0)}else{switch(r){case 40:o=t.getNext();break;case 38:o=t.getPrevious();break;case 13:case 32:t.fire("click")}}o&&(o.focus(),e.data.preventDefault())}}}var i=CKEDITOR.plugins.get("templates");CKEDITOR.document.appendStyleSheet(CKEDITOR.getUrl(i.path+"dialogs/templates.css"));var s,i="cke_tpl_list_label_"+CKEDITOR.tools.getNextNumber(),o=e.lang.templates,u=e.config;return{title:e.lang.templates.title,minWidth:CKEDITOR.env.ie?440:400,minHeight:340,contents:[{id:"selectTpl",label:o.title,elements:[{type:"vbox",padding:5,children:[{id:"selectTplText",type:"html",html:"<span>"+o.selectPromptMsg+"</span>"},{id:"templatesList",type:"html",focus:!0,html:'<div class="cke_tpl_list" tabIndex="-1" role="listbox" aria-labelledby="'+i+'"><div class="cke_tpl_loading"><span></span></div></div><span class="cke_voice_label" id="'+i+'">'+o.options+"</span>"},{id:"chkInsertOpt",type:"checkbox",label:o.insertOption,"default":u.templates_replaceContent}]}]}],buttons:[CKEDITOR.dialog.cancelButton],onShow:function(){var e=this.getContentElement("selectTpl","templatesList");s=e.getElement();CKEDITOR.loadTemplates(u.templates_files,function(){var n=(u.templates||"default").split(",");if(n.length){var r=s;r.setHtml("");for(var i=0,c=n.length;i<c;i++){for(var h=CKEDITOR.getTemplates(n[i]),p=h.imagesPath,h=h.templates,d=h.length,v=0;v<d;v++){var m=t(h[v],p);m.setAttribute("aria-posinset",v+1);m.setAttribute("aria-setsize",d);r.append(m)}}e.focus()}else{s.setHtml('<div class="cke_tpl_empty"><span>'+o.emptyListMsg+"</span></div>")}});this._.element.on("keydown",r)},onHide:function(){this._.element.removeListener("keydown",r)}}});

/**
 * Setup CKEditor configurations.
 */
CKEDITOR.editorConfig = function(config) {
  config.height = 400;
  config.allowedContent = true;
  config.magicline_everywhere = config.magicline_putEverywhere = true;
  config.indentClasses = [ 'rteindent1', 'rteindent2', 'rteindent3', 'rteindent4' ];
  config.justifyClasses = [ 'text-left', 'text-center', 'text-right', 'text-justify' ];
  config.resize_minWidth = 450;
  config.protectedSource.push(/<\?[\s\S]*?\?>/g); // PHP Code
  config.protectedSource.push(/<code>[\s\S]*?<\/code>/gi); // Code tags
  config.protectedSource.push(/\<(i|span)[^\>]*icon[^\>]*\>[^>]*\<\/(i|span)\>/g);
  config.extraPlugins = '';
  config.extraCss = '';
  config.bodyClass = '';
  config.bodyId = '';
  config.templates_replaceContent = false;
  if (Drupal.settings.enterprise_editor) {
    config.stylesSet = 'default:' + Drupal.settings.enterprise_editor.path + '/ckeditor/styles.js?' + Drupal.settings.enterprise_editor.query ;
    config.templates_files = [ Drupal.settings.enterprise_editor.path + '/ckeditor/templates.js?' + Drupal.settings.enterprise_editor.query ];
  }
};

(function($){
  /**
   * Set style dropdown height and width so it's easier to navigate.
   */
  $(document).ready(function(){
    $('head').once('ckeditor', function(){
      $('<style/>').attr('type', 'text/css').html('.cke_combopanel{height:300px !important;width:200px !important;}').appendTo(this);
    });
  });
})(jQuery);
