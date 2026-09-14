/**
문제: 팩토리얼
접근 방식: 순차로 순회해서 넘어갈경우 i를 반환 어짜피 n이 10!까지임
시간복잡도: O(10)
*/
class Solution {
    public int solution(int n) {
        int answer = 1;
        for(int i=0;i<10;i++){
            answer*=(i+1);
            if(answer>n) return i;
        }
        return 10;
    }
}