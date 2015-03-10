
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
		if(inumInput[i] > '0' || inumInput[i] < '9' || inumInput[i] > 'a' || inumInput[i] < 'z')
		{
			cout << "id"<< ' '  << input << endl;
			cout << "assign" << ' ' << assignInput << endl;
			cout << "inum" << ' ' << inumInput << endl;
		}

		else
		{
			cout << "invaild input" << endl;
			system("pause");
			return 0;
		}
	}


	system("pause");
	return 0;
}


/*/
void Scanner(string S1, string S2, string S3)
{
	if(S1.size() != 1)
	{
		cout << "invaild input.";
		flag = false;
		return;
	}
}

int main()
{
	string input_1; string input_2; string input_3;

	Scanner(input_1, input_2, input_3);
	if(flag == false)
	{
		cout << "invaild input" << endl;
		system("pause");
		return 0;
	}


	system("pause");
	return 0;
}
/*/
