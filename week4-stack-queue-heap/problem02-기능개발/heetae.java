// 문제: 기능개발
// 접근 방식: 날짜만큼 q의 peek를 검사하며 날짜*speed를 세기 그리고 충족한만큼 q에서 pop
// 시간복잡도: O(n)

import java.util.*;
class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        List<Integer> list = new ArrayList<>();

        Queue<Integer> q = new ArrayDeque<>();
        int cursor = 0;
        int percent = 1;

        for(int i =0;i<speeds.length;i++){
            q.offer(progresses[i]);
        }

        while(!q.isEmpty()){
            int count = 0;

            while(!q.isEmpty()
                  &&q.peek()+percent*speeds[cursor]>=100){
                q.poll();
                count++;
                cursor++;
            }
            if(count>0){
                list.add(count);
            }
            percent++;
        }

        return list
            .stream()
            .mapToInt(Integer::intValue)
            .toArray();
    }
}
