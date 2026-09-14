// 문제: 문자열 다루기 기본
// 접근 방식: 문자열 길이 체크 (4도 아니고 6도 아니면 false) -> 숫자구성 체크 (문자열 내 모든 문자에 대해 숫자가 아닌게 있다면 false)
// 시간복잡도: O(n)

class Solution {
    public boolean solution(String s) {
        
        // 문자열 길이가 4 혹은 6인지 확인
        if(s.length() != 4 && s.length() !=6) return false;
        
        // 숫자로만 구성되어있는지 확인
        for(char c: s.toCharArray()) {
            if(!Character.isDigit(c)) return false;
        }

         return true;
    }
}
