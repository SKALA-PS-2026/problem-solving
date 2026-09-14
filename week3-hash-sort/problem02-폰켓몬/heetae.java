// 문제: 폰켓몬
// 접근 방식: 그냥 Set에다 다 넣어놓고 최대한 많은 종류를 넣어야하니 N/2마리보다 사이즈가 크면  return N/2, 작을경우 size()
// 시간복잡도: O(n)

import java.util.*;
class Solution {
    public int solution(int[] nums) {
        int answer = nums.length/2;
        
        Set<Integer> set = new HashSet<>();
        
        for(int i:nums){
            set.add(i);
        }
        
        return set.size()>answer? answer : set.size();
    }
}
