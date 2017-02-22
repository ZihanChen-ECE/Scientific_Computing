#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string* create_filename()
{
	string *name;
	name = new string[33];
	string s1 = "detection0";
	string s1_1 = "detection";
	string s3 = ".rat";
	//cout<<s1+s3<<endl;
	//string s2;
	int i = 0;
	name[0] = "GWprediction.rat";
	for(i = 2;i<=33;i++)
	{
		int n = i;
		stringstream num;
		num << n-1;
		string s2;
		num >> s2;
		if (i<=10)
			{
				name[i-1] = s1;
				name[i-1] = name[i-1]+s2+s3;
			}
		else
			{
				name[i-1] = s1_1;
				name[i-1] = name[i-1]+s2+s3;
			}
	}
	return name;
}

