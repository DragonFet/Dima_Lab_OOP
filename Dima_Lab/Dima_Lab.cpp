#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <fstream>
#include <sstream>
using namespace std;

int N = 0;
int count_line;
string path = "base.txt";

class worcker {

public:
	void GetName()
	{
		cout << "Please input name" << endl;
		string name_;
		cin >> name_;
		name = name_;
	}
	string SetName()const {
		return name;
	}
	void GetSurename()
	{
		cout << "Please input surename" << endl;
		string surename_;
		cin >> surename_;
		surename = surename_;
	}
	string SetSurename()const 
	{
		return surename;
	}
	void GetDepartment()
	{
		cout << "Please input department" << endl;
		int department_;
		cin >> department_;
		department = department_;

	}
	int  SetDepartment()const
	{
		return department;
	}
	void GetSallary()
	{
		cout << "Please input sallary" << endl;
		double sallary_;
		cin >> sallary_;
		sallary = sallary_;
	}
	double SetSallary()const
	{
		return sallary;
	}
	void Menu()
	{
		cout << "Welcome" << endl;
		cout << "1-Add new worcker " << endl;
		cout << "2- Output all worcker " << endl;
		cout << "3-Find worcker with surename" << endl;
		cout << "4-Output all worcker with department" << endl;
		cout << "5- Sort with sallary " << endl;
		cout << "6- Exit " << endl;
		cout << "Please input your solution" << endl;
	}
	void Print2(const worcker h)
	{
		cout << "information" << endl;
		cout << "Name is :" << h.SetName() << endl;
		cout << "Surename is :" << h.SetSurename() << endl;
		cout << "Department is:" << h.SetDepartment() << endl;
		cout << "Sallary is :" << h.SetSallary() << endl;
		cout << endl;
	}
	void add(worcker* &base,int& N)
	{
		base[N].GetName();
		base[N].GetSurename();
		base[N].GetDepartment();
		base[N].GetSallary();
		N++;
	}
	void Print1(worcker base)
	{
		cout << "information" << endl;
		cout << "Name is :" << name << endl;
		cout << "Surename is :" << surename << endl;
		cout << "Department is:" << department << endl;
		cout << "Sallary is :" << sallary << endl;
		cout << endl;
	}
	void Print(worcker*& base, const int& N)
	{
		for (int i = 0; i < N; i++)
		{
			cout << "information" << endl;
			cout << "Name is :" << base[i].SetName() << endl;
			cout << "Surename is :" << base[i].SetSurename() << endl;
			cout << "Department is:" << base[i].SetDepartment() << endl;
			cout << "Sallary is :" << base[i].SetSallary() << endl;
			cout << endl;
		}
	}
	void Find_Surename(const string& surename_, worcker*& base, const int& N)
	{
		int find = 0;
		for (int i = 0; i < N; i++)
		{
			if (base[i].SetSurename() == surename_)
			{
				worcker h = base[i];
				Print2(h);
			}
		}
		if (find==0)
		{
			cout << "That surename uncorrect please try input new surename" << endl;
		}
	}
	friend void Find_department(worcker*& base, const int& N);
	void sort_SalLary(worcker*& base, const int& N)
	{
		map<int, string>people;
		for (int i = 0; i < N; i++)
		{
			people[base[i].SetSallary()] = base[i].SetName();
		}
		for (auto item:people)
		{
			for (int j = 0; j < N; j++)
			{
				if (item.second == base[j].SetName())
				{
					worcker tmp = base[j];
					tmp.Print1(tmp);
				}
			}
		}
	}
	void Gname(const string str)
	{
		name = str;
	}
	void Gsurename(const string str)
	{
		surename = str;
	}
	void Gdepartment(const int d)
	{
		department = d;
	}
	void Gsalary(const double d)
	{
		sallary = d;
	}
private:
	string name;
	string surename;
	int department;
	double sallary;
	static int count;

};

void Find_department( worcker*& base,const int &N)
{
	int department_;
	cout << "Please input department " << endl;
	cin >> department_;
	int value = 0;
	for (int i = 0; i <N ; i++)
	{
		if (base[i].SetDepartment()==department_)
		{
			worcker tmp = base[i];
			tmp.Print1(tmp);
			++value;
		}
	}
	if (value==0)
	{
		cout << "department uncorrect please try again" << endl;
	}
}
int string_to_int(string str)
{
	int result;
	istringstream iss(str, istringstream::in);
	iss >> result;
	return result;
}

double string_to_double(string str)
{
	double result;
	result  = atof(str.c_str());
	return result;
}
void Input_file(worcker*& base)
{
	fstream datainput;
	datainput.open(path, ios::out);
	for (int i = 0; i < N; i++)
	{
		datainput << base[i].SetName() << endl << base[i].SetSurename() << endl << base[i].SetDepartment()<<endl <<base[i].SetSallary()<<endl;
	}
	datainput.close();
}
void load_from_file(worcker*& base)
{
	int index = 0;
	fstream datainput;
	datainput.open(path, ios::in);
	for (int j = 0; j < count_line - 1;)
	{
		j = j + 4;
		for (int i = 0; i < 4; i++)
		{
			switch (i)
			{
			case 0:
			{
				string line;
				getline(datainput, line);
				base[index].Gname(line);
				break;
			}
			case 1:
			{
				string line;
				getline(datainput, line);
				base[index].Gsurename(line);
				break;
			}
			case 2:
			{
				string line;
				getline(datainput, line);
				base[index].Gdepartment(string_to_int(line)) ;
				break;
			}
			case 3:
			{
				string line;
				getline(datainput, line);
				base[index].Gsalary(string_to_double(line));
				break;
			}
			
			}
		}
		index++;
	}
	datainput.close();
}
void Value_N(int& N) {
	fstream read;
	read.open(path, ios::in);
	int count = 1;
	string per;
	while (read.peek() != EOF) {
		getline(read, per);
		++count;
		if (count % 4 == 0)
		{
			++N;
		}
	}
	count_line = count;
}



int main()
{
	Value_N(N);
	worcker* base = new worcker[1000000];
	worcker help;
	load_from_file(base);
	int solution = 1000;
	while (true)
	{
		help.Menu();
		cin >> solution;
		switch (solution)
		{
			case 1:
			{
				help.add(base, N);
				cout << "Complete" << endl;
				system("pause");
				system("cls");
				break;
			}

			case 2:
			{
				help.Print(base, N);
				cout << "complete,have a good day!" << endl;
				system("pause");
				system("cls");
				break;
			}
			case 3:
			{
				string str;
				cout << "Please input Surename" << endl;
				cin >> str;
				help.Find_Surename(str, base, N);
				system("pause");
				system("cls");
				break;
			}
			case 4:
			{
				Find_department(base, N);
				system("pause");
				system("cls");
				break;
			}
			case 5:
			{
				help.sort_SalLary(base, N);
				cout << endl;
				cout << "Complete" << endl;
				system("pause");
				system("cls");
				break;
			}
			case 6:
			{
				Input_file(base);
				return 0;
				break;
			}
		}
	}



	return 0;
}