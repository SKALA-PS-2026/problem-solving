'''
문제 이름: 이상한 문자 만들기
시간복잡도: O(N)
풀이 방법: split(' ')으로 단어를 구분한 뒤 2중 for문으로 각 단어의 문자 인덱스 홀/짝 여부에 따라 대소문자를 변환하여 연결
'''

def solution(s):
    answer = ''
    for word in s.split(' '):
        for i in range(len(word)):
            if i % 2 == 0:
                answer = answer + word[i].upper()
            else:
                print(word[i].lower())
                answer = answer + word[i].lower()
        answer = answer + ' '
    return answer[:-1]

