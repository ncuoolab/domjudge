#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
	string input;
	string output = "";
	int count = 0;
	getline(cin,input);
	for(int counter = 0; counter< input.size() ; counter++){
		if(input[counter] != 32){
			if(count == 0&&97 <= input[counter] && input[counter] <= 122){
			output = output +"id " + input[counter] + "\n";
			count++;
			}
			else if(count == 1 && input[counter] == 61){
				output = output + "assign " + input[counter] + "\n";
				count++;
			}
			else if(count == 2 )
			{
				if(97 <= input[counter] && input[counter] <= 122)
                {
                    output = output + "id " + input[counter];
                }
                else if(48 <= input[counter] && input[counter] <= 57)
                {
                    output = output + "inum " + input[counter];
                    count ++;
                }
			}
			else if(count == 3 )
			{
			    if(48 <= input[counter] && input[counter] <= 57)
                {
                    output = output + input[counter];
                }
            }
			else
			{
				output = "valid input";
				break;
			}
		}
	}
	cout << output;
	system("pause");
	return 0;
}
