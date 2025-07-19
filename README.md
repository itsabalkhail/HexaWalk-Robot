# Arduino 6 Servo Motors Humanoid Robot Control

## 📋 Project Overview

This project controls 6 servo motors connected to an Arduino UNO to simulate humanoid robot movements. The system performs two main functions:
1. **Sweep Motion**: All servos perform a synchronized sweep movement for 2 seconds
2. **Walking Algorithm**: Simulates humanoid walking motion using coordinated leg movements

## 🛠️ Hardware Requirements

### Components:
- **Arduino UNO** (1x)
- **Servo Motors** (6x) - Standard 9g or similar
- **Breadboard** (1x large breadboard)
- **Jumper Wires** (Male-to-Male)
- **USB Cable** (for Arduino connection)
- **Power Supply** (External 5V recommended for multiple servos)

### Circuit Connections:

| Servo Motor | Arduino Pin | Function |
|-------------|-------------|----------|
| Servo 1     | Pin 3       | Right Hip |
| Servo 2     | Pin 5       | Right Knee |
| Servo 3     | Pin 6       | Right Ankle |
| Servo 4     | Pin 9       | Left Hip |
| Servo 5     | Pin 10      | Left Knee |
| Servo 6     | Pin 11      | Left Ankle |

### Wiring Diagram:
- **Red Wire (VCC)**: Connect all to 5V rail on breadboard
- **Brown/Black Wire (GND)**: Connect all to GND rail on breadboard
- **Orange/Yellow Wire (Signal)**: Connect to respective digital pins

## 💻 Software Requirements

- **Arduino IDE** (Version 1.8.0 or higher)
- **Servo Library** (Built-in with Arduino IDE)

## 📂 Project Structure

```
humanoid-robot-control/
│
├── humanoid_servo_control.ino    # Main Arduino code
├── README.md                     # This file
└── circuit_diagram.png           # Circuit diagram (optional)
```

## 🚀 Installation & Setup

### 1. Hardware Setup:
1. Connect all 6 servo motors to the breadboard
2. Wire the servo motors according to the connection table above
3. Connect Arduino UNO to your computer via USB
4. Ensure proper power supply for servo motors

### 2. Software Setup:
1. Download and install Arduino IDE
2. Open the `humanoid_servo_control.ino` file
3. Select the correct board: **Tools > Board > Arduino UNO**
4. Select the correct port: **Tools > Port > [Your Arduino Port]**
5. Upload the code to Arduino

## ⚡ How It Works

### Phase 1: Sweep Example (2 seconds)
- All 6 servo motors perform synchronized sweep motion
- Movement range: 0° to 180° and back to 0°
- Duration: Approximately 2 seconds
- Purpose: System initialization and motor testing

### Phase 2: Hold Position (1 second)
- All servo motors move to and hold 90° position
- Duration: 1 second
- Purpose: Reset to neutral position before walking

### Phase 3: Walking Motion (Continuous Loop)
The walking algorithm follows these steps:

1. **Step 1**: Lift right leg (Hip: 45°, Knee: 135°, Ankle: 90°)
2. **Step 2**: Move right leg forward (Hip: 120°, Knee: 90°, Ankle: 90°)
3. **Step 3**: Place right leg down (Hip: 90°, Knee: 90°, Ankle: 60°)
4. **Step 4**: Lift left leg (Hip: 135°, Knee: 45°, Ankle: 90°)
5. **Step 5**: Move left leg forward (Hip: 60°, Knee: 90°, Ankle: 90°)
6. **Step 6**: Place left leg down (Hip: 90°, Knee: 90°, Ankle: 120°)
7. **Step 7**: Return to neutral position (All: 90°)

## 🎛️ Control Parameters

### Timing Settings:
- **Sweep Speed**: 50ms delay between steps
- **Walking Step Duration**: 500ms per step
- **Neutral Position Hold**: 1000ms

### Angle Ranges:
- **Minimum Angle**: 0°
- **Maximum Angle**: 180°
- **Neutral Position**: 90°

## 🔧 Customization Options

### Modify Walking Speed:
Change the `delay()` values in the walking motion function:
```cpp
delay(500); // Change this value (milliseconds)
```

### Adjust Movement Angles:
Modify servo positions in the walking motion:
```cpp
servo1.write(45); // Change angle (0-180 degrees)
```

### Add New Movement Patterns:
Create new functions following the existing pattern structure.

## 🐛 Troubleshooting

### Common Issues:

**Servos not moving:**
- Check power connections
- Verify signal wire connections
- Ensure Arduino is properly connected

**Erratic movement:**
- Check for loose connections
- Ensure adequate power supply
- Verify code upload was successful

**Serial Monitor not working:**
- Check baud rate is set to 9600
- Ensure correct COM port is selected

### Debug Tips:
- Use Serial Monitor to track execution progress
- Test individual servos before running full program
- Verify servo library is properly included

## 📊 Performance Specifications

- **Operating Voltage**: 5V DC
- **Current Draw**: ~300-500mA (depending on servo load)
- **Control Resolution**: 1° (approximately)
- **Walking Cycle Duration**: ~4 seconds per complete cycle
- **Maximum Torque**: Depends on servo specifications

## 🔄 Future Enhancements

Potential improvements and features to add:

1. **Sensor Integration**: Add ultrasonic sensors for obstacle detection
2. **Remote Control**: Implement Bluetooth/WiFi control
3. **Balance Control**: Add gyroscope for better stability
4. **Variable Speed**: Implement speed control for walking motion
5. **Multiple Gaits**: Add different walking patterns
6. **Arm Movement**: Extend to include arm servo controls

## 📝 Code Structure

### Main Functions:
- `setup()`: Initialize servos and run initial sequences
- `loop()`: Continuous walking motion execution
- `sweepExample()`: Synchronized servo sweep motion
- `holdAt90Degrees()`: Position all servos to neutral
- `walkingMotion()`: Main walking algorithm

### Libraries Used:
- `Servo.h`: Arduino servo control library

## 🤝 Contributing

To contribute to this project:
1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Test thoroughly
5. Submit a pull request

---

**Note**: This code is optimized for Tinkercad simulation but works equally well on physical Arduino hardware.
