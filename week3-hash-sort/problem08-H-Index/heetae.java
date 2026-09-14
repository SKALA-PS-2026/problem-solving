// 문제: H-Index
// 접근 방식: 인용수대로 정렬한뒤 현재 인용수가 길이에서 인덱스를 뺀 값보다 큰지를 계산한뒤 반환
// 시간복잡도: O(n)

import java.util.*;
class Solution {
    public int solution(int[] citations) {
        Arrays.sort(citations);
        for(int i=0;i<citations.length;i++){
            int current = citations[i];
            if(citations.length-i <= current) return citations.length-i;
        }
        return 0;
    }
}
