#include <LiquidCrystal.h>
#define change_btn 10
#define select_btn 9
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int hour = 0;
int minute = 0;
void setup() {
  

  pinMode (change_btn,INPUT_PULLUP); 
  pinMode (select_btn,INPUT_PULLUP);
  
  pinMode (8,OUTPUT);   //OUTPUT to RELAY
  digitalWrite(8,LOW);

  pinMode (7,OUTPUT);//OP to 2nd relay
  digitalWrite(7, LOW); //LOGIC REVERSED

  
  pinMode (6,OUTPUT); //GND
  digitalWrite(6, LOW);
  
  lcd.begin(16, 2);
  lcd.print("GADGET HANDLER!");
  delay(2000);
  lcd.setCursor(0,2);
  delay(2500);
}

void loop() 
{
lcd.clear();
lcd.print("1.COUNTDOWN MODE");
delay(1000);
lcd.setCursor(0,1);
lcd.print("2.COOLER MODE");
delay(1000);
lcd.clear();
lcd.print("Enter Choice !!");
delay(2000);  

int count = 0;                                  
while(digitalRead(select_btn) == HIGH)      //Till Ok button(butt_2) is pressed!
  {
    if(digitalRead(change_btn) == LOW)    //Mode select button i.e butt_1
      {
        delay(300);
        count++;                                //Increment if butt_1 is pressed
      }
    
    lcd.clear();
    lcd.print("YOUR CHOICE: ");                      //Loops the same output on the screen until an input is provided 
    lcd.print(count);
    delay(50);
  }
    switch(count)
      {
        case 1:
        {
          countdown();//TIMER MODE
        }
        break;
        
        case 2:                               //logic 
        {
            cooler();
        }
        break;
       default:
        lcd.print("INVALID CHOICE");
        }
}

void countdown()
{
        hour = 0;
        minute = 0;  
        lcd.clear();
        lcd.print("Enter Hours");
        delay(2000);

        while(digitalRead(select_btn) == HIGH)      //Until Ok button is pressed
          {
            if(digitalRead(change_btn) == LOW)    //When button 1 pressed Hr count increases
              {
                delay(300);
                hour++;
              }
              
            lcd.clear();
            lcd.print(hour);                            //Continuosly print Hr value
            delay(50);
          }
 
        lcd.clear();
        lcd.print("Enter Minutes");                     // same as of hour
        delay(2000);
        while(digitalRead(select_btn) == HIGH)
           {
            if(digitalRead(change_btn) == LOW)
              {
                delay(300);
                minute++;
              }
            lcd.clear();
            lcd.print(minute);
            delay(50);
           }
      
         delay(1000);

        int e2 = minute;
        int e3 = 0;
         for(int e1 = hour; e1 >= 0; e1--)            //Start printing timer
           {
              for(e2 ; e2 >=0; e2--)
              {
                for(e3 ; e3 >= 0; e3--)        //logic
                  {
                    digitalWrite(8,HIGH);
                    lcd.clear();
                    lcd.print("Time Left:");
                    lcd.setCursor(0,1);
                    lcd.print(e1);
                    lcd.print(":");
                    lcd.print(e2);
                    lcd.print(":");
                    lcd.print(e3);
                    delay(1000);
                  }
             
                e3 = 59;
              }
             
              e2 = 59; 
          }
      
          lcd.print("Time Finished");
          digitalWrite(8,LOW);          
          delay(100);
}

void cooler()
{
          lcd.clear();
          lcd.print("COOLER MODE");
          delay(2000);
          lcd.clear();
          lcd.print("ACTIVE TIME?");                
          delay(2000);
          int act_minute = 0;
          int inact_minute = 0;
          while(digitalRead(select_btn) == HIGH)
           {
            if(digitalRead(change_btn) == LOW)
              {
                delay(300);
                act_minute++;
              }
            lcd.clear();
            lcd.print(act_minute);
            delay(50);
           }
           
          lcd.clear();
          lcd.print("INACTIVE TIME?");                
          delay(2000);
          while(digitalRead(select_btn) == HIGH)
           {
            if(digitalRead(change_btn) == LOW)
              {
                delay(300);
                inact_minute++;
              }
            lcd.clear();
            lcd.print(inact_minute);
            delay(50);
           }
           
          while(1)
          {
            int active_mins = act_minute;
            int inactive_mins = inact_minute;
            int e4 = 0;
            for(active_mins ; active_mins >=0; active_mins--)
              {
                for(e4 ; e4 >= 0; e4--)
                  {
                    lcd.clear();
                    lcd.print("ACTIVE FOR: ");
                    delay(200);
                    digitalWrite(7,LOW);
                    lcd.setCursor(0,1);
                    lcd.print(active_mins);
                    lcd.print(":");
                    lcd.print(e4);
                    delay(1000);
                  }
             
                e4 = 59;
              }
            
            e4 = 0;
            
            for(inactive_mins ; inactive_mins >=0; inactive_mins--)
              {
                for(e4 ; e4 >= 0; e4--)
                  {
                    lcd.clear();
                    lcd.print("INACTIVE FOR: ");
                    delay(200);
                    digitalWrite(7,HIGH);
                    lcd.setCursor(0,1);
                    lcd.print(inactive_mins);
                    lcd.print(":");
                    lcd.print(e4);
                    delay(1000);
                  }
             
                e4 = 59;
              }
          }
        }
