# Automatic Grain Dryer System Based on Load Cell Sensor
<p align="center">
  <img src="https://github.com/arutafusain/Pengering-Gabah/assets/98148350/81441ed1-14d4-4b12-857f-31be743a43e4" width="600" />
</p>

The objective of this project is to address the conventional method of drying grain, which involves sun drying and is dependent on weather conditions and prone to contamination by dust.

This dryer uses a load cell sensor and a lamp as the drying device, controlled by an Arduino. The concept is that when the wet grain is placed into the dryer, the load cell will record the initial weight. The lamp will automatically turn on, and as the grain dries, its weight will decrease due to the reduction in moisture content. Once the rice weight decreases by 83.12%, the lamp will automatically turn off, stopping the drying process.

This project was designed using SketchUp software, and this is a 3D design view and schematic diagram of the grain dryer
<p align="center">
  <img src="https://github.com/arutafusain/Pengering-Gabah/assets/98148350/51ce58cf-2ddb-476e-b10b-0890a10e68c0" width="400" />
</p>
<p align="center">
  <img src="https://github.com/arutafusain/Pengering-Gabah/assets/98148350/1d62e088-d309-40b7-a592-3158001709b3" width="400" />
</p>

## Key Features
- **Automatic Drying Process**: The system automatically starts the drying process when wet grain is loaded.
- **Load Cell Sensor Integration**: Measures and stores the initial weight of the grain and continuously monitors the weight reduction during the drying process.
- **Drying Completion Detection**: Based on research, the drying process stops when the grain weight decreases by 83.12%.
- **Temperature and Humidity Monitoring**: Utilizes a DHT22 sensor to monitor and display the temperature and humidity levels.
- **User Interface**: An LCD screen provides real-time information on the drying status and environmental conditions.
- **Exhaust Fan Control**: Manages the exhaust fan to control the airflow and improve the drying efficiency.
- **Safety and Efficiency**: Ensures the drying process stops at the right time to prevent over-drying or under-drying.

## Technologies Used
- **Arduino Uno**: The main microcontroller for controlling the process.
- **Load Cell with HX711 Module**: For measuring the initial and reduced weight of the grain.
- **DHT22 Sensor**: For monitoring temperature and humidity.
- **Relay**: For controlling the power to the incandescent lamp and exhaust fan.
- **Incandescent Lamp**: Provides the heat necessary for drying the grain.
- **Exhaust Fan**: Controls the airflow to aid the drying process.
- **LCD Screen**: Displays real-time information on drying status, temperature, and humidity.

## Working Principle
1. **Inserting Wet Grain**: Wet grain is placed into the dryer.
2. **Initial Weight Measurement**: The load cell sensor measures and stores the initial weight of the grain.
3. **Drying Process**: The incandescent lamp turns on, and the exhaust fan starts to facilitate the drying process.
4. **Monitoring Weight Reduction**: The load cell continuously monitors the weight of the grain.
5. **Stopping Drying Process**: When the grain weight decreases by 83.12%, the relay turns off the incandescent lamp and stops the drying process.
6. **Temperature and Humidity Monitoring**: The DHT22 sensor monitors and displays temperature and humidity levels throughout the process on the LCD screen.
