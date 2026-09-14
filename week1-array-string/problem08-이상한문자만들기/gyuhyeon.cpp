// 문제: 문자열 내 p와 y의 개수
// 접근 방식: 공백이면 인덱스 초기화하고 continue
// 시간복잡도: O(n)

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int idx = 0;
    
    for (int i=0; i<s.size(); i++) {
        if (s[i] == ' ') {
            idx = 0;
            answer+=' ';
            continue;
        }
        
        if (idx%2==0) answer+=toupper(s[i]);
        else answer += tolower(s[i]);
        
        idx++;
    }
    
    return answer;
}