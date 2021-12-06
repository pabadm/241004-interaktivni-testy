#include "test.h"
#include <fstream>

struct testResults test(string filepath)
{
  ifstream file;
  file.open(filepath);
  testResults result;
  string question, howToAnswer, rightAnswer, userAnswer;

  for (int i = 1; i != 0;)
  {
    cout << "-------------------------\n";
    getline(file, question);
    if (question == "\0")
      break;
    getline(file, howToAnswer);
    getline(file, rightAnswer);
    cout << question << "\n"
         << howToAnswer << "\n>";
    cin >> userAnswer;
    if (userAnswer == rightAnswer)
    {
      result.rightAnswers += 1;
      // cout << "spravne\n";
    }
    else
    {
      result.wrongAnswers += 1;
      // cout << "neni spravne\n";
    }
  }

  cout << "spravne odpovedi: " << result.rightAnswers << "\n";
  cout << "spatne odpovedi: " << result.wrongAnswers << "\n";

  return result;
}