public class MergeSort {
    public static void mergeSort(int[] arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            merge(arr, left, mid, right);
        }
    }

    private static void merge(int[] arr, int left, int mid, int right) {
        int leftSize = mid - left + 1;
        int rightSize = right - mid;

        int[] leftPart = new int[leftSize];
        int[] rightPart = new int[rightSize];

        for (int i = 0; i < leftSize; i++)
            leftPart[i] = arr[left + i];
        for (int j = 0; j < rightSize; j++)
            rightPart[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;

        while (i < leftSize && j < rightSize) {
            if (leftPart[i] <= rightPart[j]) {
                arr[k] = leftPart[i];
                i++;
            } else {
                arr[k] = rightPart[j];
                j++;
            }
            k++;
        }

        while (i < leftSize) {
            arr[k] = leftPart[i];
            i++;
            k++;
        }

        while (j < rightSize) {
            arr[k] = rightPart[j];
            j++;
            k++;
        }
    }

    public static void main(String[] args) {
        int[] numbers = {34, 7, 23, 32, 5, 62};

        System.out.println("Before sorting:");
        printArray(numbers);

        mergeSort(numbers, 0, numbers.length - 1);

        System.out.println("After sorting:");
        printArray(numbers);
    }

    private static void printArray(int[] arr) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
