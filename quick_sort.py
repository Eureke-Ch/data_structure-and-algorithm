
def quick_sort(d):
    if len(d) <= 1:
        return d
    h = [[],[]]
    chioce = d[0]
    for i in range(1,len(d)):
        if d[i]<=chioce:
            h[0].append(d[i])
        elif d[i] >chioce:
            h[1].append(d[i])
    h[0] = quick_sort(h[0])
    h[1] = quick_sort(h[1])
    h[0].append(chioce)
    h[0].extend(h[1])
    return h[0]

d = [1,3,6,7,3,3,2,14,5,7]
print(quick_sort(d))
