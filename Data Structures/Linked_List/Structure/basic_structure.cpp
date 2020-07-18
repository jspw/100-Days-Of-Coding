/*

Author : 5hifaT

github:https://github.com/jspw

linkedin : https://www.linkedin.com/in/mehedi-hasan-shifat-2b10a4172/

Stackoverflow : https://stackoverflow.com/story/jspw 


*/

struct Person
{            //structure
    int age; //members
    float salary;
};

#include <iostream>
using namespace std;
int main()
{

    struct Person person1, person2, person3;

    person1.age = 22;
    person1.salary = 12000.50;

    printf("Age : %d\nSalary : %.3f\n", person1.age, person1.salary);

    return 0;
}