#include<iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int index = 0;
    //�ٲܷ��� �Ҷ� �ڱ� ��ġ�� �ٲ� Index�񱳸� ���� �ٲ� index���� �ڱ� ��ġ�� ũ�� + ���ֱ�
    // �ƴϸ� ��ü���ֱ� ū ������
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