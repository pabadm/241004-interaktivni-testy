#include "menu.h"
#include "test.cpp"
#include <ctype.h>
// #include "registration.h"    cout << user.name << " " << user.surname << " " << user.age << " " << user.sex;
#include "statistics.cpp"

struct USER chooseTest(USER user)
{
  for (int i = 1; i != 0;)
  {
    int number = 0;
    cout << "---------------------\n";
    cout << "1)Kryptografie\n";
    cout << "2)Římské číslice\n";
    cout << "3)Chcete být milionářem\n";
    cout << "4)Dějiny českých zemí\n";
    cout << "5)Zeměpis Ameriky\n";
    cout << "6)Právo ČR\n";
    cout << "7)///////\n";
    cout << "9)GO BACK\n";
    cout << "---------------------\n>";
    cin >> number;
    switch (number)
    {
    case 1:
      user = test("../tests/kryptografie.txt", 1, user);
      break;
    case 2:
      user = test("../tests/romanNums.txt", 2, user);
      break;
    case 3:
      user = test("../tests/millionaire.txt", 3, user);
      break;
    case 4:
      user = test("../tests/historie.txt", 4, user);
      break;
    case 5:
      user = test("../tests/geography.txt", 5, user);
      break;
    case 6:
      user = test("../tests/right.txt", 6, user);
      break;
    case 7:
      cout << "neni pristupne\n";
      break;
    case 9:
      return user;
      break;
    default:
      cout << "ERROR\n";
      break;
    }
    writeStatistics(user);
    cout << "---------------------\n>1)continue?\n>";
    cin >> number;
  }
  return user;
}

struct USER menu(USER user)
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
      user = chooseTest(user);
      break;
    case 2:
      for (int num = 1; num <= 6; num++)
      {
        showStatistics(user, num);
      }

      break;
    case 9:
      return user;
      break;
    default:
      cout << "ERROR\n";
      return user;
      break;
    }
  }
}