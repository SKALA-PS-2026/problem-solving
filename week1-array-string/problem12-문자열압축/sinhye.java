// 문제: 문자열 압축
// 접근 방식:
// 가능한 모든 자르는 단위 size에 대해 돌면서
// 각 size로 문자열을 토큰화한 뒤 연속된 동일 토큰을 묶어 압축 길이를 계산하고
// 그중 최솟값 리턴
// 시간복잡도: O(n²)
import java.util.List;
import java.util.ArrayList;

class Solution {
    private int groupLength(int count, int tokenLen) {
        if (count == 1) {
            return tokenLen;
        }
        
        return String.valueOf(count).length() + tokenLen;
    }
    
    public int solution(String s) {
        int len = s.length();
        int answer = len;

        for (int size = 1;size <= len / 2;size++) {
            List<String> tokens = new ArrayList<>();
            
            for (int i = 0;i < len;i += size) {
                int end = Math.min(i + size, len);
                tokens.add(s.substring(i, end));
            }
            
            int compressedLen = 0;
            String prev = tokens.get(0);
            int count = 1;
            
            for (int k = 1;k < tokens.size();k++) {
                if (tokens.get(k).equals(prev)) {
                    count++;
                }
                else {
                    compressedLen += groupLength(count, prev.length());
                    prev = tokens.get(k);
                    count = 1;
                }
            }
            
            compressedLen += groupLength(count, prev.length());
            answer = Math.min(answer, compressedLen);
        }
        
        return answer;
    }
}
