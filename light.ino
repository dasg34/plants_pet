#define LIGHT A0 //조도센서
#define L_RED 11
#define L_GREEN 10
#define L_BLUE 9
#define PLANTS_LED 12


void led_3color_on(int red, int green, int blue, int color);

static int light_warning_count; 

static void
plants_led_on()
{
  digitalWrite(PLANTS_LED, HIGH);
}

static void
plants_led_off()
{
  digitalWrite(PLANTS_LED, LOW);
}

static int
light_get()
{
  int val=analogRead(LIGHT);
  Serial.println(val);
  return val;
  //조도 센서로부터 받은 값을 리턴.
}

static int
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

int
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


  if (light_warning_count>=6)
  {
    plants_led_on();
    led_3color_on(L_RED, L_GREEN, L_BLUE, RED_COLOR);
    return STATE_BAD;
  }
  else if (light_warning_count >= 3)
  {
    led_3color_on(L_RED, L_GREEN, L_BLUE, YELLOW_COLOR);
    return STATE_WARN;
  }
  else
  {
    led_3color_on(L_RED, L_GREEN, L_BLUE, GREEN_COLOR);
    return STATE_GREAT;
  }

  //수준 아래로 떨어지면 카운트 플러스, 일정카운트 이상 쌓이면 0.
  //수준 이상이 되면 카운트 초기화. 식물 성장용 LED off
}

void
light_setup()
{
  pinMode(PLANTS_LED, OUTPUT);
  pinMode(L_RED, OUTPUT);
  pinMode(L_GREEN, OUTPUT);
  pinMode(L_BLUE, OUTPUT);
}

