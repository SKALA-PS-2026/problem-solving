/**
문제: 약수의 합
접근 방식: 어짜피 루트만큼 탐색하면 반대편을 알 수 있으므로 i*i만큼만 돌면 된
시간복잡도: O(√n)
*/
class Solution {
    public int solution(int n) {
        int answer = 0;

        for (int i = 1; i * i <= n; i++) {
            if (n%i  == 0) {
                answer += i;

                if (i != n/i) {
                    answer += n/i;
                }
            }
        }

        return answer;
    }
}