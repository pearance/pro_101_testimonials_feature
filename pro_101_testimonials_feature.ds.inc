<?php
/**
 * @file
 * pro_101_testimonials_feature.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function pro_101_testimonials_feature_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass;
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|testimonial|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'testimonial';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|testimonial|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass;
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|testimonial|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'testimonial';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'strong',
        'class' => '',
      ),
    ),
  );
  $export['node|testimonial|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function pro_101_testimonials_feature_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass;
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|testimonial|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'testimonial';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'left' => array(
        0 => 'field_title_graphic',
        1 => 'title',
        2 => 'field_title',
        3 => 'field_city_state',
      ),
      'right' => array(
        0 => 'body',
      ),
    ),
    'fields' => array(
      'field_title_graphic' => 'left',
      'title' => 'left',
      'field_title' => 'left',
      'field_city_state' => 'left',
      'body' => 'right',
    ),
    'classes' => array(),
  );
  $export['node|testimonial|full'] = $ds_layout;

  $ds_layout = new stdClass;
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|testimonial|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'testimonial';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
        1 => 'title',
        2 => 'field_title',
        3 => 'field_city_state',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
      'title' => 'ds_content',
      'field_title' => 'ds_content',
      'field_city_state' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|testimonial|teaser'] = $ds_layout;

  return $export;
}
