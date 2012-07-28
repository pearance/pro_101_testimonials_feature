<?php
/**
 * @file
 * pro_101_testimonials_feature.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function pro_101_testimonials_feature_default_rules_configuration() {
  $items = array();
  $items['rules_redirect_post_testimonial_creation'] = entity_import('rules_config', '{ "rules_redirect_post_testimonial_creation" : {
      "LABEL" : "Redirect post testimonial creation",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "user_has_role" : { "account" : [ "node:author" ], "roles" : { "value" : { "2" : "2" } } } },
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "testimonial" : "testimonial" } }
          }
        }
      ],
      "DO" : [
        { "redirect" : { "url" : "admin\\/workbench" } },
        { "drupal_message" : {
            "message" : "Thank you for your testimonial. It will be reviewed and proofed before being published.",
            "repeat" : 0
          }
        }
      ]
    }
  }');
  return $items;
}
