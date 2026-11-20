// 문제: 피로도
// 접근 방식: 백트래킹으로 모든 경우의 수(순열) 탐색
// 시간복잡도: O( n!)

import java.util.*;
class Solution {
    int answer = 0;
    boolean[] visited;
    int[][] dun;
    public int solution(int k, int[][] dungeons) {
        visited = new boolean[dungeons.length];
        dun = dungeons;
        for(int i=0;i<dungeons.length;i++){
           dfs(i, k, 0);
        }
        return answer;
    }
    void dfs(int idx,int health, int count){
        if(visited[idx] || health < dun[idx][0]) return;
        
        answer = Math.max(answer,count+1);
        
        visited[idx] = true;
        int nextHealth = health - dun[idx][1];
        
        for(int i=0;i<dun.length;i++){
            if(!visited[i]) dfs(i,nextHealth,count+1);
        }
        visited[idx] = false;
    }
}
