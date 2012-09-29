<?php
/**
 * @file
 * pro_101_testimonials_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pro_101_testimonials_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function pro_101_testimonials_feature_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function pro_101_testimonials_feature_node_info() {
  $items = array(
    'testimonial' => array(
      'name' => t('Testimonial'),
      'base' => 'node_content',
      'description' => t('Use of <em>Testimonial</em> should be by existing and former clients to testify to the quality of your service.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => t('Please provide a testimonial in 300 characters or less.'),
    ),
  );
  return $items;
}
