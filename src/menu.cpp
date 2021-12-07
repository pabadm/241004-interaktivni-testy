#include "menu.h"
#include "test.cpp"
#include <ctype.h>
// #include "registration.h"    cout << user.name << " " << user.surname << " " << user.age << " " << user.sex;

void chooseTest()
{
  for (int i = 1; i != 0;)
  {
    int number = 0;
    cout << "---------------------\n";
    cout << "1)Kryptografie\n";
    cout << "2)Římské číslice\n";
    cout << "3)///////\n";
    cout << "9)GO BACK\n";
    cout << "---------------------\n>";
    cin >> number;
    switch (number)
    {
    case 1:
      test("../tests/kryptografie.txt");
      break;
    case 2:
      test("../tests/romanNums.txt");
      break;
    case 3:
      cout << "neni pristupne\n";
      break;
    case 9:
      return;
      break;
    default:
      cout << "ERROR\n";
      break;
    }
    cout << "---------------------\n>1)continue?\n>";
    cin >> number;
    return;
  }
}

void menu()
{
  for (int i = 1; i != 0;)
  {
    int number = 0;
    cout << "---------------------\n";
    cout << "1) Vyplnit test\n";
    cout << "2) Statistika\n";
    cout << "---------------------\n>";
    cin >> number;
    switch (number)
    {
    case 1:
      chooseTest();
      break;
    case 2:
      cout << "neni pristupni\n";
      break;
    case 9:
      return;
      break;
    default:
      cout << "ERROR\n";
      return;
      break;
    }
  }
}