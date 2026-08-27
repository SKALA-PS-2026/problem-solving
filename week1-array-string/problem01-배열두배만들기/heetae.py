# 문제: 배열 두 배 만들기
# 접근 방식: 리스트 컴프리헨션으로 모든 원소에 2를 곱한 새 배열을 만든다.
# 시간복잡도: O(n) (n은 numbers의 길이)

def solution(numbers):
    return [i*2 for i in numbers]
