// main controller to set timer, ask to set time and then start countdown
bool set_timer_mode()
{
  if(set_time_for_variable(timer)){
    if(!bomb_countdown_started){
      start_timer();
    }
    bomb_countdown_started = true;
    return true;
  }
  
  return false;
}
// waiting to fill all necessary time units and set variable for result in seconds
bool set_time_for_variable(long &timer_variable)
{
  if(!hours_set){
    set_hours();
  }else{
    if(!minutes_set){
      set_minutes();
    }else{
      if(!seconds_set){
        set_seconds();
      }else{
        compute_time(timer_variable);
        reset_set_time_variables();
        return true;
      }
    }
  }
  compute_time(timer_variable);
  return false;
}

void set_hours()
{
  timer_changer(hours, hours_set, max_hours);
}

void set_minutes()
{
  timer_changer(minutes, minutes_set, max_minutes);
}

void set_seconds()
{
  timer_changer(seconds, seconds_set, max_seconds);
}

// keypad listener for time units filling
// it sets time unit and unit checker from parametes while keeping max time units value
// numbers are for time units, 
// sign # is for confirmation of chosen unit and confirmation of all timer when seconds unit is active
// sign * is used for change of active time unit in round
void timer_changer(int &time_unit, bool &time_unit_checker, int unit_max_value)
{
  char key = keypad.getKey();
  if (key != NO_KEY){
    if(key == '*'){
      move_units_for_change();
      return;
    }
    if(key == '#'){
      time_unit_checker = true;
      return;
    }
    time_unit *= 10;
    time_unit += key - '0';

    if(time_unit > unit_max_value){
      time_unit = 0;
    }
  }
}

// change active time unit in round
void move_units_for_change()
{
  if(!hours_set && !minutes_set && !seconds_set){
    hours_set = true;
  }else{
    if(hours_set && !minutes_set && !seconds_set){
      minutes_set = true;
    }else{
      if(hours_set && minutes_set && !seconds_set){
        hours_set = false;
        minutes_set = false;
      }
    }
  }
}

// compute total timer time in seconds
void compute_time(long &timer_variable)
{
  timer_variable = ((long)hours * 60 + minutes) * 60 + seconds;
}

// return formatted time value from parameter (value should be in seconds)
String timer_to_string(long timer_value, bool only_minutes_seconds)
{
  if(timer_value < 0){
    timer_value = 0;
  }
  String formatted_timer;

  int hours = timer_value / 3600;
  int minutes = (timer_value % 3600) / 60;
  int seconds = timer_value % 60;

  if(!only_minutes_seconds){
    formatted_timer = convert_int_to_char(hours);
    formatted_timer += ":";
  }
  formatted_timer += convert_int_to_char(minutes);
  formatted_timer += ":";
  formatted_timer += convert_int_to_char(seconds);

  return formatted_timer;
}

// conversion
String convert_int_to_char(long int_value)
{
  String output;
  if(int_value < 10){
    output = String(0);
    output += int_value;
  }else{
     output = String(int_value);
  }
    
  return output;
}

// set timer start time
bool start_timer()
{
  start_time = millis();
}

// update countdown at the moment of method run
bool timer_update()
{
  long actual_timer_time = get_actual_timer_time();
  if(actual_timer_time > 0){
    return false;
  }else{
    reset_timer_state();
    return true;
  }
}

// get actual countdown time at the moment of method run
long get_actual_timer_time()
{
  return timer - get_time_difference_to_actual_time_in_seconds(start_time);
}

// get time of timer while timer setting up, it has blinking efect on active time unit
String get_set_time(long timer_variable)
{
  String formatted_timer = timer_to_string(timer_variable, false);
  String for_blinking;
  
  if(!hours_set){
    for_blinking = get_blinking_text(formatted_timer.substring(0,2),500);
    formatted_timer = append_substring(formatted_timer, for_blinking, 0);
  }else{
    if(!minutes_set){
      for_blinking = get_blinking_text(formatted_timer.substring(3,5),500);
      formatted_timer = append_substring(formatted_timer, for_blinking, 3);
    }else{
      if(!seconds_set){
        for_blinking = get_blinking_text(formatted_timer.substring(6,8),500);
        formatted_timer = append_substring(formatted_timer, for_blinking, 6);
      }
    }
  }
  return formatted_timer;
}

String get_set_timer_time()
{
   return get_set_time(timer);
}

// return formatted countdown string
String get_countdown()
{
  return timer_to_string(get_actual_timer_time(), false);
}

// reset all timer states
void reset_timer_state()
{
  reset_start_time_value();
  reset_set_time_variables();
  bomb_countdown_started = false;
}

void reset_set_time_variables()
{
  hours_set = false;
  minutes_set = false;
  seconds_set = false;

  hours = 0;
  minutes = 0;
  seconds = 0;
}

// returned text will be blank or visible, deponds on moduled total time by blink time parameter
String get_blinking_text(String text, int blink_time)
{
  if((millis() / blink_time) % 2 == 0){
    return text;
  }else{
    String output = "";
    for(int i = 0; i < text.length(); i++){
      output += " ";
    }
    return output;
  }
}

// remove and append string to specific position of origin string
String append_substring(String origin, String for_append, int from_position)
{
  for(int i = 0; i < for_append.length(); i++){
    origin[from_position + i] = for_append[i];
  }
  return origin;
}

long get_time_difference_to_actual_time_in_seconds(long difference_start_time)
{
  return (millis() - difference_start_time)  / 1000;
}

