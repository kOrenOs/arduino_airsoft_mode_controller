int bomb_mode_index = get_index_of_mode("Bomb");

// main mode controller, mode states changing 
void bomb_mode_control()
{
  if(active_mode[bomb_mode_index]){
    if(bomb_set_pin_state){
      bomb_pin_set();
    }else{
      if(bomb_set_timer_state){
        bomb_timer_set();
      }else{
        if(bomb_active_state){
          bomb_active();
        }else{
          bomb_mode_back_to_menu();
        }
      }
    }
  }
}

// mode state
void bomb_pin_set()
{
  display_on_top_screen(bomb_mode_set_pin_message);
  display_on_lower_screen(get_pin());
  
  if(set_origin_pin()){
    bomb_set_pin_state = false;
    bomb_set_timer_state = true;
  }
}

// mode state
void bomb_timer_set()
{
  display_on_top_screen(bomb_mode_set_timer_message);
  display_on_lower_screen(get_set_time());
  
  if(set_timer_mode()){
    if(get_actual_timer_time() <= 0){
      bomb_mode_back_to_menu();
    }else{
      bomb_active_state = true;
      bomb_set_timer_state = false;
    }
  }
}

// mode state
void bomb_active()
{
  display_on_top_screen(bomb_mode_time_to_explode_message);
  display_on_lower_screen(get_countdown() + "  " + pin_try);

  if(set_try_pin()){
    show_message_for_time(bomb_mode_defused_message, 7000);
    bomb_active_state = false;
    reset_timer_state();
  }else{ 
    if(timer_update()){
      bomb_explode();
      bomb_active_state = false;
    }
  }
}

// mode state
void bomb_explode()
{
  display_on_lower_screen(get_countdown() + "  " + pin_try);
  turn_speaker_on();
  show_message_for_time(bomb_mode_explosion_message, 4000);
  turn_speaker_off();
  show_message_for_time(bomb_mesage_bomb_exploded_message, 7000);
}

// mode reset and move back to menu
void bomb_mode_back_to_menu()
{
  reset_top_screen();
  reset_lower_screen();
  
  reset_pins();
  reset_timer_state();
  
  bomb_set_pin_state = true;
  bomb_set_timer_state = false;
  bomb_active_state = false;
  active_mode[bomb_mode_index] = false;
  state_in_menu = true;
}

