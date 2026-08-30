// 문제: 문자열 압축
// 접근 방식: 문자열을 1개씩부터 (문자열개수/2)개씩까지 묶어서 압축해본다.
// 처음으로 뽑아낸 문자열을 indexS로 지정하고 그 다음으로 뽑아낸 문자열들을 indexS와 비교하여 동일하다면 count를 증가하고
// 동일하지 않다면 indexS를 그 다음 문자열로 넣어준다.
// while문이 끝난 후 마지막 그룹을 처리하고, 단위로 나누어지지 않은 문자열도 붙여서 처리해준다.
// 시간복잡도: O(n²)

import java.util.*;

class Solution {
    public int solution(String s) {
        int answer = s.length();
        
        for(int i=1; i<=s.length()/2; i++) {

            // i개씩 뽑아낸다.
            StringBuilder sb = new StringBuilder();
            String indexS = s.substring(0, i);
            int count = 1;
            
            int idx = i;
            while(idx + i <= s.length()) {
                String sub = s.substring(idx, idx + i);
                
                if(sub.equals(indexS)) count++;
                else {
                    if(count == 1) sb.append(indexS);
                    else sb.append(count).append(indexS);
                    
                    indexS = sub;
                    count = 1;
                }
                
                idx += i;
            }
            
            // 마지막 그룹 처리
            if(count == 1) sb.append(indexS);
            else sb.append(count).append(indexS);
            
            // 단위로 남은 후 남은 문자열 처리
            if(idx < s.length()) {
                String sub = s.substring(idx);
                sb.append(sub);
            }
            
            answer = Math.min(sb.length(), answer);
            
        }
        return answer;
    }
}
