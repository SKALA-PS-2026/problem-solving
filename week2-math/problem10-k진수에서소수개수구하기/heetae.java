/**
문제: K진수에서 소수 개수 구하기
접근 방식: 0을 기준으로 소수판별이므로 0 기준으로 스플릿 후 소수 구해서 수 세기
시간복잡도: O(logₖ n+√p)
*/
class Solution {
    public int solution(int n, int k) {
        int answer = 0;
        StringBuilder sb = new StringBuilder();

        while (n > 0) {
            sb.append(n % k);
            n /= k;
        }

        String[] arr = sb.reverse().toString().split("0");

        for (String s : arr) {
            if (s.isEmpty()) continue;

            long num = Long.parseLong(s);

            if (isPrime(num)) {
                answer++;
            }
        }

        return answer;
    }

    boolean isPrime(long n) {
        if (n <= 1) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;

        for (long i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }

        return true;
    }
}