// 문제: 이상한 문자 만들기
// 접근 방식: 문자열 내의 모든 문자에 대해 공백이라면 그냥 append하고, 
// 공백이 아닌 문자라면 isEven(짝수인지 여부)에 따라 대문자 또는 소문자를 append해준 후 isEven을 토글한다.
// 시간복잡도: O(n)

import java.util.*;

class Solution {
    public String solution(String s) {
        StringBuilder sb = new StringBuilder();
        boolean isEven = true;
        
        for(int i=0; i<s.length(); i++) {
            char c = s.charAt(i);
            
            if(c == ' ') {
                sb.append(c);
                isEven = true;
            } else {
                if(isEven) sb.append(Character.toUpperCase(c));
                else sb.append(Character.toLowerCase(c));

                isEven = !isEven;
            }
        }
        
        return sb.toString();
    }
}
