// 문제: 배열 만들기 2
// 접근 방식: i를 l부터 r까지 돌리면서 각 자릿수를 뽑아낸다.
// 5도 아니고 0도 아니라면 isPossible을 false 로 설정한다.
// 만약 모든 자릿수가 5또는 0이라면 (isPossible이 true인 상태) 리스트에 add해준다.
// 시간복잡도: O(r-l+1)

import java.util.*;

class Solution {
    public int[] solution(int l, int r) {
        
        List<Integer> list = new ArrayList<>();
        
        for(int i=l; i<=r; i++) {
            // i의 각 한자리씩 뽑아낸다.
            boolean isPossible = true;
            int num = i;
            while(num > 0) {
                int rest = num % 10;
                if(rest != 5 && rest != 0) {
                    isPossible = false;
                    break;
                }
                num /= 10;
            }
            
            if(isPossible) list.add(i);
        }
        
        if(list.size() == 0) return new int[] {-1};
        
        int[] answer = new int[list.size()];
        for(int i=0; i<list.size(); i++) answer[i] = list.get(i);
        
        return answer;
    }
}
