#include <LiquidCrystal_I2C.h>
#include <HX711_ADC.h>
#include <EEPROM.h>
#include <DHT.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int HX711_dout = A1;
const int HX711_sck = A0;
const int relayPin1 = 8;
const int relayPin2 = 9;
const int DHT_pin = 2;
const int NUM_SAMPLES = 200; // Jumlah sampel yang akan diambil untuk pengambilan
rata-rata
int weightSamples[NUM_SAMPLES];
int sampleIndex = 0;
int averagedWeight = 0;
HX711_ADC LoadCell(HX711_dout, HX711_sck);
DHT dht(DHT_pin, DHT22);
const int calVal_eepromAdress = 0;
float calibrationValue = 214.50;
boolean isLoadCellData = true; // Flag untuk menentukan apakah menampilkan data load cell
atau DHT22
void setup() {
  Serial.begin(9600);
  lcd.begin();
  pinMode(HX711_dout, INPUT);
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  digitalWrite(relayPin1, LOW);
  digitalWrite(relayPin2, LOW)
  dht.begin();
  delay(10);
  Serial.println();
  Serial.println("Memulai...");
  lcd.begin();
  LoadCell.begin();
  lcd.setCursor(0, 0);
  lcd.print("MASUKKAN GABAH");
  lcd.setCursor(0, 1);
  lcd.print("sebanyak 70 gr");
  //lcd.setCursor(13, 0);
  //lcd.print("gr");
  EEPROM.get(calVal_eepromAdress, calibrationValue);
  long stabilizingtime = 3000;
  boolean _tare = true;
  LoadCell.start(stabilizingtime, _tare);
    if (LoadCell.getTareTimeoutFlag()) {
    Serial.println("Timeout, cek kabel MCU > HX711 pastikan sudah tepat");
    while (1);
    } else {
  LoadCell.setCalFactor(calibrationValue);
  Serial.println("Startup selesai");
  }
}
void loop() {
  if (isLoadCellData) {
  if (LoadCell.update()) {
  int weight = LoadCell.getData();
  if (weight < 0) {
  weight = 0;
  }
  // Tambahkan nilai sampel ke array
  weightSamples[sampleIndex] = weight;
  sampleIndex++;
  // Reset indeks sampel jika sudah mencapai jumlah sampel maksimum
  if (sampleIndex >= NUM_SAMPLES) {
  sampleIndex = 0;
  }
  // Hitung rata-rata dari semua sampel
  long totalWeight = 0;
  for (int i = 0; i < NUM_SAMPLES; i++) {
  totalWeight += weightSamples[i];
  }
  averagedWeight = totalWeight / NUM_SAMPLES;
  tampilLoadCell(averagedWeight);
  kontrolRelay(averagedWeight);
  }
  } else {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  tampilDHT22(temperature, humidity);
  }
  isLoadCellData = !isLoadCellData;
  // Delay sebelum berganti ke sensor berikutnya
  }
void tampilLoadCell(int weight) {
  lcd.setCursor(6, 0);
  lcd.print(" ");
  if (weight < 10) {
  lcd.setCursor(11, 0);
  } else if (weight < 100 && weight >= 10) {
  lcd.setCursor(10, 0);
  } else if (weight < 1000 && weight >= 100) {
  lcd.setCursor(9, 0);
  } else if (weight < 10000 && weight >= 1000) {
  lcd.setCursor(8, 0);
  } else if (weight < 100000 && weight >= 10000) {
  lcd.setCursor(7, 0);
  } else if (weight < 1000000 && weight >= 100000) {
  lcd.setCursor(6, 0);
  } else if (weight < 10000000 && weight >= 1000000) {
  lcd.setCursor(5, 0);
  } else if (weight < 100000000 && weight >= 10000000) {
  lcd.setCursor(4, 0);
  } else {
  lcd.setCursor(3, 0);
  }
  lcd.print(weight);
  lcd.setCursor(0, 0);
  lcd.print("Berat:");
  lcd.setCursor(13, 0);
  lcd.print("gr");
}
void tampilDHT22(float temperature, float humidity) {
  lcd.setCursor(0, 1);
  lcd.print("T:");
  lcd.print(temperature);
  lcd.print("C");
  lcd.print(" ");
  lcd.print("H:");
  lcd.print(humidity);
  lcd.print("%");
}
void kontrolRelay(int weight) {
  float berat_awal = 70; // Ganti dengan nilai berat awal aktual
  float ambang_batas = berat_awal * 0.8312; // Hitung ambang batas 83,12% berat awal
  if (weight < ambang_batas) {
  digitalWrite(relayPin1, LOW);
  digitalWrite(relayPin2, LOW);
  } else {
  digitalWrite(relayPin1, HIGH);
  digitalWrite(relayPin2, HIGH);
  }
}
