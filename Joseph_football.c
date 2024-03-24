//** Schmidt Bryan Joseph  UNF N Number #N01538511 Date Of Submission 1/31/2024 ** //
#include <stdio.h>

int main(void) {

  double speed,time,yardLine;
//this will prompt the user to input the values and scanf will actually retrive the inputted data.
  printf("At what yard line did the recicever catch the ball?: ");
  scanf("%lf", &yardLine);

  printf("Input the speed of the receiver(yards per second): ");
  scanf("%lf", &speed);
//math formula to calculate the time by using speed and given input subtracted by the endzone// 
  time = (100.0 - yardLine) / speed;
  // This will display the caculates times with percison of two decimal places.
  printf("The receiver will score a touchdown in %.2lf seconds. \n", time);
  
  return 0;
}