bool state_in_menu = true;                                  // whether is menu displayed or not
int actual_displayed_top_menu_record = 0;                   // index of record on top of menu

// int actual_mode;

// bomb mode states
bool bomb_set_pin_state = true;
bool bomb_set_timer_state = false;
bool bomb_active_state = false;

// change this to add new mode
String mode_names[] = {"Bomb", "Flags", "Rush"};            // mode names for display in menu

const int number_of_modes = sizeof(mode_names) / sizeof(mode_names[0]);                                    // number of modes, helps menu to keep boundings
bool active_mode[number_of_modes];                          // active mode has true value

// find index of mode mentioned in parameter
int get_index_of_mode(String mode_to_find)
{
  for(int i = 0; i < number_of_modes; i++){
    if(mode_to_find == mode_names[i]){
      return i;
    }
  }
  return -1;
}

