#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int count = 0;
    bool isCheck = false;;
    for (int i = 0; i < prices.size(); ++i)
    {
        for (int j = i + 1; j < prices.size(); ++j)
        {
            if (prices[i] > prices[j])
            {
                answer.push_back(j - i);
                isCheck = true;
                break;
            }
        }
        if (!isCheck)
        {
            answer.push_back(prices.size() - (i + 1));
        }
        else
            isCheck = false;
    }
    return answer;
}
int main()
{
    vector<int> prices = { 1,2,3,2,3 };
    vector<int> answer = solution(prices);

    for (int i = 0; i < answer.size(); ++i)
    {
        cout << answer[i] << endl;
    }
}