// 문제: 소수 찾기
// 접근 방식:
// 시간복잡도: O(n log log n)
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<bool> is_prime(n,true);
    
    for (int i=2; i<=n; i++) {
        if (is_prime[i]) {
            answer++;
            for (int j=1; j*j<=n; j++) {
                if (i*j > n) break;
                is_prime[i*j] = false;
            }
        }
    }
    
    return answer;
}