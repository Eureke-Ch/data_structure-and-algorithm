d0 = [0,1,3,2,4,5,3,8,4,5,6]
maxnum = max(d0)
length = len(d0)
C = [0 for i in range(maxnum+1)]
B = [0 for i in range(length)]
for i in range(length):
    C[d0[i]]+=1
for i in range(1,maxnum+1):
    C[i] = C[i]+C[i-1]
for i in range(length):
    B[C[d0[i]]-1] = d0[i]
    C[d0[i]]-=1
print(B)