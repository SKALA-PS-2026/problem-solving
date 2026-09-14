// 문제: 문자열 내 마음대로 정렬하기
// 접근 방식: 자바의 sort 함수를 활용해 두 인덱스의 값이 다를경우 높은순대로, 같을경우 compareTo를 활용합니다.
// 시간복잡도: O(n log n)

import java.util.*;
class Solution {
    public String[] solution(String[] strings, int n) {
        Arrays.sort(strings,(a,b)->{
            if(a.charAt(n)!=b.charAt(n)) return a.charAt(n)-b.charAt(n);
            return a.compareTo(b);
        });
        return strings;
    }
}
