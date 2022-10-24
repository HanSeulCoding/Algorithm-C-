#include <iostream>
#include <vector>
using namespace std;

int main() {

	int testcase, bridge[31][31];
	vector<int> result;

	for (int i = 1; i <= 30; i++) { //initialization
		for (int j = i; j <= 30; j++) {

			if (i == 1) bridge[i][j] = j;
			else if (i == j) bridge[i][j] = 1;
			else bridge[i][j] = 0;
		}
	}

	cin >> testcase;

	for (int i = 0; i < testcase; i++) {

		int west, east;
		cin >> west >> east;

		if (bridge[west][east] > 0) result.push_back(bridge[west][east]);
		else {

			for (int p = 2; p <= west; p++) { //dynamic programming
				for (int q = p + 1; q <= east; q++) {
					if (bridge[p][q] == 0) bridge[p][q] = bridge[p][q - 1] + bridge[p - 1][q - 1];
				}
			}

			result.push_back(bridge[west][east]);
		}
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << '\n';
	}
	return 0;
}