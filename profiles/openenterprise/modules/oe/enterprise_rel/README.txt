


-- URL Paterns --

Url patterns can be used to redirect links to the appropriate view. These are processed via hook_url_outbound_alter,
therefor any Drupal setting using hook_url_outbound_alter will be automatically translated.


Patterns using current path's rel context:

rel-view/taxonomy/term/[tid|name]
rel-view/taxonomy/[vocab name]/[tid|name]
rel-view/node/[nid]
rel-view/field/[field name]/[value]

Selecting a rel context different from current path.
 2 methods, as arg 1 or query params: *
 * arg 1 - rel-view/[context id]/...
 * query - rel-view/...?rel_context=[context id]

context id formats:
 * by content type = node:[content_type]
 * by entity = entity:[entity_type]:[bundle]
 * by view = view:[view_name]:[display_name]

Examples
 * rel-view/node:enterprise_blog/taxonomy/term/1
 * rel-view/taxonomy/term/1?rel_context=view:enterprise_blog:main