// 문제: 시저 암호
// 접근 방식: 대소문자 별로 구분해서 처리, % 연산자 활용해서 n개 뒤 알파벳 구하기
// 시간복잡도: O(n)
class Solution {
    public String solution(String s, int n) {
        StringBuilder answer = new StringBuilder();
        
        for (int i = 0;i < s.length();i++) {
            char now = s.charAt(i);
            
            if (now == ' ') {
                answer.append(now);
                continue;
            }
            
            if('a' <= now && now <= 'z') {
                answer.append((char)('a' + (now + n - 'a') % 26));
                continue;
            }
            
            answer.append((char)('A' + (now + n - 'A') % 26));
        }
        
        return answer.toString();
    }
}
