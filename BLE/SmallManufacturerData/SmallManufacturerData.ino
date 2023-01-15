#include <ArduinoBLE.h>

   
const uint8_t mData[] = {119,0,98,114,105,97,110,115};   

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

  BLE.setManufacturerData(mData, sizeof(mData));

  
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
    Serial.println(central.address());
    
    // when the central disconnects, print it out:
    Serial.print(F("Disconnected from central: "));
    Serial.println(central.address());
  }
}