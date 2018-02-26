void display_init()
{
  lcd.begin();
  lcd.backlight();
}

void display_on_top_screen(String text)
{
  lcd.setCursor(0, 0);
  lcd.print(text);
}

void display_on_lower_screen(String text)
{
  lcd.setCursor(0, 1);
  lcd.print(text);
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

void reset_top_screen()
{
  display_on_top_screen(blank_line_message);
}

void reset_lower_screen()
{
  display_on_lower_screen(blank_line_message);
}

void show_message_for_time(String text, int time_in_ms)
{
  reset_top_screen();
  display_on_top_screen(text);
  delay(time_in_ms);
}

void mode_intro(int mode_number)
{
  reset_top_screen();
  reset_lower_screen();
  show_message_for_time(mode_names[mode_number - 1],3000);
}

void welcome_screen()
{
  show_message_for_time(welcome_message, 3000);
  reset_top_screen();
  reset_lower_screen();
}

