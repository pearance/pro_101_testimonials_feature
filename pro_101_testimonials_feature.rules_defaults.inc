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
  $items['rules_testimonial_creation'] = entity_import('rules_config', '{ "rules_testimonial_creation" : {
      "LABEL" : "Testimonial creation",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "-10",
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "testimonial" : "testimonial" } }
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "support@pearance.com",
            "subject" : "NEW CONTENT - [[node:content-type]@[site:name]]",
            "message" : "Title: [node:title]\\\\r\\\\nCreated: [node:created]\\\\r\\\\nLast Update: [node:changed]\\\\r\\\\n\\\\r\\\\nRevision Msg: [node:log]\\\\r\\\\n\\\\r\\\\nContent URL: [node:url]",
            "from" : "[site:mail]",
            "language" : [ "" ]
          }
        },
        { "drupal_message" : { "message" : "Thank you for your testimonial.", "repeat" : 0 } },
        { "node_unpublish" : { "node" : [ "node" ] } }
      ]
    }
  }');
  return $items;
}
