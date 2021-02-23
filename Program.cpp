#include <list>
#include <iostream>
#include <string.h>
using namespace std;

template <class T>
T* getElementAt(std::list<T> linkedList, int index);

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
        if (array[indexOfMiddleElement] < data) {
            return recursiveBinarySearch(startOfRightSubArray, sizeOfRightSubArray, data);
        } else {
            int sizeOfLeftSubArray = size - sizeOfRightSubArray;
            return recursiveBinarySearch(array, sizeOfLeftSubArray, data);
        }
    }
}

template <class T>
T* linkedBinarySearch(std::list<T> linkedList, T data) {

    int startIndex = 0;
    int endIndex = linkedList.size() - 1;

    T* result = nullptr;
    while (startIndex <= endIndex) {
        int middleIndex = (startIndex + (endIndex - 1)) / 2;
        int* ptr = getElementAt(linkedList, middleIndex);
        if (*ptr == data) {
            return ptr;
        } else if (*ptr > data) {
            endIndex = middleIndex - 1;
        } else {
            startIndex = middleIndex + 1;
        }
    } 
    return result;

}


template <class T>
T* linkedBinarySearch2(std::list<T> linkedList, T data) {
    int startIndex = 0;
    int endIndex = linkedList.size();
    T* ptr = 0;
    while (startIndex <= endIndex) {
        
        if (endIndex - startIndex == 1) {
            if (*getElementAt(linkedList, endIndex - startIndex) == data) {
                return getElementAt(linkedList, endIndex - startIndex);
            }
            return 0;
        }

        int middleIndex = (endIndex + startIndex) / 2;
        T* middleElement = getElementAt(linkedList, middleIndex);
        if (*middleElement == data) {
            return middleElement;
        } else if (*middleElement > data) {
            endIndex = middleIndex - 1;
        } else {
            startIndex = middleIndex + 1;
        }
    }
}

template <class T>
T* getElementAt(std::list<T> linkedList, int index) {
    list<int>::iterator iterator = linkedList.begin();
    advance(iterator, index);
    return &*iterator;
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
    
    /*
    int nums[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    for (int i = 0; i <= 15; i += 5) {
        int* result = recursiveBinarySearch(nums + i, 5, 10);
        if (result != 0) {
            cout << "element found at address " << result << endl;
        } else {
            cout << "element not found" << endl;
        }
    }
    */
 
    std::list<int> linkedList;
    for(int i = 0; i < 50; i+=2) {

        linkedList.push_back(i);
    }
    int* result1 = linkedBinarySearch2(linkedList, 5);
    if (result1 == 0) {
        cout << "not found" << endl;
    } else {
        cout << result1 << endl;
    }

    int* result2 = linkedBinarySearch2(linkedList, 1);

    if (result2 == 0) {
        cout << "not found" << endl;
    } else {
        cout << result2 << endl;
    }

    int* result3 = linkedBinarySearch2(linkedList, 2);

    if (result3 == 0) {
        cout << "not found" << endl;
    } else {
        cout << result3 << endl;
    }
    int* result4 = linkedBinarySearch2(linkedList, 10);

    if (result4 == 0) {
        cout << "not found" << endl;
    } else {
        cout << result4 << endl;
    }


    
}



