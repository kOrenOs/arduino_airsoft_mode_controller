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

