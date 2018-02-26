bool state_in_menu = true;
int actual_displayed_top_menu_record = 0;

int actual_mode;

bool bomb_set_pin_state = true;
bool bomb_set_timer_state = false;
bool bomb_active_state = false;

// change to add new mode
bool active_mode[] = {false, false, false};
String mode_names[] = {"Bomb", "Flags", "Rush"};
int number_of_modes = 3;
