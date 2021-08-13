//Project 1 CS2250
//Charissa Martin

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void initialize_array(int [], int);
int * shuffle_array(const int [], int);
void print_array(const int [], int);
int * createOddArray(const int [], int, int &);
int * createEvenArray(const int [], int, int &);
void array_war(int *, int, int *, int);
void sort_array(int *,int);
void swap(int &, int &);

int main(){
    int size, sizeEven, sizeOdd;
    
    srand(time(NULL));
    cout << "Please enter the size of the array: " << endl;
    cin >> size;
    if (size > 52 || size < 1){
        cout << "Please enter a number please between 1 and 52." << endl;
    }
    else {
    int *orderedArray = new int[size];
    initialize_array(orderedArray, size);
        cout << "Original array is: [ ";
        print_array(orderedArray, size);
        cout << "]\n";
        int *shoof = shuffle_array(orderedArray, size);
        cout << "Shuffled array is: [ ";
        print_array(shoof, size);
        cout << "]\n";
        int *evenArray = createEvenArray(shoof,size, sizeEven);
        int *oddArray = createOddArray(shoof, size, sizeOdd);
        cout << "After call to createOddArray, oddArray is: [ ";
        print_array(oddArray, sizeOdd);
        cout << "]\n";
        cout << "After call to createEvenArray, evenArray is: [ ";
        print_array(evenArray, sizeEven);
        cout << "]\n";
        array_war(evenArray, sizeEven, oddArray, sizeOdd);
        
        }
    
    return 0;
}

void initialize_array(int array[], int size){
    for(int i = 0; i < size; i++){
        array[i] = i;
    }

}
int *shuffle_array(const int shuffit[], int size){
    int *shuff = new int[size];
    for (int i = 0; i < size; i++){
        shuff[i] = shuffit[i];
    }
    for (int i = (size - 1); i >= 1; i--){
        int j = rand()%size;
        swap(shuff[i], shuff[j]);
    }
    return shuff;
}
void print_array(const int array[], int size){
    for (int i = 0; i < size; i++){
        cout << array[i] << " ";
    }

}
int * createOddArray(const int shuffleArray[], int size, int &sizeOdd){
    sizeOdd = size/2;
    int * arrayOfOdd = new int[sizeOdd]();
    for (int i = 0; i < size; i++){
        if (shuffleArray[i]%2 == 1){
            static int n = 0;
            arrayOfOdd[n] = shuffleArray[i];
            n++;
        }
    }
    return arrayOfOdd;
}
int * createEvenArray(const int shuffleArray[], int size, int &sizeEven){
    if (size%2 == 0){
        sizeEven = size/2;
    }
    else
        sizeEven = size/2+1;
    int * arrayOfEven = new int[sizeEven]();
    for (int i = 0; i < size; i++){
        if (shuffleArray[i]%2 == 0){
            static int n = 0;
            arrayOfEven[n] = shuffleArray[i];
            n++;
        }
    }
    return arrayOfEven;
}
void array_war(int *arrayOfEven, int sizeOfEven, int *arrayOfOdd, int sizeOfOdd){
     int * largestArray = new int[sizeOfEven]();
    for (int i = 0; i < sizeOfOdd; i++){
        if (arrayOfEven[i] > arrayOfOdd[i]){
            largestArray[i] = arrayOfEven[i];
        }
        else
            largestArray[i] = arrayOfOdd[i];
    }
    if (sizeOfEven != sizeOfOdd){
        largestArray[sizeOfEven-1] = arrayOfEven[sizeOfEven-1];
    }
    cout << "ArrayFight winners were: [ ";
    print_array(largestArray, sizeOfEven);
    cout << "]\n";
    cout << "Sorted ArrayFight winners were: [ ";
    sort_array(largestArray, sizeOfEven);
    print_array(largestArray, sizeOfEven);
    cout << "]\n";
}
void sort_array(int *sortysort, int sizeOfSort){
    int low;
    for (int i = 0; i < sizeOfSort; i++){
        low = i;
        for (int j = i+1; j < sizeOfSort; j++){
            if (sortysort[j] < sortysort[low]){
                low = j;
            }
        }
        if (low != i){
            swap(sortysort[i], sortysort[low]);
        }
    }
}
void swap(int &x, int &y){
    int temp;
    temp = x;
    x = y;
    y = temp;
}
