#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include<ctype.h>

using namespace std;



bool levelCheck(string level)
{
	bool check = true;
	if(level.size()<2)
		return false;
	if(level[0]!='l')
	{
		return false;
	}
	else 
	{
		for(int i=1;i<level.size();i++) 
		{
			if(!isdigit(level[i])) {
				return false;
			}
		}
		return true;
	}
}

bool firstNameCheck(string FirstName)
{
	for(int i=0;i<FirstName.size();i++)
	{
		if(i==0) 
		{
			if(!(FirstName[i]>= 'A' && FirstName[i] <= 'Z'))
				return false;
		}
		else
		{
			if(!(FirstName[i]>= 'a' && FirstName[i] <= 'z'))
				return false;

		}
	}
	return true;
}

bool lastNameCheck(string LastName)
{
	for(int i=0;i<LastName.size();i++)
	{
			if(!(LastName[0]>= 'c' && LastName[0] <= 'z') || LastName[0] == 'a')
				return false;
	}
	return true;
}

bool cidCheck(string cid)
{
	for(int i=0;i<cid.size();i++)
	{
			if(!isdigit(cid[i]))
				return false;
	}
	return true;
}

bool battleCheck(string battle) 
{
	if(battle.size()>1)
		return false;
	else if(battle[0] != 'b')
		return false;
	else
		return true;
}


int main () {


	string line;
	string result = "";
	bool error = false;
	getline(cin, line);
	istringstream in(line);

	string token;



	while(in >> token) {
		if(levelCheck(token))
		{
			result = result + "level " + token + "\n"; 
		}
		else if(firstNameCheck(token))
		{
			result = result + "FirstName " + token + "\n";
		}
		else if(lastNameCheck(token))
		{
			result = result + "LastName " + token + "\n";
		}
		else if(cidCheck(token))
		{
			result = result + "cid " + token + "\n";
		}
		else if(battleCheck(token))
		{
			result = result + "battle " + token + "\n";
		}
		else 
		{
			error = true;
		}
	}
	if(error)
		cout << " invalid input"<<endl;
	else
		cout << result;


	system("pause");
	return 0;
}
