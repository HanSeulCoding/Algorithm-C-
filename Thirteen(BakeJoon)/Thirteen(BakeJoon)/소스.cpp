#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//�������� ����

bool cmp(char a, char b)
{
	if (a > b)
		return true;

	return false;
}

int main(void)
{
	string N;
	cin >> N;
	long long sum = 0;
	bool zero = false;

	for (int i = 0; i <	N.size(); i++)
	{
		sum	+= (N[i] - '0');

		if (!(N[i] - '0'))
			zero = true;
	}

	//���� 3�� ����� �ƴϰų� 0�� ���ٸ�

	if (sum % 3 || !zero)
		cout << -1 << "\n";
	else
	{
		sort(N.begin(),
			N.end(), cmp);
		cout
			<< N << "\n";
	}
	return 0;
}