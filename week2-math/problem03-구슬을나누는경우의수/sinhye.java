// 문제: 구슬을 나누는 경우의 수
// 접근 방식: 처음엔 그냥 조합 공식 참고해서 팩토리얼 함수 만들어서 했는데 런타임 에러 발생!
// 그냥 팩토리얼을 그대로 하면 값이 크기 때문에 계산 식을 다르게 생각해야 했다.
// 그래도 실패해서 다시 보니 숫자 범위가 커져서 long으로 계산해줘야 했고 계산 결과를 다시 int로 바꿨습니다
// 시간복잡도: O(n)
class Solution {
    public static long comb(long n, long m) {
        long result = 1;
        
        for (int i = 0;i < m;i++) {
            result = result * (n - i) / (i + 1);
        }
        
        return result;
    }
    
    public int solution(int balls, int share) {
        int answer = 0;
        
        answer = (int)comb(Long.valueOf(balls), Long.valueOf(share));
        
        return answer;
    }
}
