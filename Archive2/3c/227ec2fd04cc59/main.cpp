#include <stdio.h>

struct emp ; // declare emp // *** added ***

void fiu(struct emp); // declare function which takes an emp by value

struct emp{ // define emp
char name[20];
int age;
};



int main()
{
    struct emp e = {"soicher",34};
    fiu(e);//error here-- type of formal parameter 1 is incomplete
}

void fiu (struct emp ee) // define function which takes an emp by value
{
    printf("%s %d\n",ee.name,ee.age);
}
