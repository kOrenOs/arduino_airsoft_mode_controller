bool state_in_menu = true;                                  // whether is menu displayed or not
int actual_displayed_top_menu_record = 0;                   // index of record on top of menu

// int actual_mode;

// bomb mode states
bool bomb_set_pin_state = true;
bool bomb_set_timer_state = false;
bool bomb_active_state = false;

// change to add new mode
bool active_mode[] = {false, false, false};                 // active mode has true value
String mode_names[] = {"Bomb", "Flags", "Rush"};            // mode names for display in menu
int number_of_modes = sizeof(mode_names);                   // number of modes, helps menu to keep boundings
