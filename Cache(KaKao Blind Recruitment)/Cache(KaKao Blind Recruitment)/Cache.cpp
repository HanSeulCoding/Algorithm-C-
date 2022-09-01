#include <iostream>
#include <string>
#include <vector>

using namespace std;
string String_Tolower(string s)
{
    for (int i = 0; i < s.size(); ++i)
    {
        s[i] = tolower(s[i]);
    }
    return s;
}
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    vector<string>::iterator it;
    int runtime = 0;
    for (int i = 0; i < cities.size(); ++i) //전부 소문자로 변환
    {
        cities[i] = String_Tolower(cities[i]);
    }

    for (int i = 0; i < cities.size(); ++i)
    {
        it = find(cache.begin(), cache.end(), cities[i]);

        if (it != cache.end() && cacheSize != 0) //hit
        {
            runtime++;
            cache.erase(it);
            cache.push_back(cities[i]);
        }
        else //miss
        {
            runtime += 5;

            if (cacheSize == cache.size() && cacheSize != 0)
            {
                cache.erase(cache.begin());
            }
            cache.push_back(cities[i]);
        }
    }
    answer = runtime;
    return answer;
}

int main()
{
    vector<string> cities = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" };
    int cacheSize = 5;
    int answer = solution(cacheSize, cities);

    cout << answer << endl;
}