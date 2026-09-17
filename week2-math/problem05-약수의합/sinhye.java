// 문제: 약수의 합
// 접근 방식: n의 제곱근까지만 순회하며 약수를 찾고, 약수의 짝을 함께 더한다.
// 시간복잡도: O(√n)
import java.lang.Math;

class Solution {
    public int solution(int n) {
        int answer = 0;
        
        for (int i = 1;i <= Math.sqrt(n);i++) {
            if (n % i == 0) {
                if ((i * i) == n) {
                    answer += i;
                }
                else {
                    answer += i;
                    answer += (n / i);
                }
            }
        }
        
        return answer;
    }
}
