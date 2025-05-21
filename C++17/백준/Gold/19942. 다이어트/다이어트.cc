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

int n;

int arr[4] = {};

struct Food
{
	int mp, mf, ms, mv,cost;
}food[16];

int Minconst = INT_MAX;
vector<int> best;

void dfs(int idx,int p, int f, int s, int v, int cost, vector<int>& sel)
{
	if (idx == n)
	{
		if (p >= arr[0] && f >= arr[1] && s >= arr[2] && v >= arr[3])
		{
			if (cost < Minconst)
			{
				Minconst = cost;
				best = sel;
			}
			else if (cost == Minconst && sel < best)
			{
				best = sel;
			}
		}
		return;
	}
	dfs(idx + 1, p, f, s, v, cost, sel);

	sel.push_back(idx + 1);
	dfs(idx + 1,
		p + food[idx].mp,
		f + food[idx].mf,
		s + food[idx].ms,
		v + food[idx].mv,
		cost + food[idx].cost,
		sel);
	sel.pop_back();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < 4; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
		cin>> food[i].mp>> food[i].mf>> food[i].ms>> food[i].mv>> food[i].cost;

	vector<int> sel;

	dfs(0,0,0,0,0,0,sel);

	if (Minconst == INT_MAX)
		cout << -1;
	else {
		cout << Minconst << '\n';
		sort(best.begin(), best.end());
		for (auto x : best)
			cout << x << " ";
	}

	return 0;
}

