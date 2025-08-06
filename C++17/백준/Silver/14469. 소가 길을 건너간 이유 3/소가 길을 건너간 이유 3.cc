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

	vector<pair<int, int>> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int y, x;
		cin >> y >> x;
		v.push_back({ y,x });
	}

	sort(v.begin(), v.end());

	int ret = 0;
	for(int i=0; i<n; i++)
	{
		if(ret == 0)
		{
			ret += v[i].first + v[i].second;
			continue;
		}

		if (ret <= v[i].first) ret = v[i].first + v[i].second;
		else if (ret > v[i].first) {
			ret += v[i].second;
		}
	}

	cout << ret;
    return 0;
}