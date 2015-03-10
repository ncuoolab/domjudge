#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

bool matchstring(string);
bool matchid(char);
void scanner(string);
void parser(int);
bool check();

int token[7];
string s[7];
int main()
{
	string input;
	int count3=0;
	while(cin>>input)
	{
		scanner(input);
		count3++;
		if(count3>3)
			break;
    }
	if(check()){
		for(int i=0;i<7;i++){
			cout<<s[i]<<endl;
		}
	}
	system("pause");
	return 0;
}

void scanner(string input)
{
	 static int count=0;
     if(input[0] == 's')
		{
		   parser(1);
		   s[count++]="strdcl s";
		}
		else if(input[0] == 'p')
		{
		   parser(5);
		   s[count++]="print p";
		}
		else if(matchid(input[0]))
		{
			parser(2);
			s[count++]="id "+input.substr(0,1);
			if(matchstring(input))
			{
			    parser(3);
                parser(4);
                parser(3);
                s[count++]="quote \"";
                s[count++]="string "+input.substr(2,input.size()-3);
                s[count++]="quote \"";
			}
		}
		else{
            cout<<"valid input\n";
            cout<<input;
		}

}
bool matchid(char in)
{
    if(in=='s' || in =='p')
        return false;
    else
        return true;
}

bool matchstring(string in)
{
	if(in.size()>=2)
	{
		if(in[1]=='\"' && in[in.size()-1]=='\"')
			return true;
		else
			return false;
	}
	else
		return false;
}

void parser(int in)
{
	static int count2 = 0;
		token[count2++]=in;
}

bool check()
{
	if(token[0]==1 && token[1]==2 && token[2]==3 && token[3]==4 && token[4]==3 && token[5]==5 && token[6]==2){
		return true;
	}
	else
		return false;
}
