#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <string.h>
#include <limits.h>
#include <cmath>
#include <iomanip>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int n;
	cin >> n;
	vector<int> v;
	v.reserve(n);
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		auto it = lower_bound(v.begin(), v.end(), temp);
		if (it == v.end()) v.push_back(temp);
		else *it = temp;
	}

	cout << v.size();

    return 0;
}