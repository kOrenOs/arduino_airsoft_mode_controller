// main control point for menu, shows menu and wait for inputs
void menu_control()
{
  if(state_in_menu){
    show_menu_on_position(actual_displayed_top_menu_record);
    keyboard_listener();
  }
}

void show_menu_on_position(int displayed_top_record)
{
  int number_of_mode = displayed_top_record + 1;
  if(displayed_top_record + 1 < number_of_modes){
    String number_of_mode_top = String(number_of_mode);
    String number_of_mode_lower = String(number_of_mode + 1);
    
    display_on_top_screen(number_of_mode_top + " " + mode_names[displayed_top_record]);
    display_on_lower_screen(number_of_mode_lower + " " +mode_names[displayed_top_record + 1]);
  }
}

// listener for menu 
// pressed number will choose mode
// sign # moves menu up, if it is possible
// sign * moves menu down, if it is possible
void keyboard_listener()
{
  char key = keypad.getKey();
  if (key != NO_KEY){
    if(key == '#'){
      go_up();
    }
    if(key == '*'){
      go_down();
    }
    int pressed_number = key - '0';
    if(pressed_number > 0 && pressed_number <= number_of_modes){
      state_in_menu = false;
      active_mode[pressed_number - 1] = true;
      mode_intro(pressed_number);
    }
  }
}

// change top menu record, if it is possible
void go_down()
{
  if(actual_displayed_top_menu_record + 2 < number_of_modes){
    reset_top_screen();
    reset_lower_screen();
    actual_displayed_top_menu_record++;
  }
}

// change top menu record, if it is possible
void go_up()
{
  if(actual_displayed_top_menu_record - 1 >= 0){
    reset_top_screen();
    reset_lower_screen();
    actual_displayed_top_menu_record--;
  }
}

