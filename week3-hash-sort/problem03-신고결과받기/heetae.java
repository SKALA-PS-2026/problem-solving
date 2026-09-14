// 문제: 신고 결과 받기
/*
접근 방식: 유저 이름을 키로 가지고 신고가 중복이 안되므로 밸류로 셋을 가진 맵을 생성
  그리고 신고 횟수를 가진 맵을 생성해서 내가 신고한 유저가 정지되었는지 세면서 구현
*/
// 시간복잡도: O(n^2)

import java.util.*;
class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];
        //유저 신고 내역
        Map<String,Set<String>> map = new HashMap<>();
        //신고당한 횟수 정산
        Map<String,Integer> reported = new HashMap<>(); 
        
        for(int i=0;i<id_list.length;i++){
            map.put(id_list[i],new HashSet<>());        
        }
        
        //신고 내역 저장
        for(int i=0;i<report.length;i++){
            String[] str = report[i].split(" ");
            map.get(str[0]).add(str[1]);
        }
        
        //신고횟수 세기
        for(String s : map.keySet()){
            for(String id : map.get(s)){
                reported.put(id,reported.getOrDefault(id,0)+1);
            }    
        }
        
        //정산
        for(int i=0;i<answer.length;i++){
            String current = id_list[i];
            for(String s : map.get(current)){
                if(reported.get(s)>=k) answer[i]++;
            }
        }
        
        return answer;
    }
}
