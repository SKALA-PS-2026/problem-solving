// 문제: 소수 찾기
/*
접근 방식: 무식한 for 루프 O(n^2)>10^8  n<=10^6 돌렸더니 시간 초과 되어 다시 고민
  약수가 존재할 경우 최소 약수로 가정하고 n을 n^0.5까지만 돌림
*/
// 시간복잡도: O(n*n^0.5) n<=10^6 미리 braek를 통해서 아슬아슬하게 통과

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i=2;i<=n;i++)//현재 숫자가 소수인지 판단
    {
        bool check=false;
        for(int j=2;j*j<=i;j++)//현재 숫자 이하의 숫자를 모두 나눔.
        {
            if(i%j==0)//소수 아님
            {
                check=true;
                break;
            }
        }
        if(!check)// 소수일경우
        {
            answer++;
        }
    }
    
    return answer;
}
