String pin = "     ";                         // origin pin variable
String pin_try = "     ";                     // pin variable while pin guessing

int actual_pin_point = -1;                    // actual char of pin for change
int pin_length = 4;                           // required pin length

long timer = 0;                                   // total time for countdown
long start_time = 2147483647L;                // time of countdown start
void reset_start_time_value()
{
  start_time = 2147483647L;
}

bool bomb_countdown_started = false;
long time_defusing_start_time = 0;
long time_to_defuse = 0;

void reset_time_defusing_start_time()
{
  time_defusing_start_time = 0;
}

// max values of time units
int max_hours = 96;
int max_minutes = 59;
int max_seconds = 59;

// variables to set time units one by one
int hours = 0;
int minutes = 0;
int seconds = 0;

// already set units
bool hours_set = false;
bool minutes_set = false;
bool seconds_set = false;



