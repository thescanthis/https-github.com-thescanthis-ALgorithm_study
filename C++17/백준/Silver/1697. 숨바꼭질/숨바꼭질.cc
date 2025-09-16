#include <fstream>
#include <cstring>
#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;
#define ARRSIZE 100001

int n, m;
int arr[ARRSIZE] = {};
bool check[ARRSIZE] = {};
int Variable[3] = { -1,1,2 };

int BFS(int start)
{
	if (n == m) return 0;
	arr[start] = 0;
	check[start] = true;
	queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		int here = q.front();
		q.pop();

		for (int i = 0; i < 3; i++)
		{
			int direct = (i != 2) ? here + Variable[i] : here * Variable[i];
			
			if (direct >= 0 && direct <= 100000)
			{
				if (direct == m)
				{
					return arr[here] + 1;
				}
				else if (!check[direct])
				{
					arr[direct] = arr[here] + 1;
					check[direct] = true;
					q.push(direct);
				}
			}
		}
	}

	return 0;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	cout << BFS(n);

	return 0;
}