// 문제: 문자열 내 p와 y의 개수
// 접근 방식: 
// 시간복잡도: O(n)

#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    
    if (s.empty()) return true;
    
    int p = 0;
    int y = 0;

    for (int i=0; i<s.size(); i++) {
        if (tolower(s[i]) == 'p') p++;
        
        else if (tolower(s[i]) == 'y') y++;
    }
    
    if (p == y) return true;
    
    return false;
}