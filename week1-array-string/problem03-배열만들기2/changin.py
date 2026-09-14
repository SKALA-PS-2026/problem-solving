'''
문제 이름: 배열만들기2
시간복잡도: O(N)
풀이 방법: set으로 0,5제외 제거 후 같은지 비교 
'''

def solution(l, r):
    answer = []   
    a = set(["1","2","3","4","6","7","8","9"])
    for num in range(l, r + 1):
        b = set(str(num))  
        if b - a == b :
            answer.append(num)    
    return answer if answer else [-1]