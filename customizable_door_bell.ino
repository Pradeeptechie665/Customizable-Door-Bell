#include <SD.h>                       // include the SD library
#define SD_ChipSelectPin 10            // using digital pin 10 on arduino uno 328, can use other pins
#include <TMRpcm.h>                   // also include this library
#include <SPI.h>

TMRpcm tmrpcm;

void setup()
{
tmrpcm.speakerPin=9;  //output pin given to speaker
pinMode(8,INPUT);          //input from doorbell switch
                                
Serial.begin(9600);   //used to read data on serial monitor
if(!SD.begin(SD_ChipSelectPin))
{
  Serial.println("SD fail");
  return;
}
tmrpcm.setVolume(5);  //you can set volume here
}

void loop() 
{
 int a=digitalRead(8); // this is the code that will play sound when anyone presses the bell
 if(a==0){play();}
 if(a==1){return;}
}
void play()
{
  tmrpcm.play("test.wav");  //test.wav is the name of the sound file (keep in mind file should be of .wav format)
  return;
}
