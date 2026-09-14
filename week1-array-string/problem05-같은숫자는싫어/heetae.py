# 문제: 같은 숫자는 싫어
# 접근 방식: 첫 원소를 저장한 뒤, 이전 원소와 다른 원소만 순서대로 추가한다.
# 시간복잡도: O(n) (n은 arr의 길이)

def solution(arr):
   return [arr[0]]+[arr[i] for i in range(1,len(arr)) if arr[i]!=arr[i-1]]
