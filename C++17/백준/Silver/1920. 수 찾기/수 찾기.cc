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

int n,m;
int arr[100001] = {};

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;

		int lo=0, hi = n - 1;
		bool check = false;

		while (lo <= hi)
		{
			int mid = (lo + hi) / 2;
			if (arr[mid] == temp) {
				check = true;
				break;
			}
			else if (temp < arr[mid])
			{
				hi = mid - 1;
			}
			else {
				lo = mid + 1;
			}
		}

		if (check) cout << 1;
		else cout << 0;
		cout << '\n';
	}

    return 0;
}