// 문제: 문자열 나누기
// 접근 방식: firstCount와 anotherCount의 개수를 센다. 
// 또한 첫번째 문자의 경우 firstChar에 해당 문자를 지정해둔 후 그 이후 문자들과 비교하여 firstCount 또는 anotherCount를 증가시키다.
// 분리가 안될 수도 있는 문자열 범위를 위해 totalLength 변수를 만들어 나중에 남게 된다면 answer를 하나 증가시켜준다.
// 시간복잡도: O(n)

class Solution {
    public int solution(String s) {
        int answer = 0;
        
        char firstChar = ' ';
        int firstCount = 0;
        int anotherCount = 0;
        int totalLength = 0;
        
        for(int i=0; i < s.length(); i++) {
            char c = s.charAt(i);
            
            if(firstCount == 0) {
                firstChar = c;
                firstCount++;
                continue;
            }
            
            if(c == firstChar) firstCount++;
            else anotherCount++;
            
            if(firstCount == anotherCount) {
                totalLength += (firstCount + anotherCount);
                answer++;
                
                firstCount = 0;
                anotherCount = 0;
            }
        }
        
        if(totalLength < s.length()) answer++;
        
        return answer;
    }
}
