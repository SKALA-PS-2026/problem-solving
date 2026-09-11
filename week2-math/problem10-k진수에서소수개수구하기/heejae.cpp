// 문제: k진수에서 소수 개수 구하기
// 접근 방식: n을 k진수로 바꾼다.
// k진수로 바뀐 숫자배열의 각 원소를 순회하며
//   0이 아니라면 temp에 push_back
//   0이라면 temp배열을 10진수로 변환하여 isPrime인지 확인
// temp에 남아있는 애가 있는 경우 temp배열을 10진수로 변환하여 isPrime인지 확인
// 시간복잡도: O(n√n)

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(long long n);
long long toNum10(vector<int> temp);

int solution(int n, int k) {
    int answer = 0;
    
    vector<int> list;
    
    // 일단 k진수로 바꾼다.
    while(n > 0) {
        int num = n % k;
        list.push_back(num);
        n /= k;
    }
    reverse(list.begin(), list.end());
    
    // 0이 아닌 연속된 숫자를 뽑는다.
    // 소수인지 확인한다.
    
    vector<int> temp; 
    for(int i=0; i<list.size(); i++) {
        long long temp10 = 0;  // 10진수
        
        if(list[i] != 0) {
            temp.push_back(list[i]);
        }
        else {
            // temp를 읽어온다.10진수로 변환
            if(temp.size() > 0) {
                temp10 = toNum10(temp);
                if(isPrime(temp10)) answer++;
                
                temp.clear();
            }
        }
    }
    
    if(!temp.empty()) {
        long long temp10 = toNum10(temp);
        if(isPrime(temp10)) answer++;
    }
    
    return answer;
}

// 소수인지 확인하는 함수
bool isPrime(long long n) {
    if(n < 2) return false;
    bool isNPrime = true;
    
    for(int i=2; i<=sqrt(n); i++) {
      if(n % i == 0) {
          return false;
      }
    }
    
    if(isNPrime) return true;
}

// 10진수 변환 함수
long long toNum10(vector<int> temp) {
    int num = 0;
    long long answer = 0;
    for(int j=temp.size()-1; j>=0; j--) {
        answer += std::pow(10, num) * temp[j];
        num++;
    }
    
    return answer;
}
