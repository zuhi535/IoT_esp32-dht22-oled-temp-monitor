# ESP32 DHT22 OLED Temperature Monitor

Ez a projekt egy **ESP32 alapú hőmérséklet- és páratartalom-figyelő rendszer**, amely egy **DHT22 szenzorból**, három **LED-ből** és egy **SSD1306 OLED kijelzőből** áll.

A rendszer a DHT22 szenzor által mért **aktuális hőmérsékletet és páratartalmat** jeleníti meg az OLED kijelzőn, valamint **LED-ekkel jelzi a hőmérséklet tartományát**:

- 🌿 **Zöld LED:** ha a hőmérséklet 20 °C alatt van  
- ☀️ **Sárga LED:** ha a hőmérséklet 20–30 °C között van  
- 🔥 **Piros LED:** ha a hőmérséklet 30 °C felett van  

---

## 🧩 Használt hardverek

- ESP32 DevKit v1
- DHT22 hőmérséklet- és páratartalom szenzor  
- SSD1306 0.96" OLED kijelző (I²C)  
- 3 LED (zöld, sárga, piros) + 3×220 Ω ellenállás

---

## ⚙️ Bekötés

| Komponens | ESP32 Pin | Megjegyzés |
|------------|------------|-------------|
| DHT22 VCC  | 5V         | tápfeszültség |
| DHT22 GND  | GND        | föld |
| DHT22 DATA | GPIO25     | adatvezeték |
| OLED SDA   | GPIO21     | I²C adatvonal |
| OLED SCL   | GPIO22     | I²C órajelvonal |
| Zöld LED   | GPIO14     | hideg jelző |
| Sárga LED  | GPIO27     | normál jelző |
| Piros LED  | GPIO26     | meleg jelző |

---

## 🧠 Fő funkciók

- Beolvassa a hőmérsékletet és páratartalmat a DHT22 szenzorból  
- Megjeleníti az értékeket az **OLED kijelzőn**  
- LED-ek segítségével jelzi a hőmérséklet szintjét  
- Hibakezelés, ha a szenzor olvasása sikertelen

---

## 🚀 Könyvtárak

A működéshez a következő Arduino könyvtárak szükségesek:

- `DHT sensor library`
- `Adafruit Unified Sensor`
- `Adafruit GFX Library`
- `Adafruit SSD1306`

Telepíthetők az Arduino IDE Library Managerből.

---

## ▶️ Használat

1. Töltsd fel a kódot az ESP32-re.  
2. Csatlakoztasd a szenzort, a LED-eket és a kijelzőt a táblázat szerint.  
3. A kijelzőn látni fogod a mért értékeket, a LED-ek pedig a hőmérséklet-tartományt jelzik.

---

## 📸 Példa működés közben

