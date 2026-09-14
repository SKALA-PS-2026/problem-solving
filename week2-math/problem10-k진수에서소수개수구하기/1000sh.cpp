// 문제: k진수에서 소수 개수 구하기
/*
접근 방식: 그냥 무식하게 0을 기준으로 쪼갠뒤 제일 큰 수 기준으로 아래로 소수 구해놓고 체크.
  멍청한 C++은 split도 없네 이런 쓰래기 같은 언어.
  꿩대신 닭으로 진수로 변환시 0이면 냅다 쪼개고 배열에 대입.
  망할 메모리 초과. 모든 소수 넣는게 메모리 많이 먹는듯. 2개 실패로 인하여 소수를 한개씩 노가다로 구하기로 결정.
*/
// 시간복잡도: 머리아픔. O(log(k)n +numSize*numb[i]^0.5)

/* 망할 메모리 초과 버전
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, int k) {
    int answer = 0;
    
    vector<int> numb;
    int changAfterNum=0;
    int digits=1;
    for(int i=0;n>0;i++) //진수로 변환.
    {
        int cutnum=n%k;
        if(cutnum==0)
        {
            if(changAfterNum!=0)
            {
                numb.push_back(changAfterNum);
                changAfterNum=0;
                digits=1;
            }
            
        }
        else 
        {
            changAfterNum+=cutnum*digits;
            digits*=10;
        }
        
        n/=k;
    }
    if(changAfterNum!=0)
    {
        numb.push_back(changAfterNum);
        changAfterNum=0;
        digits=1;
    }

    vector<bool> isPrime(*max_element(numb.begin(),numb.end())+1,true);
    isPrime[0]=false;
    isPrime[1]=false;
    int priSize=isPrime.size();
    for(int i=2;i*i<priSize;i++)
    {
        if(isPrime[i])
        {
            for(int j=i*i;j<priSize;j+=i)
            {
                isPrime[j]=false;
            }
        }
    }
    int numSize=numb.size();
    for(int i=0;i<numSize;i++)
    {
        answer+=isPrime[numb[i]]?1:0;
    }
    return answer;
}
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, int k) {
    int answer = 0;
    
    vector<long long> numb;
    long long changAfterNum=0; //진수변환으로 길어지는거 방지 더크면 문제 노양심임.
    long long digits=1;
    for(int i=0;n>0;i++) //진수로 변환.
    {
        int cutnum=n%k;
        if(cutnum==0)
        {
            if(changAfterNum!=0)
            {
                numb.push_back(changAfterNum);
                changAfterNum=0;
                digits=1;
            }
            
        }
        else 
        {
            changAfterNum+=cutnum*digits;
            digits*=10;
        }
        
        n/=k;
    }
    if(changAfterNum!=0)
    {
        numb.push_back(changAfterNum);
        changAfterNum=0;
        digits=1;
    }

   
    //메모리 초과 변경부분. 노다가로 for 돌림
    int numSize=numb.size();
    for(int i=0;i<numSize;i++)
    {
        if(numb[i]>2&&numb[i]%2==0) continue;
        if(numb[i]<=1) continue;
        int check=true;
        for(long long j=3;j*j<=numb[i];j+=2)
        {
            if(numb[i]%j==0)
            {
                check=false;
                cout<<numb[i] <<"   "<<j<<endl;
                break;
            }
        } 
                cout<<numb[i] <<"   "<<endl;
        answer+=check?1:0;
    }
    return answer;
}
