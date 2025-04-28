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
int visited[200004] = {};
int dir[3] = { -1,1,2 };
stack<int> Load;

void BFS(int start)
{
	queue<int> q;
	q.push(start);
	visited[n] = 1;

	while (!q.empty())
	{
		int here = q.front();
		q.pop();

		if (here == m) break;

		for (int i = 0; i < 3; i++)
		{
			int there = (dir[i] == 2) ? here * dir[i] : here + dir[i];

			if (there >= 0 && there <= 100000)
			{
				if (!visited[there])
				{
					visited[there] = visited[here]+1;

					q.push(there);

				}
			}
		}
	}

	int end = m;
	Load.push(end);
	while (true)
	{
		if (visited[end] == 1) break;
		for (int i = 0; i < 3; i++)
		{
			int newLoad = (dir[i] == 2) ? (end / dir[i]) : end + dir[i];
			if (end < 0) break;

			if (visited[newLoad] == visited[end] - 1)
			{
				end = newLoad;
				Load.push(end);
				break;
			}
		}

		if (end < 0) break;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	BFS(n);

	cout << visited[m] - 1<<'\n';

	while (!Load.empty())
	{
		cout << Load.top() << " ";
		Load.pop();
	}

	return 0;
}