#include <iostream>
#include <fstream>
#include <ctype.h>
#include <boost/algorithm/string.hpp>

using namespace std;

struct USER
{
  string name;
  string surname;
  int age;
  int sex;
  int isRegisteredINT;
};
void writeToUsers(string filepath, USER user);
int isRegistered(string filepath, USER user);
struct USER registration(string filepath);
