/*

Author : 5hifaT

github:https://github.com/jspw

linkedin : https://www.linkedin.com/in/mehedi-hasan-shifat-2b10a4172/

Stackoverflow : https://stackoverflow.com/story/jspw 


*/

#include <iostream>
using namespace std;

void passByValue(int x)
{
    cout << "In passByValue Function" << endl;
    x = 20;
    printf("x = %d\n", x);
    cout << "Memory address of x : " << &x << endl;
}

void passByReference(int *px)
{
    *px = 100;
    printf("Memory address =  %p\n", px);
}

int main()
{
    int a = 10;

    printf("Memory address of a is %p\n", (&a)); // & operator before a is used to get address of a

    printf("Value of Memory address %p is %d\n", &a, *(&a)); //& to print memory  location // * defines value of pointer!

    int *pa = &a; // created a pointer named pa where a int data type is stored! '*' defines pointer.

    printf("memory location of pa : %p\n", pa);

    int x = 121;

    int *point;
    cout << "Unassigned pointer" << point << endl;

    int *px = &x; //memory address of x is asigned to px ! this is called dereferencing

    printf("Memory location of x is : %p\n", px);

    printf("Asigned value of  Memory location %p is : %d\n", px, *px);

    a = 100;

    printf("a = %d\n", a);

    printf("Value of Memory address(pa) %p is %d (*pa) when a = 100\n", pa, *pa); //& to print memory  location // * defines value of pointer!

    // *pa++; //this will lead pa to point at the next memory and here the next memory is px for us
    // pa++;  //this will lead pa to point at the next memory and here the next memory is px for us

    printf("a = %d when *pa++\n", a);

    printf("Value of Memory address (pa) %p is %d (*pa)\n", pa, *pa); //& to print memory  location // * defines value of pointer!

    printf("Value of Memory address (px) %p is %d (*pa)\n", px, *px); //& to print memory  location // * defines value of pointer!

    px++;

    printf("After using 'px++'\t Pointer (px) is pointed to %p and value becomes : %d (*px)\n", px, *px); //& to print memory  location // * defines value of pointer!

    cout << "\n\nArray \n"
         << endl;

    int ar[] = {1, 2, 3, 4, 5};

    int *ptr;

    ptr = ar;

    for (int i = 0; i < 5; i++)
        cout << ptr[i] << " ";
    cout << "\n"
         << endl;

    for (int i = 0; i < 5; i++)
    {
        printf("Value of *ptr = %d\n", *ptr);
        printf("Value of ptr = %p\n\n", ptr);

        // Increment pointer ptr by 1
        ptr++;
    }

    cout << "\nAdvance Pointer\n"
         << endl;

    int sum = 0;
    int *psum = &sum;
    printf("Memory address of variable(sum) : %p\n", psum);
    printf("Memory Address of pointer(psum) :  %p\n", &psum);

    int **ppsum = &psum;
    printf("Memory Address of pointer(psum) :  %p\n", ppsum);

    cout << "\n\nPass By Value\n"
         << endl;
    x = 10;
    passByValue(10);
    cout << "In main Function" << endl;
    printf("x = %d\n", x);
    cout << "Memory address of x : " << &x << endl;

    cout << "\n\nPass By Reff\n"
         << endl;

    x = 10;
    cout << "(Before) Value of x : " << x << endl;
    passByReference(&x);
    cout << "(After) Value of x : " << x << endl;
    cout << "Memory address of x = " << &x << endl;

    cout << "\nPlay with Pointer\n" << endl;

    x = 10;
    int y = 20;
    px = &x;
    int *py = &y;

    printf("x = %d, y = %d\n", x, y);

    *px = y;

    printf("x = %d, y = %d\n", x, y);

    y = 200;

    printf("x = %d, y = %d\n",x,y);

    px  = py;
    printf("address of x = %p, address of y = %p\n",&x,&y);
    printf("px = %p,=py = %p\n",px,py);

    printf("x = %d, y = %d\n",x,y);

    return 0;
}