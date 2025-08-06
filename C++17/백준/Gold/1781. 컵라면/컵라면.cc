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

	priority_queue<int, vector<int>, greater<int>> pq;
	vector<pair<int, int>> v;
	int ret = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int y, x;
		cin >> y >> x;
		v.push_back({ y,x });
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		ret += v[i].second;
		pq.push(v[i].second);

		if (pq.size() > v[i].first)
		{
			ret -= pq.top();
			pq.pop();
		}
	}

	cout << ret;
    return 0;
}