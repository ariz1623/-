# 가사 검색

import bisect
import collections

def func(a,left,right):
    left_idx = bisect.bisect_left(a,left)
    right_idx = bisect.bisect_right(a,right)

    return right_idx - left_idx

def solution(words, queries):
    answer = []

    dic = collections.defaultdict(list)
    dic_reverse = collections.defaultdict(list)
    for word in words:
        # 단어 길이 순으로 분리
        dic[len(word)].append(word)
        dic_reverse[len(word)].append(word[::-1])


    #정렬
    for key in dic.keys():
        dic[key].sort()
        dic_reverse[key].sort()

    for query in queries: # 쿼리를 하나씩 확인하며 처리
        #접미사에 와일드 카드가 붙은 경우
        if query[0] != '?':
            answer.append(func(dic[len(query)],query.replace('?','a'),query.replace('?','z')))

        #접두사에 와일드 카드가 붙은 경우
        else :
            query = query[::-1]
            answer.append(func(dic_reverse[len(query)],query.replace('?','a'),query.replace('?','z')))
    return answer