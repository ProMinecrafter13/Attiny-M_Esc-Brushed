/* 
PA1 - FS2A throttle rx
PA3 - 100ohm - SL3416 gate

*/
const byte R = PIN_PA6;      // PA1
const byte M = PIN_PA3;   // PA3 (PWM)
const byte L = PIN_PA1;

void setup() {
  pinMode(R, INPUT);
  pinMode(M, OUTPUT);
  pinMode(L, OUTPUT);
  digitalWrite(L, HIGH);
  delay(1000);
  digitalWrite(L,LOW);
}

void loop() {
  unsigned long pulse = pulseIn(R, HIGH, 30000);

  if (pulse < 1000 || pulse > 2000) {
    analogWrite(M, 0);
    return;
  }

  int pwm = map(pulse, 1000, 2000, 0, 255);
  analogWrite(M, pwm);
  analogWrite(L, pwm);
}
