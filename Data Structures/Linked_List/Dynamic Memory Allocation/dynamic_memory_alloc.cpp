/*

Author : 5hifaT

github:https://github.com/jspw

linkedin : https://www.linkedin.com/in/mehedi-hasan-shifat-2b10a4172/

Stackoverflow : https://stackoverflow.com/story/jspw 


*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct myStruct
{
    string name;
    int age;
};

int main()
{
    int *ptr;
    ptr = (int *)malloc(100 * sizeof(int));
    printf("%p\n", ptr);
    char c = 'j';
    char *ch = (char *)malloc(10 * sizeof(c));

    printf("%p\n", ch);

    printf("Structure Size : %lu\n", sizeof(struct myStruct));

    double d = 10.9;
    double *dp = NULL;

    printf("Null pointer : %p\n", dp);

    //free a memory after use

    double *aah = (double *)malloc(sizeof(d));

    cout << aah << endl;

    free(aah);

    aah = NULL;

    printf("Memory free aah =  %p\n", aah);

    cout << "\n\nPointer with Structure\n"
         << endl;

    struct myStruct s1;

    s1.name = "Sania";
    s1.age = 22;

    struct myStruct *ps1 = &s1;

    cout << "Size of s1 = " << sizeof(s1) << " byte" << endl;

    cout << "Memory address : " << ps1 << endl;

    ps1->age = 23; //*ps1.age = 23

    cout << s1.age << endl;

    cout << "\n\nAllocate memory dynamically for Structure\n"
         << endl;

    struct myStruct *p2 = (struct myStruct *)malloc(sizeof(struct myStruct));

    p2->name = "Shifat";
    p2->age = 23;

    printf("name = %s, age = %d\n\n", (*p2).name.c_str(), (*p2).age);

    int n;

    scanf("%d",&n);

    int ar[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", ar+i);
    }

    for (int i = 0; i < n; i++)
        cout << *(ar+i) << " ";
    cout << endl;

    return 0;
}