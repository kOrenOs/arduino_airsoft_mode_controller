int flags_mode_index = 1;

// main mode controller, mode states changing 
void flags_mode_control()
{
  if(active_mode[flags_mode_index]){
    show_message_for_time(mode_not_implemented_message, 1500);
    flags_mode_back_to_menu();
  }
}

// mode reset and move back to menu
void flags_mode_back_to_menu()
{
  reset_top_screen();
  reset_lower_screen();
  
  active_mode[flags_mode_index] = false;
  state_in_menu = true;
}

