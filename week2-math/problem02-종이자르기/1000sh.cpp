// 문제: 종이 자르기
/*
접근 방식: 어느쪽으로 자르든 상관 없기떄문에 가로부터 자른다고 치고 M-1번 잘라야함. 각 M개에 따라서 N-1번 더 잘라야함. (1*N종이는 N-1자르면 모두 1,1 이 되기 때문에)
  (M-1)+M*(N-1) = M*N-1
*/
// 시간복잡도: O(n) n<=M*N=10^4

using System;

public class Solution {
    public int solution(int M, int N) {
        int answer = M*N-1;
        return answer;
    }
}
