int lightSensor = A0;

int redPin = 100;
int greenPin = 100;
int bluePin = 100;

int buzzer = 8;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void rainbowLight() {

  analogWrite(redPin, 255);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
  delay(200);

  analogWrite(redPin, 0);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 0);
  delay(200);

  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 255);
  delay(200);
}

void loop() {

  int lightValue = analogRead(lightSensor);

  if (lightValue < 300) {

    tone(buzzer, 523);
    rainbowLight();

  } else {

    noTone(buzzer);

    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
  }
}
