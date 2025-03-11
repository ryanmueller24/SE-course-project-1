def partition(arr, low, high):
    pivot = arr[high]  # Choosing the last element as pivot
    i = low - 1  # Pointer for greater element

    for j in range(low, high):
        if arr[j] <= pivot:  # If current element is smaller than or equal to pivot
            i += 1
            arr[i], arr[j] = arr[j], arr[i]  # Swap elements

    arr[i + 1], arr[high] = arr[high], arr[i + 1]  # Swap pivot with greater element
    return i + 1  # Return partition index

def quicksort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)  # Find partition index

        quicksort(arr, low, pi - 1)  # Recursively sort left subarray
        quicksort(arr, pi + 1, high)  # Recursively sort right subarray

# Driver code
if __name__ == "__main__":
    numbers = [42, 71, 1, 999, 1000, 123]
    n = len(numbers)
    
    quicksort(numbers, 0, n - 1)
    
    print("Sorted array:", numbers)
