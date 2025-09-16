#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <string.h>
#include <limits.h>
using namespace std;
#define ARRSIZE 1001

int n, m;
char arr[ARRSIZE][ARRSIZE] = {};
int visited[ARRSIZE][ARRSIZE][2] = {};
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

struct Node
{
	int y, x;
	bool cur;
};

int BFS(int y, int x)
{
	queue<Node> q;
	q.push({ y,x,false });
	visited[y][x][0] = 1;
	while (!q.empty())
	{
		Node Cur = q.front();
		q.pop();

		if (Cur.y==n-1 && Cur.x== m-1) {
			return visited[Cur.y][Cur.x][Cur.cur];
		}

		for (int i = 0; i < 4; i++)
		{
			int _dy = dy[i] + Cur.y;
			int _dx = dx[i] + Cur.x;

			if (_dy < 0 || _dx < 0 || _dy >= n || _dx >= m) continue;

			if (arr[_dy][_dx] == '0' && visited[_dy][_dx][Cur.cur] == 0)
			{
				visited[_dy][_dx][Cur.cur] = visited[Cur.y][Cur.x][Cur.cur] + 1;
				q.push({ _dy,_dx,Cur.cur });
			}
			else if (arr[_dy][_dx] == '1' && !Cur.cur && visited[_dy][_dx][1] == 0)
			{
				visited[_dy][_dx][1] = visited[Cur.y][Cur.x][0] + 1;
				q.push({ _dy,_dx,true });
			}

		}
	}

	return -1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	int ans = 1000001;
	ans = std::min(ans, BFS(0, 0));
	if (ans == 1000001) ans = -1;
	else if (n == 1 && m == 1) ans = 1;
	cout << ans;

	return 0;
}