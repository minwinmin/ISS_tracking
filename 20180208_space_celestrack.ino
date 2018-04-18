#include <Nefry.h>
#include <HTTPClient.h> // HTTP-GETのために必要
#include <ArduinoJson.h>

void setup() {
  
  //Serial.begin(115200);
  //Serial.println("start");
}

void loop() {
  String payload = ""; 
  HTTPClient http; 
  int httpCode; 
  StaticJsonBuffer<200> jsonBuffer;
  
  http.begin("https://celestrak.com/NORAD/elements/tle-new.txt");

  // その結果を保存
  httpCode = http.GET();//ちゃんと読み込めたどうかの情報が入っている
  
 
  
  if (httpCode == HTTP_CODE_OK) {
    // 成功だったら、運行情報の文字列を取得して保存
    payload = http.getString();
    //jsonデコードなるもの行う必要がある
    //char* json = new char[payload.length() + 1];
    //payload.toCharArray(json, payload.length() + 1);
    //JsonObject& root = jsonBuffer.parseObject(json);
     
    //Nefry.println("接続成功");
    Nefry.println(payload);
    //下記でパースで来ていない
    //double latitude = root["iss_position"]["latitude"];
    //double longitude = root["iss_position"]["longitude"];

    //Nefry.println(latitude);
    //Nefry.println(longitude);

    //Serial.println(latitude,longitude);
    
    
  } else {
    // 失敗だったら、エラーコードをログに出力
    Nefry.println("接続失敗");
    Nefry.println(http.errorToString(httpCode));
  }

  
   
  delay(1000);
}
