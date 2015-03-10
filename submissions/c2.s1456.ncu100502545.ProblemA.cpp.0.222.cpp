#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	string input;
	string out = "";
	int count = 0;
	getline(cin,input);


	for(int i = 0; i< input.size() ; i++)
	{

		if(input[i] != 32)
		{
			if(count == 0 && 97 <= input[i] && input[i] <= 122)
			{
			out = out +"id " + input[i] + "\n";
			count++;
		    }
			else if(count == 1 && input[i] == 61)
			{
				out = out + "assign " + input[i] + "\n";
				count++;
			}
			else if(count == 2 && 97 <= input[i] && input[i] <= 122)
			{
				out = out + "id " + input[i];
			}
			else if(count == 2 &&  48 <= input[i] && input[i] <= 57)
			{
				out = out + "inum " + input[i];
				count ++;
			}
			else if(count == 3 &&  48 <= input[i] && input[i] <= 57)
			{
				out = out + input[i];
			}
			else
			{
				out = "valid input";
				break;
			}
		}

	}
	cout<<out;



	system("pause");

	return 0;
}
