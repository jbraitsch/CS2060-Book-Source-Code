/*******************
 Understanding pointers

 Add comments to explain the code
**************/

#include <stdio.h>


int main ()
{
	// Initalize houseNum
	int houseNum = 13;
	int calcHouseNum1 = 0;
	int calcHouseNum2 = 0;
	int *houseNumPtr = &houseNum;
	
	//prints value of houseNum
	printf("houseNum %d\n", houseNum);

	//prints the address of houseNum
	printf("&houseNum %p\n\n", &houseNum);

	//prints value of houseNum
	printf ("*houseNumPtr  %d\n", *houseNumPtr);

	//prints address held in pointer (&houseNum)
	printf ("houseNumPtr %p\n\n", houseNumPtr);

	//prints address of the pointer
	printf ("&houseNumPtr %p\n\n", &houseNumPtr);

	//adds houseNum + houseNum
	calcHouseNum1 =  *houseNumPtr + *houseNumPtr;

	printf("*houseNumPtr + *houseNumPtr is %d\n\n", calcHouseNum1);

	//multiplies houseNum by 2 equal to calcHouseNum1
	calcHouseNum2 = 2 * (*houseNumPtr);

	printf("2 * (*houseNumPtr) is %d\n\n", calcHouseNum2);

	//prints address of where the value that ptr is pointing at (houseNum)
	//both get the same address just in a different order
	printf("\n&*houseNumPtr = %p"
		"\n*&houseNumPtr = %p\n", &*houseNumPtr, *&houseNumPtr);
			
	return 0;
}
