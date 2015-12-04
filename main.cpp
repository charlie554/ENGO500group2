#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <unistd.h>
using namespace std;
struct speedData{
	string dunits;
	string dspeed;
	string uunits;
	string uspeed;
};
int timer = 300;
int main()
{
	while(1)
	{
		system("python speedtest_cli.py | tee speedlog.txt");
		ifstream inFile;
		inFile.open("speedlog.txt");
		string s1="lol";
		speedData temp;
		while(s1 != "Download:")
		{
			inFile >> s1;
		}
		inFile >> temp.dspeed >> temp.dunits;
		while(s1!= "Upload:")
		{
			inFile >> s1;
		}
		inFile >> temp.uspeed >> temp.uunits;
		inFile.close();
		cout << "Your download speed is: " << temp.dspeed << " " << temp.dunits << endl;
		cout << "Your upload speed is: " << temp.uspeed << " " << temp.uunits << endl;
		cout << "uploading to Sensorup" << endl;
		string downUpload="python test.py 59003 "+temp.dspeed;
		system(downUpload.c_str());
		cout << "Waiting till next session:" << endl;
		int time = 0;
		while(time < timer)
		{
			cout << time << " seconds have passed, " << timer-time << " to go" << endl;
			sleep(60);
			time+= 60;
		}
	}
		
		return 0;
}
