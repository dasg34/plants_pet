#include "face.h"
#include "temperature.h"
#include "water.h"
#include "light.h"

enum led_color {
  RED_COLOR,
  YELLOW_COLOR,
  GREEN_COLOR
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
  face_setup();
  water_setup();
  temperature_setup();
  light_setup();
}

void 
loop()
{
  light_check();
  delay(1000);
  //이곳에 우리의 알고리즘이 들어갑니다.
}
