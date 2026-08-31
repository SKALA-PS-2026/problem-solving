// 문제: 문자열 반복해서 출력하기
// 접근 방식: n번동안 StirngBuilder에 문자열을 append해준다.
// 시간복잡도: O(n)

import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        int n = sc.nextInt();
        
        StringBuilder sb = new StringBuilder();
        for(int i=1; i<=n; i++) {
            sb.append(str);
        }
        
        System.out.println(sb);
    }
}
