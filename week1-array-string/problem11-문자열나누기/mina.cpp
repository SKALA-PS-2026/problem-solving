// 문제: 문자열 나누기
// 접근 방식: x가 나오면 cnt++ 다른게 나오면 cnt--
// 시간복잡도: O(n)

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    char x=s[0];
    int cnt=1;
    for (int i=1; i<s.size(); i++){
        if (s[i]==x) cnt++;
        else cnt--;
        if (cnt==0){
            answer++;
            if (i == s.size()-1) return answer;
            x = s[i+1];
            cnt=1;
            i++;
        }
    }
    return ++answer;
}
