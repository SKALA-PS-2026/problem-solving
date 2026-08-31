// 문제: 문자열 나누기
// 접근 방식: 처음 문자부터 읽으면서 해당 글자와 다른 글자의 개수가 같을 때까지 반복하며 나눠지는 문자열 개수 확인
// 시간복잡도: O(n)
class Solution {
    public int solution(String s) {
        int answer = 0;
        int len = s.length();
        
        for (int i = 0;i < len;i++) {
            char c = s.charAt(i);
            int count1 = 0;
            int count2 = 0;
            int j;
            
            for (j = i;j < len;j++) {
                if (s.charAt(j) == c) {
                    count1++;
                }
                else {
                    count2++;
                }
                
                if (count1 == count2) {
                    break;
                }
            }
            
            answer++;
            i = j;
        }
       
        return answer;
    }
}
