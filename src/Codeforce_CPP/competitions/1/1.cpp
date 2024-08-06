#include <bits/stdc++.h>

int main()
{
	int t, n;
	std::cin >> t;
	while(t)
	{
		std::cin >> n;
		std::cout << n % 10 + n / 10 << std::endl;
		t--;
	}

	return 0;
}