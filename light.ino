#define LIGHT A0
#define RED 11
#define GREEN 10
#define BLUE 9

void led_3color_on(int red, int green, int blue, int color);

static int light_warning_count; 

static void
plants_led_on()
{
  
}

static void
plants_led_off()
{
  
}

static int
light_get()
{
  int val=analogRead(LIGHT);
  Serial.println(val);
  return val;
  //조도 센서로부터 받은 값을 리턴.
}

int
enough_light_is()
{
  if(light_get()<600)
  {
    return 0;
  }
  else
  {
    return 1;
  }
  //조도 센서의 측정값이 일정수준 아래로 떨어지면 0, 아니면 1 리턴.
}

void
light_warn()
{
  //light on
}

void
light_check()
{ 
  if(enough_light_is()==0)
  {
    light_warning_count++;
  }
  else
  {
    light_warning_count=0;
    plants_led_off();
  }


  if(light_warning_count>=6)
  {
    plants_led_on();
  }

  //led_3color_on(RED, GREEN, BLUE, RED_COLOR);
  
  //수준 아래로 떨어지면 카운트 플러스, 일정카운트 이상 쌓이면 0.
  //수준 이상이 되면 카운트 초기화. 방열패드 off
}

void
light_setup()
{
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

