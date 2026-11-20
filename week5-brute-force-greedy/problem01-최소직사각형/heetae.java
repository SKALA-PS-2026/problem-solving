// 문제: 최소직사각형
// 접근 방식: 사이즈 배열에서 0번째 인덱스에 큰걸 1번째 인덱스에 작은걸 놓고 0번의 최댓값과 1번의 최댓값을 곱함
// 시간복잡도: O(n)

class Solution {
    public int solution(int[][] sizes) {
        int maxA = 0;
        int maxB = 0;

        for (int i = 0; i < sizes.length; i++) {
            if (sizes[i][1] > sizes[i][0]) {
                int tmp = sizes[i][0];
                sizes[i][0] = sizes[i][1];
                sizes[i][1] = tmp;
            }
        }

        for (int i = 0; i < sizes.length; i++) {
            maxA = Math.max(maxA, sizes[i][0]);
            maxB = Math.max(maxB, sizes[i][1]);
        }

        return maxA * maxB;
    }
}
