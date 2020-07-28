#include <stdio.h>
#include <time.h>       /* time_t, struct tm, time, localtime, asctime */
#include <Arduino.h>
#include "Temporizador.h"

const char * weekday[] = { "Sunday", "Monday",
                           "Tuesday", "Wednesday",
                           "Thursday", "Friday", "Saturday"
                         };


Temporizador::Temporizador(int year, int month, int day, int hour, int min, int second) {

  this->year = year;
  this->month = month;
  this->day = day;
  this->hour = hour;
  this->min = min;
  this->second = second;

  time_t rawtime;
  struct tm * timeinfo;

  /* get current timeinfo and modify it to the user's choice */
  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  timeinfo->tm_year = year - 1900;
  timeinfo->tm_mon = month - 1;
  timeinfo->tm_mday = day;
  timeinfo->tm_sec = second;
  timeinfo->tm_min = min;
  timeinfo->tm_hour = hour;

  mktime ( timeinfo );
  char texto2[256];
  sprintf (texto2, "%s", asctime(timeinfo));

  Serial.println(texto2);

  
}
