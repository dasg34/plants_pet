
static int temperature_warning_count; 

static void
heating_pad_on()
{
  
}

static void
heating_pad_off()
{
  
}

static int
temperature_get()
{
  //온도 센서로부터 받은 값을 리턴.
}

static int
enough_temperature_is()
{
  //온도 센서의 측정값이 일정수준 아래로 떨어지면 0, 아니면 1 리턴.
  //10분 단위로 측정하며 수준 아래로 떨어지면 카운트 플러스, 일정카운트 이상 쌓이면 0.
  //수준 이상이 되면 카운트 초기화. 방열패드 off
}

void
temperature_warn()
{
  //방열패드 on
}

void
temperature_setup()
{
  
}

