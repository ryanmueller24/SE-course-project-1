

class QuickSort
{

    // Main Driver Function
    public static void main(String args[])
    {
        int numbers[] = {42, 71, 1, 999, 1000, 123};
        int n = numbers.length;

        QuickSort ob = new QuickSort();
        ob.quicksort(numbers, 0, n-1);

        for (int i=0; i<n; ++i)
            System.out.print(numbers[i]+" ");
    }


    int partition(int numbers[], int low, int high)
    {
        int pivot = numbers[high]; 
        int i = (low-1);
        
        for (int j=low; j<high; j++)
        {
          
            //checks if current element <= pivot
            if (numbers[j] <= pivot)
            {
                i++;

                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
        //swap
        int temp = numbers[i+1];
        numbers[i+1] = numbers[high];
        numbers[high] = temp;

        return i+1;
    }


    /*QuickSort function
      numbers[] == input array, l=start index, h = end index */
    void quicksort(int numbers[], int l, int h)
    {
        if (l < h)
        {
            int pi = partition(numbers, l, h);

            //recursive calls 
            quicksort(numbers, l, pi-1);
            quicksort(numbers, pi+1, h);
        }
    }

    
}

