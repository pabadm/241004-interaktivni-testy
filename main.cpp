#include "main.h"

#include "src/registration.cpp"
#include "src/menu.cpp"

USER user;

int main()
{
    cout << "---------------------\n";
    cout << "Registrujte se\n";
    cout << "---------------------\n";

    user = registration("../users.txt");
    if (user.isRegisteredINT == 1)
    {
        cout << "registrace byla projdena nepravidelne\n";
        return 1;
    }
    else if (user.isRegisteredINT == 2)
    {
        cout << "nepravidelne heslo\n";
        return 1;
    }

    cout << user.name << " " << user.surname << "\n";
    cout << user.name << " " << user.surname << "\n";
    cout << "Vítáme vás,\n";
    cout << user.name << " " << user.surname << "\n";
    menu();
}
