// 문제: N개의 최소공배수
// 접근 방식: 배열을 순회하며 현재 값과 다음 수의 최소공배수를 누적한다.
// 시간복잡도: O(n log M)

#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> arr) {
    int answer = 1;

    for (int num : arr) {
        answer = answer * num / gcd(answer, num);
    }

    return answer;
}
