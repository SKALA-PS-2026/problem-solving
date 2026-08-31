// 문제: 문자열 다루기 기본
// 접근 방식: 숫자 범위가 아닐 때 false, 문자열 길이가 4와 6이 아닐때 false 처리
// 시간복잡도: O(n)
class Solution {
    public boolean solution(String s) {
        boolean answer = true;
        
        if ((s.length() != 4) && (s.length() != 6)){
            return false;
        }
        
        for (int i = 0;i < s.length();i++) {
            if((s.charAt(i) - '0') > 9 || (s.charAt(i) - '0') < 0) {
               return false;
           }
        }
        
        return true;
    }
}
