#include "test.h"
// #include "statistics.cpp"

struct USER test(string filepath, int testNUM, USER user, int mode)
{
  ifstream testFile;
  testFile.open(filepath);
  int rightAnswers, wrongAnswers;
  string question, howToAnswer, rightAnswer, userAnswer;

  for (int i = 1; i != 0;)
  {
    cout << "---------------------\n";
    getline(testFile, question);
    if (question == "\0" || testFile.eof())
      break;
    getline(testFile, howToAnswer);
    getline(testFile, rightAnswer);
    cout << question << "\n";
    cout << howToAnswer << "\n>";
    cin >> userAnswer;

    if (boost::to_lower_copy(userAnswer) == boost::to_lower_copy(rightAnswer))
    {
      if (mode == 1)
      {
        cout << "správně\n";
      }
      rightAnswers += 1;
    }
    else
    {
      if (mode == 1)
      {
        cout << "správná odpoveď je: >" << rightAnswer << "<\n";
      }
      wrongAnswers += 1;

      // cout << "neni spravne\n";
    }
  }

  cout << "správne odpovedi: " << rightAnswers << "\n";
  cout << "chybný odpovedi: " << wrongAnswers << "\n";
  if (mode == 0)
  {
    switch (testNUM)
    {
    case 1:
      user.kryptografie.rightAnswers = rightAnswers;
      user.kryptografie.wrongAnswers = wrongAnswers;
      break;
    case 2:
      user.romanNums.rightAnswers = rightAnswers;
      user.romanNums.wrongAnswers = wrongAnswers;
      break;
    case 3:
      user.millionaire.rightAnswers = rightAnswers;
      user.millionaire.wrongAnswers = wrongAnswers;
      break;
    case 4:
      user.historie.rightAnswers = rightAnswers;
      user.historie.wrongAnswers = wrongAnswers;
      break;
    case 5:
      user.geography.rightAnswers = rightAnswers;
      user.geography.wrongAnswers = wrongAnswers;
      break;
    case 6:
      user.right.rightAnswers = rightAnswers;
      user.right.wrongAnswers = wrongAnswers;
      break;
    }
  }
  return user;
}