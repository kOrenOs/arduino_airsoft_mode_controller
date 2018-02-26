// basic init diplay
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

void reset_top_screen()
{
  display_on_top_screen(blank_line_message);
}

void reset_lower_screen()
{
  display_on_lower_screen(blank_line_message);
}

// text is displayed on top of screen and delayed for time set as parameter
void show_message_for_time(String text, int time_in_ms)
{
  reset_top_screen();
  display_on_top_screen(text);
  delay(time_in_ms);
}

// intro shows name of chosen mode for several seconds  
void mode_intro(int mode_number)
{
  reset_top_screen();
  reset_lower_screen();
  show_message_for_time(mode_names[mode_number - 1],3000);
}

// shows welcome screen for several seconds
void welcome_screen()
{
  show_message_for_time(welcome_message, 3000);
  reset_top_screen();
  reset_lower_screen();
}

