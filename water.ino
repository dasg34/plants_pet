
static int moisture_warning_count; 

static int
soil_moisture_get()
{
  //수분 센서로부터 받은 값을 리턴.
}

int
enough_water_is()
{
  //수분 센서의 측정값이 일정수준 아래로 떨어지면 0, 아니면 1 리턴.
  //10분 단위로 측정하며 수준 아래로 떨어지면 카운트 플러스, 일정카운트 이상 쌓이면 0.
  //수준 이상이 되면 카운트 초기화.
}

void
dry_warn()
{
  //부저 소리 발생.
}

void
water_setup()
{
  
}

