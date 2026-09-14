// 문제: 영어 끝말잇기
/*
접근 방식: 돌면서 끝말잇는데 i번째에 걸렸으면 걸린사람의 번호는 i%n+1이고
  걸린사람의 턴은 i/n+1이다
  그리고 set으로 중복을 확인
*/
// 시간복잡도: O(N)

import java.util.*;
class Solution {
    public int[] solution(int n, String[] words) {
        int[] answer = new int[]{0,0};
        Set<String> set = new HashSet<>();
        set.add(words[0]);
        
        for(int i=1;i<words.length;i++){
            String current = words[i];
            if(set.contains(current) || words[i-1].charAt(words[i-1].length()-1)!=current.charAt(0)){
                answer[0] = i%n+1;
                answer[1] = i/n+1;
                break;
            }
            set.add(current);
        }
        
        return answer;
    }
}
