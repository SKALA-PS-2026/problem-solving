// 문제: 더 맵게
/*
접근 방식: 우선순위 큐를 통해 사이즈가 1이 되거나 peek를 검사해서 원하던 최소값보다 낮은지를 확인
  만약 1개일경우 못바꾸므로 -1을 반환
*/
// 시간복잡도: O(n log n)

import java.util.*;
class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        Queue<Long> q = new PriorityQueue<>();
        for(int i=0;i<scoville.length;i++){
            q.offer((long)scoville[i]);
        }

        while(q.size()>1 && q.peek()<K){
            long first = q.poll();
            long second = q.poll();
            q.offer(first + second*2);
            answer++;
        }

        if (q.peek() < K) {
            return -1;
        }

        return answer;
    }
}
