#include <iostream> 
#include <cstdlib> 
#include <string> 
using namespace std; 

bool check = true;
string aa[6];
string type[6];
int t = 0;
int index = 0;

void stmt(){
	char a;
	string b;
	cin >> a;
	string combine;
	if(a == 'l')
	{
		cin >> b;
		combine = a + b;
		aa[t++] = combine;
		type[index++] = "level";
	} 
	else if(a == 'b')
	{
		combine = a;
		aa[t++] = combine;
		type[index++] = "battle";
	}else
	{
		check = false;
		cout << "invalid input";
	}
	
	cin >> a;
	cin >> b;
	combine = a + b;
	if(a == 0 ||a == 1 ||a == 2 ||a == 3 ||a == 4 ||a == 5 ||a == 6 ||a == 7 ||a == 8 ||a == 9)
	{

		aa[t++] = combine;
		type[index++] = "cid";

	}else
	{
		aa[t++] = combine;
		type[index++] = "FirstName";
		cin >> b;
		aa[t++] = b;
		type[index++] = "LastName";
	}
}

int main(){
	stmt();
	stmt();
	for(int i = 0; i < t; i++)
	{
		cout << type[i] << " "<< aa[i] << endl;
	}
	system("pause");
	return 0;
}
/*
struct T
{ 
    string type; 
    string value; 
};

void compare(string ts,bool flag);

int main()
{
	string ts;
	T ts_array[6];
	int index = 0;   
	bool first = true;
	while(cin >> ts)
	{
		if(first == true && ts[0] != 'l')
		{
			cout << "invalid input";
		}
		else
		{
			for(int i=0;i<ts.length();i++)
			{
				if(first == true && (int)ts[i] >= 48 && (int)ts[i] <= 57)
				{
					ts_array[index].value.append(ts.substr(i,1));
				}
				else if((int)ts[i] >= 65 && (int)ts[i] <= 90)
				{

				}
			}
			index++;
		}
	}
	
	
		if(ts[0] != 'l')
		{
			cout << "invalid input";
		}
		else
		{
			ts_array[index].type = "level";
			ts_array[index].value = 'l';
			for(int i=1;i<ts.length();i++)
			{
				if(ts[i] != ' ')
				{
					if((int)ts[i] >= 48 && (int)ts[i] <= 57)
					{
						ts_array[index].value.append(ts.substr(i,1));
					}
					else if((int)ts[i] >= 65 && (int)ts[i] <= 90)
					{
						ts_array[index].type = "FirstName";
						ts_array[index].value.append(ts.substr(i,1));
					}
				}
				else
				{
					index++;
				}
			}
		}
	system("pause");
	return 0;
}
void compare(string ts)
{
	for(int i=0;i<ts.length();i++)
	{
		if(ts[i] == 'l')
		{
			if((int)ts[i] >= 48 && (int)ts[i] <= 57)
			{
				cout << "level";
			}
			else
			{

			}
		}
		else if(((int)ts[i] >= 65 && (int)ts[i] <= 90))
		{
			if((int)ts[i] >= 97 && (int)ts[i] <= 122)
			{

			}
		}
	}
}*/
