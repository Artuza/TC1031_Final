#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Dato
{
private:
	string month, day, t, falure,ip,temp,rstr;
	int monthint, dayint;


public:
	Dato(string temp_);
	string getFalure();
	string getIp();
	string getMonth();
	string getDay();
	string getTempo();
	string getDato();
	int getMonthint();
};
Dato::Dato(string temp_)
{
	rstr = temp_;
	monthint = 0;
	int cont = 0;
	vector<string> temp_vec = {month,day,t,ip,falure};

	for (int i = 0; i < temp_.length(); i++)
	{

		if (temp_[i] == ' ' & cont < 4)
		{
			
			//cout << temp << " ";
			temp_vec[cont] = temp;
			cont ++;

			temp = "";
		}else
		{
			temp +=temp_[i];
		}
		
	}
	temp_vec[4] = temp;
	month = temp_vec[0];
	day = temp_vec[1];
	t = temp_vec[2];
	ip = temp_vec[3];
	falure = temp_vec[4];
	string Jun = "Jun", Jul = "Jul", Aug = "Aug", Sep = "Sep", Oct = "Oct";

	if (month == Jun)
	{
		monthint = 1;
		
	}else if (month == Jul)
	{
		monthint = 2;
			
	}else if (month == Aug)
	{	
		monthint = 3;

	}else if (month == Sep)
	{
		monthint = 4;

	}else if (month == Oct)
	{
		monthint = 5;
	}
	
	
	
}
string Dato::getDato()
{
	return rstr;
}
string Dato::getDay()
{
	return day;
}
string Dato::getTempo()
{
	return t;
}
string Dato::getFalure()
{
	return falure;
}

string Dato::getMonth()
{
	return month;
}
int Dato::getMonthint()
{
	return monthint;
}


