#include "registration.h"
#include <fstream>
USER user;

int isRegistered(string filepath, USER user)
{
  string name, surname;
  int age, sex;
  ifstream users;
  users.open(filepath);
  for (int i = 1; i != 0;)
  {
    users >> name >> surname >> age >> sex;
    if (name == user.name && surname == user.surname && age == user.age && sex == user.sex)
    {
      cout << "JSTE REGISTROVANI\n";
      users.close();
      return 1;
    }
    else if (users.eof() == 1)
    {
      users.close();
      return 0;
    }
  }
}

int registration(string filepath)
{
  int age, sex;
  cout
      << "zadejte jmeno\n>";
  cin >> user.name;
  cout << "zadejte prijmeni\n>";
  cin >> user.surname;
  cout << "zadejte vas vek \n>";
  cin >> age;
  if (age <= 0)
  {
    cout << "byl zadan nepravidelni vek \n";
    return 1;
  }
  cout << "zadejte pohlavi\n muz - 1 zena - 2\n>";
  cin >> sex;
  if (sex != 1 && sex != 2)
  {
    cout << "pohlavi bylo zadano nepravidelne \n";
    return 1;
  }
  user.age = age;
  user.sex = sex;

  if (isRegistered(filepath, user) == 1)
  {
    return 0;
  };

  ofstream users;
  users.open(filepath, ios_base::app);
  users << user.name << " " << user.surname << " " << user.age << " " << user.sex << endl;
  users.close();

  cout << "REGISTRACE USPESNE DOKONCENA\n";

  return 0;
}
