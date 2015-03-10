#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
struct token{
    string type;
    string value;
    token *next;
};
void error();
bool level(string a);
bool idF(string b);
bool idL(string c);
bool cid(string d);
void output(token *p);

int main(){
    string a, b, c, d, t;
        token *start = new token;
        token *current = start;
        cin >> a;
        if(a[0]=='l'){
            cin >> b;
            if(level(a)){
                current->type = "level";
                current->value = "" + a;
                current->next = new token;
                current = current->next;
                if(cid(b)){
                    current->type = "cid";
                    current->value = ""+b;
                    current->next = new token;
                    current = current->next;
                    cin>>c;
                    if(c[0]=='b'){
                        current->type = "battle";
                        current->value = "b";
                        current->next = new token;
                        current = current->next;
                        cin >> b;
                        if(cid(b)){
                            current->type = "cid";
                            current->value = ""+b;
                            current->next = new token;
                            current = current->next;
                        }
                        else{
                            if(idF(b)){
                                current->type = "FirstName";
                                current->value = ""+b;
                                current->next = new token;
                                current = current->next;
                                cin >> c;
                                if(idL(c)){
                                    current->type = "LastName";
                                    current->value = ""+c;
                                    current->next = NULL;
                                    output(start);

                                }
                                else{
                                    error();
                                    //cout <<"6"<<endl;
                                }
                            }
                            else{
                                error();
                                //cout <<"7"<<endl;
                            }
                        }
                    }
                }
                else{
                    if(idF(b)){
                        current->type = "FirstName";
                        current->value = ""+b;
                        current->next = new token;
                        current = current->next;
                        cin >> c;
                        if(idL(c)){
                            current->type = "LastName";
                            current->value = ""+c;
                            current->next = new token;
                            current = current->next;
                            cin >> c;
                            if(c[0]=='b'){
                                current->type = "battle";
                                current->value = "b";
                                current->next = new token;
                                current = current->next;
                                cin >> b;
                                if(cid(b)){
                                    current->type = "cid";
                                    current->value = ""+b;
                                    current->next = NULL;
                                    output(start);

                                }
                                else{
                                    if(idF(b)){
                                        current->type = "FirstName";
                                        current->value = ""+b;
                                        current->next = new token;
                                        current = current->next;
                                        cin >> c;
                                        if(idL(c)){
                                            current->type = "LastName";
                                            current->value = ""+c;
                                            current->next = NULL;
                                            output(start);

                                        }
                                        else{
                                            error();
                                            //cout <<"1"<<endl;
                                        }
                                    }
                                    else{
                                        error();
                                        //cout << "2" <<endl;
                                    }
                                }
                            }
                            else{
                                error();
                                //cout <<"3"<<endl;
                            //break;
                            }
                        }
                        else{
                            error();
                            //cout <<"4"<<endl;
                       // break;
                        }
                    }

                }
            }
            else{
                error();
                //cout <<"5"<<endl;
                //break;
            }
        }
        /*else if(a[0]=='b'){
            current->type = "battle";
            current->value = "b";
            current->next = new token;
            current = current->next;
            cin >> b;
            if(cid(b)){
                current->type = "cid";
                current->value = ""+b;
                current->next = NULL;
                output(start);
                //break;
            }
            else{
                if(idF(b)){
                    current->type = "FirstName";
                    current->value = ""+b;
                    current->next = new token;
                    current = current->next;
                    cin >> c;
                    if(idL(c)){
                        current->type = "LastName";
                        current->value = ""+c;
                        current->next = NULL;
                        output(start);
                        //break;
                    }
                    else{
                        error();
                        //break;
                    }
                }
                else{
                    error();
                    //break;
                }
            }

        }*/
        else{
            error();
            //cout <<"9"<<endl;
            //break;
        }

}
void output(token *p){
    while(p != NULL){
        cout << p->type << " "<< p->value<<endl;
        p = p->next;
    }
}
void error(){
    cout << "invalid input" <<endl;
}
bool level(string a){
    bool on = true;
    for(int i=1; i<a.length(); i++){
        if(a[i]=='0'){}
        else if(a[i]=='1'){}
        else if(a[i]=='2'){}
        else if(a[i]=='3'){}
        else if(a[i]=='4'){}
        else if(a[i]=='5'){}
        else if(a[i]=='6'){}
        else if(a[i]=='7'){}
        else if(a[i]=='8'){}
        else if(a[i]=='9'){}
        else
            on = false;
    }
    //if(on == false)
    //    cout << "not level"<<endl;
    return on;
}
bool cid(string d){
    bool on = true;
    for(int i=0; i<d.length(); i++){
        if(d[i]=='0'){}
        else if(d[i]=='1'){}
        else if(d[i]=='2'){}
        else if(d[i]=='3'){}
        else if(d[i]=='4'){}
        else if(d[i]=='5'){}
        else if(d[i]=='6'){}
        else if(d[i]=='7'){}
        else if(d[i]=='8'){}
        else if(d[i]=='9'){}
        else{
            on = false;
            break;
        }
    }
   // if(on == false)
    //    cout << "not cid"<<endl;
    return on;
}
bool idF(string b){
    bool on = true;
    for(int i=0; i<b.length(); i++){
        if(i==0){
            if(b[0]=='A'){}
            else if(b[0]=='B'){}
            else if(b[0]=='C'){}
            else if(b[0]=='D'){}
            else if(b[0]=='E'){}
            else if(b[0]=='F'){}
            else if(b[0]=='G'){}
            else if(b[0]=='H'){}
            else if(b[0]=='I'){}
            else if(b[0]=='J'){}
            else if(b[0]=='K'){}
            else if(b[0]=='L'){}
            else if(b[0]=='M'){}
            else if(b[0]=='N'){}
            else if(b[0]=='O'){}
            else if(b[0]=='P'){}
            else if(b[0]=='Q'){}
            else if(b[0]=='R'){}
            else if(b[0]=='S'){}
            else if(b[0]=='T'){}
            else if(b[0]=='U'){}
            else if(b[0]=='V'){}
            else if(b[0]=='W'){}
            else if(b[0]=='X'){}
            else if(b[0]=='Y'){}
            else if(b[0]=='Z'){}
            else{
                on = false;
                break;
            }
        }
        if(b.length()>1 && i!=0){
            if(b[i]=='a'){}
            else if(b[i]=='b'){}
            else if(b[i]=='c'){}
            else if(b[i]=='d'){}
            else if(b[i]=='e'){}
            else if(b[i]=='f'){}
            else if(b[i]=='g'){}
            else if(b[i]=='h'){}
            else if(b[i]=='i'){}
            else if(b[i]=='j'){}
            else if(b[i]=='k'){}
            else if(b[i]=='l'){}
            else if(b[i]=='m'){}
            else if(b[i]=='n'){}
            else if(b[i]=='o'){}
            else if(b[i]=='p'){}
            else if(b[i]=='q'){}
            else if(b[i]=='r'){}
            else if(b[i]=='s'){}
            else if(b[i]=='t'){}
            else if(b[i]=='u'){}
            else if(b[i]=='v'){}
            else if(b[i]=='w'){}
            else if(b[i]=='x'){}
            else if(b[i]=='y'){}
            else if(b[i]=='z'){}
            else{
                on = false;
                break;
            }
        }
        else{}
    }
    //if(on == false)
    //    cout << "not idF"<<endl;
    return on;
}
bool idL(string c){
    bool on = true;
    for(int i=0 ; i<c.length(); i++){
        if(c[i]=='a'){}
        else if(c[i]=='c'){}
        else if(c[i]=='d'){}
        else if(c[i]=='e'){}
        else if(c[i]=='f'){}
        else if(c[i]=='g'){}
        else if(c[i]=='h'){}
        else if(c[i]=='i'){}
        else if(c[i]=='j'){}
        else if(c[i]=='k'){}
        else if(c[i]=='l'){}
        else if(c[i]=='m'){}
        else if(c[i]=='n'){}
        else if(c[i]=='o'){}
        else if(c[i]=='p'){}
        else if(c[i]=='q'){}
        else if(c[i]=='r'){}
        else if(c[i]=='s'){}
        else if(c[i]=='t'){}
        else if(c[i]=='u'){}
        else if(c[i]=='v'){}
        else if(c[i]=='w'){}
        else if(c[i]=='x'){}
        else if(c[i]=='y'){}
        else if(c[i]=='z'){}
        else{
            on = false;
            break;
        }
    }
    //if(on == false)
     //   cout << "not idL"<<endl;
    return on;
}
