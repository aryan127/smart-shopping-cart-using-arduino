

#define LED 13

boolean stringComplete = false;
String inputString = "";
int n = 0;
int total=0;
int flag1=0;
int flag2=0;

void setup() {
  Serial.begin(9600);
  Serial.println("******************************************************************************************");
  Serial.println("                                    WELCOME TO                                            ");
  Serial.println("                              SMART BILLING SYSTEM                                        "); 
  Serial.println("******************************************************************************************");
  Serial.println("                         SWIPE THE REGISTER THE MASTER CARD                               ");
  Serial.println("******************************************************************************************"); 
}

void loop() {
  
  //Serial.print("                       TOTAL =                                                          "); 
  //Serial.println(total);
  if (stringComplete) {
   
    if (inputString.equals("01002B7CF0A6") && flag1==0) { //Replace your tag ID
      Serial.println(" _________________________________");
      Serial.println(" |    ITEM ADD TO CART           |");
      Serial.println(" |    DAL 250gm                  |");
      Serial.println(" |    PRICE IS 200/-             |");
      total=total+200;
      Serial.print(" |     TOTAL =                ");
      Serial.print(total);
      Serial.println(" |");
      Serial.println(" _________________________________");
      delay(3000);
      flag1=1;
      
      
    }
   else if (inputString.equals("01002B7CF0A6") && flag1==1) { //Replace your tag ID
      Serial.println(" _________________________________");
      Serial.println(" |    REMOVED FROM CART          |");
      Serial.println(" |    DAL 250gm                  |");
      Serial.println(" |    PRICE IS 200/-             |");
      total=total-200;
      Serial.print(" |     TOTAL =                ");
      Serial.print(total);
      Serial.println("   |");
      Serial.println(" _________________________________");
      delay(3000);
      flag1=0;
      
      
    }
   
    if (inputString.equals("01002BDDA651") && flag2==0) { ////Replace your tag ID
      Serial.println(" _________________________________");
      Serial.println(" |    ITEM IS ADDED              |");
      Serial.println(" |    SUGER 500gm                |");
      Serial.println(" |    PRICE IS 50/-             |");
      total=total+50;
       Serial.print(" |     TOTAL =               ");
      Serial.print(total);
      Serial.println(" |");
      Serial.println(" _________________________________");
      delay(3000);
      flag2=1;
     // digitalWrite(LED, LOW);
    }
    else if (inputString.equals("01002BDDA651") && flag2==1) { ////Replace your tag ID
      Serial.println(" _________________________________");
      Serial.println(" |    ITEM IS REMOVED            |");
      Serial.println(" |    SUGER 500gm                |");
      Serial.println(" |    PRICE IS 50/-              |");
      total=total-50;
       Serial.print(" |     TOTAL =                 ");
      Serial.print(total);
      Serial.println("   |");
      Serial.println(" _________________________________");
      delay(3000);
      flag2=0;
      
     // digitalWrite(LED, LOW);
    }
    


    stringComplete = false;
    inputString = "";
  }
}

void serialEvent() {
  while (Serial.available()) {
    n++;
    char inChar = (char) Serial.read();
    inputString += inChar;
    if (n >= 12) {
      n = 0;
      stringComplete = true;
    }
  }
}
