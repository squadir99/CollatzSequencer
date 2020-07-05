/*  Author : Sohail Quadir
	Date : 10/20/2019
	Purpose : The purpose of this program is to print a range of numbers set by the user,
	and to give the number of steps it takes for each number to reach 1 when plugged into the Collatz Conjecture.
	Sources of Help : Class notes, textbook, https://www.lemoda.net/c/printf-left-justify/, 
	Time Spent : 7 hours
*/
#include <stdio.h>

void clearKeyboardBuffer();

int collatzSequencer(int, int);

int main(int argc, char* argv[]) {
	printf("Enter a starting point:\n"); //Asks the user for a starting integer.
	int startingInt;
	scanf_s("%d", &startingInt);

	while (startingInt <= 1 || startingInt >= 100) { //Makes sure user inputs good starting integer
		printf("Enter a valid starting point (2 ~ 99):\n");
		scanf_s("%d", &startingInt);
	}

	clearKeyboardBuffer();
	printf("Enter an ending number:\n"); //Asks the user for an ending integer.
	int endingInt;
	scanf_s("%d", &endingInt);

	while (endingInt <= startingInt || endingInt >= 1000) { //Makes sure the user inputs a good ending integer
		printf("Enter a valid starting point (%d ~ 99):\n", startingInt);
		scanf_s("%d", &endingInt);
	}

	int stepCounter = 0;
	int columnCounter = 1;
	for (int i = startingInt; i <= endingInt; i = i + 1) { //This for loop prints out each number in the range and the number of steps it takes to reach 1. 
		if (columnCounter == 7) {
			columnCounter = 0;
			printf("%5d:%-5d\n", i, collatzSequencer(i, stepCounter));
			columnCounter = columnCounter + 1;
		}
		else {
			printf("%5d:%-5d\t", i, collatzSequencer(i, stepCounter));
			columnCounter = columnCounter + 1;
		}
	}
	return 0;
}

void clearKeyboardBuffer() {
	char ch;
	scanf_s("%c", &ch, 1);
	while (ch != '\n' && ch != '\0') {
		scanf_s("%c", &ch, 1);
	}
}

/*
The purpose of the following function is to count how
how many steps it takes for a positive number n to reach
n == 1
*/
int collatzSequencer(int n, int stepCounter) {

	if (n == 1) {
		//printf("%d\n", stepCounter);
		return stepCounter;
	}
	else if (n % 2 == 0) { //if n is even
		stepCounter += 1;
		collatzSequencer(n / 2, stepCounter);
	}
	else if (n % 2 == 1 && !(n == 1)) {
		stepCounter += 1;
		collatzSequencer((3 * n) + 1, stepCounter);
	}
}
/* Computing I ?? COMP.1010 Honor Statement

The practice of good ethical behavior is essential for maintaining good order in the classroom,
providing an enriching learning experience for students, and as training as a practicing computing professional
upon graduation.This practice is manifested in the University's Academic Integrity policy. Students are expected
to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the course catalog.
Violations will be dealt with as outlined therein.
All programming assignments in this class are to be done by the student alone.No outside help is permitted except
the instructor and approved tutors.
I certify that the work submitted with this assignment is mine and was generated in a manner consistent with
this document, the course academic policy on the course website on Blackboard, and the UMass Lowell academic code.

Date : 10/20/2019
Name: Sohail Quadir
*/
