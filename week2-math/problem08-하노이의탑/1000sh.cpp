// 문제: 하노이의 탑
/*
접근 방식: 2개일때 방법을 3개일때 재활용 할수 있을 것 같다. 3개일때 방법을 4개일때 쓰고 그런식으로 고민해보자.
  3개일때 고민해보자  2개일떄 1->3 옮기는 방법을 1->2로 바꾸고 맨아래 있는 3번을 1->3옮기고 다시 2개일때 옮기는걸 2->3으로 응용하면 될거 같다.
  N개 옮기는법 N-1개를 1->2로 옮기고 N을 1->3으로 옮긴다음 N-1을 2->3으로 옮김 재귀를 써보자.
*/
// 시간복잡도: O(2^(n+1)) n <=15

#include <string>
#include <vector>

using namespace std;

void Move(vector<vector<int>>& answer,int n,int MoveStart,int MoveEnd)
{
    int SubPoint=6/MoveStart/MoveEnd;
    
    if(n==1)
    {
        answer.push_back({MoveStart,MoveEnd});
        return;
    }
    
    Move(answer,n-1,MoveStart,SubPoint);
    Move(answer,1,MoveStart,MoveEnd);
    Move(answer,n-1,SubPoint,MoveEnd);
}


vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    Move(answer,n,1,3);
    return answer;
}
