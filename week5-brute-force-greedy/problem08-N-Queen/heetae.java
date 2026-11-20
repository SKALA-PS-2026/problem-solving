// 문제: N-Queen
/*
접근 방식: 대각선을 인덱스 하나로 관리한다는 아이디어가 떠올리기 어려웠음
  처음에는 대각선 검색을 순회하면서 탐색하는걸 생각함
  시간복잡도는 근데 어짜피 최대 8이라...
*/
// 시간복잡도: O(N × N!)

class Solution {
    
    int answer = 0;
    static int idx;
    static boolean[] used1,used2,used3;
    
    public int solution(int n) {
        idx = n;
        used1 = new boolean[15];
        used2 = new boolean[n*2];
        used3 = new boolean[n*2];
        
        func(0);
        
        return answer;
    }
    void func(int current){
        if(current==idx){
            answer++;
            return;
        }
        for(int i=0;i<idx;i++){
            if(used1[i] || used2[i+current] || used3[i-current+idx]) continue;
            
            used1[i] = true;
            used2[i+current] = true;
            used3[i-current+idx] = true;
            func(current+1);
            used1[i] = false;
            used2[i+current] = false;
            used3[i-current+idx] = false;
        }
    }
}
