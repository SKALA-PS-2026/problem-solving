// 문제: 시저 암호
// 접근 방식: 
// 시간복잡도: O(n)

#include <string>
#include <vector>
using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for (int i=0; i<s.size(); i++) {
        if (s[i] == ' ') {
            answer+=' ';
            continue;
        }
        
        int k;
        
        if (s[i] - 'A' < 26) k = (s[i]-'A'+n)%26 + 'A';
        else k = (s[i]-'a'+n)%26 + 'a';
        
        answer += (char)k;
    }
    
    return answer;
}