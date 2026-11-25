# Smart Moisture Detection System for Smart Irrigation

An Arduino Uno-based prototype designed to support automated irrigation and efficient water management. The system combines an LDR-based sensing arrangement, rain sensor, crop-selection push buttons, 16x2 I2C LCD, relay module, buzzer and a 5V water pump.

## Main Features
- Monitors inputs from the sensing arrangement and rain sensor.
- Allows selection of crop categories using push buttons.
- Displays system information and irrigation status on an LCD.
- Uses a relay to switch the water pump according to programmed conditions.
- Includes a buzzer for system alerts.
- Designed as a low-cost educational smart-irrigation prototype.

## Hardware Components
- Arduino Uno
- LDR (light-dependent resistor) sensing arrangement
- Rain sensor module
- 5V DC water pump
- Relay module
- 16x2 LCD with I2C interface
- Buzzer
- Push buttons
- Voltage converter / regulated power supply
- Breadboard and jumper wires

## Software
- Arduino IDE
- Embedded C/C++
- LiquidCrystal_I2C library (if used by the final sketch)

## Project Status
Hardware assembly, firmware integration and system integration have been completed. The prototype is in testing and evaluation. Numerical performance results should be added after measurements are collected.

## Important Sensor Note
A standard LDR measures light intensity; it does not directly measure soil moisture. If the prototype uses an LDR in a custom arrangement, describe and calibrate that arrangement accurately. For direct soil-moisture measurement, use a dedicated capacitive or resistive soil-moisture sensor.

## Safety and Wiring
Do not power the pump directly from an Arduino I/O pin. Use a suitably rated external supply and relay/driver arrangement. Check the voltage and current ratings of the pump, relay and converter, and follow the actual circuit wiring. Any pin assignments in planning documents are examples and must be checked against the assembled hardware.

## Repository Contents
- `README.md` — project overview and setup notes
- `docs/PROJECT_DOCUMENTATION.md` — project report summary and methodology
- `docs/COMPONENTS_AND_CONNECTIONS.md` — component list and example pin plan
- `docs/TESTING_AND_OBSERVATIONS.md` — experimental procedure and observation template
- `firmware/` — add the final, tested Arduino `.ino` sketch here
- `images/` — add actual circuit, prototype and PCB images here

## How to Use
1. Review the documentation in the `docs/` folder.
2. Add the final Arduino sketch to the `firmware/` folder.
3. Verify all pin assignments against the physical circuit before uploading.
4. Test sensor readings, crop selection, rain detection, relay switching and pump operation.
5. Record actual readings and results in the testing document.

## Future Improvements
Possible upgrades include a dedicated soil-moisture sensor, IoT remote monitoring, data logging, solar power, water-level sensing and multiple irrigation zones.
