#include <list>
#include <iostream>
#include <string.h>
using namespace std;

template <class T>
T* recursiveBinarySearch(T array[], int size, T data) {
    if (size == 1) {
        if (data == *array){
            return array;
        } else {
            return 0;
        }
    }
    int indexOfMiddleElement = size / 2;
    if (array[indexOfMiddleElement] == data) {
        return &array[indexOfMiddleElement];
    } else {
        T* startOfRightSubArray = &array[indexOfMiddleElement];
        int sizeOfRightSubArray = size % 2 == 0 ? size / 2 : (size / 2) + 1;
        T* rightResult = 
            recursiveBinarySearch(startOfRightSubArray, sizeOfRightSubArray, data);
        int sizeOfLeftSubArray = size - sizeOfRightSubArray;
        T* leftResult = 
            recursiveBinarySearch(array, sizeOfLeftSubArray, data);
        return rightResult != 0 ? rightResult : leftResult;
    }
}

template <class T>
bool linkedBinarySearch(std::list<T> linkedList, T data) {
    T* middle = middleOfLinkedList(linkedList);
    

}

template <class T>
T* middleOfLinkedList(std::list<T> linkedList) {
    T* slowPtr = linkedList.begin;
    T* fastPtr = linkedList.begin;
    while (fastPtr != 0) {
        slowPtr++;
        fastPtr += 2;
    }
    return slowPtr;
}




int main() {
    
    int nums[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    for (int i = 0; i <= 15; i += 5) {
        int* result = recursiveBinarySearch(nums + i, 5, 10);
        if (result != 0) {
            cout << "result found at address " << result << endl;
        } else {
            cout << "result not found" << endl;
        }
    }
 
 



    
}



