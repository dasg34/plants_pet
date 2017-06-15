#define EYEBROW 14
#define EYE 15
#define SMILE_MOUTH 16
#define SAD_MOUTH 17

static void
all_face_unset()
{
  digitalWrite(EYEBROW, LOW);
  digitalWrite(SMILE_MOUTH, LOW);
  digitalWrite(SAD_MOUTH, LOW);
}

void
smile_face_set()
{  
  all_face_unset();
  digitalWrite(SMILE_MOUTH, HIGH);
  digitalWrite(EYEBROW, HIGH);
}

void
natural_face_set()
{
  all_face_unset();
  digitalWrite(SMILE_MOUTH, HIGH);
}

void
sad_face_set()
{
  all_face_unset();
  digitalWrite(SAD_MOUTH, HIGH);
}

void
face_setup()
{
  pinMode(EYEBROW, OUTPUT);
  pinMode(EYE, OUTPUT);
  pinMode(SMILE_MOUTH, OUTPUT);
  pinMode(SAD_MOUTH, OUTPUT);

  digitalWrite(EYE, HIGH);
}

