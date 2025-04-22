#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <limits.h>
using namespace std;

#define ARRSIZE 1001

int n;
std::vector<int> v;
std::vector<char> oper;
int ans = -987654321;

int Oper(char x, int a, int b)
{
	if (x == '+') return a + b;
	else if (x == '-') return a - b;
	else if (x == '*') return a * b;
}

void Cango(int idx, int sum)
{
	if (idx == v.size() - 1)
	{
		ans = max(ans, sum);
		return;
	}

	Cango(idx+1, Oper(oper[idx], sum, v[idx + 1]));

	if (idx + 2 <= v.size() - 1)
	{
		int temp = Oper(oper[idx + 1], v[idx + 1], v[idx + 2]);
		Cango(idx + 2, Oper(oper[idx], sum, temp));
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char temp;
		cin >> temp;
		if (temp >= '0' && temp <= '9') v.push_back(temp - '0');
		else oper.push_back(temp);
	}

	Cango(0, v[0]);
	cout << ans;
	
	return 0;
}