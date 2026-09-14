// 문제: 배열 두 배 만들기
// 접근 방식: 동일한 길이의 배열을 생성한 후, 기존 원소를 하나씩 돌면서 해당 값에 두배하여 새로운 배열에 넣어준다.
// 시간복잡도: O(n)

class Solution {
    public int[] solution(int[] numbers) {
        int[] answer = new int[numbers.length];

        for(int i=0; i<numbers.length; i++) {
            answer[i] = numbers[i] * 2;
        }
        
        return answer;
    }
}
