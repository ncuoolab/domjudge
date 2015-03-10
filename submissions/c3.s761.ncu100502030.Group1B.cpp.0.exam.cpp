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

	//string all;
	string line;
	string result = "";
	string tokens = "";
	bool error = false;




	string token;

	while(getline(cin, line))
	{
		istringstream in(line);

		while(in >> token) {
			if(levelCheck(token))
			{
				result = result + "level " + token + "\n";
				tokens = tokens + " " + "level ";
			}
			else if(firstNameCheck(token))
			{
				result = result + "FirstName " + token + "\n";
				tokens + " " + "FirstName ";
			}
			else if(lastNameCheck(token))
			{
				result = result + "LastName " + token + "\n";
				tokens = tokens + " " + "LastName ";
			}
			else if(cidCheck(token))
			{
				result = result + "cid " + token + "\n";
				tokens = tokens + " " + "cid ";
			}
			else if(battleCheck(token))
			{
				result = result + "battle " + token + "\n";
				tokens = tokens + " " + "battle ";
			}
			else 
			{
				error = true;
			}
		}
	}
	if(error)
	{
		cout << "invalid input"<<endl;
	}
	else
	{
		istringstream in(tokens);
		string level;
		string id;
		//Dcl part
		in >> level;
		if(level != "level")
			error = true;
		in >> id;
		if(!(id == "cid" || id == "FirstName"))
		{
			error = true;
		}
		else if(id == "FirstName")
		{
			in >> id;
			if(id!= "LastName")
				error = true;
		}

		// stmt part
		string ba;
		in >> ba;
		if(ba != "battle")
			error = true;
		else
		{
			in >> id;
			if(!(id == "cid" || id == "FirstName"))
			{
				error = true;
			}
			else if(id == "FirstName")
			{
				in >> id;
				if(id!= "LastName")
					error = true;
			}
		}


		}
		if(error)
		{
			cout << "invalid input"<<endl;
		}
		else
			cout << result <<endl;


		system("pause");

	return 0;
}
