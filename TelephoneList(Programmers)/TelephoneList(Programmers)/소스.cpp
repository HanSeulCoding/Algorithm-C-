#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    unordered_map<string, bool> phone_map;
    for (int i = 0; i < phone_book.size(); ++i)
    {
        phone_map[phone_book[i]] = true;
    }

    for (int i = 0; i < phone_book.size(); i++)
    {
        for (int j = 0; j < phone_book[i].size() - 1; ++j)
        {
            string s = phone_book[i].substr(0, j + 1);
            if (phone_map[s])
                return false;
        }
    }

    return true;
}

int main()
{
    vector<string> phone_book = { "119", "297674223", "1195524421" }; //{ "44", "244", "789" };//{ "119", "97674223", "1195524421" };//

    bool answer = solution(phone_book);
    cout << answer << endl;
}