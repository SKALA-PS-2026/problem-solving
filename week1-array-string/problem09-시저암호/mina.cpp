// 문제: 시저 암호
// 접근 방식: 나머지 연산이 뽀인뜨
// 시간복잡도: O(n)

#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    for (int i=0; i<s.size(); i++){
        if (s[i]==' ') continue;
        if (s[i]<'a') s[i] = 'A'+(s[i]-'A'+n)%26;
        else s[i] = 'a'+(s[i]-'a'+n)%26;
    }
    return s;
}
