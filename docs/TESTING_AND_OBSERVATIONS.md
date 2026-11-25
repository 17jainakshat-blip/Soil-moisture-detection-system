# Testing and Observations

## Experimental Procedure
1. Inspect wiring and verify supply voltage and polarity before powering the prototype.
2. Power on the Arduino and check LCD initialization.
3. Test each crop-selection push button and record the displayed selection.
4. Observe and record the LDR arrangement output under repeatable conditions.
5. Test the rain sensor in dry and wet conditions and record its raw output and interpreted state.
6. Apply test conditions that should request and should not request irrigation.
7. Observe relay switching and verify pump operation.
8. Repeat tests and note unstable readings, delays, loose connections or other faults.

## Observation Table
Enter measured values from the actual prototype. Do not invent readings.

| Test | Input / condition | Sensor reading | Expected response | Actual response / notes |
|---|---|---|---|---|
| 1 | Power-up | — | LCD initializes | |
| 2 | Crop button selection | — | Category changes | |
| 3 | Rain sensor dry | | Dry state shown/used | |
| 4 | Rain sensor wet | | Rain state; pump inhibited if coded | |
| 5 | Irrigation condition met, no rain | | Relay/pump ON if coded | |
| 6 | Irrigation condition not met | | Relay/pump OFF | |
| 7 | Repeated operation | | Stable operation | |

## Performance Metrics to Calculate
- Sensor response: compare raw readings across repeatable test conditions.
- Response time: measure time between applying an input condition and observing the output change.
- Reliability: count successful cycles and failures over a stated number of trials.
- Water use: measure actual pump output over a measured operating period if water-saving claims are evaluated.

## Reporting
Include date, test setup, supply voltage, sensor readings, crop selection, relay state, pump state and any faults. Report only observed measurements. The LDR output represents light intensity unless a separate, validated sensing mechanism is used; do not label it as a direct soil-moisture percentage.
