/*
 * Date: 30AUG2026
 * Author: Minkyu Jung
 
 * # 문제: 배열 두 배 만들기
 * # 접근 방식: 원소를 순회하며 *2 값을 저장한다. (원소 범위가 -10_000 ~ 10_000으로, Overflow는 신경쓰지 않아도 된다.)
 * # 시간복잡도: O(N) 
 */
class Solution {
    public int[] solution(int[] numbers) {
        int idx = 0; // 향상된 for문으로 해결
        for (int el : numbers)
            numbers[idx++] = el * 2;
        return numbers;
    }
}

// compile error 제거용 클래스 선언
public class jungMinkyu {

}