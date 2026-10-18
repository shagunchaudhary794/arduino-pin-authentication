
const byte rowPins[4] = {2, 3, 4, 5};
const byte colPins[4] = {6, 7, 8, 9};

const byte GREEN_LED = 10;
const byte RED_LED = 11;

const char keys[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

const char correctPIN[] = "2580";
char enteredPIN[5] = "";
byte pinLength = 0;
byte failedAttempts = 0;

bool lockedOut = false;
unsigned long lockoutStart = 0;
const unsigned long LOCKOUT_MS = 10000;

char scanKeypad() {
  for (byte r = 0; r < 4; r++) {
    digitalWrite(rowPins[r], LOW);
    delayMicroseconds(5);

    for (byte c = 0; c < 4; c++) {
      if (digitalRead(colPins[c]) == LOW) {
        digitalWrite(rowPins[r], HIGH);
        return keys[r][c];
      }
    }

    digitalWrite(rowPins[r], HIGH);
  }

  return '\0';
}

void clearPIN() {
  pinLength = 0;
  enteredPIN[0] = '\0';
}

void setup() {
  Serial.begin(9600);

  for (byte r = 0; r < 4; r++) {
    pinMode(rowPins[r], OUTPUT);
    digitalWrite(rowPins[r], HIGH);
  }

  for (byte c = 0; c < 4; c++) {
    pinMode(colPins[c], INPUT_PULLUP);
  }

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);

  Serial.println("AUTHENTICATION SYSTEM ONLINE");
  Serial.println("Enter PIN, then press #.");
  Serial.println("Press * to clear.");
}

void loop() {
  if (lockedOut) {
    digitalWrite(RED_LED, HIGH);

    if (millis() - lockoutStart >= LOCKOUT_MS) {
      lockedOut = false;
      failedAttempts = 0;
      digitalWrite(RED_LED, LOW);
      Serial.println("Lockout ended. Try again.");
    }
    return;
  }

  char key = scanKeypad();

  if (key == '\0') {
    return;
  }

  // Wait until the key is released.
  while (scanKeypad() != '\0') {
    delay(10);
  }
  delay(30);

  if (key == '*') {
    clearPIN();
    Serial.println("PIN cleared.");
    return;
  }

  if (key == '#') {
    if (pinLength == 0) {
      Serial.println("Enter a PIN first.");
      return;
    }

    enteredPIN[pinLength] = '\0';

    if (strcmp(enteredPIN, correctPIN) == 0) {
      Serial.println("ACCESS GRANTED");
      digitalWrite(GREEN_LED, HIGH);
      digitalWrite(RED_LED, LOW);
      failedAttempts = 0;
      delay(2000);
      digitalWrite(GREEN_LED, LOW);
    } else {
      Serial.println("ACCESS DENIED");
      digitalWrite(RED_LED, HIGH);
      digitalWrite(GREEN_LED, LOW);
      failedAttempts++;
      delay(500);
      digitalWrite(RED_LED, LOW);

      Serial.print("Failed attempts: ");
      Serial.println(failedAttempts);

      if (failedAttempts >= 3) {
        lockedOut = true;
        lockoutStart = millis();
        Serial.println("LOCKOUT: 10 seconds");
      }
    }

    clearPIN();
    return;
  }

  if (key >= '0' && key <= '9') {
    if (pinLength < 4) {
      enteredPIN[pinLength++] = key;
      Serial.print("*");
    } else {
      Serial.println("\nPIN full. Press # or *.");
    }
  }
}
