
  /* Recibimos los datos byte a byte
   * y se almacenan en un array de 8 bytes,
   * es decir gestionamos 8 caracteres a la vez.
   * Una vez lleno este array se encriptaran 
   * y se borrará este array con los datos en 
   * plano justo después.
   */
   
#include <AltSoftSerial.h>
char incomingByte = 0;
char delimiter = '-';
int i;
int count = 0;
int restoBytes;
int control;
//utilizr la funcion write al enviar datos en vez de print
byte bloque[16];// bloques que vamos a encryptar
AltSoftSerial altSerial;

void setup() {
  Serial.begin(9600);
  Serial.println("AltSoftSerial Test Begin");
  altSerial.begin(9600);
}

void loop() {

  // finaliza solo cuando se reciben los datos:

        while (Serial.available() > 0 ) {//inicio lectura y guardado

          incomingByte = Serial.read();
          if ( delimiter == incomingByte ) {
            bloque[count] = incomingByte;
            restoBytes = 15 - count; // al menos se envia delim (15 libres min)
            //Serial.println(restoBytes);
            count = 0;// reseteamos para la proxima vez que recibamos datos
            //procesar el array con el bloque (encrypt)
            //guardar el bloque en una variable o enviarlo
            
            // Debug
            //Serial.println("Valores enviados: ");
            //for (i = 0; i<16; i++){altSerial.println((char)bloque[i]);}
            //
            break;
          }
          
          bloque[count] = incomingByte;
          
          
          //Debug
         
          //altSerial.println("Recibido: ");
          altSerial.print(incomingByte);
          //altSerial.println(bloque[count]);
          count++;
          
          if (count == 16) {// si el array esta lleno se reinicia el contador para sobreescribirlo
            count = 0;
            //Debug
              //altSerial.println("Array de valores almacenados: ");
            for (i = 0; i<16; i++)
            {
              //altSerial.println((char)bloque[i]);
            }
            
             //procesar el array con el bloque (encrypt)
            //guardar el bloque en una variable o enviarlo
          
          }
        }//fin lectura

}//FIN VOID LOOP()
