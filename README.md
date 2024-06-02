## Pengering-Gabah
This dryer uses a load cell sensor and a lamp as the drying device, controlled by an Arduino. The concept is that when the wet rice is placed into the dryer, the load cell will record the initial weight. The lamp will automatically turn on, and as the rice dries, its weight will decrease due to the reduction in moisture content. Once the rice weight decreases by 30%, the lamp will automatically turn off, stopping the drying process.

The objective of this project is to address the conventional method of drying rice, which involves sun drying and is dependent on weather conditions and prone to contamination by dust.

## Working Principle
1. **Inserting Wet Rice**: Wet rice is placed into the device.
2. **Initial Weight Measurement**: The load cell sensor measures and records the initial weight of the rice.
3. **Drying Process**: The incandescent lamp turns on and starts the drying process.
4. **30% Weight Reduction**: Based on research, when the rice weight decreases by 30%, the lamp will automatically turn off, stopping the drying process.
5. **Temperature Monitoring**: An LCD screen is used to monitor the temperature during the drying process.

## Components Used
- **Arduino Uno**: The main microcontroller used to control the entire process.
- **Load Cell Sensor**: To measure the initial weight and monitor the reduction in rice weight.
- **Incandescent Lamp**: Serves as the heat source for drying the rice.
- **Relay**: Controls the on/off state of the lamp based on input from the Arduino.
- **LCD Screen**: Displays information about temperature and the drying status.
