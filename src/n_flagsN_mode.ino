int flagsN_mode_index = get_index_of_mode("Flags- N teams");

// main mode controller, mode states changing 
void flagsN_mode_control()
{
  if(active_mode[flagsN_mode_index]){
    show_message_for_time(mode_not_implemented_message, 1500);
    flagsN_mode_back_to_menu();
  }
}

// mode reset and move back to menu
void flagsN_mode_back_to_menu()
{
  reset_top_screen();
  reset_lower_screen();
  
  active_mode[flagsN_mode_index] = false;
  state_in_menu = true;
}

