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
#include <sstream>
#include <string>
#include <cstring>
#include <limits.h>
#include <iomanip>
using namespace std;

int X;

vector<int> v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> X;

	int count = 0;
	while (X)
	{
		count += X & 1;
		X >>= 1;
	}
	cout << count;
	
    return 0;
}
/*
 n=23
 0001 0111
 0000 1011
 0000 0101
 0000 0010
 0000 0001
 0000 0000
*/