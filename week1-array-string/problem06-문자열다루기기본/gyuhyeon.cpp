// 문제: 문자열 다루기 기본
// 접근 방식: 
// 시간복잡도: O(n)

#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    
    if (s.size() != 4 && s.size() != 6) {
        return false;
    }
    
    for (int i=0; i<s.size(); i++) {
        if (s[i] - '0' > 9) return false;
    }
    
    return true;
}