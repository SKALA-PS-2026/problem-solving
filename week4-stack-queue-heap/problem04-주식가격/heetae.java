// 문제: 주식가격
/*
접근 방식: 스택으로 탐색하며 peek보다 높으면 push
  peek보다 낮으면 높아질때까지 pop
  Pop한 대상은 현재 위치로부터 인덱스를 빼서 오른 가격 산정
*/
// 시간복잡도: O(n)

import java.util.*;

class Solution {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < prices.length; i++) {

            while (!stack.isEmpty() &&
                   prices[stack.peek()] > prices[i]) {

                int current = stack.pop();
                answer[current] = i - current;
            }

            stack.push(i);
        }

        while (!stack.isEmpty()) {
            int current = stack.pop();
            answer[current] = prices.length - 1 - current;
        }

        return answer;
    }
}
