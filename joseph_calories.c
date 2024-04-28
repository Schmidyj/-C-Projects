// Schmidt Bryan Joseph
// #N01538511
// 4-27-24



#include <stdlib.h>// standard library
#include <stdio.h> // Standard input and output for scnaf
#include <string.h> // Will be needing this library for the calorie text file

#define MAX_FOOD_NAME_LENGTH 99 
// max length for the food name

// function prototypes
void LogFood();
void PrintByDay();
void PrintMostCalories();
void ResetLog();

// function to log the food, day, and calories into a file
void LogFood() {
char food[MAX_FOOD_NAME_LENGTH + 1]; // +1 for null terminator
int day, calories;
printf("What food item did you eat? ");
scanf("%99s", food); // Im Using 99 based on MAX_FOOD_NAME_LENGTH to prevent overflow

do {
printf("What day did you eat it? (1 = Monday; 7 = Sunday) ");
 scanf("%d", &day);
 if(day < 1 || day > 7) {
 printf("Invalid day. Please enter a number between 1 and 7.\n");
 }
} while(day < 1 || day > 7); // this will repeat until a valid day is entered

printf("How many calories did it have? ");
scanf("%d", &calories);

FILE *file = fopen("calories.txt", "a");
if (file != NULL) {
 fprintf(file, "%s %d %d\n", food, day, calories);
 fclose(file);
 printf("%s logged on day %d with %d calories.\n", food, day, calories);
} else {
 printf("Unable to open file.\n");
}
}

// seconf function to print total calories consumed each day of the week
void PrintByDay() {
 int calories[7] = {0}, day, cal;
 char food[100];
 FILE *file = fopen("calories.txt", "r");
 if (file != NULL) {
 while (fscanf(file, "%99s %d %d", food, &day, &cal) == 3) { //  this will ensure we read exactly 3 items
  if (day >= 1 && day <= 7) {
 calories[day-1] += cal; // Function to add calories for the correct day
 }
  }
 fclose(file);

 // helps print the calories for each day of the week
 char* days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
   for (int i = 0; i < 7; i++) {
 printf("%s: %d calories\n", days[i], calories[i]);
 }
 } else {
 printf("Unable to open file.\n");
 }
}


// function prototype  to find and print the food item with the most calories
void PrintMostCalories() {
FILE *file = fopen("calories.txt", "r");
 if (file != NULL) {
 char food[100], maxCalFood[100] = "";
 int day, calories, maxCalories = 0;
  while (fscanf(file, "%s %d %d", food, &day, &calories) != EOF) {
 if (calories > maxCalories) {
 maxCalories = calories;
 strcpy(maxCalFood, food);
 }
 }
  if (strlen(maxCalFood) > 0) {
 printf("Food with Most Calories: %s with %d calories\n", maxCalFood, maxCalories);
 } else {
 printf("No entries found.\n");
 }
 fclose(file);
 } else {
 printf("Unable to open file.\n");
 }
}

// function to reset the log by clearing the contents of the file
void ResetLog() {
 FILE *file = fopen("calories.txt", "w");
if (file != NULL) {
 fclose(file);
 printf("Log Reset.\n");
   } else {
   printf("Unable to open file.\n");
   }
}

// this is the function to handle menu and user interaction
int main() {
  int choice;
 printf("Welcome to the Calorie Tracker!\n");
 while (1) {
 printf("1: Log Food\n2: Print Calories by Day\n3: Print Food with Most Calories\n4: Reset Log\n-1: Quit\n");
 printf("Choose an option: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 LogFood();
 break;
 case 2:
 PrintByDay();
 break;
 case 3:
 PrintMostCalories();
 break;
 case 4:
 ResetLog();
 break;
 case -1:
 printf("Goodbye!\n");
 return 0;
  default:
 printf("Invalid option. Please try again.\n");
 }
   }
   return 0;
}

