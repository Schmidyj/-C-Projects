
/* Schmidt Bryan Joseph
* N01538511
* 03 - 17 - 2024
*/
// I will be needing these three libraries
#include <stdio.h> // just to help me with smooth input and outputs to scan user inputs 
#include <stdlib.h>// For random number generation  like rand and srand but my logic we need srand for this game 
#include <time.h> // For seeding the random number generator like time


int GoFish(int baitType);

int main() {
   // Seed the random number generator
   srand(time(NULL));

   int remainingTime = 720; // As instructed in  Rubric 12 hours = 720 minutes
   int wallet = 0; // To account caught items
   int baitChoice; // holder for types of things caught

   printf("Welcome to the Jacksonville Beach pier! Ready to go fishing?\n");

   while (remainingTime > 0) {
   printf("\nWhat type of bait do you want to use?\n");
   printf("1 = Worms\n2 = Jig\n3 = Chum\n-1 = Leave the pier early\n");
   scanf("%d", &baitChoice);

       if (baitChoice == -1) {
   printf("Thank you for fishing at the Jacksonville Beach pier!.\n");
   printf("Final wallet size: $%d\n", wallet);
   break;
   } else if (baitChoice < 1 || baitChoice > 3) {
   printf("Invalid choice. Please try again. Here are valid inputs 1 = Worms\n2 = Jig\n3 = Chum\n-1 = Leave the pier early \n");
   continue;
       }
// Rubric requested a "GoFish" Named Function
  int caughtFish = GoFish(baitChoice);

  switch (caughtFish) {
  case 0:
  printf("Unlucky you've caught nothing.\n");
  remainingTime -= 5;
    break;
  case 1:
  printf("You caught a Flounder!\n");
  remainingTime -= 10;
  wallet += 100;
   break;
  case 2:
  printf("Wow a Red Snapper!\n");
   remainingTime -= 20;
    wallet += 250;
   break;
   case 3:
  printf("Nice Catch! You've caught a Shark!\n");
   remainingTime -= 60;
  wallet += 1000;
    break;
      default:
    printf("Error: Invalid fish caught.\n");
    break;
       }

       printf("Remaining time: %d\n", remainingTime);
       printf("Current Wallet Size: $%d\n", wallet);
   }

   return 0;
}

int GoFish(int baitType) {
   int randomNumber = rand() % 100; // Generates a random number between 0 and 99

   switch (baitType) {
       case 1: // Worm bait probalitity
      if (randomNumber < 60) return 0; // 60% chance of  Nothing
      else if (randomNumber < 85) return 1; // 25% chance of  Flounder
      else if (randomNumber < 99) return 2; // 14% chance of  Red Snapper
  else return 3; // 1% chance of catching Shark
       case 2: // Jig bait probalitity
      if (randomNumber < 70) return 0; // 70% chance of  Nothing
     else if (randomNumber < 75) return 1; // 5% chance of  Flounder
      else if (randomNumber < 95) return 2; // 20% chance of  Red Snapper
       else return 3; // 5% chance of catching Shark
       case 3: // Chum bait probalitity
    if (randomNumber < 80) return 0; // 80% chance of  Nothing
     else if (randomNumber < 82.5) return 1; 
   else if (randomNumber < 85) return 2; 
    else return 3; 
       default:
    printf("Error: Invalid bait type.\n");
      return -1; // Error code for invalid bait type
   }
}
