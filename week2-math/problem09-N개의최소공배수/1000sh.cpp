// 문제: N개의 최소공배수
/*
접근 방식: 각 숫자들 약수를 구함.
  int[100]에 약수의 최대 개수를 때려박음.
  int[100]을 돌려서 다곱함.
*/
// 시간복잡도: O(n^2*m) n<=100 m<=15

#include <string>
#include <cmath>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 1;
    
    vector<int> arrdi(100+1,0);
    int size=arr.size();
    for(int i=0;i<size;i++)
    {
        int max=0;
        for(int j=2;arr[i]>=1;j++)
        {
            if(arr[i]%j==0)
            {
                arr[i]/=j;
                max++;
                j--;
            }
            else if (arr[i]==1)
            {
                arrdi[j]=arrdi[j]<max?max:arrdi[j];
                break;
            }
            else 
            {
                arrdi[j]=arrdi[j]<max?max:arrdi[j];
                max=0;
            }
        }
    }
    for(int i=2;i<=100;i++)
    {
        answer*=pow(i,arrdi[i]);
    }
    return answer;
}
