#pragma once

#include <iostream>

using namespace std;

struct TEST_RESULT
{
  int rightAnswers = -1;
  int wrongAnswers = -1;
};

struct USER
{
  string name;
  string surname;
  string age;
  string sex;
  int isRegisteredINT;
  string filename;
  TEST_RESULT kryptografie;
  TEST_RESULT romanNums;
  TEST_RESULT millionaire;
  TEST_RESULT historie;
  TEST_RESULT geography;
  TEST_RESULT right;
};