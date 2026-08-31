// 문제: 같은 숫자는 싫어
// 접근 방식: 현재 넣으려는 숫자(arr[i])가 list에 없을 때만 넣는다.
// 시간복잡도: O(n)

import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        
        List<Integer> list = new ArrayList<>();
        
        for(int i=0; i<arr.length; i++) {
            if(list.size() > 0 && list.get(list.size()-1) == arr[i]) continue;
            
            list.add(arr[i]);
        }
        
        int[] answer = new int[list.size()];
        for(int i=0; i<list.size(); i++) answer[i] = list.get(i);
        
        return answer;
    }
}
