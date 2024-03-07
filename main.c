

#define FCY 4000000
#include <libpic30.h>
#include "config.h"
#include "lcd.h"


void system_init(){
    /****************************************************************************
     * Setting the Output Latch SFR(s)
     ***************************************************************************/
    LATA = 0x0000;
    LATB = 0x0000;

    /****************************************************************************
     * Setting the GPIO Direction SFR(s)
     ***************************************************************************/
    TRISA = 0x001F;
    TRISB = 0x0000;

    /****************************************************************************
     * Setting the Weak Pull Up and Weak Pull Down SFR(s)
     ***************************************************************************/
    CNPU1 = 0x0000;
    CNPU2 = 0x0000;

    /****************************************************************************
     * Setting the Open Drain SFR(s)
     ***************************************************************************/
    ODCA = 0x0000;
    ODCB = 0x0000;

    /****************************************************************************
     * Setting the Analog/Digital Configuration SFR(s)
     ***************************************************************************/
    //AD1PCFG = 0x0E3C;
     AD1PCFG = 0xFFFF;
  
}


void main(){
    //Declaracion de variables
    int LCD_AUXILIAR=0;
    char NUM='0';
    
    
    system_init();
    /*CONFIGURACION INICIAL DE LCD*/
    LCD_Initialize(); //Preder, configurar a 4 bits
    DisplayClr();  // borrar lo que tenga la pantalla
    LCDGoto(0,0); //poner el cursor en la posicion inicial
    
    while(1){
        LCD_PORT=LCD_AUXILIAR;
        
        if(NUM!='&'){
            LCDPutChar(NUM);
        }
        NUM='&';
        //Rutina del display
         /*LCDPutStr("Hello Word");
        __delay_ms(30);
        LCDGoto(0,1); 
        LCDPutStr("Valentina");
        __delay_ms(30);
         LCDGoto(0,0);*/
         
         LCD_AUXILIAR=LCD_PORT;
         //Rutina de salida del teclado
         PORTB=0x100;
            if(PORTAbits.RA3==1) NUM='7';
            if(PORTAbits.RA2==1) NUM='8';
            if(PORTAbits.RA1==1) NUM='9';
            if(PORTAbits.RA0==1) NUM='/';
         __delay_ms(30);
         PORTB=PORTB<<1;
            if(PORTAbits.RA3==1) NUM='4';
            if(PORTAbits.RA2==1) NUM='5';
            if(PORTAbits.RA1==1) NUM='6';
            if(PORTAbits.RA0==1) NUM='x';
         __delay_ms(30);
         PORTB=PORTB<<1;
            if(PORTAbits.RA3==1) NUM='1';
            if(PORTAbits.RA2==1) NUM='2';
            if(PORTAbits.RA1==1) NUM='3';
            if(PORTAbits.RA0==1) NUM='-';
         __delay_ms(30);
         PORTB=PORTB<<1;
            //if(PORTAbits.RA3==1) NUM='1';
            if(PORTAbits.RA2==1) NUM='0';
            if(PORTAbits.RA1==1) NUM='=';
            if(PORTAbits.RA0==1) NUM='+';
         __delay_ms(30);
         
         //NUM='1';
         
         
         
    }
}

