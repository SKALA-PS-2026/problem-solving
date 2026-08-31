// 문제: 배열 만들기 2
// 접근 방식: l이상 r이하를 반복해서 0과 5로만 이루어진 정규식을 만족하는지 확인
// 시간복잡도: O(n)
import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] solution(int l, int r) {
        List<Integer> answer = new ArrayList<>();
        
        for (int i = l;i <= r;i++) {            
            boolean isOnlyZeroFive = Integer.toString(i).matches("[05]+");
            if(isOnlyZeroFive) {
                answer.add(i);
            }
        }
        
        if (answer.size() > 0) {
            return answer.stream().mapToInt(Integer::intValue).toArray();
        }
        
        return new int[]{-1};
    }
}
