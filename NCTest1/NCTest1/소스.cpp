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
//execute 종류별로 하나씩 뽑아서 문자 만들기
//excutee 종류별로 하나씩 뽑고 중복되는 문자는 뒤로 붙여야함. 
int main()
{
	string s = "execute";
	string answer = solution(s);

	cout << answer << endl;
}