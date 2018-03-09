void setup()
{
  display_init();
  welcome_screen();
  init_speaker();
  init_bomb_buttons();
}

void loop()
{
  menu_control();                     //show menu
  mode_loop();
}

// looping all modes, just active one in use
void mode_loop()
{
  bomb_mode_control();
  flags2_mode_control();
  flagsN_mode_control();
}

