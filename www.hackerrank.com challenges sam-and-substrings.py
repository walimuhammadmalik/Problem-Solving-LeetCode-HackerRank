#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the substrings function below.
def substrings(n):
    mod=10**9+7
    l=len(str(n))
    dp=[0]*l
    s=str(n)
    dp[0]=int(s[0])
    for i in range(1,l):
        dp[i]=dp[i-1]*10+i*int(s[i])+int(s[i])
        dp[i]%=mod
    return sum(dp)%mod
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = input()

    result = substrings(n)

    fptr.write(str(result) + '\n')

    fptr.close()
