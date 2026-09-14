# 문제: 문자열 내 p와 y의 개수
# 접근 방식: 문자열을 소문자로 변환한 뒤 p와 y의 개수가 같은지 비교한다.
# 시간복잡도: O(n) (n은 s의 길이)

def solution(s):
    s = s.lower()
    return s.count('p') == s.count('y')
