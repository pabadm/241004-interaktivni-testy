#include <iostream>
#include <fstream>
#include <boost/algorithm/string.hpp>

using namespace std;

struct testResults
{
  int rightAnswers = 0;
  int wrongAnswers = 0;
};
struct testResults test(string filepath);