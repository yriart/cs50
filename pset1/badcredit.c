#include <stdio.h>

int sumOfDigits(int num);
int isCCValid(void);
int validityPrinter(void);

int main(void) {
	validityPrinter();
	return 0;
}

int validityPrinter(void) {
	int validity = isCCValid();
	if (validity == 1) {
		printf("CC is valid!\n");
	} else {
		printf("NOPE!\n");
	}
	return 0;
}

int isCCValid(void) {
	int ccNumber[] = { 3,7,8,2,8,2,2,4,6,3,1,0,0,0,5 };
	int ccLength = sizeof(ccNumber) / sizeof(int);

	int sumTotal = 0;

	for (int i = ccLength - 1; i >= 0; i--) {
		if (i % 2 == 0) {
			sumTotal += ccNumber[i];
		} else {
			sumTotal += sumOfDigits(ccNumber[i] * 2);
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

