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

int n, m;

int arr[5000001] = {};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		cin >> arr[i];


	deque<int> dq;
	for (int i = 0; i < n; i++)
	{
		if (!dq.empty() && dq.front() <= i - m)
			dq.pop_front();

		while (!dq.empty() && arr[dq.back()]>=arr[i])
		{
			dq.pop_back();
		}

		dq.push_back(i);


		cout << arr[dq.front()] << " ";
	}
	return 0;
}
