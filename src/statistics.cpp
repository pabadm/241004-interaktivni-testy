#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <fstream>
#include "../main.h"

void showStatistics(USER user, int num, int *pocetBodu)
{
  // int body = 0;
  switch (num)
  {
  case 1:
    if (user.kryptografie.rightAnswers != -1)
    {
      cout << "\tKryptografie:\n";
      cout << ">>spravné odpovědi:" << user.kryptografie.rightAnswers;
      cout << "\tšpatné odpovědi:"
           << user.kryptografie.wrongAnswers << "<<\n";
      *pocetBodu += user.kryptografie.rightAnswers;
    }
    else
    {
      cout << "nemáte statistiku testu z kryptografie\nstruct USER readStatistics(USER user)struct USER readStatistics(USER user)";
    }
    break;
  case 2:
    if (user.romanNums.rightAnswers != -1)
    {
      cout << "\tŘímské číslice:\n";
      cout << ">>spravné odpovědi:" << user.romanNums.rightAnswers;
      cout << "\tšpatné odpovědi:<<"
           << user.romanNums.wrongAnswers << "<<\n";
      *pocetBodu += user.romanNums.rightAnswers;
    }
    else
    {
      cout << "nemáte statistiku testu z Římských číslic\n";
    }
    break;
  case 3:
    if (user.millionaire.rightAnswers != -1)
    {
      cout << "\tChcete být milionářem:\n";
      cout << ">>spravné odpovědi:" << user.millionaire.rightAnswers;
      cout << "\tšpatné odpovědi:"
           << user.millionaire.wrongAnswers << "<<\n";
      *pocetBodu += user.millionaire.rightAnswers;
    }
    else
    {
      cout << "nemáte statistiku testu 'Chcete být milionářem'\n";
    }
    break;
  case 4:
    if (user.historie.rightAnswers != -1)
    {
      cout << "\tDějiny českých zemí:\n";
      cout << ">>spravné odpovědi:" << user.historie.rightAnswers;
      cout << "\tšpatné odpovědi:"
           << user.historie.wrongAnswers << "<<\n";
      *pocetBodu += user.historie.rightAnswers;
    }
    else
    {
      cout << "nemáte statistiku testu 'Dějiny českých zemí'\n";
    }
    break;
  case 5:
    if (user.geography.rightAnswers != -1)
    {
      cout << "\tZeměpis Ameriky:\n";
      cout << ">>spravné odpovědi:" << user.geography.rightAnswers;
      cout << "\tšpatné odpovědi:"
           << user.geography.wrongAnswers << "<<\n";
      *pocetBodu += user.geography.rightAnswers;
    }
    else
    {
      cout << "nemáte statistiku testu 'Zeměpis Ameriky'\n";
    }
    break;
  case 6:
    if (user.right.rightAnswers != -1)
    {
      cout << "\tPrávo ČR:\n";
      cout << ">>spravné odpovědi:" << user.right.rightAnswers;
      cout << "\tšpatné odpovědi:"
           << user.right.wrongAnswers << "<<\n";
      *pocetBodu += user.right.rightAnswers;
    }
    else
    {
      cout << "nemáte statistiku testu 'Právo ČR'\n";
    }
    break;
  default:
    cout << "nemáte statistiku";
    break;
  }
  // cout << "počet bodů: >" << body << "<\n";
  return;
}

void writeStatistics(USER user)
{
  ofstream statsFile;

  statsFile.open(user.filename);
  statsFile << 1 << " " << user.kryptografie.rightAnswers << " " << user.kryptografie.wrongAnswers << endl;

  statsFile << 2 << " " << user.romanNums.rightAnswers << " " << user.romanNums.wrongAnswers << endl;

  statsFile << 3 << " " << user.millionaire.rightAnswers << " " << user.millionaire.wrongAnswers << endl;

  statsFile << 4 << " " << user.historie.rightAnswers << " " << user.historie.wrongAnswers << endl;
  statsFile << 5 << " " << user.geography.rightAnswers << " " << user.geography.wrongAnswers << endl;
  statsFile << 6 << " " << user.right.rightAnswers << " " << user.right.wrongAnswers << endl;

  statsFile.close();
  return;
}