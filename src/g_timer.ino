bool set_timer_mode()
{
  if(!hours_setted){
    set_hours();
  }else{
    if(!minutes_setted){
      set_minutes();
    }else{
      if(!seconds_setted){
        set_seconds();
      }else{
        if(!bomb_countdown_started){
          start_timer();
        }
        bomb_countdown_started = true;
        return true;
      }
    }
  }
  
  return false;
}

void set_hours()
{
  timer_changer(hours, hours_setted, max_hours);
}

void set_minutes()
{
  timer_changer(minutes, minutes_setted, max_minutes);
}

void set_seconds()
{
  timer_changer(seconds, seconds_setted, max_seconds);
}

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
    compute_time();
  }
}

void move_units_for_change()
{
  if(!hours_setted && !minutes_setted && !seconds_setted){
    hours_setted = true;
  }else{
    if(hours_setted && !minutes_setted && !seconds_setted){
      minutes_setted = true;
    }else{
      if(hours_setted && minutes_setted && !seconds_setted){
        hours_setted = false;
        minutes_setted = false;
      }
    }
  }
}

void compute_time()
{
  timer = ((long)hours * 60 + minutes) * 60 + seconds;
}

String timer_to_string(long timer_value)
{
  if(timer_value < 0){
    timer_value = 0;
  }
  String formatted_timer;

  int hours = timer_value / 3600;
  int minutes = (timer_value % 3600) / 60;
  int seconds = timer_value % 60;
  
  formatted_timer = convert_int_to_char(hours);
  formatted_timer += ":";
  formatted_timer += convert_int_to_char(minutes);
  formatted_timer += ":";
  formatted_timer += convert_int_to_char(seconds);

  return formatted_timer;
}

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

bool start_timer()
{
  start_time = millis();
}

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

long get_actual_timer_time()
{
  return timer - ((millis() - start_time)  / 1000);
}

String get_set_time()
{
  String formatted_timer = timer_to_string(timer);
  String for_blinking;
  
  if(!hours_setted){
    for_blinking = get_blinking_text(formatted_timer.substring(0,2),500);
    formatted_timer = append_substring(formatted_timer, for_blinking, 0);
  }else{
    if(!minutes_setted){
      for_blinking = get_blinking_text(formatted_timer.substring(3,5),500);
      formatted_timer = append_substring(formatted_timer, for_blinking, 3);
    }else{
      if(!seconds_setted){
        for_blinking = get_blinking_text(formatted_timer.substring(6,8),500);
        formatted_timer = append_substring(formatted_timer, for_blinking, 6);
      }
    }
  }
  return formatted_timer;
}

String get_countdown()
{
  return timer_to_string(get_actual_timer_time());
}

void reset_timer_state()
{
  reset_start_time_value();
  
  hours_setted = false;
  minutes_setted = false;
  seconds_setted = false;
  bomb_countdown_started = false;
}

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

String append_substring(String origin, String for_append, int from_position)
{
  for(int i = 0; i < for_append.length(); i++){
    origin[from_position + i] = for_append[i];
  }
  return origin;
}

