T = int(input())
while T>0:
    inp = input()
    while int(inp/10)>0:
        now = 0
        while inp>0:
            now += inp%10
            inp = int(inp/10)
        inp = now
    print(inp)
    T-=1
