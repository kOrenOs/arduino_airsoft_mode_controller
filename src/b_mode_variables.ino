//pin saver
String pin = "     ";
String pin_try = "     ";

//actual char of pin for change
int actual_pin_point = -1;

long timer;
long start_time = 2147483647L;
void reset_start_time_value()
{
  start_time = 2147483647L;
}

bool bomb_countdown_started = false;

int max_hours = 96;
int max_minutes = 59;
int max_seconds = 59;

int hours = 0;
int minutes = 0;
int seconds = 0;

bool hours_setted = false;
bool minutes_setted = false;
bool seconds_setted = false;

