void init_bomb_buttons()
{
  pinMode(first_bomb_button_pin, INPUT_PULLUP);
  pinMode(second_bomb_button_pin, INPUT_PULLUP);
}

bool check_both_bomb_buttons()
{
  int button1_value = digitalRead(first_bomb_button_pin);
  int button2_value = digitalRead(second_bomb_button_pin);
  
  if (button1_value == LOW && button2_value == LOW){
    return true;
  }
  return false;
}

