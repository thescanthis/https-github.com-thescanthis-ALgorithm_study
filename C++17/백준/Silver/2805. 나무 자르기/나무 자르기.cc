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

ll n, m;
vector<ll> v;
int Max = 0;
ll lo = 1, hi = 0;
ll ret = 0;

bool check(ll mid)
{
	ll cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cnt +=max(ll(0), v[i] - mid);
	}

	return cnt >= m;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		Max = max(Max, temp);
		v.push_back(temp);
	}

	hi = Max;

	while (lo<=hi)
	{
		ll mid = (lo + hi) / 2;
		if (check(mid))
		{
			lo = mid + 1;
			ret = mid;
		}
		else {
			hi = mid - 1;
		}
	}

	cout << ret;
    return 0;
}