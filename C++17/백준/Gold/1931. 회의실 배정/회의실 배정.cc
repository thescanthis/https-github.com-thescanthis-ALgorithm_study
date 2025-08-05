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

	int n;
	vector<pair<int, int>> v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int y, x;
		cin >>y >> x;
		v.push_back({ y,x });
	}
	sort(v.begin(), v.end());
	int ret = 1;

	int from = v[v.size()-1].first;
	int to = v[v.size()-1].second;

	
	for (int i = 1; i < v.size(); i++)
	{
		if (from < v[v.size() - i - 1].second) continue;
		
		from = v[v.size() - i - 1].first;
		ret++;
	}

	cout << ret;
    return 0;
}