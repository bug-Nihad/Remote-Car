 #include <SoftwareSerial.h> 

int tx = 8;
int rx = 7;

SoftwareSerial MyCar(rx, tx);

void setup(){
   
    Serial.begin(9600);
    MyCar.begin(9600);
    pinMode(2, OUTPUT);
    pinMode(3, INPUT);
    pinMode(4, INPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, INPUT);
    pinMode(13, OUTPUT); 
}





void Turn(int x, int y, int z, int time){
    digitalWrite(x, HIGH);
    digitalWrite(y, LOW);
    analogWrite(z, 100);
    delay(time);
    digitalWrite(x, LOW);
}


void leftTurn(){
    Turn(7, 8, 6, 5000);
}
// void rightTurn(){
//     Turn(9, 10, 11, 5000);
// }


void instantRightTurn(int time){
    //Serial.println("Right");
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    analogWrite(11, 70);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    analogWrite(6, 100);
    delay(time);
    digitalWrite(10, LOW);
    digitalWrite(7, LOW);
}

void instantLeftTurn(int time){
    digitalWrite(9, HIGH);  //Right motor
    digitalWrite(10, LOW);
    analogWrite(11, 70 + 10);
    digitalWrite(7, LOW);   //Left motor
    digitalWrite(8, HIGH);
    analogWrite(6, 40);
    delay(time);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
}

void goForward(int time){
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    analogWrite(11, 62);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    analogWrite(6, 70);
    delay(time);
    digitalWrite(9, LOW);
    digitalWrite(7, LOW);
}



char ch;
void loop()
{
    if (MyCar.available())
    {
        ch = MyCar.read();
        if (ch == 'a')
        {
            instantLeftTurn(100);

        }
        if (ch == 'a')
        {
            instantRightTurn(100);
                    
        }
        if (ch == 'a')
        {
            goForward(100);
                    
        }
        
    }
    
     
}
