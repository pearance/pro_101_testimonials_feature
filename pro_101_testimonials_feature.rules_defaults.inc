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
  $items['rules_post_user_registration'] = entity_import('rules_config', '{ "rules_post_user_registration" : {
      "LABEL" : "Post user registration",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "authenticated" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "user_insert" ],
      "IF" : [
        { "NOT user_has_role" : {
            "account" : [ "account" ],
            "roles" : { "value" : {
                "1" : "1",
                "8998634" : "8998634",
                "96220023" : "96220023",
                "160159362" : "160159362",
                "121011395" : "121011395"
              }
            },
            "operation" : "OR"
          }
        }
      ],
      "DO" : [ { "redirect" : { "url" : "#overlay=add\\/testimonial" } } ]
    }
  }');
  $items['rules_testimonial_creation_from_authenticated_user'] = entity_import('rules_config', '{ "rules_testimonial_creation_from_authenticated_user" : {
      "LABEL" : "Testimonial creation from authenticated user",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "-10",
      "TAGS" : [ "authenticated" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "testimonial" : "testimonial" } }
          }
        },
        { "NOT user_has_role" : {
            "account" : [ "node:author" ],
            "roles" : { "value" : {
                "8998634" : "8998634",
                "96220023" : "96220023",
                "160159362" : "160159362",
                "121011395" : "121011395"
              }
            },
            "operation" : "OR"
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
        { "drupal_message" : {
            "message" : "Thank you for your testimonial. It is available for edit only prior to publication.",
            "repeat" : 0
          }
        },
        { "node_unpublish" : { "node" : [ "node" ] } }
      ]
    }
  }');
  return $items;
}
