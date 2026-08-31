// 문제: 배열 만들기 2
// 접근 방식: 
// 시간복잡도: 

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    
    for(int i = l; i <=r; i++) {
        int num = i;
        int check  = 1;
        
        while(num > 0) {
            int a  = num % 10;
            
            if(a!= 0 && a !=5) {
                check = 0;
                break;
            }
            
            num = num/10;
        }
        
        if(check ==1) {
            answer.push_back(i);
        }
            
    }
    
    if(answer.size() == 0) {
        answer.push_back(-1);
    }
    
    return answer;
}
