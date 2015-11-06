<?php

/**
 * @file
 * Page callbacks for Commerce Simple Address book.
 */

function commerce_simple_addressbook_view($account) {
  $output = array();

  foreach (commerce_customer_profile_types() as $type => $profile_type) {
    $output['content']['address_' . $type] = array(
      '#prefix' => '<div class="commerce-simple-addressbook-view-' . check_plain($type) . '">',
      '#suffix' => '</div>',
      'title' => array(
        '#markup' => '<h2>' . t('Saved @type Addresses', array('@type' => ucwords($type))) . '</h2>',
      ),
      'list' => array(
        '#markup' => views_embed_view('commerce_simple_addressbook_list', 'default', $account->uid, $type),
      ),
    );
  }

  return $output;
}

/*
 * Form callback for editing saved addresses.
 */
function commerce_simple_addressbook_edit($form, &$form_state, $profile, $user) {
  $form_state['profile'] = $profile;
  field_attach_form('commerce_customer_profile', $form_state['profile'], $form, $form_state);

  // Hide the save option since this address is already saved.
  $form['commerce_simple_addressbook_save']['#access'] = FALSE;

  $form['actions'] = array(
    '#type' => 'container',
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Save address'),
    ),
    'cancel' => array(
      '#markup' => l(t('Cancel'), 'user/' . $profile->uid . '/addressbook'),
    ),
  );

  return $form;
}

/**
 * Form validate callback for editing a saved address.
 */
function commerce_simple_addressbook_edit_validate($form, &$form_state) {
  field_attach_validate('commerce_customer_profile', $form_state['profile'], $form, $form_state);
}

/**
 * Form submit callback for editing a saved address.
 */
function commerce_simple_addressbook_edit_submit($form, &$form_state) {
  field_attach_submit('commerce_customer_profile', $form_state['profile'], $form, $form_state);
  commerce_customer_profile_save($form_state['profile']);
  drupal_set_message(t('Address updated successfully'));
  $form_state['redirect'] = 'user/' . $form_state['profile']->uid . '/addressbook';
}

/**
 * Profile delete form callback.
 */
function commerce_simple_addressbook_delete($form, &$form_state, $profile) {
  $form_state['profile'] = $profile;

  $output = array(
    'content' => array(
      'title' => array(
        '#markup' => '<h2>' . t('Are you sure you want to delete this address?') . '</h2>',
      ),
      'address' => array(
        entity_view('commerce_customer_profile', array($profile)),
      ),
    ),
  );

  return confirm_form(
    $form,
    t('Are you sure you want to delete this address?'),
    'user/' . $profile->uid . '/addressbook',
    render($output),
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Profile delete callback.
 */
function commerce_simple_addressbook_delete_submit($form, &$form_state) {
  $profile = $form_state['profile'];
  commerce_customer_profile_delete($profile->profile_id);
  drupal_set_message(t('Address deleted successfully.'));
  $form_state['redirect'] = 'user/' . $profile->uid . '/addressbook';
}
