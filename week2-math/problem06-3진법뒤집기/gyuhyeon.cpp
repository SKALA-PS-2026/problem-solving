// 문제: 3진법 뒤집기
// 접근 방식: n을 3으로 나눈 나머지를 차례로 사용해 뒤집힌 3진수를 바로 10진수로 변환한다.
// 시간복잡도: O(log n)
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int k = 1;
    int digit = 0;
    while (k <= n) {
        k *= 3;
        digit++;
    }

    for (int i = digit-1; i>=0; i--) {
        int a = pow(3,i);
        answer += (n/a) * pow(3,(digit-i-1));
        n %= a;
    }
    
    return answer;
}