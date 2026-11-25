# Components and Example Connections

## Components
| Category | Component | Purpose |
|---|---|---|
| Controller | Arduino Uno | Reads inputs and controls outputs |
| Sensor | LDR arrangement | Detects light level in the custom sensing arrangement |
| Sensor | Rain sensor module | Detects wet/rain condition |
| Display | 16x2 I2C LCD | Displays readings and system state |
| Actuator | 5V DC water pump | Demonstrates water delivery |
| Driver | Relay module | Switches the pump supply |
| Alert | Buzzer | Audible notification |
| Input | Push buttons | Crop-category selection |
| Power | Voltage converter and DC supply | Provides suitable regulated power |
| Prototype | Breadboard and jumper wires | Circuit assembly |

## Example Pin Plan (Verify Before Use)
The following assignments are examples discussed during project planning, not a verified record of the final assembled circuit:
- LDR arrangement analog output: A0
- Rain sensor analog output: A1
- Push buttons: D2, D3 and D4
- Relay control: D7
- Buzzer: D8
- I2C LCD: SDA A4, SCL A5 on a standard Arduino Uno

## Wiring and Power Notes
- Connect grounds appropriately according to the module and power-supply design.
- Do not connect a pump directly to an Arduino I/O pin.
- Switch the pump using a relay/driver rated for its voltage and current.
- Use a suitable external pump supply; verify the relay contact ratings and converter output.
- Confirm the actual LCD I2C address and module pin labels.
- Check the physical circuit and final firmware before relying on these example assignments.

## Sensor Accuracy Note
An ordinary LDR measures light intensity. It is not a soil-moisture sensor. For direct soil moisture measurement, use a dedicated capacitive or resistive soil-moisture sensor and calibrate it for the soil and installation conditions.
