// 문제: 숫자 문자열과 영단어
// 접근 방식: 새로운 문자열을 만들어서 그 문자열에 숫자이면 그냥 넣고 단어이면 찾아서 넣는 식으로 접근(했는데 replaceAll이라는 더 쉬운 방식이 있...)
// 시간복잡도: O(n)
import java.util.Arrays;

class Solution {
    public int solution(String s) {
        String[] dictionary = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        StringBuilder answer = new StringBuilder();
        StringBuilder word = new StringBuilder();
        
        for (int i = 0;i < s.length();i++) {
            char now = s.charAt(i);
            
            if ('0' <= now && now <= '9') {
                answer.append(now);
                continue;
            }

            word.append(now);
            int index = Arrays.asList(dictionary).indexOf(word.toString());
            if (index != -1) {
                answer.append(index);
                word.setLength(0);
            }
            
        }
        
        return Integer.parseInt(answer.toString());
    }
}
