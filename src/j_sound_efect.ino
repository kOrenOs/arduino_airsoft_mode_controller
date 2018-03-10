void init_speaker()
{
  pinMode(2, OUTPUT);
}

void turn_speaker_on()
{
  digitalWrite(2, HIGH);
}

void turn_speaker_off()
{
  digitalWrite(2, LOW);
}

void one_continouse_sound(String message_while_sound, int time_of_sound)
{
  turn_speaker_on();
  show_message_for_time(message_while_sound, time_of_sound);
  turn_speaker_off();
}

void sound_for_time(int time_of_sound)
{
  turn_speaker_on();
  delay(time_of_sound);
  turn_speaker_off();
}

void intermittent_sound(int time_of_sound, int time_of_silence, int number_of_sound_repeating, String message_while_sound)
{
  reset_top_screen();
  display_on_top_screen(message_while_sound);
  
  for(int i = 0; i < number_of_sound_repeating - 1; i++){
    sound_for_time(time_of_sound);
    delay(time_of_silence);
  }
  sound_for_time(time_of_sound);
}

