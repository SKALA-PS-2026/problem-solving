/**
문제: 구슬을 나누는 경우의 수
접근 방식: 걍 조합 공식을 때려박았는데 (팩토리얼 값은 메모제이션) 또한 20! 이상은 long 범위 초과이므로 빅 인티저를 사용
근데 찾아보니 중간중간 나눠서도 가능한듯
시간복잡도: O(n)
*/
import java.math.*;

class Solution {
    public int solution(int balls, int share) {
        BigInteger[] arr = new BigInteger[balls + 1];

        arr[0] = BigInteger.ONE;

        for (int i = 1; i <= balls; i++) {
            arr[i] = arr[i - 1].multiply(BigInteger.valueOf(i));
        }

        BigInteger result = arr[balls].divide(
            arr[balls - share].multiply(arr[share])
        );

        return result.intValue();
    }
}