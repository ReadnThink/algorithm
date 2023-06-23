from itertools import product
import sys
input = sys.stdin.readline

#인덴트 스타일 구하기
def get_indent_RCS():  
    all_indent=[] 
    for pro in product(range(1, 21), repeat=3): # 중복순열 R,C,S
        rcs=[0]
        r1,r2=0,0
        c1,c2=0,0
        s1,s2=0,0
        for i in range(len(master)):
            if i != 0:
                tmpRcs = pro[0]*(r1-r2)+pro[1]*(c1-c2)+pro[2]*(s1-s2)
                rcs.append(tmpRcs)
                
            # 원래 인덴트 스타일과 중복순열로 구한 인덴트 스타일 원소가 같다면 계속 진행
            if indentArr[i] == rcs[i]:
                for j in range(len(master[i])):
                    if master[i][j] == "(":
                            r1+=1
                    elif master[i][j] == ")":
                            r2+=1
                    elif master[i][j] == "{":
                            c1+=1
                    elif master[i][j] == "}":
                            c2+=1
                    elif master[i][j] == "[":
                            s1+=1
                    elif master[i][j] == "]":
                            s2+=1
            else:
                break
        if indentArr == rcs:
            all_indent.append(list(pro))
    return all_indent
# q_indent 배열 구하기
def q_indent(all_indent):
    total=[set() for _ in range(q)]
    total[0].add(0)
    for i in range(len(all_indent)):
        r,c,s = all_indent[i]
        # rst_indent_arr=[0]
        r1,r2=0,0
        c1,c2=0,0
        s1,s2=0,0
        
        for i in range(len(other)):
            if i != 0:
                tmpRcs = r*(r1-r2)+c*(c1-c2)+s*(s1-s2)
                total[i].add(tmpRcs)
                
            for j in range(len(other[i])):
                if other[i][j] == "(":
                        r1+=1
                elif other[i][j] == ")":
                        r2+=1
                elif other[i][j] == "{":
                        c1+=1
                elif other[i][j] == "}":
                        c2+=1
                elif other[i][j] == "[":
                        s1+=1
                elif other[i][j] == "]":
                        s2+=1
    
    return total
## main
while True:
    p,q = map(int, input().split())
    # p,q=2,3
    if p==q==0:
        break
    
    master = [input().strip() for _ in range(p)]
    other=[input().strip() for _ in range(q)]
    
    #마스터의 인덴트 개수 배열
    indentArr=[]
    
    for line in master:
        cnt=0
        for j in line:
            if j == '.':
                cnt+=1
            else:
                break
        indentArr.append(cnt)
    
    # 모든 indent 스타일 [r,c,s] 배열
    indent=get_indent_RCS() # RCS를 알 수 없으니 모든 중복순열을 돌면서 확인해야 한다.
    total_indent=q_indent(indent)

    # 모든 indent 후보군에 대하여 유일성 검사
    rst=[]
    for i in total_indent:
        if len(i)>1:
            rst.append(-1)
        else:
            rst.append(list(i)[0])
    print(*rst)