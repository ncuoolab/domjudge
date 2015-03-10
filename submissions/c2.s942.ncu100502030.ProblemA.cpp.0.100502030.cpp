#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct Token
{
	string type;
	string value;

};

string source;
vector<Token> tokens;
int sourceindex = 0;
int tokenindex = 0;

/*
inline bool checkId(string id)
{
if(id.size()==1 && id[0] >= 'a'  && id[0] <= 'z')
return true;
else 
return false;
}

inline bool checkAs(string assign)
{
if(assign.size()==1 && (assign[0] = '='))
return true;
else 
return false;
}

inline bool checkInum(string Inum)
{
for(int i=0;i<Inum.size();i++)
{
if(Inum[i]<='0' && Inum[i]>='9')
return false;

}
return true;

}
*/


inline Token scanner()
{
	Token token;
	if(sourceindex==source.size())
		token.type = '$';
	else
	{
		while(source[sourceindex]==' ')
			sourceindex++;


		if(source[sourceindex]>='a' && source[sourceindex]<='z')
		{
			
			token.type = "id";
			token.value = source[sourceindex++];
		}
		else if(source[sourceindex]=='=')
		{
			token.type = "assign";
			token.value = source[sourceindex++];
		}
		else if(source[sourceindex]>='0' && source[sourceindex]<='9')
		{	
			token.type = "inum";
			token.value = source[sourceindex];
			while(++sourceindex!=source.size()  && (source[sourceindex]>='0' && source[sourceindex]<='9'))
				token.value = token.value + source[sourceindex];
			
		}
		else
		{
			token.type = "error";
		}

		
	}
	
	return token;



}

inline bool Val()
{
	
	if((tokenindex==tokens.size()))
	{
		tokenindex++;
		return false;
	}
	else if((tokens[tokenindex].type!="id" && tokens[tokenindex].type!="inum"))
	{
		tokenindex++;
		return false;
	}

	tokenindex++;
	return true;

}

inline bool Stmt()
{

	if((tokenindex==tokens.size()))
	{
		tokenindex++;
		return false;
	}
		
	else if(tokens[tokenindex++].type!="id" )
		return false;


	if((tokenindex==tokens.size()))
	{
		tokenindex++;
		return false;
	}
	else if(tokens[tokenindex++].type!="assign")
		return false;

	if(!Val())
		return false;


	tokenindex++;
	return true;

}


inline bool parse()
{
	if(!Stmt())
		return false;

	if((tokenindex==tokens.size()))
	{
		tokenindex++;
		return false;
	}
	else if(tokens[tokenindex++].type!="$")
		return false;

	return true;


}

int main()
{
	
	getline(cin, source);
	


	
	bool scannerPass = true;
	while(scannerPass)
	{	
		tokens.push_back(scanner());

		if(tokens.back().type == "error")
		{
			scannerPass = false;
			break;
		}

		else if(tokens.back().type == "$")
		{
			break;
		}

	}
	//cout << scannerPass <<endl;
	/*for(int i =0;i<tokens.size();i++)
		{
			
			cout << tokens[i].type << " "<<endl;
		}
	system("pause");*/

	if(scannerPass && parse())
	{
		for(int i =0;i<tokens.size()-1;i++)
		{
			cout << tokens[i].type << " "<<tokens[i].value<<endl;
		}

	}
	else
		cout << "valid input" << endl;
	/*in >> id >> assign >> val;

	if(checkId(id) && checkAs(assign) && checkVal(val)!=0 )
	cout << "id "<< id << "\nassign " << assign << "\n" << valType(checkVal(val)) << " "<< val << endl;
	else
	cout << "valid input" << endl;*/

	system("pause");
	return 0;
}

