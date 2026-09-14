/**
문제: 최대공약수와 최소공배수
접근 방식: 최대공약수는 작은수가 0이될때까지 나눈 나머지를, 최소공배수는 두수의 곱을 gcd로 나누기
시간복잡도: O(log(min(n, m)))
*/
class Solution {
    public int[] solution(int n, int m) {
        int gcd = gcd(n, m);
        return new int[]{gcd, n * m / gcd};
    }
    int gcd(int a, int b){
        int tmp,k;

        if(b>a){
            tmp = b;
            b = a;
            a = tmp;
        }

        while(b!=0){
            k = a%b;
            a = b;
            b = k;
        }
        return a;
    }
}