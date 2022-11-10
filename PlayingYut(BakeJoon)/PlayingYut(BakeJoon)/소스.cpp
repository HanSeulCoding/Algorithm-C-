#include <iostream>
#include <vector>

using namespace std;
struct yutState
{
	int front = 0; //배
	int back = 0; //등
};
vector<char> Solution(vector<vector<int>> yut)
{
	char c;
	vector<char> answer;
	//배 0, 등 1
	for (int i = 0; i < yut.size(); ++i)
	{
		yutState yutState;
		for (int j = 0; j < yut[i].size(); ++j)
		{
			if (yut[i][j] == 0)
			{
				yutState.front++;
			}
			else
			{
				yutState.back++;
			}
		}
		if (yutState.front == 1 && yutState.back == 3)
		{
			answer.push_back('A');
		}
		else if (yutState.front == 2 && yutState.back == 2)
		{
			answer.push_back('B');
		}
		else if (yutState.front == 3 && yutState.back == 1)
		{
			answer.push_back('C');
		}
		else if (yutState.front == 4 && yutState.back == 0)
		{
			answer.push_back('D');
		}
		else if (yutState.front == 0 && yutState.back == 4)
		{
			answer.push_back('E');
		}
	}

	return answer;
}
int main()
{
	vector<vector<int>> yut;
	vector<char> answer;
	for (int i = 0; i < 3; ++i)
	{
		vector<int> t;
		for (int j = 0; j < 4; ++j)
		{
			int n;
			cin >> n;
			t.push_back(n);
		}
		yut.push_back(t);
	}

	answer = Solution(yut);

	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << endl;
	}

}