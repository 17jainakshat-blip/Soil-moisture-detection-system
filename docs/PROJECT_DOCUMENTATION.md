# Project Documentation

## 1. Abstract
The Smart Moisture Detection System for Smart Irrigation is an Arduino Uno-based prototype intended to automate selected irrigation operations. It combines an LDR-based sensing arrangement and rain sensor with crop-selection buttons, an LCD, relay, buzzer and water pump. The controller processes inputs according to programmed conditions and indicates system status on the display.

## 2. Problem Statement
Manual irrigation and fixed watering schedules may lead to unnecessary water use and require regular human intervention. A low-cost automated prototype can demonstrate how sensor inputs and microcontroller logic can assist irrigation decisions.

## 3. Objectives
- Develop an Arduino-based irrigation control prototype.
- Read environmental sensor inputs.
- Provide crop-category selection using push buttons.
- Display operating information on a 16x2 I2C LCD.
- Control a water pump through a relay.
- Use rain detection as an input to the irrigation decision.

## 4. Proposed System
The sensors and push buttons provide inputs to the Arduino Uno. The firmware evaluates these inputs and controls the LCD, buzzer and relay-driven pump. When the programmed conditions call for irrigation and rain is not detected, the relay can activate the pump. The exact logic and thresholds must match the final uploaded sketch.

## 5. Hardware and Software
Hardware includes Arduino Uno, LDR-based sensing arrangement, rain sensor, 5V pump, relay module, 16x2 I2C LCD, buzzer, push buttons, voltage converter, power supply, breadboard and jumper wires. Software development uses Arduino IDE and Embedded C/C++.

## 6. Working Principle
1. Initialize the Arduino, display and input/output pins.
2. Read the sensor inputs and button selections.
3. Apply the selected crop category's programmed settings.
4. Check the rain-sensor condition.
5. Operate or stop the relay and pump according to the programmed decision.
6. Update the LCD and buzzer as required.
7. Repeat the monitoring cycle.

## 7. Integration and Experimental Setup
The components are assembled and connected to the Arduino according to the physical circuit. The LCD is positioned for visibility, and the pump is connected through a suitably rated relay and external supply. Testing should cover startup, button operation, dry/wet rain-sensor conditions, sensor changes, relay switching, pump operation and display updates.

## 8. Measurements and Observations
Record actual sensor readings, selected crop, rain-sensor state, relay state, pump state, supply voltage and response time. Do not enter estimated values as measured results.

| Test | Condition | Record |
|---|---|---|
| Startup | Power applied | LCD initialization and status |
| Crop selection | Press each button | Selected category |
| Rain sensor | Dry and wet conditions | Raw reading / detected state |
| Irrigation decision | Apply test input conditions | Relay and pump state |
| Continuous operation | Run repeated cycles | Stability or faults |

## 9. Results and Performance
The prototype is in the testing and evaluation phase. Performance claims such as accuracy, response time, water savings and efficiency should be included only after controlled measurements have been completed.

## 10. Limitations
- A standard LDR measures light intensity, not soil moisture directly.
- The prototype has limited sensor coverage.
- Operation depends on a stable and correctly rated power supply.
- Crop settings and thresholds are based on the programmed logic.
- The current design does not include remote IoT monitoring.
- Calibration and field testing are needed before practical deployment.

## 11. Future Scope
Potential upgrades include a dedicated capacitive soil-moisture sensor, Wi-Fi/GSM monitoring, weather-data integration, solar power, multiple irrigation zones, data logging and water-level monitoring.

## 12. Conclusion
The project demonstrates an educational prototype for sensor-assisted irrigation control using an Arduino Uno. It integrates crop selection, rain sensing, display feedback and relay-based pump control. Further calibration and testing, particularly with a dedicated soil-moisture sensor, are needed before claiming accurate soil-moisture-based irrigation performance.
