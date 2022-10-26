#include <DFRobot_SIM808.h>
#include <SoftwareSerial.h>
#define PIN_TX 10
#define PIN_RX 11
SoftwareSerial mySerial(PIN_TX, PIN_RX);
DFRobot_SIM808 sim808(&mySerial); // Connect RX,TX,PWR,


void SendSMS();


void setup()
{
  mySerial.begin(9600);
  Serial.begin(9600);

  //************* Turn on the GPS power************
  if (sim808.attachGPS())
  {
    Serial.println("Open the GPS power success");
  }
  else
  {
    Serial.println("Open the GPS power failure");
  }

  int strengthNumber;
  char *subNumber = "";
  sim808.getSignalStrength(&strengthNumber);
  sim808.getSubscriberNumber(subNumber);

  Serial.println(strengthNumber);
  // Serial.println(subNumber);

  // sim808.sendSMS(RECEIVER, ms);
  SendSMS();
  Serial.println("Sent Message");
}

void loop()
{
  //************** Get GPS data *******************
  // if (sim808.getGPS())
  // {
  //   Serial.print(sim808.GPSdata.year);
  //   Serial.print("/");
  //   Serial.print(sim808.GPSdata.month);
  //   Serial.print("/");
  //   Serial.print(sim808.GPSdata.day);
  //   Serial.print(" ");
  //   Serial.print(sim808.GPSdata.hour);
  //   Serial.print(":");
  //   Serial.print(sim808.GPSdata.minute);
  //   Serial.print(":");
  //   Serial.print(sim808.GPSdata.second);
  //   Serial.print(":");
  //   Serial.println(sim808.GPSdata.centisecond);
  //   Serial.print("latitude :");
  //   Serial.println(sim808.GPSdata.lat, 6);

  //   sim808.latitudeConverToDMS();
  //   Serial.print("latitude :");
  //   Serial.print(sim808.latDMS.degrees);
  //   Serial.print("\^");
  //   Serial.print(sim808.latDMS.minutes);
  //   Serial.print("\'");
  //   Serial.print(sim808.latDMS.seconeds, 6);
  //   Serial.println("\"");
  //   Serial.print("longitude :");
  //   Serial.println(sim808.GPSdata.lon, 6);
  //   sim808.LongitudeConverToDMS();
  //   Serial.print("longitude :");
  //   Serial.print(sim808.longDMS.degrees);
  //   Serial.print("\^");
  //   Serial.print(sim808.longDMS.minutes);
  //   Serial.print("\'");
  //   Serial.print(sim808.longDMS.seconeds, 6);
  //   Serial.println("\"");

  //   Serial.print("speed_kph :");
  //   Serial.println(sim808.GPSdata.speed_kph);
  //   Serial.print("heading :");
  //   Serial.println(sim808.GPSdata.heading);
  //   //************* Turn off the GPS power ************
  //   sim808.detachGPS();
  // }
}

// mySerial
void SendSMS()
{
  Serial.println("Sending SMS..."); // Show this message on serial monitor
  mySerial.print("AT+CMGF=1\r");     // Set the module to SMS mode
  delay(100);
  mySerial.print("AT+CMGS=\"+250786310931\"\r"); // Your phone number don't forget to include your country code, example +212123456789"
  delay(500);
  mySerial.print("Hi the coder !!!!!!!!!!!!!!!!!!! it's working "); // This is the text to send to the phone number, don't make it too long or you have to modify the SoftwareSerial buffer
  delay(500);
  mySerial.print((char)26); // (required according to the datasheet)
  delay(500);
  mySerial.println();
  Serial.println("Text Sent.");
  delay(500);
}