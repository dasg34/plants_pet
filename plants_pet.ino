#include "face.h"
#include "temperature.h"
#include "water.h"
#include "light.h"

enum led_color {
  RED_COLOR,
  YELLOW_COLOR,
  GREEN_COLOR
};

enum senser_state {
  STATE_GREAT,
  STATE_WARN,
  STATE_BAD
};

void
led_3color_on(int red, int green, int blue, int color)
{
  switch (color)
  {
    case RED_COLOR:
      analogWrite(red, 255);
      analogWrite(green, 0);
      analogWrite(blue, 0);
      break;
    case YELLOW_COLOR:
      analogWrite(red, 255);
      analogWrite(green, 255);
      analogWrite(blue, 0);
      break;
    case GREEN_COLOR:
      analogWrite(red, 0);
      analogWrite(green, 255);
      analogWrite(blue, 0);
      break;
  }
}

void
setup()
{
  Serial.begin(9600);
  face_setup();
  water_setup();
  temperature_setup();
  light_setup();
}

void 
loop()
{
  int light_state, temp_state, water_state;

  light_state = light_check();
  temp_state = tempearture_check();
  water_state = water_check();

  if ((light_state == STATE_BAD || temp_state == STATE_BAD || water_state == STATE_BAD)
      || (light_state == STATE_WARN && temp_state == STATE_WARN && water_state == STATE_WARN))
  {
    sad_face_set();
  }
  else if (light_state == STATE_WARN || temp_state == STATE_WARN || water_state == STATE_WARN)
  {
    natural_face_set();  
  }
  else
  {
    smile_face_set();
  }
  
  delay(2000);
  //이곳에 우리의 알고리즘이 들어갑니다.
}
