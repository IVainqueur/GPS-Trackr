#include <Arduino.h>
#include <SoftwareSerial.h>
#include <GSM_Generic.h>
#include <GSM_Generic_Main.h>
#include <GSM_SMS_Generic.h>
#include <GSMScanner_Generic.h>

#define PINNUMBER ""

GSMModem modem;
GSM gsmAccess = new GSM(true);
GSM_SMS sms = new GSM_SMS(true);
GSMScanner scanner = new GSMScanner(true);

int sendSms(String message, char number[]);

void setup()
{
  Serial.begin(9600);
  boolean notConnected = true;
  Serial.print("Connecting");
  while (notConnected)
  {
    if (gsmAccess.begin(PINNUMBER) == GSM_READY)
    {
      notConnected = false;
      Serial.println();
    }
    else
    {
      Serial.print(".");
      delay(1000);
    }
  }

  Serial.println("[Success] CONNECTED!");
  Serial.print("[LOG] Carrier: ");
  Serial.println(scanner.getCurrentCarrier());

  Serial.print("[LOG] Signal Strength: ");
  Serial.println(scanner.getSignalStrength());

  delay(1000);
  Serial.println("[LOG] Searching for Networks...");
  Serial.print("[LOG] Found :");
  Serial.println(scanner.readNetworks());
}

void loop()
{
  // put your main code here, to run repeatedly:
}

int sendSms(String message, char number[])
{
  sms.beginSMS(number);
  sms.print(message);
  return sms.endSMS();
}