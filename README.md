# Prahar-cargo-v1
A Guide to make the Payload box functional.

System description:

![Screenshot 2024-09-20 124909](https://github.com/user-attachments/assets/56af61ed-31f7-43ca-909d-0e0cecc470ca)




# Copilot Control System

## Overview

The **Copilot Control System** project demonstrates a method for monitoring and managing the safety status of a vehicle, such as a drone, using the MAVLink communication protocol. The system integrates with a Raspberry Pi to interact with the vehicle's telemetry data and an Arduino to handle safety controls.

The script connects to a MAVLink-compatible vehicle and monitors various statuses, including arming, airborne state, and safety status. Additionally, it sends safety-related commands to the MCU over serial communication.

## Features

- **Vehicle Connection**: Establishes a connection with a MAVLink-compatible vehicle using TCP or Serial protocols.
- **Safety Monitoring**: Continuously monitors safety status, including motor activity and whether the vehicle is airborne.
- **Arduino Integration**: Communicates with an Arduino over a serial port to  send safety commands.
- **MAVLink Messages**: Requests specific MAVLink messages to retrieve telemetry data and configure parameters.

## Requirements

### Hardware

- Raspberry Pi
- MAVLink-compatible vehicle (e.g., drone or flight controller)
- Arduino with a compatible serial interface
- USB cable for Arduino connection

### Software

- Python 3.7+
- `pymavlink` library
- `pyserial` library

## Installation

1. **Clone the repository**:

    ```bash
    git clone https://github.com/kaustavdtl/prahar-cargo-v1.git
    ```
2. **Clone the repository**:
    ```bash
    cd prahar-cargo-v1
    ```
3. **Install the required Python libraries**:

    ```bash
    pip install pymavlink pyserial
    ```

## Configuration

1. Connect the Arduino to the Raspberry Pi using a USB cable.
2. Open the script file and set the desired MAVLink connection parameters (`protocol`, `ip`, `port`, `serial`, `baud`) when creating the `Copilot` object.

## Running the Script

To start the script on the Raspberry Pi, run:

```bash
python Raspberry-copilot
```
## If you cannot run the script in the normal environment it is recommended to switch to a virtual environment:
Activating: 
```bash
myenv\Scripts\activate(windows)
source myenv/bin/activate(linux)
```
1.**Install the required Python libraries**:
```bash
pip install pymavlink pyserial
 ```
2.**To start the script on the Raspberry Pi, run**:

```bash
python Raspberry-copilot
```
After you finish running your code (i.e testing) you can deactivate using:
```bash
deactivate
```
## Running the Script continously on bootup(i.e real life scenario)
**1.Setup the virtual environment as mentioned earlier:**

**2.Creating a Systemd Service:**
```bash
sudo nano /etc/systemd/system/Raspberry-copilot.service
```
Add the Following Configuration
```bash
[Unit]
Description=My Project Service
After=network.target

[Service]
User=pi
Group=pi
WorkingDirectory=/home/pi/prahar-cargo-v1 
Environment="PATH=/home/pi/prahar-cargo-v1 /myenv/bin"
ExecStart=/home/pi/prahar-cargo-v1/myenv/bin/python /home/pi/prahar-cargo-v1/Raspberry-copilot.py
Restart=always

[Install]
WantedBy=multi-user.target
```
**User:** The username that should run the service (usually pi).If you name something different please change this accordingly.

**WorkingDirectory:** The directory where your project is located.

**Environment:** Points to the bin directory of your virtual environment.

**ExecStart:** Command to start the script using the virtual environment's Python interpreter.

**Restart:** Ensures the service restarts on failure.

Save and Exit the file (Press Ctrl + X, then Y, and Enter).

**3.Enabling and Starting the Service:**
Reload Systemd Daemon
```bash
sudo systemctl daemon-reload
```
**4.Enable the Service to Start on Boot**
```bash
sudo systemctl enable myproject.service
```
**5.Start the Service**
```bash
sudo systemctl start myproject.service
```
**6. Checking the Service Status**
Check the Service Status
```bash
sudo systemctl status myproject.service
```
**7.View Logs for Errors (if needed)**
```bash
sudo journalctl -u myproject.service
```
**8. Testing the Service on Boot**
Reboot the Raspberry Pi
```bash
sudo reboot
```
**9.Verify the Service is Running**
```bash
sudo systemctl status myproject.service
```
**10. Troubleshooting**
If the service is not running as expected, check the logs for any errors:
```bash
sudo journalctl -u myproject.service
```
**11. Stopping and Disabling the Service**
If you need to stop or disable the service(for product version please don't do this, its for information only):
Stop the Service
```bash
sudo systemctl stop myproject.service
```
Disable the Service
```bash
sudo systemctl disable myproject.service
```

## Explanation of the Systemd Service File
**[Unit]:**

Description: A brief description of the service.

After: Specifies that the service should start after the network is up.

**[Service]:**

**User and Group:** The user and group under which the service will run.

**WorkingDirectory:** The directory from which the service will execute.

**Environment:** Sets the path to the virtual environment.

**ExecStart:** The command to execute the script.

**Restart:** Ensures the service restarts if it crashes.

[Install]:

WantedBy: Specifies the run level for the service.
By following this guide, your Python script will automatically run in a virtual environment on boot using a systemd service.
s
