#include "Temporizador.h"
Temporizador *temporizador;

int year = 2020;
int month = 12;
int day = 31;
int hour = 23;
int min = 59;
int second = 55;

unsigned long previousMillis2 = 0;        // will store last time was updated
unsigned long currentMillis2 = 0;       // will store last time  was updated
unsigned long interval2 = 1000;           // 5 seconds

char texto[256];



void setup () {
  Serial.begin(9600);
  Temporizador Temporizador(year, month, day, hour, min, second);
  delay(1000);
}

void loop () {
  Temporizador Temporizador(year, month, day, hour, min, second);
  sprintf(texto, "{\"YEAR\": %d}" "{\"MONTH\": %d}" "{\"DAY\": %d}" "{\"HOUR\": %d}" "{\"MIN\": %d}" "{\"SECOND\": %d}", year, month, day, hour, min, second);
  Serial.println(texto);
  loopTemporizador ();
}

void loopTemporizador () {
  unsigned long currentMillis2 = millis();
  if (currentMillis2 - previousMillis2 >= interval2) {
    previousMillis2 = currentMillis2;
    second++;
  }

  if (day > 31 && month == 12)
  {
    month = 01;
    day = 01;
  }

  if (day > 31)
  {
    day = 01;
  }

  if (second == 60)
  {
    min++;
    second = 0;
  }

  if (min == 60) {
    hour ++;
    min = 0;
  }

  if (hour == 24) {
    hour = 00;
    min = 00;
    second = 00;
    day++;
  }
}
