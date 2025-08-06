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
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	int x;
	cin >> x;
	sort(v.begin(), v.end());

	int start = 0, end = v.size()-1;
	int cnt = 0;
	while (start != end)
	{
		int value = v[start] + v[end];

		if (value <= x) start++;
		else if (value > x) end--;

		if (value == x) cnt++;
	}

	cout << cnt;
    return 0;
}