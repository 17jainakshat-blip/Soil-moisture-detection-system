# Smart Moisture Detection System for Smart Irrigation

An Arduino Uno-based prototype designed to automate irrigation using soil-moisture, rain and water-availability inputs, with crop-group selection and LCD status display.

## Main Features
- Reads soil-moisture, rain, light and water-level sensor inputs.
- Offers five crop groups selected with NEXT and PREVIOUS push buttons.
- Applies crop-group-specific pump ON and OFF moisture thresholds.
- Stops the pump when rain is detected or the water supply is unavailable.
- Displays crop group, moisture percentage, rain status, light reading and water status on a 16x2 I2C LCD.
- Uses a relay module to control the DC water pump and a buzzer to acknowledge button presses.
- Sends sensor and pump status to the Serial Monitor.

## Hardware Components
- Arduino Uno
- Soil-moisture sensor connected to A0
- Rain sensor module connected to A1
- LDR/light sensor connected to A2
- Water-level sensor connected to A3
- NEXT and PREVIOUS push buttons on D2 and D3
- Buzzer on D4
- Relay module on D8
- 16x2 I2C LCD (address configured as 0x27)
- DC water pump and suitable external power supply
- Breadboard, jumper wires and regulated power components

## Software
- Arduino IDE
- Arduino C/C++
- Wire library
- LiquidCrystal_I2C library

## Firmware
The main Arduino sketch is located at `firmware/Smart_Irrigation_System.ino`.

Before uploading, verify the pin assignments, LCD I2C address, relay trigger polarity and sensor output polarity against the actual hardware. Calibrate `SOIL_DRY`, `SOIL_WET`, `RAIN_THRESHOLD` and `WATER_MINIMUM` using measured readings from the installed sensors.

## Project Status
The hardware prototype and firmware integration have been completed and the system is in testing/evaluation. Add measured observations and performance results only after testing.

## Safety
Never power the pump from an Arduino I/O pin. Use a separate, suitably rated pump supply and a relay/driver rated for the pump's voltage and current. Confirm safe wiring and grounding before operation.

## Repository Structure
- `README.md` — project overview and setup notes
- `firmware/` — Arduino source code
- `docs/` — project report, component details and testing records
- `images/` — circuit, PCB and prototype photographs

## Future Improvements
Potential extensions include IoT monitoring, data logging, solar power, improved sensor calibration and multiple irrigation zones.
