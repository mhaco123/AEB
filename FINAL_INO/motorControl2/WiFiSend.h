/* this code send parameters NAME,VALUE and UNIT via UDP protocol and WiFi Adafruit_CC3000 Module to Ground Control Station (GSC)
 * Manual: go to WiFiSend_LoopFunction () find "udpclient.print" and add your parameters NAME,VALUE and UNIT same as Parameter1 & Parameter1 and clean them;
 * 
 * just Add this functions 
 * add this phrase to beginning after your code "#include" :#include "WiFiSend.h"
 * Setup Section: WiFiSend_SetupFunction ();
 * Loop Section: WiFiSend_LoopFunction (); 
 */
    #include "Adafruit_CC3000.h"    
//************************************************************************************* PreSetup
// These are the interrupt and control pins
#define ADAFRUIT_CC3000_IRQ   3  // MUST be an interrupt pin!
// These can be any two pins
#define ADAFRUIT_CC3000_VBAT  5
#define ADAFRUIT_CC3000_CS    10
// Use hardware SPI for the remaining pins
// On an UNO, SCK = 13, MISO = 12, and MOSI = 11
Adafruit_CC3000 cc3000 = Adafruit_CC3000(ADAFRUIT_CC3000_CS, ADAFRUIT_CC3000_IRQ, ADAFRUIT_CC3000_VBAT,
                                         SPI_CLOCK_DIVIDER); // you can change this clock speed

#define WLAN_SSID       "net"           // cannot be longer than 32 characters!
#define WLAN_PASS       "pass1234"
// Security can be WLAN_SEC_UNSEC, WLAN_SEC_WEP, WLAN_SEC_WPA or WLAN_SEC_WPA2
#define WLAN_SECURITY   WLAN_SEC_WPA2
Adafruit_CC3000_Client udpclient;
uint32_t gateway;
int port = 4023;
//************************************************************************************* Functions
    bool displayConnectionDetails(void)
{
  uint32_t ipAddress, netmask, dhcpserv, dnsserv;
  
  if(!cc3000.getIPAddress(&ipAddress, &netmask, &gateway, &dhcpserv, &dnsserv))
  {
    Serial.println(F("Unable to retrieve the IP Address!\r\n"));
    return false;
  }
  else
  {
    Serial.print(F("\nIP Addr: ")); cc3000.printIPdotsRev(ipAddress);
    Serial.print(F("\nNetmask: ")); cc3000.printIPdotsRev(netmask);
    Serial.print(F("\nGateway: ")); cc3000.printIPdotsRev(gateway);
    Serial.print(F("\nDHCPsrv: ")); cc3000.printIPdotsRev(dhcpserv);
    Serial.print(F("\nDNSserv: ")); cc3000.printIPdotsRev(dnsserv);
    Serial.println();
      udpclient = cc3000.connectUDP(gateway, port);
      if (udpclient.connected()) {
         udpclient.fastrprint(F("Connected!"));
         uint8_t *ipAddr = (uint8_t*) &ipAddress;
         char buf[16];
         sprintf(buf, "%d.%d.%d.%d", ipAddr[3], ipAddr[2], ipAddr[1],ipAddr[0]);
        udpclient.fastrprint(buf);
      }
         udpclient.close();
    return true;
  }}


//************************************************************************************* Setup Function
void WiFiSend_SetupFunction () {
    Serial.begin(115200);
   // Initialise the module
  Serial.println(F("\nInitializing..."));
  if (!cc3000.begin())
  {
    Serial.println(F("Couldn't begin()! Check your wiring?"));
    while(1);
  }
  
  Serial.print(F("\nAttempting to connect to ")); Serial.println(WLAN_SSID);
  if (!cc3000.connectToAP(WLAN_SSID, WLAN_PASS, WLAN_SECURITY)) {
    Serial.println(F("Failed!"));
    while(1);
  }
   
  Serial.println(F("Connected!"));

  Serial.println(F("Request DHCP"));
  while (!cc3000.checkDHCP())
  {
    delay(100); // ToDo: Insert a DHCP timeout!
  }  

  // lay the IP address DNS, Gateway, etc.  
  while (! displayConnectionDetails()) {
    delay(1000);
  }
    udpclient = cc3000.connectUDP(gateway, port);
}

//*************************************************************************************Loop Function
void WiFiSend_LoopFunction () {

     if (udpclient.connected()) {
     udpclient.print(
     "MotorSpeed:\t"+String(filteredPos)+"\t(m/s)\n"
     +"MotorOrder:\t"+String(MotorOrder)+"\t(Parameter2_UNIT)\n"
     );
  }
}
