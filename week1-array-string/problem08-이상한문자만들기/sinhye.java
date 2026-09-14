// 문제: 이상한 문자 만들기
// 접근 방식:
// 1. 답을 위한 문자열 하나 생성
// 2. 입력받은 문자열을 한 글자씩 읽으면서 공백이면 답에 추가
// 3. 답이 아닌 문자이면 해당 단어의 인덱스의 홀짝을 확인해서 대소문자 처리해서 추가
// 시간복잡도: O(n)
class Solution {
    public String solution(String s) {
        StringBuilder answer = new StringBuilder();
        int index = 0;
        
        for (int i = 0;i < s.length();i++) {
            // 공백이면 추가
            if (s.charAt(i) == ' ') {
                answer.append(s.charAt(i));
                index = 0;
                continue;
            }
            
            // 단어이면 대소문자 처리
            if (index % 2 == 0) {
                answer.append(Character.toUpperCase(s.charAt(i)));
            } else {
                answer.append(Character.toLowerCase(s.charAt(i)));
            }
            index++;
        }
        
        return answer.toString();
    }
}
