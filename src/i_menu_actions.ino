void menu_control()
{
  if(state_in_menu){
    show_menu_on_position(actual_displayed_top_menu_record);
    keyboardListener();
  }
}

void keyboardListener()
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

void go_down()
{
  if(actual_displayed_top_menu_record + 2 < number_of_modes){
    reset_top_screen();
    reset_lower_screen();
    actual_displayed_top_menu_record++;
  }
}

void go_up()
{
  if(actual_displayed_top_menu_record - 1 >= 0){
    reset_top_screen();
    reset_lower_screen();
    actual_displayed_top_menu_record--;
  }
}

