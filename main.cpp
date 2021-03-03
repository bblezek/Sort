#include <iostream>

void quicksort(int list[], int length);
void mergesort(int list[], int length);
int* merge(int list1[], int list2[], int length1, int length2);

int main() {
    int list1[] = {8,6,7,5,3,0,9};
    int length = 7;
    std::cout << "List 1 is \n";
    for(int x = 0; x < length; x++){
        std::cout << list1[x] << ' ';
    }
    std::cout << '\n';
    quicksort(list1,length);
    std::cout << "List 1 quick sorted is \n";
    for(int x = 0; x < length; x++){
        std::cout << list1[x] << ' ';
    }
    std::cout << '\n';
    int list1b[] = {8,6,7,5,3,0,9};
    mergesort(list1b,length);
    std::cout << "List 1 merge sorted is \n";
    for(int x = 0; x < length; x++){
        std::cout << list1[x] << ' ';
    }
    std::cout << '\n';
    int list2[50];
    int list2b[50];
    length = 50;

    int num;
    std::cout << "List 2 is \n";
    for(int x = 0; x < length; x++){
        num = rand() % 100;
        list2[x] = num;
        list2b[x] = num;
        std::cout << num << ' ';
        if((x+1)%10 == 0){
            std::cout << '\n';
        }
    }

    quicksort(list2,length);
    std::cout << "List 2 quick sorted is \n";
    for(int x = 0; x < length; x++){
        std::cout << list2[x] << ' ';
        if((x+1)%10 == 0){
            std::cout << '\n';
        }
    }
    mergesort(list2b,length);
    std::cout << "List 2 merge sorted is \n";
    for(int x = 0; x < length; x++){
        std::cout << list2b[x] << ' ';
        if((x+1)%10 == 0){
            std::cout << '\n';
        }
    }
    int list3[] = {7,4,2,1,3,3,7,11,8,6,7,5,3,0,9,12};
    int list3b[] = {7,4,2,1,3,3,7,11,8,6,7,5,3,0,9,12};
    length = 16;
    std::cout << "List 3 is  \n";
    for(int x = 0; x < length; x++){
        std::cout << list3[x] << ' ';
    }
    quicksort(list3,length);
    std::cout << "\nList 3 quick sorted is \n";
    for(int x = 0; x < length; x++){
        std::cout << list3[x] << ' ';
    }
    mergesort(list3b,length);
    std::cout << "\nList 3 merge sorted is \n";
    for(int x = 0; x < length; x++){
        std::cout << list3b[x] << ' ';
    }
    return 0;
}

//This method "quick sorts" the list in place
void quicksort(int list[], int length){
    //If the length is 1, leave the list unchanged
    if(length <= 1) {
        return;
    //If we have two elements, see which one is larger and switch if needed
    } else if(length == 2) {
        if(list[0] < list[1]){
            return;
        } else {
            int temp = list[0];
            list[0] = list[1];
            list[1] = temp;
        }
    //Otherwise, pick pivot (I have it set to first element),
    //divide list by pivot and sort two halves
    } else {
        int pivot;
        int lowList[length], highList[length];
        int lowIdx = 0, highIdx = 0;
        pivot = list[0];
        //Fill low and high lists
        for (int x = 1; x < length; x++) {
            if (list[x] < pivot) {
                lowList[lowIdx] = list[x];
                lowIdx++;
            } else {
                highList[highIdx] = list[x];
                highIdx++;
            }
        }
        //Sort lower list and higher list
        quicksort(lowList, lowIdx);
        quicksort(highList, highIdx);
        //Merge lists
        for (int y = 0; y < length; y++) {
            if (y < lowIdx) {
                list[y] = lowList[y];
            } else if (y == lowIdx) {
                list[y] = pivot;
            } else {
                list[y] = highList[y - lowIdx - 1];
            }
        }
    }
    return;
}

//This method merge sorts the list, again in place
void mergesort(int list[], int length){
    //Simply return the list if it is of length 1 or 0
    if(length <= 1){
        return;
    //Check if elements in two element list need to be switched
    } else if (length == 2){
        if(list[0] <= list[1]){
            return;
        } else {
            int temp = list[0];
            list[0] = list[1];
            list[1] = temp;
        }
        return;
    //Otherwise...
    } else {
        int half = length / 2;
        int list1[half], list2[length-half];
        //Split list in half
        for(int x = 0; x < half; x++){
            list1[x] = list[x];
        }
        for(int y = half; y < length; y++){
            list2[y - half] = list[y];
        }

        //Sort two halves
        mergesort(list1, half);
        mergesort(list2, length-half);
        int list1Idx = 0, list2Idx = 0;
        //Merge two lists
        for(int x = 0; x < length; x++){
            //If element in first list is smaller than second list
            if(list1Idx < half && list1[list1Idx] < list2[list2Idx]){
                list[x] = list1[list1Idx];
                list1Idx++;
            //If we don't have any elements in first list or if the
            //element in the second list is smaller than in the first list
            } else if(list2Idx < length-half) {
                list[x] = list2[list2Idx];
                list2Idx++;
            //If we only have elements in the first list
            } else if (list1Idx < half) {
                list[x] = list1[list1Idx];
                list1Idx++;
            }
        }
    }
    return;
}
