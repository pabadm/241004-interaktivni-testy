#include "main.h"

#include "src/registration.cpp"
#include "src/menu.cpp"

int main()
{
    cout << "---------------------\n"
         << "Registrujte se\n"
         << "---------------------\n";

    int isSuccsesfull = registration("../users.txt");
    if (isSuccsesfull == 1)
    {
        cout << "registrace byla projdena nepravidelne\n";
        return 1;
    }
    else if (isSuccsesfull == 2)
    {
        cout << "nepravidelne heslo\n";
        return 1;
    }

    menu();
}
