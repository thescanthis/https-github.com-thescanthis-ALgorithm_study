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

int n;
vector<int> v[14];
int arr[1030] = {};
void BaineryTree(int s,int e,int level)
{
	if (s > e) return;
	if (s == e)
	{
		v[level].push_back(arr[s]);
		return;
	}

	int mid = (s + e) / 2;
	v[level].push_back(arr[mid]);
	BaineryTree(s, mid - 1, level + 1);
	BaineryTree(mid + 1, e, level + 1);
}

int main()
{
	cin >> n;
	int size = (2 << n-1) - 1;

	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}

	BaineryTree(0, size,1);

	for (int i = 1; i <= n; i++)
	{
		for (auto x : v[i])
		{
			cout << x << " ";
		}
		cout << '\n';
	}
	return 0;
}