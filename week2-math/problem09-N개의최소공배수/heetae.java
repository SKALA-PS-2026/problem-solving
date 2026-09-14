/**
문제: N개의 최소공배수
접근 방식: 앞의 두개의 최소공배수를 구한뒤 순차 진행하며 각각 최소공배수 구함
시간복잡도: O(n)
*/
class Solution {
    public int solution(int[] arr) {
        int answer = 0;
        answer = arr[0] * arr[1] / gcd(arr[0],arr[1]);
        for(int i=2;i<arr.length;i++){
            answer = answer * arr[i]/gcd(answer,arr[i]);
        }
        return answer;
    }
    int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
}