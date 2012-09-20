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
      "DO" : [ { "redirect" : { "url" : "add\\/testimonial" } } ]
    }
  }');
  $items['rules_testimonial_creation_from_authenticated_user'] = entity_import('rules_config', '{ "rules_testimonial_creation_from_authenticated_user" : {
      "LABEL" : "Testimonial creation from authenticated user",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "-10",
      "TAGS" : [ "authenticated" ],
      "REQUIRES" : [ "rules", "workbench_moderation" ],
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
        { "workbench_moderation_set_state" : {
            "node" : [ "node" ],
            "moderation_state" : "needs_review",
            "force_transition" : 1
          }
        },
        { "redirect" : { "url" : "admin\\/workbench" } },
        { "drupal_message" : {
            "message" : "Thank you for your testimonial. You are free to make edits until its publication.",
            "repeat" : 0
          }
        }
      ]
    }
  }');
  return $items;
}
