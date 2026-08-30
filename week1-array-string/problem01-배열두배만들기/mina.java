// 문제 이름: 배열 두배 만들기
// 시간복잡도: O(n)

class Solution {
    public int[] solution(int[] numbers) {
        int[] answer = new int[numbers.length];
        for (int i=0; i<numbers.length; i++){
            answer[i] = numbers[i]*2;
        }
        return answer;
    }
}
