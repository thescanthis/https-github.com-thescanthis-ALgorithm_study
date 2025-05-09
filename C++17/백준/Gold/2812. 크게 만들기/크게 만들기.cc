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
#include <string>
#include <cstring>
#include <limits.h>
using namespace std;

int n, k;
char arr[500001] = {};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	deque<int> q;
	for (int i = 0; i < n; i++)
	{
		while (k!=0 && !q.empty() && arr[q.back()] < arr[i])
		{
			q.pop_back();
			k--;
		}

		q.push_back(i);

	}


	while (k!=0 && !q.empty())
	{
		q.pop_back();
		k--;
	}
	

	string str = "";
	while (!q.empty()) {
		str+=arr[q.front()];
		q.pop_front();
	}
	cout << str << '\n';


	return 0;
}

//5 2
//98765
// ans = 987
// your = 98765