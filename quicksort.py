"""Implement quick sort in Python.
Input a list.
Output a sorted list."""
def quicksort(arr):
    if len(arr) < 2:
        return arr

    pivot = arr.pop()
    left = list(filter(lambda x: x <= pivot, arr))
    right = list(filter(lambda x: x > pivot, arr))

    return quicksort(left) + [pivot] + quicksort(right)

test = [21, 4, 1, 3, 9, 20, 25, 6, 21, 14]
print(quicksort(test))
