<?php

function enterprise_config_unset_entity_uuid(&$entity) {
  if (isset($entity->uuid)) {
    unset($entity->uuid);
  }
  if (isset($entity->vuuid)) {
    unset($entity->vuuid);
  }
}