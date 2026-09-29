// 문제: 이중우선순위큐
// 접근 방식: 
// 시간복잡도: O(NlogK)

// Date: 29SEP2026
// Author: Jung Minkyu
import java.util.*;

class Solution {
    public int[] solution(String[] operations) {
        PriorityQueue<Integer> minQ = new PriorityQueue<>();
        PriorityQueue<Integer> maxQ = new PriorityQueue<>(Collections.reverseOrder());

        for (String op : operations) {
            String[] split = op.split(" ");
            String command = split[0];
            int value = Integer.parseInt(split[1]);

            if (command.equals("I")) {
                minQ.add(value);
                maxQ.add(value);
            } else if (!minQ.isEmpty()) {
                if (value == 1) {
                    int max = maxQ.poll();
                    minQ.remove(max);
                } else {
                    int min = minQ.poll();
                    maxQ.remove(min);
                }
            }
        }

        if (minQ.isEmpty()) return new int[]{0, 0};
        
        return new int[]{maxQ.peek(), minQ.peek()};
    }
}