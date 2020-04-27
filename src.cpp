#include <SoftwareSerial.h>
int led = 3;
int pinOut1 = 5;
int pinOut2 = 6;
int pinOut3 = 12;
int pinOut4 = 11;
char bluetooth = 0;
SoftwareSerial BTSerial(4,5);

void setup(){
	Serial.begin(9600);
    BTSerial.begin(38400);
    BTSerial.print("AT\r\n"); //Check Status
    delay(500);
	pinMode(pinOut1, OUTPUT);
	pinMode(pinOut2, OUTPUT);
	pinMode(pinOut3, OUTPUT);
	pinmode(pinOut4, OUTPUT);
	pinMode(led, OUTPUT);
    //To send sensor data through our BT module
    while (BTSerial.available()){
    	Serial.write(BTSerial.read());
    }
    BTSerial.print(setName);
    delay(500);
    while (BTSerial.available()){
    	Serial.write(BTSerial.read());
    }
}

void loop(){
		if (Serial.available() > 0){
			bluetooth = Serial.read();
			digitalWrite(led, 1);
			if (bluetooth == 'F'){          //Forward Movement
				digitalWrite(pinOut1, HIGH);
				digitalWrite(pinOut2, LOW);
				digitalWrite(pinOut3, HIGH);
				digitalWrite(pinOut4, LOW);
			}
			else if (bluetooth == 'B'){     //Backwards Movement
				digitalWrite(pinOut1, LOW);
				digitalWrite(pinOut2, HIGH);
				digitalWrite(pinOut3, LOW);
				digitalWrite(pinOut4, HIGH);
			}
			else if (bt == 'R'){            //Turn Right 
				digitalWrite(outPin1, HIGH);
				digitalWrite(outPin2, LOW);
				digitalWrite(outPin3, LOW);
				digitalWrite(outPin4, LOW);
			}   
            else if (bt == 'L'){    	    //Turn Left  
				digitalWrite(outPin1, LOW);
				digitalWrite(outPin2, LOW);
				digitalWrite(outPin3, HIGH);
				digitalWrite(outPin4, LOW);
			}
		}
