bool pin_setter(String &pin_place)
{
  char key = keypad.getKey();
  if (key != NO_KEY){
    if(key == '#' && actual_pin_point == 3){
      actual_pin_point = -1;
      return true;
    }
    
    if(key == '*' || key == '#'){
      return false;
    }
    
    actual_pin_point++;
    if(actual_pin_point == 4){
      actual_pin_point = 0;
      pin_reset(pin_place);
    }
    
    pin_place[actual_pin_point] = key;
  }
  return false;
}

bool set_origin_pin()
{
  return pin_setter(pin);
}

bool set_try_pin()
{
  if(pin_setter(pin_try)){
    if(pin == pin_try){
      return true;
    }else{
      pin_reset(pin_try);
    }
  }
  return false;
}

void pin_reset(String &pin_place)
{
  pin_place[0] = ' ';
  pin_place[1] = ' ';
  pin_place[2] = ' ';
  pin_place[3] = ' ';
}

void reset_pins()
{
  actual_pin_point = -1;
  pin_reset(pin);
  pin_reset(pin_try);
}

String get_pin()
{
  return pin;
}

String get_pin_try()
{
  return pin_try;
}

