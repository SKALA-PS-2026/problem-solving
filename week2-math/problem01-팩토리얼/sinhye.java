// 문제: 팩토리얼
// 접근 방식: 팩토리얼 계산하면서 처음으로 커지는 값 비교
// 시간복잡도: O(log²n)
class Solution {
    public static int fact(int n) {
        if (n == 1) {
            return 1;
        }
        
        return n * fact(n - 1);
    }
    
    public int solution(int n) {
        int answer = 0;
        
        int i = 1;
        while (true) {
            if (fact(i) > n) {
                answer = i - 1;
                break;
            }
            
            i++;
        }
        
        return answer;
    }
}
