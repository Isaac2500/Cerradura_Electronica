#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7); //Conexiones (RS,E,D4,D5,D6,D7)
int puerto[]={8,9,10,11,12};
byte numero=0,password[4];
int longitudClave = 0;
void setup() {
lcd.begin(16,2);
lcd.clear();
lcd.setCursor(0,0);
  for(int i=0;i<5;i++){ // Se configuran todos los pines a modo entrada
    pinMode(puerto[i],INPUT);
  }
}

void loop() {

  numero=0;
  if(digitalRead(12)==HIGH){//Detecta si se recibio un digito
        for(int i=0;i<4;i++){
            numero |= digitalRead(puerto[i])<<i;//Se construye el byte de entrada
        }
        
        password[longitudClave]=numero;
        
        longitudClave++;
        
        if(longitudClave == 3){// verifica que se han recibido 4 digitos
          if(password[0]== 1 && password[1] == 5 && password[2] == 9){
            lcd.clear();
            lcd.print("Clave Correcta");  
          }else{
            lcd.clear();
            lcd.print("Clave Incorrecta");
          }

          longitudClave = 0;
        }
        delay(1000);
        
  }


  
  
}
