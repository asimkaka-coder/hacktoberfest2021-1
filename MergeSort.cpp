int main() {
    int arrayOfNumbers[100];
    int arrayOfNumbers1[1000];
    int arrayOfNumbers2[10000];
    int arrayOfNumbers3[100000];
    for (int i = 0; i < 100; i++) {
        arrayOfNumbers[i] = 1 + rand() % 100;
    }
    for (int i = 0; i < 1000; i++) {
        arrayOfNumbers1[i] = 1 + rand() % 100;
    }
    for (int i = 0; i < 10000; i++) {
        arrayOfNumbers2[i] = 1 + rand() % 100;
    }
    for (int i = 0; i < 100000; i++) {
        arrayOfNumbers3[i] = 1 + rand() % 100;
    }


    int sizeOfArray = sizeof(arrayOfNumbers) / sizeof(arrayOfNumbers[0]);
    int sizeOfArray1 = sizeof(arrayOfNumbers1) / sizeof(arrayOfNumbers1[0]);
    int sizeOfArray2 = sizeof(arrayOfNumbers2) / sizeof(arrayOfNumbers2[0]);
    int sizeOfArray3 = sizeof(arrayOfNumbers3) / sizeof(arrayOfNumbers3[0]);

    /**
    * Sorting Arrays in Ascending Order
    * **/
    sortArrayInAscendingOrder(arrayOfNumbers,sizeOfArray);
    sortArrayInAscendingOrder(arrayOfNumbers1,sizeOfArray1);
    sortArrayInAscendingOrder(arrayOfNumbers2,sizeOfArray2);
    sortArrayInAscendingOrder(arrayOfNumbers3,sizeOfArray3);
    //print(arrayOfNumbers,sizeOfArray);
    cout << "After Merge Sorting (Ascending Order): " << endl;
    auto start = high_resolution_clock::now();
    MergeSort(arrayOfNumbers, 0, sizeOfArray-1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken on first array is: " << duration.count() << " microseconds" << endl;
    //print(arrayOfNumbers, sizeOfArray);
    start = high_resolution_clock::now();
    MergeSort(arrayOfNumbers1, 0 ,sizeOfArray1-1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken on second array is: " << duration.count() << " microseconds" << endl;

    start = high_resolution_clock::now();
    MergeSort(arrayOfNumbers2,0,  sizeOfArray2-1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken on third array is: " << duration.count() << " microseconds" << endl;

    start = high_resolution_clock::now();
    MergeSort(arrayOfNumbers3,0,  sizeOfArray3-1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken on fourth array is: " << duration.count() << " microseconds" << endl;


    /**
    * Sorting Arrays in Descending Order
    * **/
    sortArrayInDescendingOrder(arrayOfNumbers,sizeOfArray);
    sortArrayInDescendingOrder(arrayOfNumbers1,sizeOfArray1);
    sortArrayInDescendingOrder(arrayOfNumbers2,sizeOfArray2);
    sortArrayInDescendingOrder(arrayOfNumbers3,sizeOfArray3);
    cout << "After Merge Sorting (Descending Order): " << endl;
    start = high_resolution_clock::now();
    MergeSort(arrayOfNumbers, 0, sizeOfArray-1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken on first array is: " << duration.count() << " microseconds" << endl;
    //print(arrayOfNumbers, sizeOfArray);
    start = high_resolution_clock::now();
    MergeSort(arrayOfNumbers1, 0 ,sizeOfArray1-1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken on second array is: " << duration.count() << " microseconds" << endl;

    start = high_resolution_clock::now();
    MergeSort(arrayOfNumbers2,0,  sizeOfArray2-1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken on third array is: " << duration.count() << " microseconds" << endl;

    start = high_resolution_clock::now();
    MergeSort(arrayOfNumbers3,0,  sizeOfArray3-1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken on fourth array is: " << duration.count() << " microseconds" << endl;
}
