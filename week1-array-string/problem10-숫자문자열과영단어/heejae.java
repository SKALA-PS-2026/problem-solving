// 문제: 숫자 문자열과 영단어
// 접근 방식: 먼저 특정 문자열과 매칭되는 숫자를 저장하는 map을 만들어 각 숫자별로 저장한다.
// 이후 입력 문자열을 돌면서 숫자라면 answer에 바로 append하고, 
// 문자라면 문자열을 만드는 sb에 append하여 만약 sb가 map의 key중 하나와 일치한다면 그 숫자값을 answer에 넣고 sb는 초기화해준다.
// 시간복잡도: O(n)

import java.util.*;

class Solution {
    public int solution(String s) {
        StringBuilder answer = new StringBuilder();
        StringBuilder sb = new StringBuilder();
        
        Map<String, String> map = new HashMap<>();
        map.put("zero", "0");
        map.put("one", "1");
        map.put("two", "2");
        map.put("three", "3");
        map.put("four", "4");
        map.put("five", "5");
        map.put("six", "6");
        map.put("seven", "7");
        map.put("eight", "8");
        map.put("nine", "9");
        
        for(int i=0; i<s.length(); i++) {
            char c = s.charAt(i);
            // 숫자라면
            if(Character.isDigit(c)) {
                answer.append(c);
            }
            // 문자라면
            else {
                sb.append(c);
                if(map.containsKey(sb.toString())) {
                    answer.append(map.get(sb.toString()));
                    sb.setLength(0);
                }
            }
        }
        
        return Integer.parseInt(answer.toString());
    }
}
