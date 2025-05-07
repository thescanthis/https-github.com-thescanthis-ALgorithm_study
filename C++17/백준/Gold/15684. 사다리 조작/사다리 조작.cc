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

int n, m, h;
bool visited[40][40] = {};
int ret = INT_MAX;

bool check() {
	for (int i = 1; i <= n; i++)
	{
		int start = i;
		for (int j = 1; j <= h; j++)
		{
			if (visited[j][start]) start++;
			else if (visited[j][start - 1]) start--;
		}

		if (start != i)
			return false;
	}
	return true;
}

void go(int here, int cnt)
{
	if (cnt > 3 || cnt >= ret) return;
	if (check())
	{
		ret = min(ret, cnt);
		return;
	}

	for (int i = here; i <= h; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (visited[i][j] || visited[i][j - 1] || visited[i][j + 1]) continue;
			visited[i][j] = true;
			go(i, cnt + 1);
			visited[i][j] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		visited[a][b] = true;
	}

	go(1, 0);
	cout << ((ret == INT_MAX) ? -1 : ret) << '\n';

	return 0;
}