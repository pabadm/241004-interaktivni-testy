#include "registration.h"

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
  string age, sex;
  ifstream users;

  int isRegisteredINT = 0;

  users.open(filepath);
  for (int i = 1; i != 0;)
  {
    users >> name >> surname >> age >> sex >> password;
    if (name == user.name && surname == user.surname &&
        age == user.age && sex == user.sex)
    {
      cout << "---------------------\n";
      cout << "JSTE REGISTROVANI\nZadejte svoje heslo\n>";
      for (int b = 0; b != 1;)
      {
        cin >> enteredPassword;
        if (enteredPassword == password)
        {
          isRegisteredINT = 1;
          i = 0;
          b = 1;
          break;
        }
        else
        {
          cout << "---------------------\n";
          cout << "Nespravne heslo\nZadejte svoje heslo\n";
          b = 0;
          isRegisteredINT = 0;
          continue;
        }
      }
      //JSTE REGISTROVANI
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

struct USER registration(string filepath)
{
  USER user;
  string name, surname, password;
  string age, sex;

  cout
      << "zadejte jmeno\n>";
  cin >> name;
  cout << "zadejte prijmeni\n>";
  cin >> surname;
  cout << "zadejte vas vek \n>";
  cin >> age;
  if (stoi(age) <= 0)
  {
    cout << "byl zadan nepravidelni vek \n";
    user.isRegisteredINT = 1; //chyba
    return user;
  }
  cout << "zadejte pohlavi\n muz - 1 zena - 2\n>";
  cin >> sex;
  if (stoi(sex) != 1 && stoi(sex) != 2)
  {
    cout << "pohlavi bylo zadano nepravidelne \n";
    user.isRegisteredINT = 1; //chyba
    return user;
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
  user.filename = createFilename(user);

  int isRegisteredINT = isRegistered(filepath, user);

  if (isRegisteredINT == 1)
  {
    user = readStatistics(user);
    user.isRegisteredINT = 0; // bez chyb
    return user;
  }

  else if (isRegisteredINT == 0)
  {
    cout << "zadejte heslo\n>";
    cin >> password;
  }
  else if (isRegisteredINT == 2)
  {
    user.isRegisteredINT = 2;
    return user;
  }

  writeToUsers(filepath, user, password);

  user.isRegisteredINT = 0; //bez chyb
  return user;
}
//filename pro statistiku
string createFilename(USER user)
{
  string filename = "../statistics/";
  filename.append(user.name);
  filename.append("_");
  filename.append(user.surname);
  filename.append("_");
  filename.append(user.age);
  filename.append("_");
  filename.append(user.sex);
  filename.append(".txt");
  return filename;
}

struct USER readStatistics(USER user)
{
  int num, rightAnswers, wrongAnswers;
  ifstream statsFile;
  statsFile.open(user.filename);
  if (statsFile.is_open())
  {
    statsFile >> num >> rightAnswers >> wrongAnswers;
    user.kryptografie.rightAnswers = rightAnswers;
    user.kryptografie.wrongAnswers = wrongAnswers;

    statsFile >> num >> rightAnswers >> wrongAnswers;
    user.romanNums.rightAnswers = rightAnswers;
    user.romanNums.wrongAnswers = wrongAnswers;

    statsFile >> num >> rightAnswers >> wrongAnswers;
    user.millionaire.rightAnswers = rightAnswers;
    user.millionaire.wrongAnswers = wrongAnswers;

    statsFile >> num >> rightAnswers >> wrongAnswers;
    user.historie.rightAnswers = rightAnswers;
    user.historie.wrongAnswers = wrongAnswers;

    statsFile >> num >> rightAnswers >> wrongAnswers;
    user.geography.rightAnswers = rightAnswers;
    user.geography.wrongAnswers = wrongAnswers;

    statsFile >> num >> rightAnswers >> wrongAnswers;
    user.right.rightAnswers = rightAnswers;
    user.right.wrongAnswers = wrongAnswers;

    statsFile.close();
    return user;

    statsFile.close();
  }
  return user;
}