int first_bomb_button_address = 52;
int second_bomb_button_address = 50;

void init_bomb_buttons()
{
  pinMode(first_bomb_button_address, INPUT_PULLUP);
  pinMode(second_bomb_button_address, INPUT_PULLUP);
}

bool check_both_bomb_buttons()
{
  int button1_value = digitalRead(first_bomb_button_address);
  int button2_value = digitalRead(second_bomb_button_address);
  
  if (button1_value == LOW && button2_value == LOW){
    return true;
  }
  return false;
}

