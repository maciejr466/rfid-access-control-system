#include <Wire.h> // I2C works 
#include <LiquidCrystal_I2C.h>
#include <MFRC522.h>
#include <SPI.h>
#include <config.h> //correct UID card

// RFID pin decleration 
#define SS_PIN 10
#define RST_PIN 9

// diode declaration
#define RED_PIN 7
#define GREEN_PIN 6

// buzzer declaration
const int buzzer = 5;

// creating object RFID
MFRC522 rfid(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  // start SPI and inicjalization rfid
  SPI.begin();
  rfid.PCD_Init(); 

  // Diode pinMode
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);

  // setting buzzer
  pinMode(buzzer, OUTPUT);

  // start lcd 
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Tap card...");
}

void loop() {
  // put your main code here, to run repeatedly:

  // is there new card?
  if(!rfid.PICC_IsNewCardPresent()){
    return;
  }

  // if it read it correctly?
  if(!rfid.PICC_ReadCardSerial()){
    return;
  }

  // creating variable to save read UID 
  String readUID ="";
  for (byte i = 0; i < rfid.uid.size; i++) {
    if (rfid.uid.uidByte[i] < 0x10) {
      readUID += "0";
    }
    readUID += String(rfid.uid.uidByte[i], HEX);
  }
  readUID.toUpperCase();
  
  // preparing lcd for answer
  lcd.clear();
  lcd.setCursor(0, 0);
  
  // checking if read UID is correct 
  if(readUID == correctUID){
    digitalWrite(GREEN_PIN, HIGH);
    lcd.print("Access granted!");
    delay(1000);
    digitalWrite(GREEN_PIN, LOW);
  }
  else{
    digitalWrite(RED_PIN, HIGH);
    lcd.print("Access denied!");
    tone(buzzer, 2000);
    delay(1000);
    digitalWrite(RED_PIN, LOW);
    noTone(buzzer);
  }

  // stop communication with card and stop encryption
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();

  // continutity 
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Tap card...");
}
