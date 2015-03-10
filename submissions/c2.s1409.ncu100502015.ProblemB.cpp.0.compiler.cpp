#include<iostream>
#include<string>
#include<sstream>
using namespace std;
string output ="";
bool str= false ;
bool error = false;
bool print = false;
bool str2 = false;
bool print2 =false;
void scanner(string input);
void id(string input);
void quote(string input);

int main()
{
    string input;
    int i=0;
    while(getline(cin,input))
    {

        //cout<<i<<endl;
        istringstream in(input);
        string x;

        while(in>>x)
        {
            //cout<<x<<endl;
            if(str)
            {
                //cout<<x<<endl;
                string temp_id ="";
                //cout<<"s"<<endl;
                output+="strdcl s";
                output+="\n";
                if(x.size()<=1){
                    id(x);
                    in>>x;
                    quote(x);
                }

                else{
                    string temp="";
                    temp = x[0];
                    //cout<<temp<<endl;
                    id(temp);
                    for(int i=1;i<x.size();i++){
                        temp_id+=x[i];
                    }
                    //cout<<temp_id<<endl;
                    quote(temp_id);
                }

            }
            else if(print){
                output+="print p";
                output+="\n";
                id(x);
            }
            else if(error)
            {
                output = "valid input";
                //error = true;
                break;
            }
            else
            {
                scanner(x);
            }
        }
        i++;
        if(i==2){
            if(!str2 || !print2){
                output =  "valid input";
            }
            break;
        }
    }
    cout<<output<<endl;
    output = "";

    return 0;
}
void scanner(string input)
{
    if(input == "s")
    {
        str = true;
        str2 = true;
    }
    else if(input =="p")
    {
        print = true;
        print2 =true;
    }
    else
    {
        error = true;
    }
}
void id(string input)
{
    if(!error)
    {
        //cout<<input<<endl;
        if(input>="a" && input<="o" || input =="q" || input=="r" || input>="t"&&input<="z")
        {
            output+= "id ";
            output+= input;
            output+="\n";
            //cout<<"id "<<input<<endl;
        }
        else
        {
            error = true;
            output = "valid input";
            //cout<< "invalid id"<<endl;
        }
    }
    else
    {
        output = "valid input ";
    }
}
void quote(string input)
{
    if(!error)
    {
        // cout<<input<<endl;
        if(input[0]=='\"' && input[input.size()-1]=='\"')
        {
            string temp="";
            output+="quote ";
            output+='\"';
            output+="\n";
            for(int i=1; i<input.size()-1; i++)
            {
                temp+=input[i];
            }
            if((temp>="a"&& temp<="z")|| (temp >="A" && temp<="Z" )|| (temp>= "0" && temp<="9"))
            {
                output+="string ";
                output+= temp;
                output+="\n";
                output+="quote ";
                output+='\"';
                output+="\n";
                str = false;
            }
            else
            {
                error = true;
                output = "valid input";
                //cout<< "invalid string"<<endl;
            }
        }
        else
        {
            error = true;
            output = "valid input";
            //cout<< "invalid quote"<<endl;
        }
    }
    else{
        output = "valid input";
    }
}










