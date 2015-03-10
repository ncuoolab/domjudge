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
			if(!(FirstName[0]>= 'A' && FirstName[0] <= 'Z'))
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
		if(!((LastName[i]>= 'c' && LastName[i] <= 'z') || (LastName[i] == 'a')))
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
		//cout << "line:" <<line<<endl;

		while(in >> token) {


			//cout << "token: " << token<<endl;
			if(levelCheck(token))
			{
				result = result + "level " + token + "\n";
				tokens = tokens + " " + "level ";
			}
			else if(firstNameCheck(token))
			{
				result = result + "FirstName " + token + "\n";
				tokens = tokens + " " +  "FirstName ";
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

	//cout << "tokens: " << tokens <<endl;
	//cout << "result: "<<result << endl;

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
		{
			error = true;
			//cout << "level err" <<endl;
		}
		in >> id;
		if(id != "cid" && id != "FirstName")
		{
			error = true;
			//cout << "Did err" <<endl;
		}
		else if(id == "FirstName")
		{
			in >> id;
			if(id!= "LastName")
			{
				error = true;
				//cout << "la err" <<endl;
			}
		}

		// stmt part
		string ba;
		in >> ba;
		if(ba != "battle")
			error = true;

		in >> id;
		if(id != "cid" && id != "FirstName")
		{
			error = true;
			//cout << "sid err" <<endl;
		}
		else if(id == "FirstName")
		{
			in >> id;
			if(id!= "LastName")
			{
				error = true;
				//cout << "slast err" <<endl;
			}


		}
		
			if(error)
			{
				cout << "invalid input"<<endl;
			}
			else
				cout << result <<endl;
	}
	system("pause");

	return 0;
}