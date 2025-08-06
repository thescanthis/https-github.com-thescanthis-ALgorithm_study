#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <algorithm>
#include <sstream>
#include <string>
#include <cstring>
#include <limits.h>
#include <iomanip>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	std::string str, Pung;
	cin >> str >> Pung;

	string ret = "";

	for (int i = 0; i < str.size(); i++)
	{
		ret += str[i];
		if (ret.size() >= Pung.size()) {

			string SubStr = ret.substr(ret.size() - Pung.size(), ret.size());

			if (SubStr == Pung)
			{
				ret.erase(ret.size() - Pung.size(), ret.size());
			}

		}
	}
	

	if (ret.empty()) cout << "FRULA";
	else cout << ret;
    return 0;
}