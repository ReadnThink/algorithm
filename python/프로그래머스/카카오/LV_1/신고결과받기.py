from collections import defaultdict
def solution(id_list, report, k):
    # 신고를 받은 횟수 저장하는 hashTable = 한 유저를 여러 번 신고할 수도 있지만, 동일한 유저에 대한 신고 횟수는 1회로 처리됩니다.
    # 유저별 신고목록 list = 해당 유저를 신고한 모든 유저에게 정지 사실을 메일로 발송합니다.
    # 유저가 신고한 모든 내용을 취합하여 마지막에 한꺼번에 게시판 이용 정지를 시키면서 정지 메일을 발송합니다.
    
    reportedUser =  defaultdict(int)    
    reportList = defaultdict(set)    
    ben = set()
    for r in report:
        here,to = r.split()
        if to in reportList[here]:
            continue
        reportList[here].add(to)
        reportedUser[to] = reportedUser.get(to,0) + 1
        if reportedUser[to] >= k:
            ben.add(to)    
    
    print('reportedUser',reportedUser)
    print('reportList',reportList)
    print('ben',ben)
    answer = []
    
    for id in id_list:
        cnt = 0
        for b in reportList[id]:
            if b in ben:
                cnt += 1
        answer.append(cnt)
    
    return answer