/* Simple USB Mouse Example
   Teensy becomes a USB mouse and moves the cursor in a triangle

   You must select Mouse from the "Tools > USB Type" menu

   This example code is in the public domain.
*/

/*
 * Mouse.move(signed char x, signed char y, signed char wheel)
 *        left/right on x is -x/x respectively
 *        up/down on y is -y/y respectively
 *        scroll up/down is wheel/wheel respectively
 *        use for loop to show movement, otherwise it jumps to new distance
 *        
 * for click/press/release/isPressed:       
 *        default button is MOUSE_LEFT
 *        other options are MOUSE_RIGHT, MOUSE_MIDDLE
 * 
 * Mouse.click(uint8_t b)
 * 
 * Mouse.press(uint8_t b) 
 * 
 * Mouse.release(uint8_t b)
 * 
 * Mouse.isPressed(uint8_t b)
 * 
 * Mouse.buttons(uint8_t b)
 *        ?used to set buttons?
 * 
 * 
 *depends on the Mouse.h file
 *
 *Mac display res: 1680 x 1050
 *Mac display dim: 13" x 8 3/16"
 *
 *
 *depends on Keyboard.h and Mouse.h
 *
 *
 *
 */

#include <Keyboard.h>

int i = 10;
int resetButt = 10; // reset button pin 8
int resetButtState = LOW; // reset button state
int stepSize = 1; // standard step size, controls mouse movement


char ctrlKey = KEY_LEFT_GUI; //supposed to be used for OSX
//char ctrlKey = KEY_LEFT_CTRL; //supposed to be used for windows/linux

void setup()
{
  Serial.begin(9600);
  pinMode(resetButt, INPUT);
}

void loop()
{
  resetButtState = digitalRead(resetButt);

  //checks button state
  if(resetButtState == HIGH) // if press button, set i = 0, runs program
  {
    i = 0;
  }


  //if button was pressed, start code
  if (i <= 0) {
    Mouse.begin();
    Keyboard.begin();
    delay(250);

    homeXY(); //homes cursor to max x and y

    ////////////////////////////
    ////copy/paste BP/AP Number///////
    ////////////////////////////
    //move to copy left BP/AP x
    for (i=0; i<stepSize*320; i++) {
      Mouse.move(-4, 0); // move -x only
    }
    //move to copy left BP/AP y
    for (i=0; i<stepSize*113; i++) {
      Mouse.move(0, 4); // move -x only
    }
    delay(250);
    Mouse.press(1); //click down.. later need to release
    //move to copy right BP/AP x
    for (i=0; i<stepSize*180; i++) {
      Mouse.move(4, 0); // move -x only
    }
    delay(250);
    /////release click after highlighting////
    Mouse.release(1); //click release
    delay(250);

    ctrl('c'); //control C

    /////move to address bar x//////
    for (i=0; i<stepSize*1; i++) {
      Mouse.move(0, 0); // move -x only
    }
    //move to address bar y
    for (i=0; i<stepSize*90; i++) {
      Mouse.move(0, -4); // move -x only
    }
    delay(250);
    ////click address bar//////
    Mouse.click(1); //click once
    delay(250);

    /////paste BP/AP into address bar////
    ctrl('v'); //control v




    ////////////////////////////
    ////copy/paste BP/AP Title///////
    ////////////////////////////
    //move to copy left BP/AP x
    for (i=0; i<stepSize*180; i++) {
      Mouse.move(-4, 0); // move -x only
    }
    //move to copy left BP/AP y
    for (i=0; i<stepSize*80; i++) {
      Mouse.move(0, 4); // move -x only
    }
    delay(250);
    Mouse.press(1); //click down.. later need to release
    //move to copy right BP/AP x
    for (i=0; i<stepSize*180; i++) {
      Mouse.move(4, 0); // move -x only
    }
    delay(250);
    /////release click after highlighting////
    Mouse.release(1); //click release
    delay(250);

    ctrl('c'); //control C

    /////move to address bar x//////
    for (i=0; i<stepSize*1; i++) {
      Mouse.move(0, 0); // move -x only
    }
    //move to address bar y
    for (i=0; i<stepSize*80; i++) {
      Mouse.move(0, -4); // move -x only
    }
    delay(250);
    ////click address bar//////
    Mouse.click(1); //click once
    delay(250);

    ///enter space into address bar
    Keyboard.press(KEY_RIGHT_ARROW);
    Keyboard.release(KEY_RIGHT_ARROW);
    delay(25);
    Keyboard.print(" ");

    /////paste BP/AP into address bar////
    ctrl('v');
    


    ////////////////////////////
    ////copy intended doc file name from address bar///////
    ////////////////////////////
    
    /////select all address bar////
    ctrl('a'); //control a to select all

    /////copy selected text//////
    ctrl('c'); //control c to copy
    



    ////////////////////////////
    ////print, print, save as pdf, paste doc title, enter///////
    ////////////////////////////
    
    homeXY(); // send cursor to max x and y
    delay(250);

    //move to print button1 x
    for (i=0; i<stepSize*345; i++) { //stepSize*232 and Mouse.move(-5, 0)
      Mouse.move(-4, 0); // move -x only
    }
    //move to print button1 y
    for (i=0; i<stepSize*65; i++) { //stepSize*46 and Mouse.move(0,5)
      Mouse.move(0, 4); // move -x only
    }
    delay(250);
    Mouse.click(1); //click print button1


    //move to print button2 x
    for (i=0; i<stepSize*320; i++) { //stepSize*232 and Mouse.move(-4, 0)
      Mouse.move(4, 0); // move -x only
    }
    //move to print button2 y
    for (i=0; i<stepSize*235; i++) { //stepSize*46 and Mouse.move(0,4)
      Mouse.move(0, 4); // move -x only
    }
    delay(2000);
    Mouse.click(1); //click print button2


    /*
    //move to save print button x
    for (i=0; i<stepSize*305; i++) { //stepSize*232 and Mouse.move(-4, 0)
      Mouse.move(-4, 0); // move -x only
    }
    //move to save print button y
    for (i=0; i<stepSize*242; i++) { //stepSize*46 and Mouse.move(0,4)
      Mouse.move(0, -4); // move -x only
    }
    delay(2500);
    Mouse.click(1); //click save button
    */

    //hit enter to save as pdf
    delay(2750);
    Keyboard.press(KEY_RETURN); //hit enter key to save
    Keyboard.release(KEY_RETURN); //release enter key to saved
    

    
    delay(2000);
    ctrl('v'); //paste document title

    delay(250);
    Keyboard.press(KEY_RETURN); //hit enter key to save
    Keyboard.release(KEY_RETURN); //release enter key to saved
    delay(2500);
    Keyboard.press(KEY_ESC); //hit esc key to close open window
    Keyboard.release(KEY_ESC); //release esc
    delay(1000);
    
    nextPg(); //clicks next button taking you to next doc

    Mouse.end();
    Keyboard.end();
    i=10;
  }
}









////////////////////////////
/////functions used////////
///////////////////////////


void homeXY()
{
    //ZERO X AND Y (upper right corner)
    for (i=0; i<90; i++) {
      Mouse.move(10, -10);
    }
    delay(250);
}

void ctrl(char letter)
{
    /////copy BP/AP//////
    Keyboard.press(KEY_RIGHT_GUI); //press CTRL
    delay(25);
    Keyboard.press(letter); //press letter
    delay(25);
    Keyboard.releaseAll(); //release all
    delay(250);
}

void nextPg()
{
  homeXY();
  ////////////////////////////
  ////click next file///////
  ////////////////////////////
  //move to copy left BP/AP x
  for (i=0; i<stepSize*360; i++) {
    Mouse.move(-4, 0); // move -x only
  }
  //move to copy left BP/AP y
  for (i=0; i<stepSize*65; i++) {
    Mouse.move(0, 4); // move -x only
  }
  delay(250);
  Mouse.click(1); //click left
}

