void selectionSort(int array[], int n) {

    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        int temp = array[min];
        array[min] = array[i];
        array[i] = temp;
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int len = nums1Size + nums2Size;
    int arr[len];
    double median = 0;
    int i = 0;
    int j = 0;
    while (i < nums1Size) {
        arr[i] = nums1[i];
        printf("%d ok\n", arr[i]);
        i++;
    }
    while (j < nums2Size) {
        arr[j+nums1Size] = nums2[j];
        printf("%d bad\n", arr[i]);
        j++;
    }
    selectionSort(arr, len);
    if (len == 0) {
        return 0;
    } else if (len == 1) {
        return arr[0];
    } else if ((len) % 2 == 0) {
        median = ((double)arr[len/2] + (double)arr[(len/2)-1])/2;
    } else if ((len) % 2 == 1) {
        median = (double)arr[(len/2)];
    }
    return median;
}