#include <iostream>
#include <cassert>
#include <string>
using namespace std;


int main ()
{

// int
    assert(1 + 1 == 2);
    assert(-2 - -1 <= 0);
    assert(2 * 3 != 7);
    assert(4 / 2 > 1);
    assert(5 % 2 == 1);

// double
    assert(1.0 / 3.0 > 0.32);
    assert(1.0 / 3.0 < 0.34);
    assert(0.25 * 2 == 0.5);
    assert(0.25 + 0.25 == 1.0 / 2.0);
    assert(0.25 - 0.05 == 0.2);
    assert(1.0 != 0.1 + 0.1 +0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1); //esto pasa porque el nro se pasa con potencias de base binaria a base decimal.


// bool
    assert(true != false or true);
    assert(false == false or true);
    assert(true == true and true);

// char
    assert('A' + 1 == 'B');
    assert('B' - 'A' == 1);

// string
    assert("AB" != "AC");
    assert(string("hola").length()<5);
    assert(string("hola")+string("bro")==string("holabro"));

// unsigned
    assert(3u>=3);

    

    std::cout <<"buena\n";

    //printf("%d\n", b);
    //printf("%d\n", i);
    //printf("%d\n", c);
    //printf("%d\n", u);
    //printf("%d\n", u2);
    //printf("%d\n", d);
    
    return 0;
}