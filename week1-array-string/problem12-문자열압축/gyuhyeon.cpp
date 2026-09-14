// 문제: 숫자 문자열 압축
// 접근 방식: 단위별로 문자열 잘라서 대상과 비교후 cnt 계산 -> 문자열로 전환
// 시간복잡도: O(n^2)

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string s) {
    
    int n = s.size();
    int answer = n;
    
    for (int k=1; k<=n/2; k++) { // n/2 초과는 반복 불가능
        string sub = s.substr(0,k);
        int cnt = 1;
        string res = "";
        
        for (int i=k; i<n; i+=k) {
            if (s.substr(i,k) == sub) cnt++;
            else {
                if (cnt > 1) res+=to_string(cnt);
                res+=sub;
                
                sub = s.substr(i,k);
                cnt = 1;
            }
        }
        
        if (cnt > 1) res+=to_string(cnt);
        res+=sub;
        
        answer = min((int)res.size(), answer);
    }
    
    return answer;
}