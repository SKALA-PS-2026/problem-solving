'''
문제 이름: 문자열 압축
시간복잡도: O(N²)
풀이 방법:  i개씩 짤라서 splited 리스트에 저장 (i는 전체 문자열의 절반까지만 )
            ㄴsplited 리스트 순회하면서 이전거랑 같은지 비교 : 
                ㄴ같으면 cnt + 1
                ㄴ다른게나오면 cnt가 2 이상인지 확인 후 이상이면 압축 
    #다른게나왔을떄 cnt 가 1이면 걍 어펜드 
'''
def solution(s):
    answer = 0
    #i글자씩 해서 길이 저장 
    min_len = len(s)
    b = min_len//2+1
    for n in range(1,b):
        splited = [s[i : i + n] for i in range(0, len(s), n)]
        splited.append("")
        prev = ''
        cnt = 1
        tmpstr = ''
        for word in splited:
            if prev == word:
                cnt += 1
            elif prev == '':
                pass
            else:
                if cnt == 1: 
                    tmpstr = tmpstr+prev
                else:
                    tmpstr = tmpstr+str(cnt)+prev
                    cnt = 1
            prev = word
        min_len = min(len(tmpstr),min_len)
    answer= min_len
    return answer


