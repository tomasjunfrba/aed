#include <cassert>
#include <iostream>
//#include <conio.h>
#include <string.h>
#include <stdio.h>

int main (void)
{
    bool b = true;
    int i = 5;
    char c[] = "t";
    unsigned char u = 128;
    unsigned int u2 = 2147483648;
    double d = 11;
    //string s;


    assert(i%2==1);
    //assert(c==);


    printf("%d\n", b);
    printf("%d\n", i);
    printf("%d\n", c);
    printf("%d\n", u);
    printf("%d\n", u2);
    printf("%d\n", d);
    
    return 0;
}