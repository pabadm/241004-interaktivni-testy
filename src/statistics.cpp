#include <iostream>
#include <fstream>
#include "../main.h"
#include <string>

void statistics(USER user)
{
}
void readStatistics(USER user)
{
}
void writeStatistics(USER user, string testName, string trueAnswers, string falseAnswers)
{
  ofstream statsFile;
  statsFile.open(user.filename, ios_base::app);
}
