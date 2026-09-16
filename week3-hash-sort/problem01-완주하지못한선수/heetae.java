// 문제: 완주하지 못한 선수
// 접근 방식: 맵에다가 완주했으면 0으로 바꾸고 아닐경우 1로 넣는식
// 시간복잡도: O(n)

import java.util.*;
class Solution {
    public String solution(String[] participant, String[] completion) {
        Map<String,Integer> map = new HashMap<>();
        for(String s : participant){
            map.put(s,map.getOrDefault(s,0)+1);
        }
        for(String s : completion){
            if(map.get(s)>0) map.put(s,map.get(s)-1);
        }
        for(String s : map.keySet()){
            if(map.get(s)>0) return s;
        }
            return "";
    }
}
