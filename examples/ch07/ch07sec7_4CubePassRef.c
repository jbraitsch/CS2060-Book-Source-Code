// Passing Primitive Data Types and pointers
//Add comments to explain the code

#include <stdio.h>	
#include <stdlib.h>

int cubePass1(int number);
int cubePass2(int * numberPtr);

int main(void) {

	int numberMain = 5;
	int result = 0;
	
	printf ("In main before cubePass1  numberMain = %d\n", numberMain);
	printf("&numberMain = %p\n", &numberMain);
	result = cubePass1(numberMain);//doesn't change value of numberMain in function
	printf ("In main after cubePass1  numberMain = %d\n", numberMain);
	printf ("Result = %d\n", result);
	printf("\nIn main before cubePass2  numberMain = %d\n", numberMain);
	result = cubePass2(&numberMain);//changes value of numberMain in function
	printf("\nIn main after cubePass2  numberMain = %d\n", numberMain);
	printf("result = %d\n", result);

} // main


//pass by value
//returns value of cube and stored in result in main
int cubePass1 (int number) 
{
	int cube = 0;
	puts("\nIn cubePass1");
	printf("number = %d\n", number);
	printf("&number = %p\n", &number);
	cube = number * number * number;
	printf("cube  = %d\n", cube);
	number = cube;
	printf("number = %d\n", number);
	return cube;
} 

//pass by reference
//numberMain is changed while function is running
//result is changed in main when cube is returned
int cubePass2 (int * numberPtr) 
{
	int cube = 0;
	puts ("\nIn cubePass2");
	
	//prints the address stored in the pointer
	printf("numberPtr = %p\n", numberPtr);

	//prints value in pointed variable
	printf ("*numberPtr = %d\n", *numberPtr);

	//prints address of the pointer
	printf("&numberPtr = %p\n", &numberPtr);

	//cubes the pointed at variable
	cube = (* numberPtr )* (* numberPtr )* (* numberPtr); 

	//assigns value of cube to pointed variable (numberMain)
	*numberPtr = cube;
	printf ("*numberPtr = %d\n", *numberPtr);
	return cube;
} 


