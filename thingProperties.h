
#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char DEVICE_LOGIN_NAME[]  = "";

const char SSID[]               = SECRET_SSID;    
const char PASS[]               = SECRET_OPTIONAL_PASS;    
const char DEVICE_KEY[]  = SECRET_DEVICE_KEY;    

void onLedChange();
void onLed2Change();
void onServoChange();

bool led;
bool led2;
bool servo;

void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(led, READWRITE, ON_CHANGE, onLedChange);
  ArduinoCloud.addProperty(led2, READWRITE, ON_CHANGE, onLed2Change);
  ArduinoCloud.addProperty(servo, READWRITE, ON_CHANGE, onServoChange);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
