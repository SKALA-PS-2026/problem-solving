// 문제: 문자열 내림차순으로 배치하기
// 접근 방식: 정렬한다음 그걸 뒤집으면 내림차순
// 시간복잡도: O(n log n) - 자바 sort의 시간복잡도

import java.util.*;

class Solution {
    public String solution(String s) {
        char[] answer = s.toCharArray();
        Arrays.sort(answer);

        StringBuilder sb = new StringBuilder(new String(answer));
        return sb.reverse().toString();
    }
}
