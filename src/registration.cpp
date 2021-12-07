#include "registration.h"

USER user;

void writeToUsers(string filepath, USER user, string password)
{
  ofstream users;
  users.open(filepath, ios_base::app);
  users << user.name << " " << user.surname << " " << user.age << " " << user.sex << " " << password << endl;
  users.close();

  cout << "REGISTRACE USPESNE DOKONCENA\n";
}

int isRegistered(string filepath, USER user)
{
  string enteredPassword;
  string name, surname, password;
  int age, sex;
  ifstream users;

  int isRegisteredINT = 0;

  users.open(filepath);
  for (int i = 1; i != 0;)
  {
    users >> name >> surname >> age >> sex >> password;
    if (name == user.name && surname == user.surname &&
        age == user.age && sex == user.sex)
    {
      cout << "JSTE REGISTROVANI\nZadejte svoje heslo\n>";
      cin >> enteredPassword;
      if (enteredPassword == password)
      {
        isRegisteredINT = 1;
        i = 0;
        break;
      }
      else
      {
        //cout << "Nespravne heslo\n";
        return 2;
      }
      isRegisteredINT = 1; //JSTE REGISTROVANI
      i = 0;
      break;
    }
    else if (users.eof() == 1)
    {
      isRegisteredINT = 0; // NENI REGISTROVANI
      i = 0;
      break;
    }
  }
  users.close();
  return isRegisteredINT;
}

int registration(string filepath)
{
  string name, surname, password;
  int age, sex;

  cout
      << "zadejte jmeno\n>";
  cin >> name;
  cout << "zadejte prijmeni\n>";
  cin >> surname;
  cout << "zadejte vas vek \n>";
  cin >> age;
  if (age <= 0)
  {
    cout << "byl zadan nepravidelni vek \n";
    return 1; //chyba
  }
  cout << "zadejte pohlavi\n muz - 1 zena - 2\n>";
  cin >> sex;
  if (sex != 1 && sex != 2)
  {
    cout << "pohlavi bylo zadano nepravidelne \n";
    return 1; //chyba
  }
  /// z pAVlo do Pavlo
  boost::to_lower(name);
  boost::to_lower(surname);
  name[0] = toupper(name[0]);
  surname[0] = toupper(surname[0]);

  user.name = name;
  user.surname = surname;
  user.age = age;
  user.sex = sex;

  int isRegisteredINT = isRegistered(filepath, user);

  if (isRegisteredINT == 1)
  {
    return 0; // bez chyb
  }
  else if (isRegisteredINT == 0)
  {
    cout << "zadejte heslo\n>";
    cin >> password;
  }
  else if (isRegisteredINT == 2)
  {
    return 2;
  }

  writeToUsers(filepath, user, password);

  return 0; //bez chyb
}
