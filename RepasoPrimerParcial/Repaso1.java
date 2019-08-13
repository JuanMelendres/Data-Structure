public class Repaso1 {
    public static void selectionSort(int[] arr) {
        int size = arr.length;
        for (int i = 0; i < size - 1; i++) {
            int min_idx = i;
            for (int j = i +  1; j < size; j++) {
                if (arr[j] < arr[min_idx]) {
                    min_idx = j;
                }
            }
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }

    public static void insertionSort(int arr[]) {
        int size = arr.length;
        for (int i = 0; i < size; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

    public static void bubbleSort(int arr[]) {
        int size = arr.length;
        for (int i = 0; i < size - 1 ; i++) {
            for (int j = 0; j < size - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int tmp = arr[j];
                    arr[j] = arr [j + 1];
                    arr[j + 1] = tmp;
                }
            }
        }
    }

    public static void mergeSort(int arr[], int l, int r) {
        if (l < r) {
            int m = (l + r) / 2;
            mergeSort(arr, l, m);
            mergeSort(arr , m +  1, r);
            merge(arr, l, m, r);
        }
    }

    public static void merge(int arr[], int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;
        int L[] = new int [n1];
        int R[] = new int [n2];
        for (int i = 0; i < n1; ++i) {
            L[i] = arr[l + i];
        }
        for (int j = 0; j < n2; ++j) {
            R[j] = arr[m + 1 + j];
        }
        int i = 0, j = 0;
        int k = l;
        while (i < n1 && j < n2){
            if (L[i] <= R[j]){
                arr[k] = L[i];
                i++;
            }
            else{
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1){
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2){
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    public static void quickSort(int arr[], int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    public static int partition(int arr[], int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
        int tmp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = tmp;
        return i + 1;
    }

    public static int binarySearch(int arr[], int l, int r, int x) {
        if (r >= l) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == x) {
               return mid;
            }
            if (arr[mid] > x) {
               return binarySearch(arr, l, mid-1, x);
            }
            return binarySearch(arr, mid+1, r, x);
        }
        return -1;
    }

    public static void printArray(int arr[]){
        int n = arr.length;
        for (int i = 0; i < n; ++i) {
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int arr[] = {64,25,12,22,11};
        //SelectionSort
        Repaso1.selectionSort(arr);
        System.out.println("SelectionSort");
        Repaso1.printArray(arr);
        //InsertionSort
        Repaso1.insertionSort(arr);
        System.out.println("InsertionSort");
        Repaso1.printArray(arr);
        //BubbleSort
        Repaso1.bubbleSort(arr);
        System.out.println("BubbleSort");
        Repaso1.printArray(arr);
        //MergeSort
        Repaso1.mergeSort(arr, 0, arr.length - 1);
        System.out.println("MergeSort");
        Repaso1.printArray(arr);
        //QuickSort
        Repaso1.quickSort(arr, 0, arr.length - 1);
        System.out.println("QuickSort");
        Repaso1.printArray(arr);
    }
}
