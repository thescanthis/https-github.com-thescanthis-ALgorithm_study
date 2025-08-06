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

vector<int> num;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i <= n; i++)
	{
		num.push_back(i);
	}
	
	num[0] = 0;
	num[1] = 0;
	for (long long int i = 2; i * i <= n; i++)
	{
		if (num[i] == 0) continue;
		for (long long int j = i * i; j <= n; j+=i)
		{
			num[j] = 0;
		}
	}


	for (int i = 0; i < num.size(); i++)
	{
		if (num[i] != 0) v.push_back(num[i]);
	}

	int start = 0, end = 0;
	long long int ret = 0,cnt=0;
	while (true)
	{
		
		if (ret >= n)
		{
			ret -= v[start++];
		}
		else if (end == v.size()) break;
		else
		{
			ret += v[end++];
		}
		if (ret == n) cnt++;
	}

	cout << cnt;
    return 0;
}