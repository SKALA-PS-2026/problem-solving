// 문제: 문자열 내 p와 y의 개수
// 접근 방식: p또는 P라면 numP증가, y또는 Y라면 numY증가 -> 이후 비교한다.
// 시간복잡도: O(n)

class Solution {
    boolean solution(String s) {
        
        int numP = 0;
        int numY = 0;
        
        for(char c: s.toCharArray()) {
            if(c == 'p' || c == 'P') numP++;
            else if(c == 'y' || c == 'Y') numY++;
        }
        
        if(numP == numY) return true;
        else return false;
    }
}
