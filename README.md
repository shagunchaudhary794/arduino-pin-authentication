# Arduino PIN Authentication System

My first circuit simulation project exploring the intersection of embedded systems and cybersecurity.

## About the Project

This project is a simple PIN-based authentication and access-control system built using an Arduino Uno R3 and simulated in Tinkercad Circuits.

The system uses a 4×4 matrix keypad to accept a PIN, verifies the entered value through Arduino firmware, and uses red and green LEDs to indicate whether access is denied or granted.

This is my first circuit simulation project, and I'm using it as an opportunity to explore hardware, embedded programming, and basic cybersecurity concepts.

## Features

- PIN-based authentication
- 4×4 matrix keypad input
- Red and green LED status indicators
- Temporary lockout after three failed attempts
- Serial Monitor output for authentication events

## Components Used

- Arduino Uno R3
- 4×4 matrix keypad
- Red LED
- Green LED
- 220 Ω resistors
- Breadboard and jumper wires

## Project Files

- **Project Report:** Overview, implementation, testing, and security analysis.
- **Arduino Firmware:** Source code for the authentication system.
- **Circuit Schematic:** Diagram showing the circuit connections.
- **3D Circuit View:** Visual representation of the simulated circuit.

## What I'm Learning

Through this project, I'm exploring:

- Arduino programming with C/C++
- Microcontroller input and output
- Keypad interfacing and matrix scanning
- Authentication and access-control logic
- Basic security testing and software limitations

## Room for Improvement

This is a beginner project, and there is plenty of room to improve it.

Possible future enhancements include:

- Stronger authentication mechanisms
- Better handling of repeated failed attempts
- Secure credential management
- Persistent authentication logs
- Additional hardware security experiments

Suggestions, constructive feedback, and improvements are welcome. If you find a way to make this project more efficient, reliable, or secure, feel free to explore and build upon it.

## Disclaimer

This is an educational simulation, not a production-ready security system. The demonstration PIN is hardcoded in the firmware, and the lockout mechanism is implemented in software. The project has not been validated against physical hardware attacks.

## A Note

This is my first step into circuit simulation and hardware-oriented cybersecurity. I'm sharing the project as part of my learning journey, and I hope to improve it as I learn more.

**Built to learn. Shared to improve.**
