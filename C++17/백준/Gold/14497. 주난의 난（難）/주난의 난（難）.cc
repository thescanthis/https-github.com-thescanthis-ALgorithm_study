// BigStone.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <string.h>
using namespace std;

int n, m;
int a, b, a1, b1;
char _map[303][303];
int visted[303][303] = {};
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void fastIO()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int BFS(int _x1, int _y1)
{
    queue<pair<int, int>> q;
    q.push({ _x1,_y1 });

    int cnt = 0;
    while (_map[a1-1][b1-1] != '0')
    {
        cnt++;
        
        queue<pair<int, int>> q1;
        while (q.size())
        {
            int f = q.front().first;
            int t = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int _dy = f + dy[i];
                int _dx = t + dx[i];

                if (_dy < 0 || _dx < 0 || _dy >= n || _dx >= m || visted[_dy][_dx]) continue;

                visted[_dy][_dx] = cnt;
                if (_map[_dy][_dx] != '0')
                {
                    _map[_dy][_dx] = '0';
                    q1.push({ _dy,_dx });
                }
                else q.push({ _dy,_dx });
            }
        }

        q = q1;
    }
    

    return visted[a1-1][b1-1];
}

int main()
{
    fastIO();
    cin >> n >> m;
    cin >> a >> b >> a1 >> b1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> _map[i][j];
        }
    }

    cout << BFS(a-1, b-1);
    return 0;
}