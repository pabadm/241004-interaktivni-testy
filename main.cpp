#include "main.h"

#include "src/registration.cpp"
#include "src/menu.cpp"
#include "src/statistics.cpp"

static USER user;

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

    cout << "\n---------------------\n";
    cout << "Vítáme vás,\n";
    cout << user.name << " " << user.surname << "\n";
    // writeStatistics(user);
    menu();
}
