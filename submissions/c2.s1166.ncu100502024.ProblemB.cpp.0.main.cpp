#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;


string token(string);

bool Is_strdcl(string);
bool Is_id(string);
bool Is_quote(string);
bool Is_string(string);
bool Is_print(string);

int index = 0;

struct astring
{
	string type;
	string value;
};

bool stmt(astring* );

int main()
{
    astring astr[7];
    bool Is_Error = false;

    for ( int i = 0 ; i < index ; i++ ) {
        astr[i].type = "";
        astr[i].value = "";
    }

	Is_Error = stmt(astr);

	if(Is_Error)
	{
		cout << "valid input" << endl;
	}
	else
	{
		for( int i = 0 ; i < index ; i++ )
		{
			cout << astr[i].type << "\t" << astr[i].value << endl;
		}
	}

	system("pause");
	return 0;
}
bool stmt(astring* astr)
{
	string ts = "";

	cin >> ts;

	if(Is_strdcl(ts))
	{
		astr[index].type = "strdcl";
		astr[index].value = ts;

		index++;

		cin >> ts;
		if(ts.length()> 1)
        {
            string temp1 = "";
            string temp2 = "";
            temp1 += ts.substr(0,1);
            temp2 += ts.substr(1,ts.length()-1);
            if(Is_id(temp1))
            {
                astr[index].type += "id";
                astr[index].value += temp1;

                index++;

                //cin >> ts;

                if(Is_quote(temp2.substr(0,1)))
                {
                    astr[index].type += "quote";
                    astr[index].value += temp2.substr(0,1);

                    index++;

                    if(Is_string(temp2.substr(1,temp2.length()-2)))
                    {
                        astr[index].type += "string";
                        astr[index].value += temp2.substr(1,temp2.length()-2);

                        index++;

                        if(Is_quote(temp2.substr(temp2.length()-1,1)))
                        {
                            astr[index].type += "quote";
                            astr[index].value += temp2[temp2.length()-1];

                            index++;

                            ts = "";
                            cin >> ts;

                            if(Is_print(ts))
                            {
                                astr[index].type += "print";
                                astr[index].value += ts;

                                index++;

                                ts = "";
                                cin >> ts;

                                if(Is_id(ts))
                                {
                                    astr[index].type += "id";
                                    astr[index].value += ts;
                                    index++;
                                }
                                else
                                {
                                    return true;
                                }
                            }
                        }
                        else
                        {
                            return true;
                        }
                    }
                    else
                    {
                        return true;
                    }
                }
                else
                {
                    return true;
                }

            }
            else
            {
                return true;
            }
        }
        else
        {
            if(Is_id(ts))
            {
                astr[index].type += "id";
                astr[index].value += ts;

                index++;

                cin >> ts;

                if(Is_quote(ts.substr(0,1)))
                {
                    astr[index].type += "quote";
                    astr[index].value += ts.substr(0,1);

                    index++;

                    if(Is_string(ts.substr(1,ts.length()-2)))
                    {
                        astr[index].type += "string";
                        astr[index].value += ts.substr(1,ts.length()-2);

                        index++;

                        if(Is_quote(ts.substr(ts.length()-1,1)))
                        {
                            astr[index].type += "quote";
                            astr[index].value += ts[ts.length()-1];

                            index++;

                            ts = "";
                            cin >> ts;

                            if(Is_print(ts))
                            {
                                astr[index].type += "print";
                                astr[index].value += ts;

                                index++;

                                ts = "";
                                cin >> ts;

                                if(Is_id(ts))
                                {
                                    astr[index].type += "id";
                                    astr[index].value += ts;
                                    index++;
                                }
                                else
                                {
                                    return true;
                                }
                            }
                        }
                        else
                        {
                            return true;
                        }
                    }
                    else
                    {
                        return true;
                    }
                }
                else
                {
                    return true;
                }

            }
            else
            {
                return true;
            }
        }


	}
	else
	{
		return true;
	}
}
string token(string str)
{
	if(Is_strdcl(str))
	{
		return "strdcl";
	}
	else if(Is_id(str))
	{
		return "id";
	}
	else if(Is_quote(str))
	{
		return "quote";
	}
	else if(Is_string(str))
	{
		return "string";
	}
	else if(Is_print(str))
	{
		return "print";
	}
	else
	{
		return "Error";
	}
}
bool Is_strdcl(string st)
{
	if(st == "s")
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Is_id(string st)
{
	char c = st[0];
	int ASCII = (int)c;
	if(st.length() == 1)
	{
		if(((ASCII>=97 && ASCII <= 111) || (ASCII>= 113 && ASCII <= 114) || (ASCII >= 116 && ASCII <= 122)))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
bool Is_quote(string st)
{
	char c = st[0];
	int ASCII = (int)c;
	if(ASCII == 34 || ASCII == 92)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Is_string(string st)
{
	int ASCII;

	bool check = true;

	for(int i=0 ; i < st.length() ; i++ )
	{
		ASCII = (int)st[i];
		if( (ASCII >= 97 && ASCII <= 122) || (ASCII >= 65 && ASCII <= 90) || (ASCII >= 48 && ASCII <= 57) )
		{
			check = true;
		}
		else
		{
			check = false;
		}
	}

	return check;
}

bool Is_print(string st)
{
	if(st == "p")
	{
		return true;
	}
	else
	{
		return false;
	}
}
