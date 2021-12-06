#include <iostream>
using namespace std;

#include "test.cpp"

void chooseTest()
{
  for (int i = 1; i != 0;)
  {
    int number = 0;
    cout << "---------------------\n";
    cout << "1)kryptografie\n";
    cout << "2)///////\n";
    cout << "9)GO BACK\n";
    cout << "---------------------\n>";
    cin >> number;
    switch (number)
    {
    case 1:
      test("../kryptografie.txt");
      break;
    case 2:
      cout << "neni pristupne\n";
      break;
    case 9:
      return;
      break;
    default:
      cout << "error\n";
      break;
    }
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
      cout << "error\n";
      break;
    }
  }
}