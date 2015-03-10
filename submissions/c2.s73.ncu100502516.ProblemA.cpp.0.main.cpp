#include <iostream>
#include <string>
using namespace std;

char c;
string ter = "";
string nums = "";
string outString = "";
bool errorF = false;
void stmt();
void val();

int main()
{
    while(cin.get(c))
    {
        cout << "d" << endl;

        /*outString = "";
        ter = "";
        nums = "";

        stmt();

        if(!errorF)
            cout << outString;
        else
            break;*/
    }

	return 0;
}

void stmt()
{
    switch(c)
	{
		case 'a':
		case 'b':
		case 'c':
		case 'd':
		case 'e':
		case 'f':
		case 'g':
		case 'h':
		case 'i':
		case 'j':
		case 'k':
		case 'l':
		case 'm':
		case 'n':
		case 'o':
		case 'p':
		case 'q':
		case 'r':
		case 't':
		case 's':
		case 'u':
		case 'v':
		case 'w':
		case 'x':
		case 'y':
		case 'z':
			ter = "id";
			break;
		case '=':
			ter = "assign";
			break;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			ter = "inum";
			break;
		default:
			cout << "valid input" << endl;
			errorF = true;
			return;
	}

	if(ter != "id")
	{
		cout << "valid input" << endl;
		errorF = true;\
		return;
	}
	else
	{
		outString += "id ";
		outString += c;
		outString += "\n";

		cin.get(c);
		while(c == ' ')
            cin.get(c);

		switch(c)
		{
		case 'a':
		case 'b':
		case 'c':
		case 'd':
		case 'e':
		case 'f':
		case 'g':
		case 'h':
		case 'i':
		case 'j':
		case 'k':
		case 'l':
		case 'm':
		case 'n':
		case 'o':
		case 'p':
		case 'q':
		case 'r':
		case 't':
		case 's':
		case 'u':
		case 'v':
		case 'w':
		case 'x':
		case 'y':
		case 'z':
			ter = "id";
			break;
		case '=':
			ter = "assign";
			break;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			ter = "inum";
			break;
		default:
			cout << "valid input" << endl;
			errorF = true;
			return;
		}

		if(ter != "assign")
		{
			cout << "valid input" << endl;
			errorF = true;
			return;
		}
		else
		{
			outString += "assign ";
            outString += c;
            outString += "\n";
			val();
		}
	}
}
void val()
{
	cin.get(c);
	while(c == ' ')
        cin.get(c);

	switch(c)
	{
		case 'a':
		case 'b':
		case 'c':
		case 'd':
		case 'e':
		case 'f':
		case 'g':
		case 'h':
		case 'i':
		case 'j':
		case 'k':
		case 'l':
		case 'm':
		case 'n':
		case 'o':
		case 'p':
		case 'q':
		case 'r':
		case 't':
		case 's':
		case 'u':
		case 'v':
		case 'w':
		case 'x':
		case 'y':
		case 'z':
			ter = "id";
			break;
		case '=':
			ter = "assign";
			break;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			ter = "inum";
			break;
		default:
			cout << "valid input" << endl;
			errorF = true;
			return;
	}

	if(ter == "id")
	{
		outString += "id ";
		outString += c;
		outString += "\n";
	}
	else if(ter == "inum")
	{
		nums += c;
		cin.get(c);
		while(c - '0' <= 9 && c - '0' >= 0)
		{
			nums += c;
			cin.get(c);
		}

		outString += "inum ";
		outString += nums;
		outString += "\n";
	}
	else
    {
        cout << "valid input" << endl;
		errorF = true;
    }

}
