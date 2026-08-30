// 문제: 문자열 다루기 기본
// 접근 방식: 길이가 4나 6이 아니면 false, 숫자가 아니면 false 리턴하고 다 통과하면 true 리턴
// 시간복잡도: O(n)

#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    if (s.size()!=4 && s.size()!=6) return false;
    for (int i=0; i<s.size(); i++){
        if (s[i]<'0'||s[i]>'9') return false;
    }
    return true;
}
