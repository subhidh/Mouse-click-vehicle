// Motor A

int enA=9;
int in1=8;
int in2=7;

// Motor B

int enB = 3;
int in3 = 4;
int in4 = 5;
int data,datas ;

void setup()

{
  Serial.begin(9600);

  pinMode(enA,OUTPUT);
  pinMode(enB,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  
}

void demoForward()
{
  
  analogWrite(enA,250);
  analogWrite(enB,250);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  delay(2000);

}

void demobackward()
{
   analogWrite(enA,200);
   analogWrite(enB,200);
   digitalWrite(in1,LOW);
   digitalWrite(in2,HIGH);
   digitalWrite(in3,LOW);
   digitalWrite(in4,HIGH);

    delay(2000);

    
}
     
void demoStop()
{

  //now turn off motro
   analogWrite(enA,200);
   analogWrite(enB,200);

   digitalWrite(in1,LOW);
   digitalWrite(in2,LOW);
   digitalWrite(in3,LOW);
   digitalWrite(in4,LOW);

}

void demoRight()

{

   analogWrite(enA,200);
   analogWrite(enB,200);
   digitalWrite(in1,HIGH);
   digitalWrite(in2,LOW);
   digitalWrite(in3,LOW);
   digitalWrite(in4,LOW);
   delay(500);

   digitalWrite(in1,HIGH);
   digitalWrite(in2,LOW);
   digitalWrite(in3,HIGH);
   digitalWrite(in4,LOW);

   delay(2000);
   
}

void demoLeft()
{
   analogWrite(enA,200);
   analogWrite(enB,200);
   digitalWrite(in1,LOW);
   digitalWrite(in2,LOW);
   digitalWrite(in3,HIGH);
   digitalWrite(in4,LOW);
   delay(500);

   digitalWrite(in1,HIGH);
   digitalWrite(in2,LOW);
   digitalWrite(in3,HIGH);
   digitalWrite(in4,LOW);

   delay(2000);
  
 }

void loop()
{

  if(Serial.available()>0)
  {
    datas=Serial.read();
    Serial.print(data);
    Serial.print("\n");
    data=datas%1000;
     if(data=='1')
    
     {
        demoForward();
        delay(datas);
       demoStop(); 
     }


     else if(data=='2')
    
     {
      demobackward();
     }


     else if(data=='3')
    
      {
       demoStop();
      }
      

      else if(data=='4')
    
      {
       demoRight();
      }

    
      else if(data=='5')
    
      {
       demoLeft();
      }
  
  }
}
