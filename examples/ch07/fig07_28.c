// Fig. 7.28: fig07_28.c
// Demonstrating an array of pointers to functions.
#include <stdio.h>

// prototypes
double add(double a, const double e);
double subtract(double b, const double f);
double multiply(double c, const double g);
double divide(double d, const double h);

int main(void)
{
    // initialize array of 3 pointers to functions that each take an
    // int argument and return void                              
    double (*f[4])(double, double) = { add, subtract, multiply, divide};

    puts("Enter calculator function:");
    printf("%s", "0. Add 1. Subtract 2. Multiply 3. Divide - ");
    size_t choice; // variable to hold user's choice
    //depending on your compiler you may need to change the format specifier
    //windows needs llu  mac needs lu
    scanf("%llu", &choice);

    // process user's choice
    while (choice >= 0 && choice < 4) {

        // invoke function at location choice in array f and pass
        // choice as an argument 
        printf("%s", "What two number do you want to ");
        switch (choice)
        {
        case 0: puts("add: "); break;
        case 1: puts("subtract: "); break;
        case 2: puts("multiply: "); break;
        case 3: puts("divide: "); break;
        }

        float x = 0;
        float y = 0;
        scanf("%e", &x);
        scanf("%e", &y);
        double returned = (*f[choice])(x, y);
        printf("%.2f\n", returned);
        puts("Enter calculator function:");
        printf("%s", "0. Add 1. Subtract 2. Multiply 3. Divide - ");
        //windows needs llu  mac needs lu
        scanf("%llu", &choice);
    }

    printf("Program execution completed.");
}

double add(double a, const double e)
{
    printf("You added %.2f and %.2f equals ", a, e);
    a += e;
    return a;
}

double subtract(double b, const double f)
{
    printf("You subtracted %.2f and %.2f equals ", b, f);
    b -= f;
    return b;
}

double multiply(double c, const double g)
{
    printf("You multiplied %.2f and %.2f equals ", c, g);
    c *= g;
    return c;
}

double divide(double d, const double h)
{
    printf("You divided %.2f and %.2f equals ", d, h);
    d /= h;
    return d;
}




/**************************************************************************
 * (C) Copyright 1992-2015 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/

