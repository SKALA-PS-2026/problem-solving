// 문제: 시저 암호
// 접근 방식: 문자열 내의 문자가 공백이라면 그냥 append해주고,
// 공백이 아닌 문자라면 대문자인지 소문자인지 여부에 따라 n씩 밀어준다. (밀어주는 공식은 그냥 외웠음.)
// 시간복잡도: O(n)

class Solution {
    public String solution(String s, int n) {
        StringBuilder sb = new StringBuilder();
        
        for(char c: s.toCharArray()) {
            if(c == ' ') {
                sb.append(c);
                continue;
            }
            
            char newC = ' ';
            
            if(Character.isUpperCase(c)) newC = (char) ((c - 'A' + n) % 26 + 'A');
            else newC = (char) ((c - 'a' + n) % 26 + 'a');
            
            sb.append(newC);
        }
        
        return sb.toString();
    }
}
