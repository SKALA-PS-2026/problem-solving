#include <string>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for_each(numbers.begin(), numbers.end(), [&](int& n){
        answer.push_back(n*2);
    });
    return answer;
}