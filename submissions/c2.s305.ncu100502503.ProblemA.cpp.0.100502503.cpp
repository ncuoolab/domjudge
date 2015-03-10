#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	
	string input;
	string assignInput;
	string inumInput;

	cin >> input;
	cin >> assignInput;
	cin >> inumInput;

	if(input.size() > 1)
	{
		cout << "invalid input";
		system("pause");
		return 0;
	}
	if(input[0] < 'a' || input[0] > 'z')
	{
		cout << "invaild input."; 
		system("pause");
		return 0;
	}

	if(assignInput.size() > 1)
	{
		cout << "invalid input."; 
		system("pause");
		return 0;
	}
	if(assignInput[0] != '=')
	{
		cout << "invaild input.";
		system("pause");
		return 0;
	}

	if(inumInput.size() < 1)
	{
		cout << "invaild input";
		system("pause");
		return 0;
	}
	for(int i = 0; i < inumInput.size(); i++)
	{
		if(inumInput[i] < '0' || inumInput[i] > '9')
		{
			cout << "invaild input" << endl;
			system("pause");
			return 0;
		}
	}

	cout << "id"<< ' '  << input << endl;
	cout << "assign" << ' ' << assignInput << endl;
	cout << "inum" << ' ' << inumInput << endl;
	
	system("pause");
	return 0;
}