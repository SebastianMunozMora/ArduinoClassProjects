const int DobuttonPin = 22;
const int DoledPin = 23;
const int DoSbuttonPin = 24;
const int DoSledPin = 25;
const int RebuttonPin = 26;
const int ReledPin = 27;
const int ReSbuttonPin = 28;
const int ReSledPin = 29;
const int MibuttonPin = 30;
const int MiledPin = 31;
const int FabuttonPin = 6;
const int FaledPin = 7;
const int FaSbuttonPin = 34;
const int FaSledPin = 35;
const int SolbuttonPin = 36;
const int SolledPin = 37;
const int SolSbuttonPin = 38;
const int SolSledPin = 39;
const int LabuttonPin = 40;
const int LaledPin = 41;
const int LaSbuttonPin = 42;
const int LaSledPin = 43;
const int SibuttonPin = 44;
const int SiledPin = 45;
const int Do5buttonPin = 46;
const int Do5ledPin = 47;
const int Do5SbuttonPin = 48;
const int Do5SledPin = 49;
const int Re5buttonPin = 50;
const int Re5ledPin = 51;
const int SwitchPin = 52;
const int led13 = 13;
int a = 0;
int b = 0;
int c = 0;
int d = 0;
int e = 0;
int f = 0;
int g = 0;
int h = 0;
int i = 0;
int j = 0;
int k = 0;
int l = 0;
int m = 0;
int n = 0;
int o = 0;
int mm = 0;
int ii = 0;
char aa = 0;
char arrayLeds[] = {Do5ledPin, LaledPin, FaledPin, FaledPin, FaledPin, SolledPin, SolledPin, SolledPin, LaledPin, SolledPin, FaledPin, Do5ledPin, Do5SledPin, Re5ledPin, Re5ledPin, LaledPin, LaSledPin, Do5ledPin, Do5ledPin, LaSledPin, LaSledPin, SiledPin, Do5ledPin, Do5ledPin, SolledPin, LaledPin, LaSledPin, LaSledPin, LaledPin, LaledPin, LaledPin, SolledPin, SolledPin, SolledPin, SolledPin, LaledPin, SiledPin, Do5ledPin, SolledPin, LaledPin, LaledPin, SolledPin, FaledPin, MiledPin, FaledPin, MiledPin, ReledPin, DoledPin};
char arrayButtons[] = {Do5buttonPin, LabuttonPin, FabuttonPin, FabuttonPin, FabuttonPin, SolbuttonPin, SolbuttonPin, SolbuttonPin, LabuttonPin, SolbuttonPin, FabuttonPin, Do5buttonPin, Do5SbuttonPin, Re5buttonPin, Re5buttonPin, LabuttonPin, LaSbuttonPin, Do5buttonPin, Do5buttonPin, LaSbuttonPin, LaSbuttonPin, SibuttonPin, Do5buttonPin, Do5buttonPin, SolbuttonPin, LabuttonPin, LaSbuttonPin, LaSbuttonPin, LabuttonPin, LabuttonPin, LabuttonPin, SolbuttonPin, SolbuttonPin, SolbuttonPin, SolbuttonPin, LabuttonPin, SibuttonPin, Do5buttonPin, SolbuttonPin, LabuttonPin, LabuttonPin, SolbuttonPin, FabuttonPin, MibuttonPin, FabuttonPin, MibuttonPin, RebuttonPin, DobuttonPin};
void setup()
{
  // initialize the LED pin as an output:
  pinMode(DoledPin, OUTPUT);
  pinMode(DobuttonPin, INPUT);
  pinMode(SwitchPin, INPUT);
  pinMode(DoSledPin, OUTPUT);
  pinMode(DoSbuttonPin, INPUT);
  pinMode(ReledPin, OUTPUT);
  pinMode(RebuttonPin, INPUT);
  pinMode(ReSledPin, OUTPUT);
  pinMode(ReSbuttonPin, INPUT);
  pinMode(MiledPin, OUTPUT);
  pinMode(MibuttonPin, INPUT);
  pinMode(FaledPin, OUTPUT);
  pinMode(FabuttonPin, INPUT);
  pinMode(FaSledPin, OUTPUT);
  pinMode(FaSbuttonPin, INPUT);
  pinMode(SolledPin, OUTPUT);
  pinMode(SolbuttonPin, INPUT);
  pinMode(SolSledPin, OUTPUT);
  pinMode(SolSbuttonPin, INPUT);
  pinMode(LaledPin, OUTPUT);
  pinMode(LabuttonPin, INPUT);
  pinMode(LaSledPin, OUTPUT);
  pinMode(LaSbuttonPin, INPUT);
  pinMode(SiledPin, OUTPUT);
  pinMode(SibuttonPin, INPUT);
  pinMode(Do5ledPin, OUTPUT);
  pinMode(Do5buttonPin, INPUT);
  pinMode(Do5SledPin, OUTPUT);
  pinMode(Do5SbuttonPin, INPUT);
  pinMode(Re5ledPin, OUTPUT);
  pinMode(Re5buttonPin, INPUT);
  pinMode(led13, OUTPUT);
  Serial.begin(115200);
}

void loop()
{
  if (digitalRead(SwitchPin) == HIGH)
  {
    // read the state of the pushbutton value:
    //Do
    digitalWrite(led13, HIGH);
    aa = 0;
    notas();
  }
  if (digitalRead(SwitchPin) == LOW)
  {
    digitalWrite(led13, LOW);
    ii = 0;
    aa = 0;
    while (ii <= 47)
    {
      digitalWrite(arrayLeds[ii], HIGH);

      if (aa == arrayLeds[ii])
      {
        digitalWrite(arrayLeds[ii], LOW);
        if (aa == arrayLeds[ii + 1])
        {
          delay(200);
          digitalWrite(led13, HIGH);
        }
        ii++;
        aa = 0;
      }
      if (digitalRead(SwitchPin) == HIGH)
      {
        digitalWrite(arrayLeds[ii], LOW);
        break;
      }
      ii = 0;
      aa = 0;
    }
  }
}
void notas()
{
  if (digitalRead(DobuttonPin) == HIGH && a == 0)
  {
    digitalWrite(DoledPin, HIGH);
    noteOn(0x90, 60, 120);
    a = 1;
    aa = DoledPin;
  }
  if (digitalRead(DobuttonPin) == LOW && a == 1)
  {
    digitalWrite(DoledPin, LOW);
    noteOn(0x90, 60, 0);
    a = 0;
  }
  //Do#
  if (digitalRead(DoSbuttonPin) == HIGH && b == 0)
  {
    digitalWrite(DoSledPin, HIGH);
    noteOn(0x90, 61, 120);
    b = 1;
    aa = DoSledPin;
  }

  if (digitalRead(DoSbuttonPin) == LOW && b == 1)
  {
    digitalWrite(DoSledPin, LOW);
    noteOn(0x90, 61, 0);
    b = 0;
  }
  //Re
  if (digitalRead(RebuttonPin) == HIGH && c == 0)
  {
    digitalWrite(ReledPin, HIGH);
    noteOn(0x90, 62, 120);
    c = 1;
    aa = ReledPin;
  }

  if (digitalRead(RebuttonPin) == LOW && c == 1)
  {
    digitalWrite(ReledPin, LOW);
    noteOn(0x90, 62, 0);
    c = 0;
  }
  //Re#
  if (digitalRead(ReSbuttonPin) == HIGH && d == 0)
  {
    digitalWrite(ReSledPin, HIGH);
    noteOn(0x90, 63, 120);
    d = 1;
    aa = ReSledPin;
  }

  if (digitalRead(ReSbuttonPin) == LOW && d == 1)
  {
    digitalWrite(ReSledPin, LOW);
    noteOn(0x90, 63, 0);
    d = 0;
  }
  //Mi
  if (digitalRead(MibuttonPin) == HIGH && e == 0)
  {
    digitalWrite(MiledPin, HIGH);
    noteOn(0x90, 64, 120);
    e = 1;
    aa = MiledPin;
  }
  pian if (digitalRead(MibuttonPin) == LOW && e == 1)
  {
    digitalWrite(MiledPin, LOW);
    noteOn(0x90, 64, 0);
    e = 0;
  }
  //Fa
  if (digitalRead(FabuttonPin) == HIGH && f == 0)
  {
    digitalWrite(FaledPin, HIGH);
    noteOn(0x90, 65, 120);
    f = 1;
    aa = FaledPin;
  }
  if (digitalRead(FabuttonPin) == LOW && f == 1)
  {
    digitalWrite(FaledPin, LOW);
    noteOn(0x90, 65, 0);
    f = 0;
  }
  //Fas
  if (digitalRead(FaSbuttonPin) == HIGH && g == 0)
  {
    digitalWrite(FaSledPin, HIGH);
    noteOn(0x90, 66, 120);
    g = 1;
    aa = FaSledPin;
  }
  if (digitalRead(FaSbuttonPin) == LOW && g == 1)
  {
    digitalWrite(FaSledPin, LOW);
    noteOn(0x90, 66, 0);
    g = 0;
  }
  //sol
  if (digitalRead(SolbuttonPin) == HIGH && h == 0)
  {
    digitalWrite(SolledPin, HIGH);
    noteOn(0x90, 67, 120);
    h = 1;
    aa = SolledPin;
  }
  if (digitalRead(SolbuttonPin) == LOW && h == 1)
  {
    digitalWrite(SolledPin, LOW);
    noteOn(0x90, 67, 0);
    h = 0;
  }
  //SolS
  if (digitalRead(SolSbuttonPin) == HIGH && i == 0)
  {
    digitalWrite(SolSledPin, HIGH);
    noteOn(0x90, 68, 120);
    i = 1;
    aa = SolSledPin;
  }
  if (digitalRead(SolSbuttonPin) == LOW && i == 1)
  {
    digitalWrite(SolSledPin, LOW);
    noteOn(0x90, 68, 0);
    i = 0;
  }
  //La
  if (digitalRead(LabuttonPin) == HIGH && j == 0)
  {
    digitalWrite(LaledPin, HIGH);
    noteOn(0x90, 69, 120);
    j = 1;
    aa = LaledPin;
  }
  if (digitalRead(LabuttonPin) == LOW && j == 1)
  {
    digitalWrite(LaledPin, LOW);
    noteOn(0x90, 69, 0);
    j = 0;
  }
  //LaS
  if (digitalRead(LaSbuttonPin) == HIGH && k == 0)
  {
    digitalWrite(LaSledPin, HIGH);
    noteOn(0x90, 70, 120);
    k = 1;
    aa = LaSledPin;
  }
  if (digitalRead(LaSbuttonPin) == LOW && k == 1)
  {
    digitalWrite(LaSledPin, LOW);
    noteOn(0x90, 70, 0);
    k = 0;
  }
  //Si
  if (digitalRead(SibuttonPin) == HIGH && l == 0)
  {
    digitalWrite(SiledPin, HIGH);
    noteOn(0x90, 71, 120);
    l = 1;
    aa = SiledPin;
  }
  if (digitalRead(SibuttonPin) == LOW && l == 1)
  {
    digitalWrite(SiledPin, LOW);
    noteOn(0x90, 71, 0);
    l = 0;
  }
  //Do5
  if (digitalRead(Do5buttonPin) == HIGH && m == 0)
  {
    digitalWrite(Do5ledPin, HIGH);
    noteOn(0x90, 72, 120);
    m = 1;
    aa = Do5ledPin;
  }
  if (digitalRead(Do5buttonPin) == LOW && m == 1)
  {
    digitalWrite(Do5ledPin, LOW);
    noteOn(0x90, 72, 0);
    m = 0;
  }
  //Do5S
  if (digitalRead(Do5SbuttonPin) == HIGH && n == 0)
  {
    digitalWrite(Do5SledPin, HIGH);
    noteOn(0x90, 73, 120);
    n = 1;
    aa = Do5SledPin;
  }
  if (digitalRead(Do5SbuttonPin) == LOW && n == 1)
  {
    digitalWrite(Do5SledPin, LOW);
    noteOn(0x90, 73, 0);
    n = 0;
  }
  //Re5
  if (digitalRead(Re5buttonPin) == HIGH && o == 0)
  {
    digitalWrite(Re5ledPin, HIGH);
    noteOn(0x90, 74, 120);
    o = 1;
    aa = Re5ledPin;
  }
  if (digitalRead(Re5buttonPin) == LOW && o == 1)
  {
    digitalWrite(Re5ledPin, LOW);
    noteOn(0x90, 74, 0);
    o = 0;
  }
}
void noteOn(int cmd, int pitch, int velocity)
{
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}
