// 문제: 팩토리얼
// 접근 방식: 입출력 제한사항이 0 < n ≤ 3,628,800 (=10 팩토리얼) 이므로..
// 10에서부터 1까지 각 숫자의 팩토리얼을 구하여 n 이하가 되는 순간 해당 숫자를 return한다.
// 시간복잡도: O(1)

class Solution {
    public int solution(int n) {
        
        for(int i=10; i>=1; i--) {
            int num = i;
            for(int j=i-1; j>=1; j--) {
                num *= j;
            }
            
            if(num > n) continue;
            else return i;
        }
        
        return 0;
    }
}
