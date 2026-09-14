/*
 * Date: 30AUG2026
 * Author: Minkyu Jung
 
 * # 문제: 배열 만들기 2
 * # 접근 방식: 5 또는 0만 붙인다. bfs로 해보는 연습
 * # 시간복잡도: O(2^p) p == 자리수(r의 자리수 -> r이 limit이기 때문에)
 */
import java.util.*;

class Solution {
    
    // 접근 제어자 선언 안하면 default로 취급
    /* default */    
    boolean isValid(int integer, int l, int r) {
        if (l <= integer && r >= integer) return true;
        return false;
    }
    
    boolean isValid(int integer, int r) {
        if (r >= integer) return true;
        return false;
    }

    public int[] solution(int l, int r) {
        ArrayDeque<String> q = new ArrayDeque<>();
        PriorityQueue<Integer> list = new PriorityQueue<>(/*내림차순이면 이거로 Collections.reverseOrder*/);
        // q.offer("0");
        q.offer("5");
        
        while (!q.isEmpty()) {
            String curr = q.poll();
            
            int appendZero = Integer.parseInt(curr + "0");
            int appendFive = Integer.parseInt(curr + "5");
            
            if (isValid(appendZero, r)) q.offer(String.valueOf(appendZero));
            if (isValid(appendFive, r)) q.offer(String.valueOf(appendFive));
            
            if (isValid(Integer.parseInt(curr), l, r)) list.offer(Integer.parseInt(curr));
        }
        // 1. 조건에 맞는 정수가 하나도 없을 경우 [-1] 반환
        if (list.isEmpty()) {
            return new int[]{-1};
        }

        // 2. list의 크기만큼 배열 생성
        int[] answer = new int[list.size()]; 
        int idx = 0;
        for (int el : list) {
            answer[idx++] = el;
        }

        return answer;
       
    }
}