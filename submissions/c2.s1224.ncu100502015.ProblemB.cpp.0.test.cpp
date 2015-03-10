#include<iostream>
#include<string>
#include<sstream>
using namespace std;
string output ="";
bool str= false ;
bool error = false;
bool print = false;
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
                //cout<<"s"<<endl;
                output+="strdcl s";
                output+="\n";
                id(x);
                in>>x;
                quote(x);
            }
            else if(print){
                output+="print p";
                output+="\n";
                id(x);
            }
            else if(error)
            {
                output = "invalid scanner";
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
            if(!str || !print){
                output =  "invalid";
            }
            break;
        }
        //str = false;
        //error = false;
        //print = false;
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
    }
    else if(input =="p")
    {
        print = true;
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
            output = "invalid";
            //cout<< "invalid id"<<endl;
        }
    }
    else
    {
        output = "invalid id";
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
                output = "invalid";
                //cout<< "invalid string"<<endl;
            }
        }
        else
        {
            error = true;
            output = "invalid";
            //cout<< "invalid quote"<<endl;
        }
    }
    else{
        output = "invalid";
    }
}










