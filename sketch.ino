#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#define DHTPIN 8
#define DHTTYPE DHT22
DHT dht (DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Sistem Monitoring Suhu");
  lcd.begin(16, 2);
  dht.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  delay(1000);

//Menampilkan di LCD
  lcd.setCursor(0,0);
  lcd.println("Suhu=");
  lcd.print(t);
  lcd.println(" C");
  lcd.setCursor(0,1);
  lcd.println("Lembab=");
  lcd.print(h);
  lcd.println(" %");

//Menampilkan di serial monitor
  Serial.println("Suhu = ");
  Serial.print(t);
  Serial.println(" C");
  Serial.println("Kelembaban = ");
  Serial.print(h);
  Serial.println(" %");

}
