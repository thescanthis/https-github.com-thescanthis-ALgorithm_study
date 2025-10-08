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

ll n, k;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	cin >> n >> k;

	ll lo = 1, hi = k;
	while (lo < hi)
	{
		ll mid = (lo + hi) / 2;

		ll cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			cnt += min(n, mid / i);
			if (cnt >= k) break;
		}

		if (cnt >= k) hi = mid;
		else lo = mid + 1;
	}

	cout << lo;
    return 0;
}