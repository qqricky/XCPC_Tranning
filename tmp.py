from math import floor
t=int(input())
s=list()
for i in range(t):
    input()
    s.append(list(map(int,input().split())))
for item in s:
    n=len(item)
    li=list()
    for num in item:
        tmp_li=list()
        while num!=1:
            if num<=n:
                tmp_li.append(num)
            num=floor(num/2)
        li.append(tmp_li)
    flag=1
    all_li=[]
    for arr in li:
        count=0
        otherArr=list()
        for arr2 in li:
            if arr2==arr:
                continue
            otherArr=otherArr+arr2
        for num in arr:
            if num not in otherArr:
                count+=1
        if count>=2:
            print('NO')
            flag=0
            break
    if flag:
        for arr in li:
            all_li += arr
        for i in range(2,n+1):
            if i not in all_li:
                print('NO')
                flag = 0
                break
        if flag:
            print('YES')