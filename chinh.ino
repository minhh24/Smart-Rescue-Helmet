/*************************************************** 
  Kết nối:
            MPU6050                  UNO R3              MEGA
              VIN                     5V                 5V
              GND                     GND                GND
              SCL                     A5                 SCL
              SDA                     A4                 SDA
// Pins d7 TX, d8 RX are used as used as software serial pin A9G
// ancol A0
// tien can d4
  Nạp code mở Serial Monitor chọn No line ending, baud 9600.
 ****************************************************/

 
int x=0, y=0, tn=0;
#include "OneButton.h" 
  int tc= 4;                        
int but = 12; 

int gtbut;

OneButton button(but, true);                       

int coi2 = A3;
int coi = A2; int trangthai_coi = LOW;
int dem1=0; int dem2=0; int dem3=0;

#include <MPU6050_tockn.h>
#include <Wire.h>
MPU6050 mpu6050(Wire);

  
 #include <SoftwareSerial.h> 
SoftwareSerial SIM900(7, 8);

String incomingData;   // for storing incoming serial data
//String message = "";   // A String for storing the message
//int relay_pin = 2;    // Initialized a pin for relay module
char msg;
char call;


void setup() {

    pinMode(tc, INPUT);
    
    Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);

   SIM900.begin(115200); // baudrate for GSM shield

   
  Serial.begin(9600);
  pinMode(coi, OUTPUT);                                                   
  pinMode(coi2, OUTPUT);  

  
//  button.attachDoubleClick(nhan_double);  //Kích hoạt lệnh khi nhấn liên tục 2 lần      bo 
//  button.attachClick(nhan_don);   //Kích hoạt lệnh khi nhấn 1 lần rồi nhả               bo
   button.attachLongPressStart(nhan_giu); //Kích hoạt lệnh khi nhấn giữ 1s          
  //attachDuringLongPress Kích hoạt lệnh liên tục miễn là còn nhấn nút                    bo  
  //attachLongPressStop Kích hoạt lệnh khi nút nhận được nhả ra                           bo
  //attachMultiClick Thực hiện lệnh sau khi nhiều lần nhấn                                bo

  digitalWrite(coi, trangthai_coi);

  Serial.println("GSM SIM900A BEGIN");
  Serial.println("Enter character for control option:");
  Serial.println("h : cup may");
  Serial.println("i : nghe masy");
  Serial.println("s : gui tn");
  Serial.println("c : goi");  
  Serial.println("e : goi lai");
  Serial.println("l : tra ve gps");
  Serial.println();
  delay(100);
   /*SIM900.println("AT+GPS=1");
  delay(100);
  SIM900.println("AT+GPSRD=5");
  delay(5000);*/
  
  // set SMS mode to text mode
  SIM900.print("AT+CMGF=1\r");  
  delay(100);
  
  // set gsm module to tp show the output on serial out
  SIM900.print("AT+CNMI=2,2,0,0,0\r"); 
  delay(100);

  
  Serial.begin(9600);
}

void loop() {

 
    receive_message();
         
    mpu6050.update();

    incomingData = SIM900.readString(); // Get the data from the serial port.  
     Serial.print(incomingData); 
     
      if(incomingData.indexOf("RING") != -1){
          ReceiveCall();
          tnnguoinha();
          
      }   
      
  Serial.print("angleX : ");
  Serial.print(mpu6050.getAngleX());
  Serial.print("\tangleY : ");
  Serial.println(mpu6050.getAngleY());
  delay(0);
   mpu6050.update();
   
        if( digitalRead(tc)== 0){
          delay(20);
          if( digitalRead(tc)== 0){
          delay(20);
          if( digitalRead(tc)== 0){
          delay(20);
          if( digitalRead(tc)== 0){
            
          delay(20);
          if( digitalRead(tc)== 0){
          delay(20);
          if( digitalRead(tc)== 0){
          delay(20);
          
       gtbut = digitalRead(but);
  //Serial.print("Nút nhấn: "); Se rial.println(gtbut);  
  button.tick(); //Kiểm tra trạng thái nút nhấn    
               
     receive_message();
    mpu6050.update();

     incomingData = SIM900.readString();     // Get the data from the serial port.  
     Serial.print(incomingData); 
     
      if(incomingData.indexOf("RING") != -1){
          ReceiveCall();
          tnnguoinha();
          
      }

  
       
   mpu6050.update();
   delay(0);
   mpu6050.update();
   delay(0);
   mpu6050.update();
   delay(0);
   
   mpu6050.update();
  Serial.print("angleX : ");
  Serial.print(mpu6050.getAngleX());
  Serial.print("\tangleY : ");
  Serial.println(mpu6050.getAngleY());
  
 
           
           if(mpu6050.getAngleX() > 100 ||mpu6050.getAngleX() <-100 ||mpu6050.getAngleY() >100 || mpu6050.getAngleY() <-100){
            delay(0);
            mpu6050.update();
            
           if(mpu6050.getAngleX() > 100 ||mpu6050.getAngleX() <-100 ||mpu6050.getAngleY() >100 || mpu6050.getAngleY() <-100){
            delay(2000);
            mpu6050.update();
            
            if(mpu6050.getAngleX() > 100 ||mpu6050.getAngleX() <-100 ||mpu6050.getAngleY() >100 || mpu6050.getAngleY() <-100){
              if(tn ==0 && digitalRead(tc)== 0){                        
              tntainan();
              
              
             }
        }
        }
        
        }
     
  Serial.println(analogRead(A0)); // cb con
//    ReceiveCall();
//  receive_message();
  
  if(analogRead(A0) > 400){
    tnsay();
  }


  } 
}
          }
          }
          }
        } else Serial.print("                    doi len dau dee        ");  
}



void receive_message() //doc tn
  {
    if (SIM900.available() > 0)
    {
      incomingData = SIM900.readString(); // Get the data fro  the serial port.
      Serial.print(incomingData); 
      delay(10); 
    }
  }
 
  void tntainan() //gui tn
  {
       Serial.print("sap goi tai nan");
    
    for (int i=0; i<=4; )  {
       digitalWrite(coi,HIGH);
    delay(100);
    digitalWrite(coi,LOW);
    delay(100);
   digitalWrite(coi,HIGH);
    delay(100);
    digitalWrite(coi,LOW);
    delay(1000);
    i++;
    }
        
        SIM900.println("ATD+84916254336;"); 
    Serial.println("Calling  "); 
    delay(1000);     
    
    SIM900.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
    delay(1000);                    // Delay of 1000 milli seconds or 1 second
    SIM900.println("AT+CMGS=\"+84916254336\"\r"); // Replace x with mobile number
    delay(1000);
    SIM900.println("toi dang bi tai nan tai:  https://www.google.com/maps/place/12.686424,%20108.046166 ");
    delay(100);
     SIM900.println((char)26);
    delay(1000);   

      for (int i=0; i<=300; )  {
       digitalWrite(coi,HIGH);
    delay(90);
    digitalWrite(coi2,LOW);
    delay(100);
   digitalWrite(coi,HIGH);
    delay(90);
     digitalWrite(coi2,HIGH);
    delay(100);
   digitalWrite(coi,LOW);
    delay(90);
    digitalWrite(coi2,HIGH);
    delay(100);
    digitalWrite(coi,LOW);
    delay(90);
    
    i++;
    }
    
  }

  void tnnguoinha(){
    
        Serial.print("nguoi nha goi");
    SIM900.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
    delay(1000);                    // Delay of 1000 milli seconds or 1 second
    SIM900.println("AT+CMGS=\"+84916254336\"\r"); // Replace x with mobile number
    delay(1000);
    SIM900.println("thiet bi dang o: https://www.google.com/maps/place/12.686424,%20108.046166 ");
    delay(100);
     SIM900.println((char)26);
    delay(1000);
  }
  
  void tncuop()
  {
    for (int i=0; i<=3; )  {
       digitalWrite(coi,HIGH);
    delay(100);
    digitalWrite(coi,LOW);
    delay(100);
   digitalWrite(coi,HIGH);
    delay(100);
    digitalWrite(coi,LOW);
    delay(500);
    i++;
    }


        Serial.print("bi cuop ");
    SIM900.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
    delay(1000);  // Delay of 1000 milli seconds or 1 second
    SIM900.println("AT+CMGS=\"+84916254336\"\r"); // Replace x with mobile number
    delay(1000);
    SIM900.println("toi dang bi cuop tai: https://www.google.com/maps/place/12.686424,%20108.046166 ");// The SMS text you want to send
    delay(100);
     SIM900.println((char)26);// ASCII code of CTRL+Z
    delay(1000);
  }

  void tnsay(){
    Serial.print("say roiii ");
    SIM900.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
    delay(100);  // Delay of 1000 milli seconds or 1 second
    SIM900.println("AT+CMGS=\"+84916254336\"\r"); // Replace x with mobile number
    delay(100);
    SIM900.println("nguoi nha cua ban bi say ruou tai: https://www.google.com/maps/place/12.686424,%20108.046166 ,     neu dieu khien phuong tien co the nguy hiem den tinh mang.");// The SMS text you want to send
    delay(100);
     SIM900.println((char)26);// ASCII code of CTRL+Z
    delay(100);
  }
  
  void ReceiveMessage()  //nhan tn
  {
    SIM900.println("AT+CNMI=2,2,0,0,0"); // AT Command to recieve a live SMS
    delay(100);
    if (SIM900.available()>0)
    {
      msg=SIM900.read();
      Serial.print(msg);
    }
  }
  
  void MakeCall() //goi
  {
    SIM900.println("ATD+84916254336;"); // ATDxxxxxxxxxx; -- watch out here for semicolon at the end, replace your number here!!
    Serial.println("Calling  "); // print response over serial port
    delay(100);
  }
  
  
  void HangupCall()  //cup may
  {
    SIM900.println("ATH");
    Serial.println("Hangup Call");
    delay(100);
  }
  
  void ReceiveCall()// nghe
  {
    SIM900.println("ATA");
    delay(100);
    {
      call=SIM900.read();
      Serial.print(call);
    }
  }
  
  void RedialCall() // goi lai
  {
    SIM900.println("ATDL");
    Serial.println("Redialing");
    delay(100);
  }
  void ReadLocation() //no toa do
  {
  
    SIM900.println("AT+GPS=1");
    delay(100);
    SIM900.println("AT+GPSRD=5");
    delay(100);
   
    }

 void nhan_giu()
{                                   
 dem2 += 1;     
  Serial.print("Đếm 2: "); Serial.println(dem2); 
  
    Serial.print("sapgoi");
    
    for (int i=0; i<=3; )  {
       digitalWrite(coi,HIGH);
    delay(100);
    digitalWrite(coi,LOW);
    delay(100);
   digitalWrite(coi,HIGH);
    delay(100);
    digitalWrite(coi,LOW);
    delay(500);
    i++;
    }
        
        SIM900.println("ATD+84916254336;"); // ATDxxxxxxxxxx; -- watch out here for semicolon at the end, replace your number here!!
    Serial.println("Calling  "); // print response over serial port
    delay(1000);     

           Serial.print("bi cuop ");
    SIM900.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
    delay(1000);  // Delay of 1000 milli seconds or 1 second
    SIM900.println("AT+CMGS=\"+84916254336\"\r"); // Replace x with mobile number
    delay(1000);
    SIM900.println("toi dang bi cuop tai: https://www.google.com/maps/place/12.686424,%20108.046166 ");// The SMS text you want to send
    delay(100);
     SIM900.println((char)26);// ASCII code of CTRL+Z
    delay(1000);  
}
