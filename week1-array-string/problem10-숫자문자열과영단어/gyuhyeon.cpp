// 문제: 숫자 문자열과 영단어
// 접근 방식: 문자가 나오면 part에 담아서 words에서 찾아보기
// 시간복잡도: O(n)

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const vector<string> words = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int solution(string s) {
    string answer = "";
    
    string part = "";
    
    for (int i=0; i<s.size(); i++) {
        
        if (s[i] - '0' < 10) answer+=s[i];
        else {
            part += s[i];
            
            auto it = find(words.begin(), words.end(), part);
            
            if (it != words.end()) {
                answer += to_string(it - words.begin());
                part = "";
            }
        }
    }
    
    return stoi(answer);
}