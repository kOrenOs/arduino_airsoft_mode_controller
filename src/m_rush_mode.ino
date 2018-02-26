int rush_mode_index = 2;

void rush_mode_control()
{
  if(active_mode[rush_mode_index]){
    show_message_for_time(mode_not_implemented_message, 1500);
    rush_mode_back_to_menu();
  }
}

void rush_mode_back_to_menu()
{
  reset_top_screen();
  reset_lower_screen();
  
  active_mode[rush_mode_index] = false;
  state_in_menu = true;
}

