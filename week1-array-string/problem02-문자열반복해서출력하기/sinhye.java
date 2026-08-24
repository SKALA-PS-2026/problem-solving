# 문제: 문자열 반복해서 출력하기
# 접근 방식: n번만큼 반복하면서 빈 문자열에 붙임
# 시간복잡도: O(n)
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        int n = sc.nextInt();
        
        String answer = "";
        for (int i = 0;i < n;i++) {
            answer += str;
        }
        
        System.out.println(answer);
    }
}
