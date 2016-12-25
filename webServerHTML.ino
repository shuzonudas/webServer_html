#include <ESP8266WiFi.h> 
#include <ESP8266WebServer.h> 

const char* ssid = "BTCL ADSL";
const char* password = "UHUBFJ2DNG";

ESP8266WebServer server(80);

void handleRoot() 
{
	char temp[400];

	snprintf(temp, 400,
		"<html>\
  <head>\
  </head>\
    <body>\
    <h1>How to html page really good</h1>\
    <a href =\"/0\">Turn OFF</a>\
    <a href =\"/1\">Turn ON</a>\
    <a href =\"/1\"> <button> Turn ON</button> </a>\
    <a href =\"/0\"> <button> Turn OFF</button> </a>\
  </body>\
</html>");
	server.send(200, "text/html", temp);
//	server.send(200, "text/plain", "I'm an awasome webServer!!!");

}


void ledOn() {
	server.send(200, "text/plain", "turn on the LED!!!");
	pinMode(16, OUTPUT);
	digitalWrite(16, HIGH);
}

void ledOff() {
	server.send(200, "text/plain", "Turn off the LED");
	pinMode(16, OUTPUT);
	digitalWrite(16, LOW);
}

void Flash() {

	server.send(200, "text/plain", "LED flashing");

	pinMode(16, OUTPUT);
	digitalWrite(16, HIGH);
	delay(500);
	digitalWrite(16, LOW);
	delay(500);
	digitalWrite(16, HIGH);
	delay(500);
	digitalWrite(16, LOW);
	delay(500);
	digitalWrite(16, HIGH);
	delay(500);
	digitalWrite(16, LOW);
	delay(500);
	digitalWrite(16, HIGH);
	delay(500);
	digitalWrite(16, LOW);
	delay(500);
}

void LEDdim()
{
	pinMode(16, OUTPUT);
	analogWrite(16, 200);
}
void setup(void) {

	Serial.begin(115200);
	Serial.print("Connecting to network");
	WiFi.mode(WIFI_STA);
	WiFi.begin(ssid, password);   // Connect to WiFi network

	while (WiFi.status() != WL_CONNECTED) {    // Wait for connection
		delay(500);
		Serial.print(".");
	}

	Serial.print("Connected to ");
	Serial.println(ssid);
	Serial.print("IP address: ");
	Serial.println(WiFi.localIP());

	server.on("/", handleRoot);
	server.on("/0", ledOff);
	server.on("/1", ledOn);
	server.on("/2", Flash);
	server.on("/3", LEDdim);

	server.begin();
	Serial.println("HTTP server started");
}

void loop(void)
{
	server.handleClient();
}
