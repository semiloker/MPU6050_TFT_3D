#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <math.h>

#define TFT_CS    10
#define TFT_DC    9
#define TFT_RST   8

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
Adafruit_MPU6050 mpu;

// Координати вершин куба
float cube[8][3] = 
{
  {-20, -20, -20}, {20, -20, -20}, {20, 20, -20}, {-20, 20, -20},
  {-20, -20, 20}, {20, -20, 20}, {20, 20, 20}, {-20, 20, 20}
};

// Ребра куба
int edges[12][2] = 
{
  {0, 1}, {1, 2}, {2, 3}, {3, 0},
  {4, 5}, {5, 6}, {6, 7}, {7, 4},
  {0, 4}, {1, 5}, {2, 6}, {3, 7}
};

void setup() 
{
  tft.initR(INITR_BLACKTAB);
  tft.setRotation(45);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(1);
  tft.setCursor(10, 10);
  tft.print("Initializing...");

  if (!mpu.begin()) {
    tft.setTextColor(ST77XX_RED);
    tft.setCursor(10, 30);
    tft.print("MPU6050 Error!");
    while (1);
  }

  tft.setTextColor(ST77XX_GREEN);
  tft.setCursor(10, 30);
  tft.print("MPU6050 OK");
  delay(1000);
  tft.fillScreen(ST77XX_BLACK);
}

void drawCube(float rotationX, float rotationY, float lastTransformed[8][2]) 
{
  float transformed[8][2];
  for (int i = 0; i < 8; i++) 
  {
    float y = cube[i][1] * cos(rotationX) - cube[i][2] * sin(rotationX);
    float z = cube[i][1] * sin(rotationX) + cube[i][2] * cos(rotationX);
    float x = cube[i][0] * cos(rotationY) + z * sin(rotationY);
    z = -cube[i][0] * sin(rotationY) + z * cos(rotationY);

    transformed[i][0] = x * (tft.width() / 2) / (z + 100) + tft.width() / 2;
    transformed[i][1] = y * (tft.height() / 2) / (z + 100) + tft.height() / 2;
  }

  for (int i = 0; i < 12; i++) 
  {
    int start = edges[i][0];
    int end = edges[i][1];

    // Стираємо старі лінії
    tft.drawLine(
      lastTransformed[start][0], lastTransformed[start][1],
      lastTransformed[end][0], lastTransformed[end][1],
      ST77XX_BLACK
    );

    // Малюємо нові
    tft.drawLine(
      transformed[start][0], transformed[start][1],
      transformed[end][0], transformed[end][1],
      ST77XX_WHITE
    );
  }

  for (int i = 0; i < 8; i++) 
  {
    lastTransformed[i][0] = transformed[i][0];
    lastTransformed[i][1] = transformed[i][1];
  }
}

void drawText(float ax, float ay, float az, float gx, float gy, float gz, float temp) 
{
  int textAreaHeight = 40;
  int startY = tft.height() - textAreaHeight;

  tft.setTextSize(1);
  tft.fillRect(0, startY, tft.width(), textAreaHeight, ST77XX_BLACK);
  tft.setCursor(2, startY + 2);
  tft.setTextColor(ST77XX_WHITE);
  tft.print("Acc: X:"); tft.print(ax, 1); tft.print(" Y:"); tft.print(ay, 1); tft.print(" Z:"); tft.print(az, 1);
  tft.setCursor(2, startY + 12);
  tft.print("Gyro: X:"); tft.print(gx, 1); tft.print(" Y:"); tft.print(gy, 1); tft.print(" Z:"); tft.print(gz, 1);
  tft.setCursor(2, startY + 22);
  tft.print("Temp: "); tft.print(temp, 1); tft.print("C");
}

void loop() 
{
  static float rotationX = 0, rotationY = 0;
  static float lastTransformed[8][2] = {0};

  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  rotationX += g.gyro.y * 0.05;
  rotationY += g.gyro.x * 0.05;

  drawCube(rotationY, rotationX, lastTransformed);
  drawText(a.acceleration.x, a.acceleration.y, a.acceleration.z, g.gyro.x, g.gyro.y, g.gyro.z, temp.temperature);

  delay(50);
}
