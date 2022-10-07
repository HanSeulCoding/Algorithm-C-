#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<pair<int, int>> meetingRoom)
{
	int answer = 0;
	sort(meetingRoom.begin(), meetingRoom.end());
	int meetingTime = 0;

	for (int i = 0; i < meetingRoom.size(); ++i)
	{
		if (meetingTime <= meetingRoom[i].second)
		{
			meetingTime = meetingRoom[i].first;
			answer++;
		}
	}
	return answer;
}

int main()
{
	int num ;
	int answer = 0;
	vector<pair<int, int>> meetingRoom;
	cin >> num;
	for (int i = 0; i < num; ++i)
	{
		int first;
		int second;
		cin >> first >> second;
		meetingRoom.push_back(make_pair(second, first));
	}
	answer = solution(meetingRoom);
	cout << answer << endl;
}
bool Compare(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}
int solution(vector<pair<int, int>> meetingRoom)
{
	int answer = 0;
	sort(meetingRoom.begin(), meetingRoom.end(), Compare);
	int meetingTime = 0;

	for (int i = 0; i < meetingRoom.size(); ++i)
	{
		if (meetingTime <= meetingRoom[i].first)
		{
			meetingTime = meetingRoom[i].second;
			answer++;
		}
	}
	return answer;
}
int main()
{
	int num;
	int answer = 0;
	vector<pair<int, int>> meetingRoom;
	cin >> num;
	for (int i = 0; i < num; ++i)
	{
		int first;
		int second;
		cin >> first >> second;
		meetingRoom.push_back(make_pair(first, second));
	}
	answer = solution(meetingRoom);
	cout << answer << endl;
}