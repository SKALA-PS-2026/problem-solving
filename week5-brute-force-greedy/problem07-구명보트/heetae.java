// 문제: 구명보트
// 접근 방식: 그리디로 정렬 후 sum을 기준으로 제일 작은사람과 제일 큰사람을 더하는데 더 크면 무거운 사람을 줄이고 아닐 경우 동시에 줄임
// 시간복잡도: O(n)

import java.util.*;
class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;
        int start = 0;
        int end = people.length-1;
        Arrays.sort(people);
        
        while(start<=end){
            int sum = people[start] + people[end];
            if(sum<=limit){
                answer++;
                start++;
                end--;
            }
            else{
                end--;
                answer++;
            }
        }
        return answer;
    }
}
