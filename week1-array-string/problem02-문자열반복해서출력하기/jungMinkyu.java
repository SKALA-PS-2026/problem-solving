/*
 * Date: 30AUG2026
 * Author: Minkyu Jung
 
 * # 문제: 문자열 반복해서 출력하기
 * # 접근 방식: 문자열과 정수를 읽고 문자열을 정수만큼 반복한다.
 * # 시간복잡도: O(M * N) M은 반복 횟수, N은 문자열 길이
 */
// 이후 import문은 편의를 위해 java.io.* 로 대체
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Solution {
    public static void main(String[] args) throws IOException {
        // 입력용 BufferedReader 선언
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // 출력용 BufferedWriter 선언
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        // ex Format: 문자열 정수
        String[] split = br.readLine().split(" "); // 공백으로 구분되기 때문에. (StringTokenizer 가능)
        int limit = Integer.parseInt(split[1]); // 반복 횟수 typeCasting
        
        for (int i = 0; i < limit; i++)
            bw.write(split[0]); // split[0] : 반복할 문자열
        
        bw.flush(); // 출력
        bw.close(); // 종료
        
        
    }
}

// compile error 제거용 클래스 선언
public class jungMinkyu {

}