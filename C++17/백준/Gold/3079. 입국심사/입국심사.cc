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

int n,m;
vector<ll> v;

bool check(ll mid)
{
	ll cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cnt += mid / v[i];
		if (cnt >= m) return true;
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	cin >> n>>m;

	for (int i = 0; i < n; i++)
	{
		ll temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	ll lo = 1, hi = v[v.size() - 1]*m;
	while (lo < hi)
	{
		ll mid = (lo + hi) / 2;
		if (check(mid))
		{
			hi = mid;
		}
		else {
			lo = mid + 1;
		}
	}

	cout << lo;
    return 0;
}