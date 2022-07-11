/*
	if (inputStr[strlen(inputStr) - 1] == '\n')
	{
		inputStr[strlen(inputStr) - 1] = '\0';
	}
*/

#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define LENGTH 13

bool exploreValidateInt(const char* buff);
void printLimits();

int main(void)
{
	char inputStr[LENGTH]; // create char arintray
	bool isValid = false;
	int integerValue = 0;
	size_t inputLength = 0;
	char* endPtr;

	printLimits();

	puts("\nEnter an integer");
	fgets(inputStr, LENGTH , stdin);
	inputStr[strlen(inputStr) - 1] = '\0';

	//returns isValid as true if  valid integer was input
	for (unsigned int counter = 1; counter < 6; counter++)
	{
		isValid = exploreValidateInt(inputStr);

	}
	//converts string to an integer if isValid is returned true 
	//in exploreValidateInt
	if (isValid) 
	{
		integerValue = strtol(inputStr, &endPtr, 10);
		printf("Input %d is a valid integer\n", integerValue);
	}
	else
	{
		printf("Input %s is a not a valid integer", inputStr);
	}
	
}



void printLimits()
{
	printf("The number of bits in a byte %d\n", CHAR_BIT);

	printf("The minimum value of SIGNED CHAR = %d\n", SCHAR_MIN);
	printf("The maximum value of SIGNED CHAR = %d\n", SCHAR_MAX);
	printf("The maximum value of UNSIGNED CHAR = %d\n", UCHAR_MAX);

	printf("The minimum value of SHORT INT = %d\n", SHRT_MIN);
	printf("The maximum value of SHORT INT = %d\n", SHRT_MAX);

	printf("The minimum value of INT = %d\n", INT_MIN);
	printf("The maximum value of INT = %d\n", INT_MAX);

	printf("The minimum value of CHAR = %d\n", CHAR_MIN);
	printf("The maximum value of CHAR = %d\n", CHAR_MAX);

	printf("The minimum value of LONG = %ld\n", LONG_MIN);
	printf("The maximum value of LONG = %ld\n", LONG_MAX);
}


bool exploreValidateInt(const char* buff)
{
	char* end;
	errno = 0;
	bool valid = false;
	int validInt = 0;
	long intTest = strtol(buff, &end, 10);

	//compares pointer address to see if strtol converted string
	if (end == buff) {
		fprintf(stderr, "%s: not a decimal number\n", buff);
	}
	//determines if string is properly ended
	else if ('\0' != *end) {
		fprintf(stderr, "%s: extra characters at end of input: %s\n", buff, end);
	}
	//test if integer is withing a valid range
	else if ((LONG_MIN == intTest || LONG_MAX == intTest) && ERANGE == errno) {
		fprintf(stderr, "%s out of range of type long\n", buff);
	}
	else if (intTest > INT_MAX) {
		fprintf(stderr, "%ld greater than INT_MAX\n", intTest);
	}
	else if (intTest < INT_MIN) {
		fprintf(stderr, "%ld less than INT_MIN\n", intTest);
	}
	//if all above is false then input is a valid int
	//stores converted long into an int and makes the bool true
	else {
		validInt = (int)intTest;
		valid = true;
		printf("%ld is integer value\n", intTest);
	}

	return valid;
}
