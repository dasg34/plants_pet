#include <OneWire.h>
#include <DallasTemperature.h>
#define TEMPERATURE 2
#define T_RED 11
#define T_GREEN 10
#define T_BLUE 9
#define HEATINGPAD 5

OneWire oneWire(TEMPERATURE);
DallasTemperature sensors(&oneWire);

void led_3color_on(int red, int green, int blue, int color);

static int temperature_warning_count; 


static void
heating_pad_on()
{
  // 열선패드에 전원을 공급
  digitalWrite(HEATINGPAD,HIGH);        
}

static void
heating_pad_off()
{
  //열선패드에 전원 off
  digitalWrite(HEATINGPAD,LOW);
}

static int
temperature_get()
{
  sensors.requestTemperatures();
  int temp = sensors.getTempCByIndex(0);
  
  Serial.println(temp);
  //온도 센서로부터 받은 값을 리턴.
  return temp;
}

static int
enough_temperature_is()
{
  //온도 센서의 측정값이 일정수준 아래로 떨어지면 0, 아니면 1 리턴.
  if (temperature_get() < 30)
     return 0;
  else 
     return 1;
}

void
tempearture_check()
{
  //수준 아래로 떨어지면 카운트 플러스, 일정카운트 이상 쌓이면 0.
  //수준 이상이 되면 카운트 초기화. 열선패드 off
  if (enough_temperature_is() == 0)
    temperature_warning_count++;
  else
  {
    temperature_warning_count = 0;
    heating_pad_off();
  }

  if (temperature_warning_count >= 6)
  {
     heating_pad_on();
     led_3color_on(T_RED, T_GREEN, T_BLUE, RED_COLOR);
  }
  else if (temperature_warning_count >= 3)
  {
     led_3color_on(T_RED, T_GREEN, T_BLUE, YELLOW_COLOR);
  }
  else
  {
    led_3color_on(T_RED, T_GREEN, T_BLUE, GREEN_COLOR);
  }
}

void
temperature_setup()
{
  sensors.begin();
  pinMode(HEATINGPAD, OUTPUT);
  pinMode(T_RED, OUTPUT);
  pinMode(T_GREEN, OUTPUT);
  pinMode(T_BLUE, OUTPUT);
}

