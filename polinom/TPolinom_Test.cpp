#include <iostream>
#include "TList.h"
#include "TPolinom.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "¬ведите полином:" << endl;
	string str;
	cin >> str;
	TPolinom p1(str);
	cout << "¬ведите второй полином:" << endl;
	string str2;
	cin >> str2;
	TPolinom p2(str2);
	string str3;
	TPolinom res(str3);
	res = p1 + p2;
	cout << "–езультат: " << res.ToString() << endl;

}