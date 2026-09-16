// 문제: 가장 큰 수
// 접근 방식: 자바의 소트를 이용해서 비교한뒤 스트림으로 합산
// 시간복잡도: O(nlogn)

import java.util.*;
import java.util.stream.*;
class Solution {
    public String solution(int[] numbers) {
        String answer = Arrays.stream(numbers)
            .mapToObj(String::valueOf)
            .sorted((a,b)->(b+a).compareTo(a+b))
            .collect(Collectors.joining());
        
        if(answer.startsWith("0")) return "0";
        
        return answer;
    }
}
