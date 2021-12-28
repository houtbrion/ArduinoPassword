

/*
 * テスト用サンプルパスワード "Keccak" (SHA3の元の名前)
 */

//char sample_user_name[]="bar";
//char sample_passwd_str[]="Keccak";
//char sample_user_name[]="foo";
//char sample_passwd_str[]="bar";
char sample_user_name[]="hoge";
char sample_passwd_str[]="foo";

#define CHIP_SELECT 4

#include <ArduinoPassword.h>

Passwd passwdDB;

/*
 * 
 */
void setup() {
  Serial.begin(9600); // ハードウェアシリアルを準備
  while (!Serial) {
    ; // シリアルポートの準備ができるのを待つ(Leonardoのみ必要)
  };
  passwdDB.begin(CHIP_SELECT);
  passwdDB.init("pass.txt");
  
  if (passwdDB.CheckPasswd(sample_user_name,sample_passwd_str)) {
    Serial.println("match");
  } else {
    Serial.println("miss match");
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
