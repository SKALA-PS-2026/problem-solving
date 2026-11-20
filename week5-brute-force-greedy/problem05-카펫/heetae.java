// 문제: 카펫
// 접근 방식: yellow의 값은 항상 x-2 * y-2 이므로 두 칸의 합의 약수를 찾아가며 값을 찾기
// 시간복잡도: O(n)

class Solution {
    public int[] solution(int brown, int yellow) {
        int total = brown + yellow;
        
        for(int y=3;y*y<=total;y++){
            if(total%y==0){
                int x = total/y;
                
                if((x-2) * (y-2) == yellow) return new int[]{x,y};
            }
        }
        
        return new int[]{};
    }
}
