# 문제: 최대공약수와 최소공배수
# 접근 방식: 유클리드 호제법 원리를 확인하고 해당 원리를 기반으로 작성 큰 값이 앞으로 와야 하므로 큰 값에 따라 순서 조정하여 계산
# 시간복잡도: O(log(min(n, m))) -> 이거 시간복잡도 계산은 왜 이렇게 됐는지 잘 모르겠어요
class Solution {
    public int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        
        return gcd(b, a % b);
    }
    
    public int[] solution(int n, int m) {
        int[] answer = new int[2];
        
        // n과 m 중 큰 값이 앞으로
        int result = 0;
        if (n > m) {
            result = gcd(n, m);
        }
        else {
            result = gcd(m, n);
        }
        
        answer[0] = result;
        answer[1] = (n * m) / result;
        
        return answer;
    }
}
