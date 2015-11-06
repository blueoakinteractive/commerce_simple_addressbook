<?php

/**
 * @file
 * Provides default views for commerce_simple_addressbook.
 */

/**
 * Implements hook_views_default_views().
 */
function commerce_simple_addressbook_views_default_views() {
  $views = array();

  // Create the simple address book list view.
  $view = new view();
  $view->name = 'commerce_simple_addressbook_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_customer_profile';
  $view->human_name = 'Commerce Simple Addressbook List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Commerce Customer Profile: Owner */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'commerce_customer_profile';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: Commerce Customer Profile: Rendered Commerce Customer profile */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_commerce_customer_profile';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'customer';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  /* Field: Commerce Customer Profile: Edit link */
  $handler->display->display_options['fields']['edit_customer_profile']['id'] = 'edit_customer_profile';
  $handler->display->display_options['fields']['edit_customer_profile']['table'] = 'commerce_customer_profile';
  $handler->display->display_options['fields']['edit_customer_profile']['field'] = 'edit_customer_profile';
  $handler->display->display_options['fields']['edit_customer_profile']['label'] = '';
  $handler->display->display_options['fields']['edit_customer_profile']['element_label_colon'] = FALSE;
  /* Field: Commerce Customer Profile: Delete link */
  $handler->display->display_options['fields']['delete_customer_profile']['id'] = 'delete_customer_profile';
  $handler->display->display_options['fields']['delete_customer_profile']['table'] = 'commerce_customer_profile';
  $handler->display->display_options['fields']['delete_customer_profile']['field'] = 'delete_customer_profile';
  $handler->display->display_options['fields']['delete_customer_profile']['label'] = '';
  $handler->display->display_options['fields']['delete_customer_profile']['element_label_colon'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Commerce Customer Profile: Type */
  $handler->display->display_options['arguments']['type']['id'] = 'type';
  $handler->display->display_options['arguments']['type']['table'] = 'commerce_customer_profile';
  $handler->display->display_options['arguments']['type']['field'] = 'type';
  $handler->display->display_options['arguments']['type']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['type']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['type']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['type']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['type']['limit'] = '0';
  /* Filter criterion: Commerce Customer Profile: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_customer_profile';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Addressbook: Profile ID */
  $handler->display->display_options['filters']['profile_id']['id'] = 'profile_id';
  $handler->display->display_options['filters']['profile_id']['table'] = 'commerce_simple_addressbook_list_defaults';
  $handler->display->display_options['filters']['profile_id']['field'] = 'profile_id';
  $handler->display->display_options['filters']['profile_id']['operator'] = 'empty';
  /* Filter criterion: Commerce Customer profile: Save Address (commerce_simple_addressbook_save) */
  $handler->display->display_options['filters']['commerce_simple_addressbook_save_value']['id'] = 'commerce_simple_addressbook_save_value';
  $handler->display->display_options['filters']['commerce_simple_addressbook_save_value']['table'] = 'field_data_commerce_simple_addressbook_save';
  $handler->display->display_options['filters']['commerce_simple_addressbook_save_value']['field'] = 'commerce_simple_addressbook_save_value';
  $handler->display->display_options['filters']['commerce_simple_addressbook_save_value']['value'] = array(
    1 => '1',
  );

  $views['commerce_simple_addressbook_list'] = $view;

  return $views;
}
