#include<iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int index = 0;
    //바꿀려고 할때 자기 위치랑 바꿀 Index비교를 통해 바꿀 index보다 자기 위치가 크면 + 해주기
    // 아니면 교체해주기 큰 값으로
    for (int i = 0; i < number.size() - k; ++i)
    {
        int tempIndex = index;
        char c = number[index];
        for (int j = index; j <= k + i; ++j)
        {
            if (c < number[j])
            {
                tempIndex = j;
                c = number[j];
            }
        }
        index = tempIndex + 1;
        answer += c;
    }
    return answer;
}

int main()
{
    string number = "15243";

    int k = 3;
    string answer = solution(number, k);
    cout << answer << endl;
}