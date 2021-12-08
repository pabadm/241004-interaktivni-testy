#include "menu.h"
#include "test.cpp"
#include <ctype.h>
#include "statistics.cpp"

struct USER chooseTest(USER user, int mode)
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
      if (user.kryptografie.rightAnswers >= 0)
      {
        cout << "tento test jste již psali\n";
      }
      else
      {
        user = test("../tests/kryptografie.txt", 1, user, mode);
        writeStatistics(user);
      }
      break;
    case 2:
      if (user.romanNums.rightAnswers >= 0)
      {
        cout << "tento test jste již psali\n";
      }
      else
      {
        user = test("../tests/romanNums.txt", 2, user, mode);
        writeStatistics(user);
      }
      break;
    case 3:
      if (user.millionaire.rightAnswers >= 0)
      {
        cout << "tento test jste již psali\n";
      }
      else
      {
        user = test("../tests/millionaire.txt", 3, user, mode);
        writeStatistics(user);
      }
      break;
    case 4:
      if (user.historie.rightAnswers >= 0)
      {
        cout << "tento test jste již psali\n";
      }
      else
      {
        user = test("../tests/historie.txt", 4, user, mode);
        writeStatistics(user);
      }
      break;
    case 5:
      if (user.geography.rightAnswers >= 0)
      {
        cout << "tento test jste již psali\n";
      }
      else
      {
        user = test("../tests/geography.txt", 5, user, mode);
        writeStatistics(user);
      }
      break;
    case 6:
      if (user.right.rightAnswers >= 0)
      {
        cout << "tento test jste již psali\n";
      }
      else
      {
        user = test("../tests/right.txt", 6, user, mode);
        writeStatistics(user);
      }
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
    // writeStatistics(user);
    cout << "---------------------\n>1)continue?\n>";
    cin >> number;
  }
  return user;
}

void menu(USER user)
{
  string actSex;
  for (int i = 1; i != 0;)
  {
    int number = 0;
    cout << "---------------------\n";
    cout << "1) Vyplnit test\n";
    cout << "2) Příprava k testu\n";
    cout << "3) Statistika\n";
    cout << "4) Učet\n";
    cout << "5) Log Out\n";
    cout << "---------------------\n>";
    cin >> number;
    switch (number)
    {
    case 1:
      user = chooseTest(user, 0);
      // 0 test na body
      break;
    case 2:
      user = chooseTest(user, 1);
      //1 - priprava k testu
      break;
    case 3:
      int pocetBodu;
      cout << "---------------------\n";
      for (int num = 1; num <= 6; num++)
      {
        showStatistics(user, num, &pocetBodu);
      }
      cout << "---------------------\n";
      cout << "Počet Bodů >" << pocetBodu << "<\n";
      cout << "---------------------\n>1)continue?\n>";
      cin >> number;

      break;
    case 4:
      cout << "---------------------\n";
      user.sex = 1 ? actSex = "mužský" : actSex = "ženský";
      cout << user.name << "\n"
           << user.surname << "\n"
           << user.age << " let\n"
           << actSex << "\n";
      cout << "---------------------\n>1)continue?\n>";
      cin >> number;
      break;
    case 5:
      return;
      break;
    default:
      number = 1;
      break;
    }
  }
}