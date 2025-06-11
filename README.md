# ElectronicsProjects
Electronics &amp; Communication Engineering Real Time Projects Codes
# Ultrasonic Radar Detection System 🚀

A real-time object detection system using an ultrasonic sensor and servo motor to simulate radar. The system detects obstacles and visualizes their positions using a radar-style graphical interface built in Processing.

## 🔧 Technologies Used
- **Arduino Uno**
- **HC-SR04 Ultrasonic Sensor**
- **Servo Motor (SG90)**
- **Processing (Java-based IDE for visual output)**

## 🧠 Project Description
This project simulates a radar system using Arduino. It scans the surroundings using an ultrasonic sensor mounted on a servo motor and sends distance data to the Processing interface, which visually displays detected objects in real time.

## 📌 Features
- Rotating radar sweep with servo motor
- Real-time object detection using ultrasonic sensor
- Visual output showing object position and distance
- Adjustable scan angle and resolution

## ⚙️ How It Works
1. The servo rotates from 0° to 180°.
2. At each angle, the ultrasonic sensor measures distance to nearby objects.
3. Data is sent via serial to Processing.
4. Processing draws the radar scan and object location visually.

## 🖥️ Circuit Diagram
> ![Radar Circuit Diagram](Projects/RadarDetection/Screenshot%202025-06-11%20121524.png)

## 📸 Screenshots
> *(Insert radar output screenshots/GIFs here if possible)*

## 📂 Files
- `arduino code.txt` – Arduino code
- `processing code.txt` – Processing visualization script

## 🚀 Getting Started
1. Connect the components as per the circuit diagram.
2. Upload the Arduino code.
3. Run the Processing sketch (ensure the correct serial port is selected).

## 📎 License
This project is open-source and available under the MIT License.

