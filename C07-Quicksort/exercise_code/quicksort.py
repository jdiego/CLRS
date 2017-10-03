#!/usr/bin/env python
# coding=utf-8


def partition(items, p, r):
    x = items[r]
    i = p-1
    count = 0

    for j in range(p, r):
        if items[j] == x:
            count += 1

        if items[j] <= x:
            i = i + 1
            items[i],items[j] = items[j],items[i]

    items[i+1],items[r] = items[r],items[i+1]
    return i+1-count/2

def modify_partition(A, p, r):
    x = A[r]
    i = p-1
    l = p - 1

    for j in range(p, r):
        if A[j] < x:
            i = i + 1
            A[i],A[j] = A[j], A[i]
            l = l + 1
        elif A[j] == x:
            l = l + 1
            A[l],A[j] = A[j], A[l]
    #
    A[l+1],A[r] = A[r], A[l+1]
    return ((i+l)/2) + 1

def quicksort(A, p, r):
    if p < r:
        q = modify_partition(A, p, r)
        assert(q == (p + r)/2)
        quicksort(A, p, q-1)
        quicksort(A, q+1, r)


items = [2,5,9,3,7,0,-1]
A = [2,2,2,2,2,2,2,2]
quicksort(A, 0, len(A)-1)
print A
