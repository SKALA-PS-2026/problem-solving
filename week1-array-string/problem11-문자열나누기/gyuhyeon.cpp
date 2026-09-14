// 문제: 숫자 문자열 나누기
// 접근 방식: x와 같은 문자열 수, 다른 문자열 수 기록 후 비교
// 시간복잡도: O(n)

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    char x;
    int x_cnt = 0;
    int y_cnt = 0;
    
    for (int i=0; i<s.size(); i++) {
        if (x_cnt == 0) {
            x = s[i];
            x_cnt++;
            continue;
        }
        
        if (s[i] == x) x_cnt++;
        else y_cnt++;
        
        if (x_cnt == y_cnt) {
            answer++;
            x_cnt = 0;
            y_cnt = 0;
        }
    }
    
    if (x_cnt != y_cnt) answer++;
    
    return answer;
}