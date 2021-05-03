#include <iostream>
#include <string>
#include <math.h>

using namespace std;

string stuff;
string stuff1;
int shag = 0;
int tralala;
bool boooool;
int qoflet;
char letters[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int* stuffinnum;

int main()
{
	setlocale(LC_ALL, "rus");
	string lang;
	cout << "Choose language Выберите язык (eng / rus) \n";
	cin >> lang;
	while (lang != "eng" && lang != "rus")
	{
		cout << "\n";
		cin >> lang;
	}
	cout << "\n";
	while (true)
	{
		if (lang == "rus")
		cout << "Введите текст для шифра (текст только латинскими буквами, вместо пробелов использовать '_' ) ";
		else
		cout << "Put your text here (only english language, use '_' instead of space) ";
		cin >> stuff;
		if (lang == "rus")
		cout << "Теперь шаг ";
		else
		cout << "Now write a shift ";
		cin >> shag;
		if (true)
		{
			if (shag < 0)
				boooool = false;
			else
				boooool = true;
			shag = abs(shag);
			int i = 0;
			while (int(shag / pow(10, i)) > 1)
			{
				i++;
			}
			tralala = i + 1;
		}
		qoflet = stuff.size();
		stuff1 = stuff;
		stuffinnum = new int[qoflet];
		for (int i = 0; i < qoflet; i++) stuffinnum[i] = 0;

		for (int i = 0; i < qoflet; i++)
			for (int u = 0; u < 26; u++)
				if (stuff[i] == letters[u]) stuffinnum[i] = u;

		bool cont = true;

		for (int i = 0; i < qoflet; i++) if (stuffinnum[i] == -1) cont = false;

		if (!cont)
		{
			if (lang == "rus")
			cout << "Ошибка, использованы недопустимые знаки \n\n";
			else
			cout << "Error, you used a not english letters \n\n";
		}
		else
		{
			for (int i = 0; i < qoflet; i++)
			{
					if (boooool) stuffinnum[i] += int(shag / (pow(10, i % tralala))) % int(pow(10, (i % tralala) + 1));
					else stuffinnum[i] -= int(shag / (pow(10, i % tralala))) % int(pow(10, (i % tralala) + 1));

					while (stuffinnum[i] < 0) stuffinnum[i] += 26;
					stuffinnum[i] = stuffinnum[i] % 26;
			}
			for (int i = 0; i < qoflet; i++)
			{
				stuff[i] = letters[stuffinnum[i]];
			}
			for (int i = 0; i < qoflet; i++)
			{
				if (stuff1[i] == '_') stuff[i] = stuff1[i];
			}
			if (lang == "rus")
			cout << "Выход: " << stuff << "\n\n";
			else
			cout << "Output: " << stuff << "\n\n";
		}
	}
}