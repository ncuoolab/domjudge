#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

bool matchstring(string);
bool matchid(char);
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
		static int count=0;
		if(input !="s" && count3==0)
        {
            cout<<"valid input";
            return 0;
        }
        else if(input == "s")
		{
		     if(count==1)
            {
                cout<<"valid input";
            system("pause");
            return 0;
            }
		   parser(1);
		   s[count++]="strdcl s";
		}
		else if(input == "p")
		{
            if(count==1)
            {
                cout<<"valid input";
            system("pause");
            return 0;
            }
		   parser(5);
		   s[count++]="print p";
		}
		else if(matchid(input[0]))
		{
			parser(2);
			s[count++]="id "+input.substr(0,1);
			if(input.size()>1){
                if(matchstring(input))
                {
                    parser(3);
                    parser(4);
                    parser(3);
                    s[count++]="quote \"";
                    s[count++]="string "+input.substr(2,input.size()-3);
                    s[count++]="quote \"";
                }
                else{
                    cout<<"valid input";
                    system("pause");
                    return 0;
                }
            }
		}
		else{
            cout<<"valid input";
            system("pause");
            return 0;
		}
		count3++;
		if(count3>3)
			break;
    }
    if(s[1].substr(3,4)!=s[6].substr(3,4)){
        cout<<"valid input";
        system("pause");
            return 0;
	}
	else if(check()){
		for(int i=0;i<7;i++){
			cout<<s[i]<<endl;
		}
	}
	else{
       cout<<"valid input";
	}
	system("pause");
	return 0;
}

bool matchid(char in)
{
    if(in -'a'>=0 && in-'z'<=0)
    {
        if(in!='p' && in!='s')
           return true;
        return false;
    }
    return false;
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
