#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void stmt();
string token(string);
bool Is_strdcl(string);
bool Is_id(string);
bool Is_quote(string);
bool Is_string(string);
bool Is_print(string);
int index = 0;
bool Is_Error = false;
bool before_string = true;
bool before_print = true;
struct astring
{
	string type;
	string value;
};
astring astr[6];
int main()
{
	stmt();
	if(Is_Error)
	{
		cout << "valid input" << endl;
	}
	else
	{
		for(int i=0;i<index;i++)
		{
			cout << astr[i].type << " " << astr[i].value << endl;
		}
	}
	system("pause");
	return 0;
}
void stmt()
{
	string ts = "";
	before_string = true;
	cin >> ts;
	if(Is_strdcl(ts))
	{
		astr[index].type = "strdcl";
		astr[index].value = ts;
		index++;
		cin >> ts;
		if(Is_id(ts))
		{
			astr[index].type = "id";
			astr[index].value = ts;
			before_string = false;
			index++;
			cin >> ts;
			if(Is_quote(ts.substr(0,1)))
			{
				astr[index].type = "quote";
				astr[index].value = ts.substr(0,1);
				index++;
				if(Is_string(ts.substr(1,ts.length()-2)))
				{
					astr[index].type = "string";
					astr[index].value = ts.substr(1,ts.length()-2);
					before_print = false;
					index++;
					if(Is_quote(ts.substr(ts.length()-1,1)))
					{
						astr[index].type = "quote";
						astr[index].value = ts.substr(ts.length()-1,1);
						index++;
						cin >> ts;
						if(Is_print(ts))
						{
							astr[index].type = "print";
							astr[index].value = ts;
							index++;
							cin >> ts;
							if(Is_id(ts))
							{
								astr[index].type = "id";
								astr[index].value = ts;
								index++;
							}
							else
							{
								Is_Error = true;
							}
						}
					}
					else
					{
						Is_Error = true;
					}
				}
				else
				{
					Is_Error = true;
				}
			}
			else
			{
				Is_Error = true;
			}
		}
		else
		{
			Is_Error = true;
		}
	}
	else
	{
		Is_Error = true;
	}
}
string token(string str)
{
	if(Is_strdcl(str))
	{
		return "strdcl";
	}
	else if(Is_id(str))
	{
		return "id";
	}
	else if(Is_quote(str))
	{
		return "quote";
	}
	else if(Is_string(str))
	{
		return "string";
	}
	else if(Is_print(str))
	{
		return "print";
	}
	else
	{
		return "Error";
	}
}
bool Is_strdcl(string st)
{
	if(st == "s")
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Is_id(string st)
{
	char c = st[0];
	int ASCII = (int)c;
	if(st.length() == 1)
	{
		if(((ASCII>=97 && ASCII <= 111) || (ASCII>= 113 && ASCII <= 114) || (ASCII >= 116 && ASCII <= 122)))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
bool Is_quote(string st)
{
	char c = st[0];
	int ASCII = (int)c;
	if(ASCII == 34 || ASCII == 92)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Is_string(string st)
{
	int ASCII;
	bool check = true;
	for(int i=0;i<st.length();i++)
	{
		ASCII = (int)st[i];
		if(((ASCII >= 97 && ASCII <= 122) || (ASCII >= 65 && ASCII <= 90) || (ASCII >= 48 && ASCII <= 57)))
		{
			check = true;
		}
		else
		{
			check = false;
		}
	}
	if(check)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Is_print(string st)
{
	if(st == "p")
	{
		return true;
	}
	else
	{
		return false;
	}
}