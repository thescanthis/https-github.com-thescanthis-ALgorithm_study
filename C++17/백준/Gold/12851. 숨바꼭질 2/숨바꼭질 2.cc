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
int arr[200004] = {};
int visited[200004] = {};
int dir[3] = { -1,1,2 };

int BFS(int start)
{
	queue<int> q;
	q.push(start);
	arr[n] = 1;
	visited[n] = 1;

	while (!q.empty())
	{
		int here = q.front();
		q.pop();

		for (int i = 0; i < 3; i++)
		{
			int there = (dir[i] == 2) ? here * dir[i] : here + dir[i];

			if (there >= 0 && there <= 100000)
			{
				if (!visited[there])
				{
					visited[there] = visited[here]+1;
					arr[there] = arr[here];
					q.push(there);
				}
				else if (visited[there] == visited[here]+1)
				{
					arr[there] += arr[here];
				}
			}
		}
	}
	return visited[m] - 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	cout<<BFS(n)<<'\n';
	cout << arr[m];


	return 0;
}