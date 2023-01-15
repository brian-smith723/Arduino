#include <ArduinoBLE.h>

   
const uint8_t mData1[] = {119,0,98,114,105,97,110,115,0,0,0,0,13,50,5,0,6,128,29,1,0};   
const uint8_t mData2[] = {119,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,49,48,49,48,0,0,0,0};   

void setup() {
  Serial.begin(9600);
  while (!Serial);

  // begin initialization
  if (!BLE.begin()) {
    Serial.println("starting Bluetooth® Low Energy failed!");

    while (1);
  }

  // set advertised local name and device name
  BLE.setLocalName("MyBLE");
  BLE.setDeviceName("MyBLE");

  // Build advertising data packet
  BLEAdvertisingData advData;

  advData.setManufacturerData(mData1, sizeof(mData1));
  
  BLE.setAdvertisingData(advData);

  // Build scan response data packet
  BLEAdvertisingData scanData;
 
  scanData.setManufacturerData(mData2, sizeof(mData2));

  BLE.setScanResponseData(scanData);

  // start advertising
  BLE.advertise();

  Serial.println("BLE Peripheral");
}

void loop() {
  // listen for BLE peripherals to connect:
  BLEDevice central = BLE.central();

  // if a central is connected to peripheral:
  if (central) {
    Serial.print("Connected to central: ");
    // print the central's MAC address:
   


    // when the central disconnects, print it out:
    Serial.print(F("Disconnected from central: "));
    Serial.println(central.address());
  }
}