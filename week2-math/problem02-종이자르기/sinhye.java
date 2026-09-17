// 문제: 종이 자르기
// 접근 방식: M과 N에 관계에 따른 계산식을 구했습니다
// 시간복잡도: O(1)
class Solution {
    public int solution(int M, int N) {
        int answer = 0;
        
        answer = (M - 1) + (N - 1) * M;
        
        return answer;
    }
}
