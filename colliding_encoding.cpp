#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

bool has_collision(const unordered_map<char, int>& mapping, const vector<string>& words)
{
    // unordered_map <string, vector<string> > encode_list;
    unordered_map <string, string > encode_list;
    for(const auto& word: words){
        string encode;
        for(char ch: word)
            encode += to_string(mapping.at(ch)); 
    
        if(encode_list.count(encode) > 0){
            // encode_list[encode].push_back(word);
            return true;
        }
        else
            encode_list[encode] = {word};
    }
    return false;
}

int main()
{
    int test_cases;
    cin >> test_cases;

    for(int i = 0; i < test_cases; i++){
        unordered_map<char, int> mapping;
        for (char c = 'A'; c <= 'Z'; c++)
        {
            int digit;
            cin >> digit;
            mapping[c] = digit;
        }
        int n;
        cin >> n;
        vector<string> words(n);
        for(int w = 0; w < n; w++)
            cin >> words[w];

        if (has_collision(mapping, words))
            cout << "Case #" << i+1 << ": YES" << endl;
        else
            cout << "Case #" << i+1 << ": NO" << endl;
        

    }
    return 0;
}



