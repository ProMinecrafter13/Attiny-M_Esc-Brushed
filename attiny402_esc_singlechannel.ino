/* 
Unichannel Brushed Esc by Param
I have used an attiny402 here. Similar chips such as attiny412, 202, 212, etc can be used.
Just go over their pinouts and change the pin taken accordingly.

PA1 - 1kohm - LED
PA6 - Rx input
PA3 - 100ohm - Mosfet gate
Mosfet gate - 10kohm - Mosfet source - Ground  (I have used SL3416, si2300, si2302 N channel mosfets)
Flyback Diode across motor terminals is necessary (SS24, SS34 or similar being very fast at switching)

*/
const byte R = PIN_PA6;      
const byte M = PIN_PA3;   
const byte L = PIN_PA1; // Only incorporated this as an indicator for whether attiny is correctly receiving the input.

void setup() {
  pinMode(R, INPUT);
  pinMode(M, OUTPUT);
  pinMode(L, OUTPUT);
  digitalWrite(L, HIGH);
  delay(1000);         // If this LED sequence doesnt occur,
  digitalWrite(L,LOW); // then there is something wrong with the power supply.
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
