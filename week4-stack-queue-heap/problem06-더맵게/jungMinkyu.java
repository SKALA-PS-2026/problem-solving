// 문제: 더 맵게
// 접근 방식: 
// 시간복잡도:

// Date: 29SEP2026
// Author: Jung Minkyu


// 16:07 시작 ~ 16:24 종료
import java.util.Arrays;
import java.util.Queue;
import java.util.PriorityQueue;
import java.util.Comparator;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        // 섞은 음식의 스코빌 지수 
        // = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)
        // Leo는 모든 음식의 스코빌 지수가 K 이상이 될 때까지 반복하여 섞습니다.
        Queue<Integer> q = new PriorityQueue<>();
        
        /*
        필요 없음
        // 정렬 후 삽입하기
        Arrays.sort(scoville);
        */
        // 음식 넣기
        for (int el : scoville)
            q.add(el);
        
        int result = 0; // 최종 결과
        
        while (q.peek() < K) {
            if (q.size() < 2) return -1;
            
            int first = q.poll();
            int second = q.poll();
            
            int mixed = first + (second * 2);
            q.add(mixed);
            answer++;
        }
        
        return answer;
    }
}