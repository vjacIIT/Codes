def power(a, b):
    no = 1
    for x in range(1, b+1, 1):
        no *= a
    return no


def binary(n):
    arr = 40*[0]
    k = 0
    while n != 1:
        arr[k] = n % 2
        n = int(n / 2)
        k = k+1
    arr[k] = 1
    return arr


def hcf(a, b):
    if b == 0:
        return a
    else:
        while a % b != 0:
            temp = b
            b = a % b
            a = temp
        return b


tc = int(input())
while tc > 0:
    tc = tc-1
    A, B, N = input().split()
    A = int(A)
    B = int(B)
    N = int(N)
    index = binary(N)
    no1 = 1
    no2 = 1
    ar1 = [1]*40
    ar2 = [1]*40
    if A == B:
        for i in range(0, 40, 1):
            if index[i] == 1:
                ar1[i] = A
                j = 2
                while j <= power(2, i):

                    j *= 2
                    ar1[i] *= ar1[i]
                    ar1[i] = ar1[i] % 1000000007

            else:
                ar1[i] = 1

        for i in range(0, 40, 1):
            no1 *= ar1[i]
            no1 = no1 % 1000000007

        print("{}".format((2*no1) % 1000000007))

    elif A == B+1:
        print("1\n")

    else:
        for i in range(0, 40, 1):
            if index[i] == 1:
                ar1[i] = A
                ar2[i] = B
                j = 2
                while j <= power(2, i):
                    j = j*2
                    ar1[i] *= ar1[i]
                    ar1[i] = ar1[i] % (A-B)
                    ar2[i] *= ar2[i]
                    ar2[i] = ar2[i] % (A-B)
            else:
                ar1[i] = 1
                ar2[i] = 1

        for i in range(0, 40, 1):
            no1 *= ar1[i]
            no1 = no1 % (A-B)
            no2 *= ar2[i]
            no2 = no2 % (A-B)

        no2 = (no1+no2) % (A-B)
        no1 = A-B
        hfc = hcf(no1, no2) % 1000000007
        print("{}".format(hfc))





