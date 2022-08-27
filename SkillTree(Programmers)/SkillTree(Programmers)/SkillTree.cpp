#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

bool Compare(map<char, char> skill_map, string skill)
{
    for (int i = 0; i < skill.size(); ++i)
    {
        bool isEqual = false;
        if (skill_map.count(skill[i]) != 0)
        {
            for (int j = i - 1; j >= 0; --j)
            {
                string temp(1, skill[j]);
                if (skill_map[skill[i]] == skill[j])
                {
                    isEqual = true;
                    break;
                }
            }
            if (!isEqual)
            {
                return false;
            }
        }
    }

    return true;
}
int solution(string skill, vector<string> skill_trees) {
    int answer = -1;
    map<char, char> skill_map;

    for (int i = 1; i < skill.size(); ++i)
    {
        skill_map.insert({ skill[i], skill[i - 1] });
    }
    for (int i = 0; i < skill_trees.size(); ++i)
    {
        if (Compare(skill_map, skill_trees[i]))
        {
            answer++;
        }
    }
    return answer + 1;
}

int main()
{
    string skill = "CBD";
    vector<string> skill_tress = { "CBADF","BACDE", "AECB", "BDA" };
    int answer = solution(skill, skill_tress);
    cout << answer;
}