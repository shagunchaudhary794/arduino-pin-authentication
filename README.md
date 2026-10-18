# Arduino PIN Authentication & Access Control

A simulated embedded cybersecurity project implementing PIN-based authentication using an Arduino Uno R3, a 4×4 matrix keypad, and LED indicators.

## Overview

This project demonstrates how an embedded system can validate user input, grant or deny access, and temporarily restrict repeated failed authentication attempts.

**Platform:** Tinkercad Circuits  
**Microcontroller:** Arduino Uno R3 (ATmega328P)  
**Language:** Arduino C/C++  
**Interface:** 4×4 matrix keypad  
**Output:** Red and green LEDs  
**Serial communication:** 9600 baud

## Features

- PIN-based access verification
- Matrix keypad scanning without an external keypad library
- Green LED for successful authentication
- Red LED for denied authentication
- Temporary lockout after three failed attempts
- Serial Monitor authentication logs
- Documented security limitations and testing scenarios

## Circuit Connections

| Component | Arduino pin |
|---|---|
| Keypad R1–R4 | D2–D5 |
| Keypad C1–C4 | D6–D9 |
| Green LED | D10 |
| Red LED | D11 |

Each LED is connected in series with a 220 Ω resistor. The LED cathodes connect to GND.

The keypad column pins use the Arduino's internal pull-up resistors.

## How It Works

1. The system initializes the keypad interface, LEDs, and Serial Monitor.
2. The user enters a PIN using the keypad.
3. Pressing `#` submits the PIN.
4. Pressing `*` clears the current input.
5. The firmware compares the entered PIN with the configured demonstration credential.
6. Successful authentication activates the green LED.
7. Failed authentication activates the red LED briefly.
8. Three failed submissions trigger a ten-second software lockout.

## Running the Project

1. Open the circuit in Tinkercad Circuits.
2. Open the Arduino code editor in Text mode.
3. Load `firmware/pin_authentication.ino`.
4. Start the simulation.
5. Open the Serial Monitor at 9600 baud.
6. Test successful authentication, incorrect PINs, input clearing, and lockout behavior.

## Security Analysis

This is an educational prototype, not a production-ready authentication system.

Known limitations include:

- The demonstration PIN is hardcoded in firmware.
- The lockout state is held in volatile memory and may be cleared by a reset.
- The design does not implement cryptographic authentication.
- Serial logs are not persistent or tamper-resistant.
- Physical hardware attacks have not been evaluated.

Future improvements include secure credential management, persistent failure tracking, cryptographic challenge-response authentication, and controlled firmware security testing.

## Testing

The test plan covers successful authentication, incorrect credentials, input clearing, and the three-attempt lockout.

Test results should be recorded from actual simulator runs. The project is currently a simulated implementation; physical hardware validation has not been established.

## Scope

This project is intended for learning embedded programming, access-control logic, and cybersecurity fundamentals in a controlled environment.

