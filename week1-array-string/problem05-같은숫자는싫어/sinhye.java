// 문제: 같은 숫자는 싫어
// 접근 방식: 임의로 기준값을 하나 정하고 배열을 돌면서 이전값과 같으면 넘기고 다를 때만 새 배열에 넣어서 해당 배열을 출력
// 시간복잡도: O(n)
import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        List<Integer> list = new ArrayList<>();
        
        int tmp = -1;
        for (int i = 0;i < arr.length;i++) {
            if (tmp == arr[i]) {
                continue;
            }
            
            list.add(arr[i]);
            tmp = arr[i];
        }

        int[] answer = new int[list.size()];
        for (int i = 0;i < answer.length;i++) {
            answer[i] = list.get(i);
        }
        
        return answer;
    }
}
