// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int n,m;
char arr[101][101]={};
int ans[101][101]={};
bool vist[101][101]={};

int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};

void BFS(int y,int x)
{
    if(y==n-1 && x==m-1) return;
    
    vist[y][x] = true;
    queue<pair<int,int>> q;
    q.push({y,x});
    
    while(!q.empty())
    {
        int fy=q.front().first;
        int fx=q.front().second;
        
        q.pop();
        for(int i=0; i<4; i++)
        {
            int ny = fy+dy[i];
            int nx = fx+dx[i];
            
            if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
            else
            {
                if(!vist[ny][nx] && arr[ny][nx]=='1')
                {
                    vist[ny][nx]=true;
                    ans[ny][nx] = ans[fy][fx]+1;
                    q.push({ny,nx});
                }
            }
        }
    }
}

int main() {
    cin>>n>>m;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>arr[i][j];
        }
    }
    
    BFS(0,0);
    cout<<ans[n-1][m-1]+1;
    return 0;
}