#include <iostream>
#include <vector>

using namespace std;
enum oper
{
	Plus, Minus, Mul, Divide,None
};

void Dfs(vector<int> n, int index, int total, vector<int>& answer,
	int plus, int minus, int gob, int divide,oper op)
{
	if (op != None)
	{
		if (index == n.size())
		{
			answer[0] = max(answer[0], total);
			answer[1] = min(answer[0], total);
			return;
		}
		if (op == Plus)
		{
			total += n[index];
		}
		else if (op == Minus)
		{
			total -= n[index];
		}
		else if (op == Mul)
		{
			total *= n[index];
		}
		else if (op == Divide)
		{
			total /= n[index];
		}
	}

	if (plus != 0)
	{
		Dfs(n,index + 1, total, answer,  plus - 1 , minus, gob, divide, Plus);
	}
	if (minus != 0)
	{
		Dfs(n, index + 1, total, answer, plus,  minus - 1 , gob, divide, Minus);
	}
	if (gob != 0)
	{
		Dfs(n, index + 1, total, answer, plus, minus, gob - 1, divide, Mul);
	}
	if (divide != 0)
	{
		Dfs(n, index + 1, total, answer, plus, minus, gob, divide - 1, Divide);
	}
	
	if (plus == 0 && minus == 0 && gob == 0 && divide == 0)
	{
		answer[0] = max(answer[0], total);
		answer[1] = min(answer[1], total);
		return;
	}
}
// + , -, *, / 
//answer 0 max, answer 1 min
vector<int> solution(vector<int> n, vector<int> operators)
{
	vector<int> answer;
	vector<oper>test;
	answer.push_back(-1000000000);
	answer.push_back(1000000000);

	Dfs(n, 0, n[0], answer, operators[0], operators[1], operators[2], operators[3], None);
		
	return answer;
}

int main()
{
	int count = 3;
	vector<int> n ;
	vector<int> operators ;
	vector<int> answer;

	cin >> count;
	for (int i = 0; i < count; ++i)
	{
		int num;
		cin >> num;
		n.push_back(num);
	}
	for (int i = 0; i < 4; ++i)
	{
		int operatorNum;
		cin >> operatorNum;
		operators.push_back(operatorNum);
	}

	answer = solution(n, operators);
	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << endl;
	}
}