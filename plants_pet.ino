#include "face.h"
#include "temperature.h"
#include "water.h"
#include "light.h"

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
  //이곳에 우리의 알고리즘이 들어갑니다.
}
