#include <iostream>

using namespace std;
void Solution(int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = n - 1 - i; j > 0; --j)
		{
			cout << " ";
		}
		for (int j = 0; j < i + 1; ++j)
		{
			cout << "*" << " ";
		}
		cout << endl;
	}
}

int main()
{
	int n = 4;
	cin >> n;
	Solution(n);
}