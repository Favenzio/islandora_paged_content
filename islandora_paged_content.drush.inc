<?php

/**
 * @file
 * Drush commands for paged content.
 */

/**
 * Implements hook_drush_command().
 */
function islandora_paged_content_drush_command() {
  $items['paged-content-consolidate-missing-ocr'] = array(
    'aliases' => array('pccmo'),
    'description' => dt('Consolidates and appends paged content page OCR to any paged content objects with no OCR datastream.'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_LOGIN,
    'drupal dependencies' => array(
      'islandora_ocr',
    ),
    'examples' => array(
      'Trigger OCR consolidation' => 'drush -u 1 paged-content-consolidate-missing-ocr',
    ),
  );
  
  $items['paged-content-ingest-zip-pages'] = array(
    'aliases' => array('pcizp'),
    'description' => dt('Extracts a zip folder of images and adds the pages to an object.'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_LOGIN,
    'drupal dependencies' => array(
      'islandora_ocr',
    ),
    'examples' => array(
      'Ingest zip folder' => 'drush -u 1 paged-content-consolidate-missing-ocr',
    ),
  );
  
  return $items;
}

/**
 * Triggers the OCR consolidation batch process.
 */
function drush_islandora_paged_content_paged_content_consolidate_missing_ocr() {
  module_load_include('inc', 'islandora_paged_content', 'includes/batch');
  batch_set(islandora_paged_content_consolidate_missing_ocr_batch());
  drush_backend_batch_process();
}

/**
 * Triggers the zip page upload and ingest process.
 */
function drush_islandora_paged_content_paged_content_ingest_zip_pages() {
  module_load_include('inc', 'islandora_paged_content', 'includes/manage_pages');
}