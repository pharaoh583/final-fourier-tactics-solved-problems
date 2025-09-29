import math

n = int(input())
arr = list(map(int, input().split()))

lcms = 1;
s = set();
for e in arr:
    lcms = min(lcms, e)*(max(e, lcms)//math.gcd(lcms, e))
    s.add(e)

arr.sort()

if(lcms == 1):
    print('*')
else:
    res = 0
    for e in arr:
        if lcms//e not in s:
            res = lcms//e;
            break;

    if res == 0:
        print(arr[n-1]*arr[1], arr[n-1]*arr[1])
    else:
        print(lcms, res)

