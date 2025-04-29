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

int n, m;
int visited[2][500001] = {};

int BFS(int start)
{
	queue<int> q;
	q.push(start);

	visited[0][start] = 1;

	int trun = 1;

	while (q.size())
	{
		m += trun;
		if (m > 500'000) break;
		if (visited[trun % 2][m])
		{
			return trun;
		}

		int qsize = q.size();
		for (int i = 0; i < qsize; i++)
		{
			int dir = q.front();
			q.pop();

			for (int x : {dir + 1, dir - 1, dir * 2})
			{
				if (x < 0 || x>500'000 || visited[trun % 2][x]) continue;
				visited[trun % 2][x] = visited[(trun+1) % 2][dir] + 1;

				if (x == m)return trun;
				q.push(x);
			}
		}
		trun++;
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	
	if (n == m)
		cout << 0 << '\n';
	else
		cout << BFS(n);

	return 0;
}