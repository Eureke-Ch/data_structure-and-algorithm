class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        if not s:return 0
        sl = len(s)
        time = [[0 for i in range(5)]for j in range(sl)]
        letter = {0:"a",1:"e",2:"i",3:"o",4:"u"}
        for i in range(5):
            if s[0] == letter[i]:
                time[0][i] = 1
        for i in range(1,sl):
            for j in range(5):
                if s[i] == letter[j]:
                    time[i][j] = (time[i-1][j]+1)%2
                else:
                    time[i][j] = time[i-1][j]
        lenght = 0
        for i in range(sl-1,-1,-1):
            if i<lenght:break
            if sum(time[i]) == 0:
                if i+1>lenght:lenght=i+1
                continue
            for j in range(i-lenght):
                if time[i] == time[j]:
                    if i-j>lenght:lenght = i-j
                    break
        return lenght
