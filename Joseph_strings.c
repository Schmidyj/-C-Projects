// Schmidt Bryan Joseph
// N01538511
// 4-24-24
// 

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function prototypes
int isPalindrome(char str[]);
void encryptMessage(char message[], int shift);
void decryptMessage(char message[], int shift);

int main() {
  int choice;
char word[51]; //  for word input, increased to handle 50 characters

 while(1) {
 printf("\nSelect a function:\n");
 printf("1 = Check Palindrome\n");
printf("2 = Encrypt Message\n");
printf("3 = Decrypt Message\n");
 printf("-1 = Quit\n");
  scanf("%d", &choice);
   switch(choice) {
   case 1:
   printf("Enter a word to check for palindrome: ");
   scanf(" %50[^\n]", word); // reads up to 50 characters 
   if(isPalindrome(word))
  printf("\"%s\" is a Palindrome!\n", word);
   else
   printf("\"%s\" is not a Palindrome.\n", word);
   break;
  case 2:
   printf("Enter a message to encrypt: ");
   scanf(" %50[^\n]", word);
    encryptMessage(word, 3);
     printf("Encoded Message: %s\n", word);
  break;

  case 3:
 printf("Enter an encrypted message to decrypt: ");
 scanf(" %50[^\n]", word);
 decryptMessage(word, 3);
 printf("Decoded Message: %s\n", word);
 break;

  case -1:
 return 0;

   default:
 printf("Invalid choice. Please try again.\n");
    }
    }
    return 0;
}

// prototype  to check if a string is a palindrome
int isPalindrome(char str[]) {
 int len = strlen(str);
    for(int i = 0; i < len / 2; i++) {
        if(tolower(str[i]) != tolower(str[len - 1 - i]))
   return 0;
    }
    return 1;
}

// function to encrypt a message using caesar cipher
void encryptMessage(char message[], int shift) {
    int i = 0;
    while(message[i] != '\0') {
     if(isalpha(message[i])) {
 char base = isupper(message[i]) ? 'A' : 'a';
 message[i] = (message[i] - base + shift) % 26 + base;
 }
 i++;
   }
}

// function to decrypt a message using a caesar cipher
void decryptMessage(char message[], int shift) {
    int i = 0;
    while(message[i] != '\0') {
    if(isalpha(message[i])) {
   char base = isupper(message[i]) ? 'A' : 'a';
   message[i] = (message[i] - base - shift + 26) % 26 + base;
   }
   i++;
    }
}
