<h1 align="center">MPU6050_TFT_3D</h1>

<p align="center">
  A project to display and rotate 3D objects on a TFT screen using data from the MPU6050 gyroscope and accelerometer.
</p>

---

<h2>📜 Overview</h2>

<p>
  <strong>MPU6050_TFT_3D</strong> is an interactive 3D visualization project. It uses the MPU6050 module to detect motion and displays a rotating 3D cube on an Adafruit TFT display. This is a great learning tool for working with accelerometers, gyroscopes, and graphical displays with Arduino or PlatformIO.
</p>

<h3>✨ Features</h3>
<ul>
  <li>Real-time 3D cube rendering on a TFT screen.</li>
  <li>Dynamic rotation based on MPU6050 sensor data.</li>
  <li>Displays real-time acceleration, gyroscope, and temperature readings.</li>
  <li>Optimized drawing to reduce flickering.</li>
</ul>

---

<h2>🛠️ Components Required</h2>
<ul>
  <li><strong>Microcontroller:</strong> Arduino, ESP32, or compatible board.</li>
  <li><strong>Display:</strong> Adafruit ST7735 or compatible TFT screen.</li>
  <li><strong>MPU6050:</strong> Gyroscope and accelerometer module.</li>
</ul>

---

<h2>🚀 Getting Started</h2>

<h3>1. Clone the Repository</h3>
<pre>
<code>git clone https://github.com/your-username/MPU6050_TFT_3D.git</code>
</pre>

<h3>2. Open the Project</h3>
<p>Open the downloaded folder in <strong>PlatformIO</strong> (recommended) or <strong>Arduino IDE</strong>.</p>

<h3>3. Connect Hardware</h3>
<p>
Follow the pin connections below to set up the hardware:
</p>

<ul>
  <li><strong>MPU6050 to Microcontroller:</strong></li>
  <ul>
    <li>VCC → 5V (Arduino Nano)</li>
    <li>GND → GND (Arduino Nano)</li>
    <li>SCL → A5 (Arduino Nano)</li>
    <li>SDA → A4 (Arduino Nano)</li>
  </ul>
  <li><strong>TFT Display  to Microcontroller:</strong></li>
  <ul>
    <li>VCC (ST7735S) → 5V (Arduino Nano)</li>
    <li>GND (ST7735S) → GND (Arduino Nano)</li>
    <li>CS (ST7735S) → D10 (Arduino Nano)</li>
    <li>RST (ST7735S) → D8 (Arduino Nano)</li>
    <li>A0(DC) (ST7735S) → D9 (Arduino Nano)</li>
    <li>SDA (ST7735S) → D11 (Arduino Nano)</li>
    <li>SCK (ST7735S) → D13 (Arduino Nano)</li>
    <li>LED (ST7735S) → 3V (Arduino Nano)</li>
  </ul>
</ul>

<h3>4. Install Required Libraries</h3>
<p>
Ensure the following libraries are installed in your PlatformIO or Arduino IDE:
</p>
<ul>
  <li>Adafruit GFX Library</li>
  <li>Adafruit ST7735 and ST7789 Library</li>
  <li>Adafruit MPU6050 Library</li>
  <li>Adafruit Sensor Library</li>
</ul>

<h3>5. Upload the Code</h3>
<p>Compile and upload the code to your microcontroller using PlatformIO or Arduino IDE.</p>

<h3>6. View the Results</h3>
<p>
Once uploaded, the TFT screen will display a rotating 3D cube, along with real-time sensor data such as acceleration, gyroscope readings, and temperature.
</p>

---

<h2>📂 Project Structure</h2>
<ul>
  <li><strong>src/:</strong> Contains the main source code.</li>
  <li><strong>platformio.ini:</strong> PlatformIO project configuration file.</li>
</ul>

---
