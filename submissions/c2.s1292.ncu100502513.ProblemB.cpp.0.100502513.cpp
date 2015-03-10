#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

bool matchstring(string);
bool matchs1(char);
bool matchs2(char);
bool matchs3(char);
bool matchid(char);
void parser(int);
bool check(int);

int token[100];
int corr[7] = {1,2,3,4,3,5,2};
string s[7];
string ori[100];
int main()
{
	string input;
	int count=0;
	int count2 = 0;
	while(cin>>input)
	{
	    ori[count2++] = input;
    }

    for(int i=0;i<count2;i++){
        if(ori[i] == "s")
		{
		   parser(1);
		   s[count++]="strdcl s";
		}
		else if(ori[i] == "p")
		{
		   parser(5);
		   s[count++]="print p";
		}
		else if(matchid(ori[i].at(0)))
		{
			parser(2);
			s[count++]="id "+ori[i].substr(0,1);
			if(ori[i].size()> 1){
                if(count==7){
                    cout<<"valid input";
                    system("pause");
                    return 0;
                }
                else if(matchstring(ori[i].substr(1,ori[i].size()-1)))
                {
                    parser(3);
                    parser(4);
                    parser(3);
                    s[count++]="quote \"";
                    s[count++]="string "+ori[i].substr(2,ori[i].size()-3);
                    s[count++]="quote \"";
                }
                else{
                    cout<<"valid input";
                    system("pause");
                    return 0;
                }
            }
		}
		else if(matchid(ori[i].at(0)))
		{
		     if(count==6){
                    cout<<"valid input";
                    system("pause");
                    return 0;
             }
             parser(3);
             parser(4);
             parser(3);
             s[count++]="quote \"";
             s[count++]="string "+ori[i].substr(1,ori[i].size()-2);
             s[count++]="quote \"";
		}
		else{
            cout<<"valid input";
            system("pause");
            return 0;
		}
		if(check(count-1))
        {
           continue;
        }
        else{
            cout<<"valid input";
            system("pause");
            return 0;
        }
    }
    if(count<7){
        cout<<"valid input";
        system("pause");
        return 0;
	}
    else if(s[1].substr(3,4)!=s[6].substr(3,4)){
        cout<<"valid input";
        system("pause");
            return 0;
	}
	else if(token[7]!=0){
        cout<<"valid input";
        system("pause");
            return 0;
	}

	else{
       for(int i=0;i<7;i++){
        cout<<s[i]<<endl;
       }
	}

	system("pause");
	return 0;
}

bool matchid(char in)
{
    if(in -'a'>=0 && in-'z'<=0 && in!='p' && in!='s')
    {
       return true;
    }
    return false;
}

bool matchstring(string in)
{
	if(in.size()>=2)
	{
		if(in[0]=='\"' && in[in.size()-1]=='\"')
		{
           for(int i=1;i<in.size()-1;i++)
           {
              if(matchs1(in[i]) || matchs2(in[i]) || matchs3(in[i]))
                 continue;
              else
                return false;
           }
           if(in.size()==2)
              return true;
           return true;
        }
	}
	else
		return false;
}

bool matchs1(char in)
{
    if(in -'a'>=0 && in-'z'<=0)
    {
       return true;
    }
    return false;
}

bool matchs2(char in)
{
    if(in -'A'>=0 && in-'Z'<=0)
    {
       return true;
    }
    return false;
}

bool matchs3(char in)
{
    if(in -'0'>=0 && in-'9'<=0)
    {
       return true;
    }
    return false;
}


void parser(int in)
{
	static int count2 = 0;
	token[count2++]=in;
}

bool check(int index)
{
	if(token[index]==corr[index]){
		return true;
	}
	else
		return false;
}
