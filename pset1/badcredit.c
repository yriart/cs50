#include <stdio.h>
#include <cs50.h>

int sumOfDigits(int num);
int isCCValid(int[] ccNum);
int validityPrinter(int[] ccNum);
long long getUserInput(void);
int[] convertInputToArray(long long userInput);

int main(void) {
	long long userInput = getUserInput();
	//validityPrinter();
	return 0;
}

//getCC num from user input
//convert to array and return
long long getUserInput(void) {
	printf("Number: ");
	long long userInput = GetLongLong();
	return userInput;
}

array convertInputToArray(long long userInput) {
	return 0;
}

int validityPrinter(int[] ccNum) {
	int validity = isCCValid(ccNum);
	if (validity == 1) {
		printf("CC is valid!\n");
	} else {
		printf("NOPE!\n");
	}
	return 0;
}

int isCCValid(int[] ccNum) {
	//int ccNumber[] = { 3,7,8,2,8,2,2,4,6,3,1,0,0,0,5 };

	int ccLength = sizeof(ccNum) / sizeof(int);

	int sumTotal = 0;

	for (int i = ccLength - 1; i >= 0; i--) {
		if (i % 2 == 0) {
			sumTotal += ccNum[i];
		} else {
			sumTotal += sumOfDigits(ccNum[i] * 2);
		}
	}

	if (sumTotal % 10 == 0) {
		return 1;
	} else {
		return 0;
	} 	
}

int sumOfDigits(int num) {
	int firstDigit = num / 10;
	int secondDigit = num % 10;
	return firstDigit + secondDigit;
}

