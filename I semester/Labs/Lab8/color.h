 #include<windows.h>
#include<stdio.h>
#include<conio.h>
void SetColorAndBackground(int ForgC, int BackC)
 {
      WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);

 }



 COORD coord={0,0}; // this is global variable
                                     //center of axis is set to the top left cornor of the screen

  void SetColor(int ForgC)
 {
      WORD wColor;
                           //We will need this handle to get the current background attribute
      HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
      CONSOLE_SCREEN_BUFFER_INFO csbi;

                            //We use csbi for the wAttributes word.
      if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
      {
                      //Mask out all but the background attribute, and add in the forgournd color
           wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
           SetConsoleTextAttribute(hStdOut, wColor);
      }}

