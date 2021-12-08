#include <fstream>
#include <ctype.h>
#include <boost/algorithm/string.hpp>
#include "../main.h"

using namespace std;

void writeToUsers(string filepath, USER user);
int isRegistered(string filepath, USER user);
struct USER registration(string filepath);
string createFilename(USER user);
