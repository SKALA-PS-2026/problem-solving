// 문제: 예산
/*
접근 방식: 정렬한뒤 가장 작은것부터 더하는 그때그때 최적의 작은걸 찾는 방법을 활용함
  합을 초과할경우 반복문 종료
*/
// 시간복잡도: O(nlogn)

import java.util.*;
class Solution {
    public int solution(int[] d, int budget) {
        int answer = 0;
        Arrays.sort(d);
        int sum = 0;
        for(int i=0;i<d.length;i++){
            if (sum+d[i] > budget) break;
            sum+=d[i];
            answer++;
        }
        return answer;
    }
}
