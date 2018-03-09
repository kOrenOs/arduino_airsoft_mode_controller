// basic method for keypad listening and pin building click by click
// numbers are used for pin, sign # for pin confirmation (when pin has required length),
// sign * has no functionality

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
    if(actual_pin_point == pin_length){
      actual_pin_point = 0;
      pin_reset(pin_place);
    }
    
    pin_place[actual_pin_point] = key;
  }
  return false;
}

// set ogirin pin
bool set_origin_pin()
{
  return pin_setter(pin);
}

// set guessing pin and compare with origin after pin confirmation,
// return true if both same, false if not same or if guessed pin has not required length
bool set_try_pin()
{
  if(pin_setter(pin_try)){
    if(compare_pins()){
      return true;
    }else{
      pin_reset(pin_try);
    }
  }
  return false;
}

bool compare_pins()
{
  if(pin == pin_try){
    return true;
  }
  return false;
}

// reset pin to empty string (spaces- necesarry for position pin editing)
void pin_reset(String &pin_place)
{
  pin_place[0] = ' ';
  pin_place[1] = ' ';
  pin_place[2] = ' ';
  pin_place[3] = ' ';
}

// reset both pin and guessed pin
void reset_pins()
{
  actual_pin_point = -1;
  pin_reset(pin);
  reset_try_pin();
}

void reset_try_pin()
{
  pin_reset(pin_try);
}

// get origin pin
String get_pin()
{
  return pin;
}

// get guessed pin
String get_pin_try()
{
  return pin_try;
}

