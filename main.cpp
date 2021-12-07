// #pragma once
#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

#include "src/registration.cpp"
// #include "src/test.h"

#include "src/menu.cpp"

int main()
{
    int isSuccsesfull = registration("../users.txt");
    if (isSuccsesfull == 1)
    {
        cout << "registrace byla projdena nepravidelne\n";
        return 1;
    }
    menu();
}
