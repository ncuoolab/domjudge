#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

bool matchstring(string);
bool matchs1(char);
bool matchs2(char);
bool matchs3(char);
bool matchid(char);
void parser(string);
bool check(int);

string token;
string corr = "1234352";
string s[7];
string ins;
int main()
{
	string input;
	int count=0;
	while(cin>>input)
	{
	    ins += input;
    }
    for(int i=0;i<ins.size();i++){
        if(ins[i] == 's')
		{
		   parser("1");
		   s[count++]="strdcl s";
		}
		else if(ins[i] == 'p')
		{
		   parser("5");
		   s[count++]="print p";
		}
		else if(matchid(ins[i]))
        {
            parser("2");
			s[count++]="id "+ins.substr(i,i);
        }
		else if(ins[i]=='\"')
		{
            string temp;
            for(int j = i+1;j<ins.size();j++){
                if(ins[j]=='\"')
                    break;
                else if(ins[j]==NULL){
                    cout<<"valid input";
                    system("pause");
                    return 0;
                }
                else if(j==ins.size()-1){
                    cout<<"valid input";
                    system("pause");
                    return 0;
                }
                temp +=ins[j];
            }
            if(matchstring(temp)){
                parser("3");
                parser("4");
                parser("3");
                s[count++]="quote \"";
                s[count++]="string "+temp;
                s[count++]="quote \"";
                i+=temp.size()+1;
            }
            else
            {
                cout<<"valid input";
                system("pause");
                return 0;
            }
        }
		else{ 
            cout<<"valid input";
            system("pause");
            return 0;
		}
		if(check(count))
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
	else if(token[7]!='\0'){
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
    if(in-'a'>=0 && in-'z'<=0 && in!='p' && in!='s')
    {
       return true;
    }
    return false;
}

bool matchstring(string in)
{
    for(int i=0;i<in.size();i++)
    {
        if(matchs1(in[i]) || matchs2(in[i]) || matchs3(in[i]))
            continue;
        else
            return false;
    }
    return true;
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


void parser(string in)
{
	token+=in;
}

bool check(int index)
{
    for(int i=0;i<index;i++){
        if(token[i]==corr[i])
            continue;
        return false;
    }
    return true;
}
