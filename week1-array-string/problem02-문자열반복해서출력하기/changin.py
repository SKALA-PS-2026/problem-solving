'''
문제 이름: 문자열 반복해서 출력하기

시간복잡도: O(n)
'''

str, n = input().strip().split(' ')

for _ in range(int(n)): print(str,end='')