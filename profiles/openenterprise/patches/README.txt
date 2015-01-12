This document describes the patches used in Open Enterprise

PATCH: uuid-add-features-import-alter-hook-2406051.patch

Adds a hook to alter uuid entities (content) when the content is imported.
This is used to reverse alterations done using hook_uuid_entities_features_export_entity.
Used with webform blocks to add uuid to block id on export then replace uuid with nid on import.