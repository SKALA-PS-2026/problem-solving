// 문제: 배열 두 배 만들기
// 접근 방식: 새 배열을 만들어 각 요소를 순회하며 2배 값을 저장
// 시간복잡도: O(n)
class Solution {
    public int[] solution(int[] numbers) {
        int[] answer = new int[numbers.length];
        
        for (int i = 0;i < numbers.length;i++) {
            answer[i] = numbers[i] * 2;
        }
        
        return answer;
    }
}
