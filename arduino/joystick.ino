void setup() {
  Serial.begin(115200);
}

int throttle_val;
int break_val;
int axis_val;

void loop() {
  break_val = analogRead(0);
  throttle_val = analogRead(1);
  axis_val = map(throttle_val - break_val, -1023, 1023, 0, 1023);
  Serial.print("break = ");
  Serial.print(break_val, DEC);
  Serial.print(" throt = ");
  Serial.print(throttle_val, DEC);
  Serial.print(" axis  = ");
  Serial.println(axis_val, DEC);
  Joystick.Y(axis_val);
  delay(50);
}
