int m = 0;
int lm = 0;
int mA[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int sA[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int pA[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int p2A[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int faA[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int fA[2];
int so = 0;
int ls = 0;
int panA[2];
int p = 0;
int pa = 0;
int s = 0;
int r = 0;
int re = 0;
int f = 0;
int canal = 0;
int cme = 0;
int cma = 0;
void setup()
{
  Serial.begin(31250);
  pinMode(42, INPUT);
  pinMode(35, INPUT);
  pinMode(30, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(22, INPUT);
  pinMode(23, INPUT);
  pinMode(25, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}
void loop()
{
  l();
  mute();
  solo();
  pan();
  play();
  sto();
  record();
  rewind();
  forward();
  canalmas();
  canalmenos();
  dis();
  fade();
}
void mute()
{
  if (digitalRead(42) == HIGH && m == 0 && mA[canal] == 0)
  {
    m = 1;
    mA[canal] = 1;
    controlChange(12, 127);
  }
  if (digitalRead(42) == HIGH && m == 0 && mA[canal] == 1)
  {
    m = 1;
    mA[canal] = 0;
    controlChange(12, 127);
  }
  if (digitalRead(42) == LOW && m == 1)
  {
    m = 0;
  }
}
void solo()
{
  if (digitalRead(35) == HIGH && so == 0 && sA[canal] == 0)
  {
    so = 1;
    sA[canal] = 1;
    controlChange(13, 127);
  }
  if (digitalRead(35) == HIGH && so == 0 && sA[canal] == 1)
  {
    so = 1;
    sA[canal] = 0;
    controlChange(13, 127);
  }
  if (digitalRead(35) == LOW && so == 1)
  {
    so = 0;
  }
}
void l()
{
  if (mA[canal] == 1)
  {
    led(25, HIGH);
  }
  if (mA[canal] == 0)
  {
    led(25, LOW);
  }
  if (sA[canal] == 1)
  {
    led(28, HIGH);
  }
  if (sA[canal] == 0)
  {
    led(28, LOW);
  }
}
void pan()
{
  panA[0] = analogRead(A0);
  panA[1] = analogRead(A0);
  panA[0] = map(panA[0], 0, 1023, -300, 300);
  panA[1] = map(panA[1], 0, 1023, -300, 300);
  if (panA[1] >= pA[canal] - 10 && panA[1] <= pA[canal] + 10)
  {
    pA[canal] = panA[1];
    if (panA[0] != panA[1])
    {
      if (panA[1] > p2A[canal])
      {
        controlChange(canal + 17, 127);
        p2A[canal] = panA[1];
      }
      if (panA[1] < p2A[canal])
      {
        controlChange(canal + 17, 1);
        p2A[canal] = panA[1];
      }
    }
  }
}
void fade()
{
  fA[0] = analogRead(A1);
  fA[1] = analogRead(A1);
  fA[0] = map(fA[0], 0, 1023, 0, 127);
  fA[1] = map(fA[1], 0, 1023, 0, 127);
  if (fA[1] >= faA[canal] - 10 && fA[1] <= faA[canal] + 10)
  {
    faA[canal] = fA[1];
    if (fA[0] != fA[1])
    {
      controlChange(canal + 33, fA[1]);
    }
  }
}
void play()
{
  if (digitalRead(30) == HIGH && p == 0 && pa == 0)
  {
    p = 1;
    pa = 1;
    controlChange(117, 127);
  }
  if (digitalRead(30) == HIGH && p == 0 && pa == 1)
  {
    p = 1;
    pa = 0;
    controlChange(116, 127);
  }
  if (digitalRead(30) == LOW && p == 1)
  {
    p = 0;
  }
}
void sto()
{
  if (digitalRead(2) == HIGH && s == 0)
  {
    s = 1;
    pa = 0;
    controlChange(116, 127);
  }
  if (digitalRead(2) == LOW && s == 1)
  {
    s = 0;
  }
}
void record()
{
  if (digitalRead(3) == HIGH && r == 0)
  {
    r = 1;
    controlChange(118, 127);
  }
  if (digitalRead(3) == LOW && r == 1)
  {
    r = 0;
  }
}
void rewind()
{
  if (digitalRead(4) == HIGH && re == 0)
  {
    re = 1;
    controlChange(114, 127);
  }
  if (digitalRead(4) == LOW && re == 1)
  {
    re = 0;
    controlChange(114, 0);
  }
}
void forward()
{
  if (digitalRead(5) == HIGH && f == 0)
  {
    f = 1;
    controlChange(115, 127);
  }
  if (digitalRead(5) == LOW && f == 1)
  {
    f = 0;
    controlChange(115, 0);
  }
}
void controlChange(int control, int valor)
{
  Serial.write(176);
  Serial.write(control);
  Serial.write(valor);
}
void canalmenos()
{
  if (canal < 0)
  {
    canal = 0;
  }
  if (digitalRead(23) == HIGH && cme == 0)
  {
    if (canal >= 0)
    {
      canal = canal--;
      controlChange(110, 127);
    }
    cme = 1;
  }
  if (digitalRead(23) == LOW && cme == 1)
  {
    cme = 0;
  }
}
void canalmas()
{
  if (canal > 7)
  {
    canal = 7;
  }
  if (digitalRead(22) == HIGH && cma == 0)
  {
    if (canal <= 7)
    {
      canal = canal++;
      controlChange(111, 127);
    }
    cma = 1;
  }
  if (digitalRead(22) == LOW && cma == 1)
  {
    cma = 0;
  }
}
void led(int n, char e) { digitalWrite(n, e); }
void dis()
{
  switch (canal)
  {
  case 0:
    display(1, 0, 0, 1, 1, 1, 1);
    break;
  case 1:
    display(0, 0, 1, 0, 0, 1, 0);
    break;
  case 2:
    display(0, 0, 0, 0, 1, 1, 0);
    break;
  case 3:
    display(1, 0, 0, 1, 1, 0, 0);
    break;
  case 4:
    display(0, 1, 0, 0, 1, 0, 0);
    break;
  case 5:
    display(0, 1, 0, 0, 0, 0, 0);
    break;
  case 6:
    display(0, 0, 0, 1, 1, 1, 1);
    break;
  case 7:
    display(0, 0, 0, 0, 0, 0, 0);
    break;
  }
}
void display(int a, int b, int c, int d, int e, int f, int g)
{
  digitalWrite(7, a);
  digitalWrite(8, b);
  digitalWrite(9, c);
  digitalWrite(10, d);
  digitalWrite(11, e);
  digitalWrite(12, f);
  digitalWrite(6, g);
}
