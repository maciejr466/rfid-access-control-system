### Rfid-access-control-system English version
An embedded access control and security system built on Arduino. It reads RFID tags and verifies their UID, granting access with a green LED and an "Access granted!" message on the I2C LCD, or triggering an alert with a red LED, an "Access denied!" prompt, and a buzzer alarm.

## Parts and modules used:
* Arduino Uno R3
* RFID-RC522 module (13.56 MHz)
* 1602A LCD display (16x2)
* I2C converter for the LCD display (PCF8574)
* 1x Green LED
* 1x Red LED
* 1x Passive buzzer (or active 5V buzzer)
* 2x 220Ω resistors (for the LEDs)
* Breadboard and jumper wires
  <img width="563" height="305" alt="Zrzut ekranu 2026-11-22 200447" src="https://github.com/user-attachments/assets/73845065-88cf-4d12-862e-7635d0ff8bb7" />

  ### Pinout summary:
| Component | Module Pin | Arduino Uno Pin | Notes |
| :--- | :--- | :--- | :--- |
| **RFID-RC522** | `SDA (SS)` | `D10` | SPI Chip Select |
| **RFID-RC522** | `SCK` | `D13` | SPI Clock |
| **RFID-RC522** | `MOSI` | `D11` | SPI Master Out Slave In |
| **RFID-RC522** | `MISO` | `D12` | SPI Master In Slave Out |
| **RFID-RC522** | `RST` | `D9` | Hardware Reset |
| **RFID-RC522** | `3.3V` / `GND` | `3.3V` / `GND` | **Must be powered with 3.3V!** |
| **LCD I2C** | `SDA` / `SCL` | `SDA` / `SCL` | I2C Bus (Default address: `0x27`) |
| **LCD I2C** | `VCC` / `GND` | `5V` / `GND` | 5V Power Supply |
| **Green LED** | Anode (+) | `D6` | Through a 220Ω resistor |
| **Red LED** | Anode (+) | `D7` | Through a 220Ω resistor |
| **Buzzer** | Signal (+) | `D5` | 2 kHz tone alert |


## Configuration & Setup:

All of the external libraries used in this project (`MFRC522`, `LiquidCrystal_I2C`) were created by their respective open-source authors.

### Legal notice
This project is a non-commercial, educational project developed for learning and academic purposes only. It uses publicly available third-party libraries, assets, and open-source tools, which remain the property of their respective authors and are subject to their original licenses. 
I do not claim ownership over any third-party content used, and no profit is being made from this project. If any author of included content wishes for their work to be removed or properly attributed, please contact me and I will address the issue immediately.   



# System Kontroli Dostępu RFID  PL

System kontroli dostępu i zabezpieczeń zbudowany na platformie Arduino. Układ odczytuje tagi/karty RFID i weryfikuje ich unikalny identyfikator (UID), przyznając dostęp za pomocą zielonej diody LED oraz komunikatu `"Access granted!"` na wyświetlaczu LCD I2C, lub uruchamiając alarm za pomocą czerwonej diody LED, komunikatu `"Access denied!"` oraz sygnału dźwiękowego z buzzera.

## Użyte części i moduły:
- Arduino Uno R3
- Moduł czytnika RFID-RC522 (13.56 MHz)
- Wyświetlacz LCD 1602A (16x2)
- Konwerter I2C do wyświetlacza LCD (PCF8574)
- 1x Dioda LED zielona
- 1x Dioda LED czerwona
- 1x Buzzer pasywny (lub aktywny 5V)
- 2x Rezystor 220Ω (do diod LED)
- Płytka stykowa i przewody połączeniowe

<img width="563" height="305" alt="Schemat połączeń" src="https://github.com/user-attachments/assets/73845065-88cf-4d12-862e-7635d0ff8bb7" />

### Podsumowanie połączeń (Pinout):
| Komponent | Pin modułu | Pin Arduino Uno | Uwagi |
| :--- | :--- | :--- | :--- |
| **RFID-RC522** | `SDA (SS)` | `D10` | Magistrala SPI (Chip Select) |
| **RFID-RC522** | `SCK` | `D13` | Magistrala SPI (Zegar) |
| **RFID-RC522** | `MOSI` | `D11` | Magistrala SPI (Master Out Slave In) |
| **RFID-RC522** | `MISO` | `D12` | Magistrala SPI (Master In Slave Out) |
| **RFID-RC522** | `RST` | `D9` | Reset sprzętowy |
| **RFID-RC522** | `3.3V` / `GND` | `3.3V` / `GND` | **Musi być zasilany napięciem 3.3V!** |
| **LCD I2C** | `SDA` / `SCL` | `SDA` / `SCL` (`A4` / `A5`) | Magistrala I2C (Domyślny adres: `0x27`) |
| **LCD I2C** | `VCC` / `GND` | `5V` / `GND` | Zasilanie 5V |
| **LED Zielona** | Anoda (+) | `D6` | Przez rezystor 220Ω |
| **LED Czerwona** | Anoda (+) | `D7` | Przez rezystor 220Ω |
| **Buzzer** | Sygnał (+) | `D5` | Sygnał alarmowy 2 kHz |

## Konfiguracja i uruchomienie:

Wszystkie zewnętrzne biblioteki użyte w tym projekcie (`MFRC522`, `LiquidCrystal_I2C`) zostały stworzone przez ich odpowiednich autorów na licencjach open-source.

### Nota prawna
Ten projekt jest niekomercyjnym projektem edukacyjnym stworzonym wyłącznie w celach nauki i rozwoju. Wykorzystuje publicznie dostępne biblioteki zewnętrzne, zasoby oraz narzędzia open-source, które pozostają własnością ich odpowiednich autorów i podlegają ich oryginalnym licencjom.

Nie roszczę sobie praw własności do jakichkolwiek wykorzystanych treści stron trzecich, a projekt nie generuje żadnych zysków. 
Jeśli którykolwiek z autorów użytych materiałów życzy sobie ich usunięcia lub innego oznaczenia autorstwa, proszę o kontakt, a sprawa zostanie niezwłocznie rozwiązana.
