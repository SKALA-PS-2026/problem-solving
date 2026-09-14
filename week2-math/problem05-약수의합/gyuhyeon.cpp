// 문제: 약수의 합
// 접근 방식: 1부터 n까지 순회하며 n을 나누어떨어지게 하는 수를 모두 더한다.
// 시간복잡도: O(n)
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = n;
    
    for (int i=1; i<=n/2; i++) {
        if (n%i==0) answer+=i;
    }
    
    return answer;
}