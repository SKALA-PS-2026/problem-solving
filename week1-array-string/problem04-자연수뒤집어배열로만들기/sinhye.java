# 문제: 자연수 뒤집어 배열로 만들기
# 접근 방식: long으로 받은 자연수를 문자열로 변환하고 해당 문자열을 뒤집어서 배열로 반환
# 시간복잡도: O(log n)
import java.util.ArrayList;

class Solution {
    public int[] solution(long n) {
        String tmp = Long.toString(n);
        
        String reversed = new StringBuilder(tmp).reverse().toString();
        ArrayList<Integer> answer = new ArrayList<>();
        
        for (int i = 0;i < reversed.length();i++) {
            answer.add(reversed.charAt(i) - '0');
        }
        
        return answer.stream().mapToInt(Integer::intValue).toArray();
    }
}
