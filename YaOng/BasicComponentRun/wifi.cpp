// YaOng BS1004
// Board : ESP32 Dev Module (esp32 by Espressif 2.0.16)
// wifi.cpp

// 참고 : https://microcontrollerslab.com/esp32-wi-fi-manager-asyncwebserver/, https://forum.arduino.cc/t/esp32-switch-sta-with-ap/1112471, https://blog.naver.com/alfee0/223393634853, https://velog.io/@kksp12y/ESP32AccessPointAP, https://bota.tistory.com/2157, 
#include "header.h"
/*
setup : 
  connectWifiSTA();
  setWifiAp();
  server.begin();
*/
void fixIpAddress(boolean isApMode) {
  IPAddress ip(192, 168, WIFI_FIX_THIRD_NUMBER, WIFI_FIX_FOURTH_NUMBER);  //고정 IP 지정
  IPAddress gateway(192, 168, 0, 1);
  IPAddress subnet(255, 255, 255, 0);
  if (isApMode) {
    WiFi.softAPConfig(ip, gateway, subnet);  //내가 원하는 설정 반영
  } else {
    WiFi.config(ip, gateway, subnet);  //내가 원하는 설정 반영
  }
}
void setWifiAp() {
  Serial.print("Setting AP (Access Point)...");
  WiFi.mode(WIFI_AP);

  // fixIpAddress(true);
  boolean apResult = WiFi.softAP(WIFI_AP_SSID, WIFI_AP_PASSWORD);
  if (!apResult) {
    Serial.println("soft ap failed.");
  }

  IPAddress IP = WiFi.softAPIP();
  Serial.println(String("soft-AP IP adderss: ") + IP.toString());
  Serial.println(String("MAC Address: ") + WiFi.softAPmacAddress().c_str());
}
void connectWifiSTA() {

  // WiFi 접속을 시작한다.
  Serial.println(String("Connecting to") + WIFI_SSID);
  fixIpAddress(false);
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  // 즉 begin을 하면 사용자가 어떤 제지를 할 때까지는 계속 접속을 시도한다.
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(String("\nWiFi connected. IP address: ") + WiFi.localIP().toString());
  // WiFi에 연결이되고 DHCP로 IP를 받아오면 WiFi.localIP()확인할 수 있다.
}
void listenClient(WiFiClient client) {
  // loop()에서 이전에 실행시킬 코드 : WiFiClient client = server.available();  
  // 만약 client가 없다면 종료
  if (!client) {
    return;
  }
  Serial.println("New Client.");  // print a message out the serial port
  String currentLine = "";        // 클라이언트에서 들어오은 데이터를 저장할 빈 문자열
  String headerLine = "";        // url라인만 저장할 빈 문자열
  while (client.connected()) {    // 클라이언트가 연결된동안 반복
    if (client.available()) {     // 만약 읽을 byte가 있을 경우
      char c = client.read();     // 읽고,
      Serial.write(c);            // 시리얼 출력
      headerLine += c;
      if (c == '\n') {            // "\n" 이 들어오면
        // if the current line is blank, you got two newline characters in a row.
        // that's the end of the client HTTP request, so send a response:
        // 접속한 클라이언트에서의 명령이 없다면 헤더를 출력
        if (currentLine.length() == 0) {  // 줄이 비어있으면 줄바꿈 문자가 두개 연속임
          printClintWebpageHrefLED(client);
          break;
        } else {  // if you got a newline, then clear currentLine:
          currentLine = "";
        }
      } else if (c != '\r') {  // if you got anything else but a carriage return character,
        currentLine += c;      // add it to the end of the currentLine
      }
      orderLEDWithCurrentLine(currentLine);
    }
  }
  // 처리가 끝나면 client와의 연결을 끊는다.
  headerLine = "";
  client.stop();
  Serial.println("Client Disconnected.");
}
void printClintWebpageHrefLED(WiFiClient client) {
  // HTTP 해더는 항상 응답코드로 시작(e.g. HTTP/1.1 200 OK)
  client.println("HTTP/1.1 200 OK");
  client.println("Content-type:text/html");
  client.println();

  // the content of the HTTP response follows the header:
  // 클라이언트 화면에 문자열 2개를 출력한다.
  client.print("Click <a href=\"/H\">here</a> to turn the LED on pin 5 on.<br>");
  client.print("Click <a href=\"/L\">here</a> to turn the LED on pin 5 off.<br>");

  // The HTTP response ends with another blank line:
  client.println();
}
void printClientWebpageButtonLED(WiFiClient client, String headerLine) {
  String output2State = "off";
  client.println("HTTP/1.1 200 OK");
  client.println("Content-type:text/html");
  client.println("Connection: close");
  client.println();
  if (headerLine.indexOf("GET /2/on") >= 0) {
    Serial.println("GPIO 2 on");
    output2State = "on";
    digitalWrite(LED_PIN, HIGH);
  } else if (headerLine.indexOf("GET /2/off") >= 0) {
    Serial.println("GPIO 2 off");
    output2State = "off";
    digitalWrite(LED_PIN, LOW);
  }
  client.println("<!DOCTYPE html><html>");
  client.println("<head><meta name=\"viewport\" content=\"width=device-width, inital-scale=1\">");
  // css
  client.println("<link rel=\"icon\" href=\"data:,\">");
  client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
  client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
  client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
  client.println(".button2 {background-color: #555555;}</style></head>");
  // 제목
  client.println("<h1>ESP32 Web Server</h1>");
  client.println("<p>GPIO 2 - State " + output2State + "</p>");
  if (output2State == "off") {
    client.println("<p><a href=\"/2/on\"><button class=\"button\">ON</button></a></p>");
  } else {
    client.println("<p><a href=\"/2/off\"><button class=\"button button2\">OFF</button></a></p>");
  }
  client.println("</body></html>");

  client.println();
}
void orderLEDWithCurrentLine(String currentLine) {
  // Check to see if the client request was "GET /H" or "GET /L":
  // request가 H인지 L인지에 따라 명령울 수행한다.
  if (currentLine.endsWith("GET /H")) {
    digitalWrite(LED_PIN, HIGH);  // GET /H turns the LED on
  }
  if (currentLine.endsWith("GET /L")) {
    digitalWrite(LED_PIN, LOW);  // GET /L turns the LED off
  }
}

void scanWifi() {
  /*
  setup: 
      // Set WiFi to station mode and disconnect from an AP if it was previously connected
    WiFi.mode(WIFI_STA);  // WiFi_STA와 WiFi_AP 모드, 이를 합친 WiFi_STA+WiFi_AP 모드가 존재
    WiFi.disconnect();
  */
  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  //스캔한 Wifi 이름 WiFi.SSID(i), 세기 WiFi.RSSI(i), 보안 상태  WiFi.encryptionType(i)들을 저장
  for (int i = 0; i < n; ++i) {
    // Print SSID and RSSI for each network found
    Serial.print(WiFi.SSID(i));
    Serial.println(WiFi.RSSI(i));
  }
  Serial.println("...............");
  delay(1000);
}
