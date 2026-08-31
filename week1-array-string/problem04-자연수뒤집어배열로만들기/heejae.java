// 문제: 자연수 뒤집어 배열로 만들기
// 접근 방식: 10으로 나눈 나머지로 숫자의 뒷자리수부터 뽑은 후 리스트에 add해준다.
// 시간복잡도: O(log n)

import java.util.*;

class Solution {
    public int[] solution(long n) {
        List<Integer> list = new ArrayList<>();
        
        while(n > 0) {
            int num = (int) (n % 10); 
            n /= 10;
            
            list.add(num);
        }
        
        int[] answer = new int[list.size()];
        for(int i=0; i<list.size(); i++) answer[i] = list.get(i);
        
        return answer;
    }
}
