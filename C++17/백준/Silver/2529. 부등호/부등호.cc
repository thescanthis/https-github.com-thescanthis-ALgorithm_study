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

vector<int> v;
char cpr[10] = {};
bool visted[10] = {};
bool check = false;

void Print()
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}
	cout << '\n';
}

bool Compare(char c,int idx)
{
	if (c == '<')
	{
		if (v[v.size()-2] < v[v.size() - 1])
			return true;
	}
	else if (c == '>') {
		if (v[v.size() - 2] > v[v.size() - 1])
			return true;
	}
	v.pop_back();
	visted[idx] = false;
	return false;
}

void goMin()
{
	if (v.size() == n + 1 && check == false)
	{
		Print();
		check = true;
		return;
	}

	for (int i = 0; i < n + 1; i++)
	{
		if (visted[i]) continue;
		visted[i] = true;

		v.push_back(i);
		
		if (v.size()>1)
			if (!Compare(cpr[v.size()-2],i))
				continue;
		goMin();
		v.pop_back();
		visted[i] = false;
	}
}

void goMax()
{
	if (v.size() == n + 1 && check == false)
	{
		Print();
		check = true;
		return;
	}

	for (int i = 9; i >= 9-n; i--)
	{
		if (visted[i]) continue;
		visted[i] = true;

		v.push_back(i);

		if (v.size() > 1)
			if (!Compare(cpr[v.size() - 2], i))
				continue;
		goMax();
		v.pop_back();
		visted[i] = false;
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> cpr[i];
	}

	goMax();
	check = false;
	goMin();
	
	return 0;
}