// 문제: 문자열 내 p와 y의 개수
// 접근 방식: 대소문자 구분을 없애기 위해 하나로 통일, java의 스트림을 활용해서 간단하게 해당하는 알파벳의 개수를 계산
// 시간복잡도: O(n)
class Solution {
    boolean solution(String s) {
        boolean answer = true;
        
        String newS = s.toLowerCase();

        long pCount = newS.chars().filter(c -> c == 'p').count();
        long yCount = newS.chars().filter(c -> c == 'y').count();
        
        if (pCount == yCount) {
            return true;
        }

        return false;
    }
}
