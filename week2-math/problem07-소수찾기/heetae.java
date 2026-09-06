/**
문제: 소수찾기
접근 방식: 1부터 소수판별법을 사용 -> 이게 빠른줄 알았는데 에라토스테네스의 체가 더빠르다고 함
시간복잡도: O(n√n)
*/
class Solution {
    public int solution(int n) {
        int answer = 0;
        for(int i =1;i<=n;i++){
            if(isPrime(i)) answer++;
        }
        return answer;
    }
    boolean isPrime(int n){
        if(n<=1) return false;
        if(n==2 || n==3) return true;
        if(n%2==0 || n%3==0) return false;

        for(int i=5;i*i<=n;i+=6){
            if(n%i==0 || n%(i+2) == 0) return false;
        }

        return true;
    }
}