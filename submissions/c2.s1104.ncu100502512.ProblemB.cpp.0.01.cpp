#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>

using namespace std;

bool check = true;
string str;
string astr[7];
int count = 0;
bool Isstrdcl(string);
bool Isid(string);
bool Isquote(string);
bool Isstring(string);
bool Isprint(string);
void stmt();
string token(string);


int main(){

    stmt();

  if(check)
    {

        for(int i=0;i<count;i++)
        {
            cout << token(astr[i]) << " " << astr[i] << endl;
        }
    }
    else
    {
        cout << "valid input" << endl;
       /* for(int i=0;i<count;i++)
        {
            cout  << astr[i] << endl;
        }*/
    }



 system("pause");
 return 0;

}

string token(string str)
{
    string type;

    if(Isstrdcl(str))
        type = "strdcl";
    else if(Isid(str))
        type = "id";
    else if(Isquote(str))
        type = "quote";
    else if(Isprint(str))
        type = "print";
        else if(Isstring(str))
        type = "string";
    else
        type = "invalid input";
    return type;

}

bool Isstrdcl(string str){

        for(int i=0;i<str.size();i++){

        if(str[0] == 's'){
            return true;
        }
        else
            return false;
        }

}

bool Isid(string str){

        if(str.size() == 1){
            if(!islower(str[0]) || str == "s" || str == "p" ){
                return false;
            }
            else
                return true;
        }
        else if(str.size()!=1){
            if((int)str[1] == 34){

                return true;

            }
                return false;
        }
        else
            return false;

}

bool Isquote(string str){

        for(int i=0;i<str.size();i++){
            if((int)str[i] == 34  ) {

                return true;

            }
            return false;
        }

}

bool Isstring(string str){

        for(int i=0;i<str.size();i++){

                if(!isalnum(str[i]))
                return false;
        }
        return true;

        }

bool Isprint(string str){
        for(int i=0;i<str.size();i++){
            if(str[i] == 'p'){
                return true;
            }
            else
                return false;
        }
}

void stmt(){
    string temp = "";
    cin>>str;

    //cout<<str;
    if(Isstrdcl(str)){
        //cout<<token(str)<<"a1";
        astr[count] = str;
            count ++;
            cin>>str;
            string id;
            id.assign(str,0,1);
           // cout<<id<<endl;
        if(Isid(id)){
            //cout<<token(str)<<"a2";
            astr[count] = id;
                count ++;

                string Astring;
                Astring.assign(str,1,str.size()-1);
               // cout<<Astring<<endl;
               // cout<<(int)str[str.size()-1]<<"a1"<<endl;
            if((int)Astring[0] == 34 && (int)Astring[Astring.size()-1]==34){

                for(int i=1;i<Astring.size()-1;i++)
                {
                    temp = temp + Astring[i];
                }
                astr[count] = (char)34;
                   count ++;
                //cout << temp << " haha" << endl;
                //cout << Isstring(temp) << " isstring" << endl;
                if(Isstring(temp)){
                   //cout<<token(str)<<"a4";
                   astr[count] = temp;
                   count ++;
                   astr[count] = (char)34;
                   count ++;
                   cin>>str;
                }
                else{
                check = false;
                //cout << "5" << endl;
         }
            }
            else{
                check = false;
               // cout << "6" << endl;
         }
                    if(Isprint(str)){
                        //cout<<token(str)<<"a6";
                        astr[count] = str;
                        count ++;
                        cin>>str;
                        if(Isid(str)){
                           // cout<<token(str)<<"a7";
                            astr[count] = str;
                            count ++;
                    }
                     else{
                        check = false;
                        // cout << "1" << endl;
                     }
                   }
                    else{
                        check = false;
                        //cout << "2" << endl;
                    }
                }
                  else{
                        check = false;
                       // cout << "3" << endl;
                  }
            }
             else{
                        check = false;
                      //  cout << "4" << endl;
             }


}


