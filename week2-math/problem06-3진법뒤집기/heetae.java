/**
문제: 3진법 뒤집기
접근 방식: n진수 구하기 -> n으로 나누고 나머지들을 합산 n진수를 10진수로 -> n의 0승 1승 2승.... * 자릿수
시간복잡도: O(log n)
*/
class Solution {
    public int solution(int n) {
        int answer = 0;
        int current = n;
        StringBuilder sb = new StringBuilder();
        while(current>0){
            sb.append(current%3);
            current/=3;
        }
        int tmp = 0;
        for(int i=sb.length()-1;i>=0;i--){
            answer += (sb.charAt(i) - '0') * (int) Math.pow(3, tmp);
            tmp++;
        }
        return answer;
    }
}