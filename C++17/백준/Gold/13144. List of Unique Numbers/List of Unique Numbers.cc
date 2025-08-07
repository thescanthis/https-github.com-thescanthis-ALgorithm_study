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

vector<long long> num;
bool check[100001] = {};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		num.push_back(temp);
	}

	long long  start = 0, end = 0;
	long long  ret = 0;
	while (end<n)
	{
		if (!check[num[end]]) {
			check[num[end]] = true;
			end++;
		}
		else {
			ret += (end - start);
			check[num[start]] = false;
			start++;
		}
	}

	ret += (long long )((end - start) * (end - start + 1)) / 2 ;

	cout << ret;
    return 0;
}