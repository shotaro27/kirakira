#include <TimerOne.h>
#include <TimerThree.h>
#define latchPina 4
#define clockPina 5
#define dataPina 3
#define latchPink 7
#define clockPink 8
#define dataPink 6
#define SWA A0
#define SWB A1
#define SWC A2
#define SWD A3
#define SWE A5
#define LEDI 10
#define LEDJ 11
#define LEDK 12
#define ILA 22
#define ILB 23
#define ILC 24
#define ILD 25
#define ILE 26
#define TEMPO 250
#define LENGTH 209
#define LENGTH2 113
#define LENGTH3 145
#define REST 9
#define DATA 13
byte oto[] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 0, 0, 0, 1, 0, 0, 0, 5, 0, 0, 0, 5, 0, 0, 0, 6, 0, 0, 0, 6, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0,
  4, 0, 0, 0, 4, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
  5, 0, 0, 0, 5, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0,
  5, 0, 0, 0, 5, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0,
  1, 0, 0, 0, 1, 0, 0, 0, 5, 0, 0, 0, 5, 0, 0, 0, 6, 0, 0, 0, 6, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0,
  4, 0, 0, 0, 4, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0
},
oto2[] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  5, 0, 0, 0, 4, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 3, 0, 4, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0,
  3, 0, 4, 0, 5, 0, 3, 0, 2, 0, 3, 0, 4, 0, 2, 0, 3, 0, 4, 0, 5, 0, 3, 0, 2, 0, 3, 0, 4, 0, 2, 0,
  5, 0, 0, 0, 4, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 3, 0, 4, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0
},
oto3[] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  1, 0, 0, 0, 2, 0, 0, 0, 3, 0, 0, 0, 4, 0, 0, 0, 3, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
  3, 0, 0, 0, 4, 0, 0, 0, 5, 0, 0, 0, 6, 0, 0, 0, 5, 0, 0, 0, 4, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0,
  1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
  1, 0, 1, 0, 2, 0, 2, 0, 3, 0, 3, 0, 4, 0, 4, 0, 3, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0
},
hosi[][8] = {
  {
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000
  },
  {
    0b00000000,
    0b00000000,
    0b00000000,
    0b11000000,
    0b11000000,
    0b00000000,
    0b00000000,
    0b00000000
  },
  {
    0b00000000,
    0b00000000,
    0b11000000,
    0b00100000,
    0b00100000,
    0b11000000,
    0b00000000,
    0b00000000
  },
  {
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000
  },
  {
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b11100000,
    0b11100000,
    0b00000000
  },
  {
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b01100000,
    0b00010000,
    0b00010000,
    0b01100000
  },
  {
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000
  },
  {
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00111000,
    0b00111000,
    0b00000000
  },
  {
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00110000,
    0b01000000,
    0b01000000,
    0b00110000
  },
  {
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000
  },
  {
    0b00000000,
    0b00000000,
    0b00000000,
    0b00011000,
    0b00011000,
    0b00000000,
    0b00000000,
    0b00000000
  },
  {
    0b00000000,
    0b00000000,
    0b00011000,
    0b00100000,
    0b00100000,
    0b00011000,
    0b00000000,
    0b00000000
  },
  {
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000
  },
  {
    0b00000000,
    0b01110000,
    0b01110000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000
  },
  {
    0b01110000,
    0b10001000,
    0b10001000,
    0b01110000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000
  },
  {
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000
  }
},
stoto[] = {1, 3, 5, 8, 5, 3, 1, 3, 5, 8, 5, 3, 1, 3, 5, 8},
datas[209],
kiralevel[3][8] = {
  {
    0b00000000,
    0b00000000,
    0b00000000,
    0b00001000,
    0b00011000,
    0b00111000,
    0b01111000,
    0b11111000
  },
  {
    0b00001000,
    0b00011000,
    0b00011000,
    0b00111000,
    0b01111000,
    0b11111000,
    0b11111000,
    0b11111000
  },
  {
    0b00000000,
    0b00001000,
    0b00011000,
    0b00011000,
    0b00111000,
    0b01111000,
    0b11111000,
    0b11111000
  }
};
static volatile int index;
static volatile bool spk, gameclear;
static volatile uint8_t n;
int velocity;
bool ook = true, okk = false;
int x = 0;
static volatile int kyoku = 0;
void setup() {
  pinMode(SWA, INPUT_PULLUP);
  pinMode(SWB, INPUT_PULLUP);
  pinMode(SWC, INPUT_PULLUP);
  pinMode(SWD, INPUT_PULLUP);
  pinMode(SWE, INPUT_PULLUP);
  pinMode(REST, OUTPUT);
  pinMode(DATA, OUTPUT);
  pinMode(latchPina, OUTPUT);
  pinMode(clockPina, OUTPUT);
  pinMode(dataPina, OUTPUT);
  pinMode(latchPink, OUTPUT);
  pinMode(clockPink, OUTPUT);
  pinMode(dataPink, OUTPUT);
  pinMode(LEDI, OUTPUT);
  pinMode(LEDJ, OUTPUT);
  pinMode(LEDK, OUTPUT);
  pinMode(ILA, OUTPUT);
  pinMode(ILB, OUTPUT);
  pinMode(ILC, OUTPUT);
  pinMode(ILD, OUTPUT);
  pinMode(ILE, OUTPUT);
  initStart(1);
}
void loop() {
  byte i, j;
  bool over;
  for (i = 0; i < 8; i++) {
    digitalWrite(latchPink, LOW);
    shiftOut(dataPink, clockPink, MSBFIRST, B11111111);
    digitalWrite(latchPink, HIGH);
    digitalWrite(latchPina, LOW);
    shiftOut(dataPina, clockPina, LSBFIRST, datas[index + i]);
    digitalWrite(latchPina, HIGH);
    digitalWrite(latchPink, LOW);
    shiftOut(dataPink, clockPink, MSBFIRST, ~(1 << (8 - i - 1)));
    digitalWrite(latchPink, HIGH);
  }
  delay(1);
  switch (kyoku) {
    case 1:
      if (oto[index] != 0) {
        byte switchdata = (!digitalRead(SWA) << 7) | (!digitalRead(SWB) << 6) | (!digitalRead(SWC) << 5) | (!digitalRead(SWD) << 4) | (!digitalRead(SWE) << 3);
        if (switchdata == datas[index] && switchdata > 0) {
          spk = true;
        }
      }
      break;
    case 2:
      if (oto2[index] != 0) {
        byte switchdata = (!digitalRead(SWA) << 7) | (!digitalRead(SWB) << 6) | (!digitalRead(SWC) << 5) | (!digitalRead(SWD) << 4) | (!digitalRead(SWE) << 3);
        if (switchdata == datas[index] && switchdata > 0) {
          spk = true;
        }
      }
      break;
    case 3:
      if (oto3[index] != 0) {
        byte switchdata = (!digitalRead(SWA) << 7) | (!digitalRead(SWB) << 6) | (!digitalRead(SWC) << 5) | (!digitalRead(SWD) << 4) | (!digitalRead(SWE) << 3);
        if (switchdata == datas[index] && switchdata > 0) {
          spk = true;
        }
      }
      break;
  }
  digitalWrite(LEDK, (n > 0) ? HIGH : LOW);
  digitalWrite(LEDJ, (n > 1) ? HIGH : LOW);
  digitalWrite(LEDI, (n > 2) ? HIGH : LOW);
  if (n == 0) {
    initStart(3);
  }
  if (gameclear) {
    initStart(2);
  }
}
void onTimerFlashed() {
  switch (kyoku) {
    case 1:
      if (spk) {
        sound(oto[index]);
      } else if (oto[index] != 0 && n > 0) {
        n--;
      }
      spk = false;
      gameclear = (++index >= LENGTH - 8) ? true : false;
      break;
    case 2:
      if (spk) {
        sound(oto2[index]);
      } else if (oto2[index] != 0 && n > 0) {
        n--;
      }
      spk = false;
      gameclear = (++index >= LENGTH2 - 8) ? true : false;
      break;
    case 3:
      if (spk) {
        sound(oto3[index]);
      } else if (oto3[index] != 0 && n > 0) {
        n--;
      }
      spk = false;
      gameclear = (++index >= LENGTH3 - 8) ? true : false;
      break;    
  }
}
void kirikae() {
  x++;
  if (x > 15) {
    x = 0;
    ook = false;
  }
  if (ook){
    sound(stoto[x]);
  }
}
void hyoji() {
  digitalWrite(22 + x / 3, HIGH);
}
void initStart(int initpettern) {
  Timer1.detachInterrupt();
  index = 0;
  spk = false;
  digitalWrite(latchPink, LOW);
  shiftOut(dataPink, clockPink, LSBFIRST, B11111111);
  digitalWrite(latchPink, HIGH);
  digitalWrite(latchPina, LOW);
  shiftOut(dataPina, clockPina, LSBFIRST, B00000000);
  digitalWrite(latchPina, HIGH);
  for (int i = 0; i < 209; i++) {
    datas[i] = 0;
  }
  switch (initpettern) {
    case 1:
      sound(1);
      delay(TEMPO);
      sound(3);
      delay(TEMPO);
      sound(5);
      delay(TEMPO);
      sound(8);
      delay(TEMPO);
      break;
    case 2:
      sound(8);
      delay(TEMPO);
      sound(5);
      delay(TEMPO);
      sound(3);
      delay(TEMPO);
      sound(1);
      delay(TEMPO);
      for (int i = 0; i < 8; i++) {
        digitalWrite(latchPink, LOW);
        shiftOut(dataPink, clockPink, MSBFIRST, B11111111);
        digitalWrite(latchPink, HIGH);
        digitalWrite(latchPina, LOW);
        shiftOut(dataPina, clockPina, LSBFIRST, B11111000);
        digitalWrite(latchPina, HIGH);
        digitalWrite(latchPink, LOW);
        shiftOut(dataPink, clockPink, MSBFIRST, ~(1 << (8 - i - 1)));
        digitalWrite(latchPink, HIGH);
        delay(60);
      }
      if (n == 3) {
        Timer1.initialize(200000);
        Timer1.attachInterrupt(kirikae);
        Timer3.initialize(600000);
        Timer3.attachInterrupt(hyoji);
        while (digitalRead(SWA) && digitalRead(SWB) && digitalRead(SWC) && digitalRead(SWD) && digitalRead(SWE)) {
          for (int i = 0; i < 8; i++) {
            digitalWrite(latchPink, LOW);
            shiftOut(dataPink, clockPink, MSBFIRST, B11111111);
            digitalWrite(latchPink, HIGH);
            digitalWrite(latchPina, LOW);
            shiftOut(dataPina, clockPina, LSBFIRST, hosi[x][i]);
            digitalWrite(latchPina, HIGH);
            digitalWrite(latchPink, LOW);
            shiftOut(dataPink, clockPink, LSBFIRST, ~(1 << (8 - i - 1)));
            digitalWrite(latchPink, HIGH);
          }
        }
        while (!(digitalRead(SWA) && digitalRead(SWB) && digitalRead(SWC) && digitalRead(SWD) && digitalRead(SWE))) {}
        Timer1.detachInterrupt();
        Timer3.detachInterrupt();
      }
      ook = true;
      x = 0;
      break;
    case 3:
      sound(13);
      delay(TEMPO * 2);
      sound(13);
      delay(TEMPO * 3);
      break;
  }
  n = 3;
  digitalWrite(ILA, LOW);
  digitalWrite(ILB, LOW);
  digitalWrite(ILC, LOW);
  digitalWrite(ILD, LOW);
  digitalWrite(ILE, LOW);
  digitalWrite(latchPink, LOW);
  shiftOut(dataPink, clockPink, LSBFIRST, B11111110);
  digitalWrite(latchPink, HIGH);
  digitalWrite(latchPina, LOW);
  shiftOut(dataPina, clockPina, LSBFIRST, B11111111);
  digitalWrite(latchPina, HIGH);
  digitalWrite(LEDI, HIGH);
  digitalWrite(LEDJ, HIGH);
  digitalWrite(LEDK, HIGH);
  delay(100);
  while (1) {
    while (digitalRead(SWA) && digitalRead(SWB) && digitalRead(SWC) && digitalRead(SWE)) {}
    if (!digitalRead(SWA)) {
      kyoku = 1;
      okk = true;
      digitalWrite(latchPina, LOW);
      shiftOut(dataPina, clockPina, LSBFIRST, B10000000);
      digitalWrite(latchPina, HIGH);
      sound(1);
      delay(TEMPO);
      sound(1);
      delay(TEMPO);
      sound(5);
      delay(TEMPO);
      sound(5);
      delay(TEMPO);
      sound(6);
      delay(TEMPO);
      sound(6);
      delay(TEMPO);
      sound(5);
    }
    if (!digitalRead(SWB)) {
      kyoku = 2;
      okk = true;
      digitalWrite(latchPina, LOW);
      shiftOut(dataPina, clockPina, LSBFIRST, B01000000);
      digitalWrite(latchPina, HIGH);
      sound(5);
      delay(TEMPO);
      sound(4);
      delay(TEMPO);
      sound(3);
      delay(TEMPO * 2);
      sound(2);
      delay(TEMPO / 2);
      sound(3);
      delay(TEMPO / 2);
      sound(4);
      delay(TEMPO / 2);
      sound(2);
      delay(TEMPO / 2);
      sound(1);
    }
    if (!digitalRead(SWC)) {
      kyoku = 3;
      okk = true;
      digitalWrite(latchPina, LOW);
      shiftOut(dataPina, clockPina, LSBFIRST, B00100000);
      digitalWrite(latchPina, HIGH);
      sound(1);
      delay(TEMPO);
      sound(2);
      delay(TEMPO);
      sound(3);
      delay(TEMPO);
      sound(4);
      delay(TEMPO);
      sound(3);
      delay(TEMPO);
      sound(2);
      delay(TEMPO);
      sound(1);
    }
    if (!digitalRead(SWE) && okk) {
      okk = false;
      while (!digitalRead(SWE)) {}
      goto okkyoku;
    }
  }
  okkyoku:
  delay(100);
  while (!(digitalRead(SWA) && digitalRead(SWB) && digitalRead(SWC) && digitalRead(SWD) && digitalRead(SWE))) {}
  while (digitalRead(SWA) && digitalRead(SWB) && digitalRead(SWC) && digitalRead(SWD) && digitalRead(SWE)) {
    for (int i = 0; i < 8; i++) {
      digitalWrite(latchPink, LOW);
      shiftOut(dataPink, clockPink, MSBFIRST, B11111111);
      digitalWrite(latchPink, HIGH);
      digitalWrite(latchPina, LOW);
      shiftOut(dataPina, clockPina, LSBFIRST, kiralevel[kyoku - 1][i]);
      digitalWrite(latchPina, HIGH);
      digitalWrite(latchPink, LOW);
      shiftOut(dataPink, clockPink, LSBFIRST, ~(1 << (8 - i - 1)));
      digitalWrite(latchPink, HIGH);
    }
  }
  if (!digitalRead(SWA)) {
    digitalWrite(latchPina, LOW);
    shiftOut(dataPina, clockPina, LSBFIRST, B10000000);
    digitalWrite(latchPina, HIGH);
    Timer1.initialize(200000);
  }
  if (!digitalRead(SWB)) {
    digitalWrite(latchPina, LOW);
    shiftOut(dataPina, clockPina, LSBFIRST, B01000000);
    digitalWrite(latchPina, HIGH);
    Timer1.initialize(180000);
  }
  if (!digitalRead(SWC)) {
    digitalWrite(latchPina, LOW);
    shiftOut(dataPina, clockPina, LSBFIRST, B00100000);
    digitalWrite(latchPina, HIGH);
    Timer1.initialize(150000);
  }
  if (!digitalRead(SWD)) {
    digitalWrite(latchPina, LOW);
    shiftOut(dataPina, clockPina, LSBFIRST, B00010000);
    digitalWrite(latchPina, HIGH);
    Timer1.initialize(120000);
  }
  if (!digitalRead(SWE)) {
    digitalWrite(latchPina, LOW);
    shiftOut(dataPina, clockPina, LSBFIRST, B00001000);
    digitalWrite(latchPina, HIGH);
    Timer1.initialize(100000);
  }
  delay(2000);
  switch (kyoku) {
    case 1:
      for (int j = 0; j <= LENGTH - 1; j++) {
        if (oto[j] != 0) {
          datas[j] = bit(random(3, 8));
        }
      }
      break;
    case 2:
      for (int j = 0; j <= LENGTH2 - 1; j++) {
        if (oto2[j] != 0) {
          datas[j] = bit(random(3, 8));
        }
      }
      break;
    case 3:
      for (int j = 0; j <= LENGTH3 - 1; j++) {
        if (oto3[j] != 0) {
          datas[j] = bit(random(3, 8));
        }
      }
      break;
  }
  Timer1.attachInterrupt(onTimerFlashed);
}

void sound(int n) {
  int i;
  digitalWrite(REST, HIGH);
  delay(2);
  digitalWrite(REST, LOW);
  delay(2);
  for (i = 0; i < n; i++) {
    digitalWrite(DATA, HIGH);
    delay(1);
    digitalWrite(DATA, LOW);
    delay(1);
  }
}
