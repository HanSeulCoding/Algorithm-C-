#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
void Dfs(string s, map<char, bool> check, string& answer, int count, int sSize)
{
	string temp;
	if (count == sSize)
	{
		return;
	}
	for (int i = 0; i < s.size(); ++i)
	{
		if (check[s[i]])
			continue;
		check[s[i]] = true;
		temp += s[i];
		s.erase(s.begin() + i);
		--i;
		count++;
	}
	sort(temp.begin(), temp.end());
	answer += temp;
	check.clear();
	Dfs(s, check, answer, count, sSize);
}

string solution(string source)
{
	string answer = "";
	map<char, bool> check;
	for (int i = 0; i < source.size(); ++i)
	{
		check[source[i]] = false;
	}
	Dfs(source, check, answer, 0, source.size());
	return answer;
}
//execute �������� �ϳ��� �̾Ƽ� ���� �����
//excutee �������� �ϳ��� �̰� �ߺ��Ǵ� ���ڴ� �ڷ� �ٿ�����. 
int main()
{
	string s = "execute";
	string answer = solution(s);

	cout << answer << endl;
}