void setup()
{
  display_init();
  welcome_screen();
  init_speaker();
}

void loop()
{
  menu_control();
  mode_loop();
}

void mode_loop()
{
  bomb_mode_control();
  flags_mode_control();
  rush_mode_control();
}

