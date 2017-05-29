
#define TEMPERATURE A0
#define HEATINGPAD1 5
#define HEATINGPAD2 6

#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);


static int temperature_warning_count; 


static void
heating_pad_on()
{
  // 열선패드에 전원을 공급
  digitalWrite(HEATINGPAD1,HIGH);
  digitalWrite(HEATINGPAD2,HIGH);
         
        
    }
 


static void
heating_pad_off()
{
  //열선패드에 전원 off
  
  digitalWrite(HEATINGPAD1,LOW);
  digitalWrite(HEATINGPAD2,LOW);

 
 }

static int
temperature_get()
{
  int temp=analogRead(TEMPERATURE);
  
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

  if (temperature_warning_count > 3)
  {
     heating_pad_on();
  }
}

void
temperature_setup()
{
  pinMode(HEATINGPAD1, OUTPUT);
  pinMode(HEATINGPAD2, OUTPUT);
}

