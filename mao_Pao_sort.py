d0 = [1,3,2,4,5,3,8,4,5,6]
for i in range(len(d0)):
    state = 0  # 假设本次循环没有改变
    for j in range(len(d0) - 1,i,-1):
        if d0[j] < d0[j - 1]:
            d0[j], d0[j - 1] = d0[j - 1], d0[j]
            state = 1  # 有数值交换，那么状态值置1
    if not state:  # 如果没有数值交换，那么就跳出
        break