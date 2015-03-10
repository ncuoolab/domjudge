#include<iostream>
#include<cstdlib>
using namespace std;

int falsenum=0;
string number="0123456789";
    string Beng="ABCDEFGHIJKLMNOPQUSTUVWXYZ";
    string LNeng="acdefghijklmnopqustuvwxyz";

void checkstr(string strinput,int strindex,string savestr[])
{
    string number="0123456789";
    string Beng="ABCDEFGHIJKLMNOPQUSTUVWXYZ";
    string LNeng="acdefghijklmnopqustuvwxyz";
    int judgenum=0;
    int arrayindex[9]={0,1,2,3,4,5,6,7,8};
    if(strindex==arrayindex[0] && strinput[0]=='l')
    {
        for(int i=1;i<strinput.length();i++)
        {
            for(int j=0;j<10;j++)
            {
                if(strinput[i]==number[j])
                {
                    //cout << i << "   " << strinput[i] << "   " << j << endl;
                    judgenum++;
                }
            }
        }
        if(judgenum==strinput.length()-1)
        {
            cout << "level " << strinput << endl;
        }
        else if(judgenum!=strinput.length()-1)
        {
            falsenum=1;
        }
    }
    else if(strindex==arrayindex[1])
    {
        int id=0;
        int name=0;

        for(int i=0;i<10;i++)
        {
            if(strinput[0]==number[i])
            {
                id=1;
            }
            else
            {
                name=1;
            }
        }

        if(id==1)
        {
             cout << "cid1 " << strinput << endl;
        }
        else if(name==1)
        {
             arrayindex[2]++;
             arrayindex[3]++;
             arrayindex[4]++;
             cout << "FirstName " << savestr[1] << endl;
             cout << "LastName " << savestr[2] << endl;
        }

    }
    else if(strindex==arrayindex[2])
    {
        if(strinput.length()==1 && strinput=="b")
        {
            cout << "battle " << "b" << endl;
        }
    }
    else if(strindex==arrayindex[3])
    {
        /*int id=0;
        int name=0;

        for(int i=0;i<10;i++)
        {
            if(strinput[0]==number[i])
            {
                id=1;
            }
            else
            {
                name=1;
            }
        }

        if(id=1)
        {
             cout << "cid2 " << strinput << endl;
        }
        else
        {
             cout << "FirstName " << strinput << endl;
        }*/

        int id=0;
        int name=0;

        for(int i=0;i<10;i++)
        {
            if(strinput[0]==number[i])
            {
                id=1;
            }
            else
            {
                name=1;
            }
        }

        if(id==1)
        {
             cout << "cid3 " << strinput << endl;
        }
        else if(name==1)
        {
             arrayindex[3]++;
             arrayindex[4]++;
             arrayindex[5]++;
             cout << "FirstName " << savestr[3] << endl;
             cout << "LastName " << savestr[4] << endl;
        }
    }






}

int main(){
    string inputstr;
    string savestr[9999];
    int index=0;
    int idtest=0;
    int nametest=0;
    int idtest1=0;
    int nametest1=0;
    for(int i=0;i<2;i++)
    {
        cin >> inputstr;
        savestr[i]=inputstr;
        index++;
        if(i==0)
        {
             checkstr(inputstr,i,savestr);
        }

        if(i==1)
        {
            for(int i=0;i<10;i++)
            {
                if(inputstr[0]==number[i])
                {
                    idtest=1;
                    ///    cid

                }
                else if(inputstr[0]!=number[i])
                {
                    nametest=1;
                    ///    FN LN
                }
            }

            if(idtest==1)
            {
                checkstr(inputstr,i,savestr);
                //cout << "cid5" << endl;
                ///    cid
                    for(int i=2;;i++)
                    {

                        cin >> inputstr;
                        savestr[i]=inputstr;
                        index++;
                        if(i==2)
                        {
                            checkstr(inputstr,i,savestr);
                        };
                        if(i==3)  /////   cid b FN LN
                        {
                            for(int i=0;i<10;i++)
                            {
                                if(inputstr[0]==number[i])
                                {
                                    idtest1=1;
                                    ///    cid

                                }
                                else if(inputstr[0]!=number[i])
                                {
                                    nametest1=1;
                                    ///    FN LN
                                }
                            }


                            if(idtest1==1)
                            {
                                //checkstr(inputstr,i,savestr);
                                cout << "cid4 ";
                                cin >> inputstr;
                                //cout << inputstr << endl;
                                savestr[i]=inputstr;
                                index++;

                                checkstr(inputstr,4,savestr);
                            }
                            else if(nametest1==1)
                            {
                                cout << "name11" << endl;
                                ///    FN LN

                                        cin >> inputstr;
                                    savestr[index]=inputstr;
                                    index++;
                                    checkstr(savestr[3],3,savestr);


                            }
                            }

                        }
                    }

            else if(nametest==1)
            {
                //checkstr(inputstr,i,savestr);
                //cout << "name" << endl;
                ///    FN LN
                    for(int i=2;;i++)
                    {
                        if(i==2)
                        {
                            cin >> inputstr;
                        savestr[index]=inputstr;
                        index++;
                         checkstr(savestr[1],1,savestr);

                        }
                        else
                        {
                            cin >> inputstr;
                        savestr[i]=inputstr;
                        index++;
                        checkstr(savestr[i],i-1,savestr);
                        }
                    }
            }




        }
       // checkstr(inputstr,i,savestr);

    }



    system("pause");
    return 0;
}
