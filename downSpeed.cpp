#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

struct Speed{
	double speed;
	string units;
};
Speed speedTest();
int main()
{

	Speed current=speedTest();
	cout << "your download speed is: " << current.speed << current.units << endl;
	return 0;
}

Speed speedTest()
{
	system("wget -O /dev/null http://speedtest.wdc01.softlayer.com/downloads/test10.zip 2>&1 | grep ' [KM]B/s' > speedlog.txt");
	ifstream file;
	file.open("speedlog.txt");
	
	Speed temp;	
	
	if(file.fail())
	{
		temp.speed = 0;
		temp.units = "null";
		return temp;
	}


	string s1, unit;
	char c1;
  
	
	file >> s1 >> s1 >> c1 >> temp.speed >> unit;
	temp.units=unit.substr(0,4);

	return temp;
}
