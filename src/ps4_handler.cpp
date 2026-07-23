#include "ps4_handler.h"
#include <Arduino.h>

int player = 0;
int battery = 0;

void notify() {
    //--- Digital cross/square/triangle/circle button events ---
    if( Ps4.event.button_down.cross )
        Serial.println("Started pressing the cross button");
    if( Ps4.event.button_up.cross )
        Serial.println("Released the cross button");

    if( Ps4.event.button_down.square )
        Serial.println("Started pressing the square button");
    if( Ps4.event.button_up.square )
        Serial.println("Released the square button");

    if( Ps4.event.button_down.triangle )
        Serial.println("Started pressing the triangle button");
    if( Ps4.event.button_up.triangle )
        Serial.println("Released the triangle button");

    if( Ps4.event.button_down.circle )
        Serial.println("Started pressing the circle button");
    if( Ps4.event.button_up.circle )
        Serial.println("Released the circle button");

    //--------------- Digital D-pad button events --------------
    if( Ps4.event.button_down.up )
        Serial.println("Started pressing the up button");
    if( Ps4.event.button_up.up )
        Serial.println("Released the up button");

    if( Ps4.event.button_down.right )
        Serial.println("Started pressing the right button");
    if( Ps4.event.button_up.right )
        Serial.println("Released the right button");

    if( Ps4.event.button_down.down )
        Serial.println("Started pressing the down button");
    if( Ps4.event.button_up.down )
        Serial.println("Released the down button");

    if( Ps4.event.button_down.left )
        Serial.println("Started pressing the left button");
    if( Ps4.event.button_up.left )
        Serial.println("Released the left button");

    //------------- Digital shoulder button events -------------
    if( Ps4.event.button_down.l1 )
        Serial.println("Started pressing the left shoulder button");
    if( Ps4.event.button_up.l1 )
        Serial.println("Released the left shoulder button");

    if( Ps4.event.button_down.r1 )
        Serial.println("Started pressing the right shoulder button");
    if( Ps4.event.button_up.r1 )
        Serial.println("Released the right shoulder button");

    //-------------- Digital trigger button events -------------
    if( Ps4.event.button_down.l2 )
        Serial.println("Started pressing the left trigger button");
    if( Ps4.event.button_up.l2 )
        Serial.println("Released the left trigger button");

    if( Ps4.event.button_down.r2 )
        Serial.println("Started pressing the right trigger button");
    if( Ps4.event.button_up.r2 )
        Serial.println("Released the right trigger button");

    //--------------- Digital stick button events --------------
    if( Ps4.event.button_down.l3 )
        Serial.println("Started pressing the left stick button");
    if( Ps4.event.button_up.l3 )
        Serial.println("Released the left stick button");

    if( Ps4.event.button_down.r3 )
        Serial.println("Started pressing the right stick button");
    if( Ps4.event.button_up.r3 )
        Serial.println("Released the right stick button");

    //---------- Digital select/start/ps button events ---------


    if( Ps4.event.button_down.ps )
        Serial.println("Started pressing the Playstation button");
    if( Ps4.event.button_up.ps )
        Serial.println("Released the Playstation button");


    //---------------- Analog stick value events ---------------
   if( abs(Ps4.event.analog_changed.stick.lx) + abs(Ps4.event.analog_changed.stick.ly) > 2 ){
       Serial.print("Moved the left stick:");
       Serial.print(" x="); Serial.print(Ps4.data.analog.stick.lx, DEC);
       Serial.print(" y="); Serial.print(Ps4.data.analog.stick.ly, DEC);
       Serial.println();
    }

   if( abs(Ps4.event.analog_changed.stick.rx) + abs(Ps4.event.analog_changed.stick.ry) > 2 ){
       Serial.print("Moved the right stick:");
       Serial.print(" x="); Serial.print(Ps4.data.analog.stick.rx, DEC);
       Serial.print(" y="); Serial.print(Ps4.data.analog.stick.ry, DEC);
       Serial.println();
   }

   //--------------- Analog D-pad button events ----------------

   //---------- Analog shoulder/trigger button events ----------

   

   if( abs(Ps4.event.analog_changed.button.l2) ){
       Serial.print("Pressing the left trigger button: ");
       Serial.println(Ps4.data.analog.button.l2, DEC);
   }

   if( abs(Ps4.event.analog_changed.button.r2) ){
       Serial.print("Pressing the right trigger button: ");
       Serial.println(Ps4.data.analog.button.r2, DEC);
   }

   //---- Analog cross/square/triangle/circle button events ----


   //---------------------- Battery events ---------------------
    if( battery != Ps4.data.status.battery ){
        battery = Ps4.data.status.battery;
        Serial.print("The controller battery is ");
        if( battery == ps4_status_battery_charging )      Serial.println("charging");
        else if( battery == ps4_status_battery_full )     Serial.println("FULL");
        else if( battery == ps4_status_battery_high )     Serial.println("HIGH");
        else if( battery == ps4_status_battery_low)       Serial.println("LOW");
        else if( battery == ps4_status_battery_dying )    Serial.println("DYING");
        else if( battery == ps4_status_battery_shutdown ) Serial.println("SHUTDOWN");
        else Serial.println("UNDEFINED");
    }
}

void onConnect() {
    Serial.println("Connected.");
}
