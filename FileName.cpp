#include<iostream>
#include<cstdlib>
#include<vector>


int divide(std::vector<int>& arr, int lowest, int highest){    
    int pivot = arr[highest];   
    int i = lowest - 1;

    for (int j = lowest; j < highest; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[highest]);    
    return i + 1;
}

int randomDivide(std::vector<int>& arr, int lowest, int highest) {  //функция для рандомизированного выбора pivot элемента
    int random = lowest + rand() % (highest - lowest);
    std::swap(arr[random], arr[highest]);
    return divide(arr, lowest, highest);
}

void quickSort(std::vector<int>& arr, int lowest, int highest) {  //разделение массива на два подмассива
    if (lowest < highest) {
        int pivotal = randomDivide(arr, lowest, highest);  //индекс pivot элемента

        quickSort(arr, lowest, pivotal - 1);  //раздельная сортировка элементов до разделения и после разделения 
        quickSort(arr, pivotal + 1, highest); 
    }
}

void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
}


void bubbleSort(std::vector<int>& arr) {     //для сортировки Bubble Sort
    
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);   //обмен значений
            }
        }
    }
}

void insertionSort(std::vector<int>& arr) {  //для сортировки Incertion sort
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int var = arr[i];       //выделение первого элемента для дальнейшей сортировки
        int j = i - 1;

        while (j >= 0 && arr[j] > var) {
            arr[j + 1] = arr[j];     //изменение мест элементов
            j--;
        }
        arr[j + 1] = var;
    }
}

int main() {  
    
    /*Quick Sort*/

    int number1 = 0;
    std::cout << "enter the size of the array (Quick Sort) " << std::endl;
    std::cin >> number1;
    std::vector<int> arr(number1);
    for (int i = 0; i < number1; i++) {
        std::cin >> arr[i];
    }
    
    quickSort(arr, 0, number1 - 1);
    std::cout << "the array after sorting: " << std::endl;
    printArray(arr);

    /*Bubble Sort*/

    int number2;
    std::cout << "enter the size of the array (Bubble Sort) " << std::endl;
    std::cin >> number2;
    std::vector<int> arr1(number2);
    std::cout << "enter the elements of the array" << std::endl;
    for (int i = 0; i < number2; i++) {
        std::cin >> arr1[i];
    }

    bubbleSort(arr1);

    std::cout << "the array after sorting: " << std::endl;
    for (int i = 0; i < number2; i++) {
        std::cout << arr1[i] << " ";
    }
    

    /*Incertion Sort*/

    int number3;
    std::cout << "enter the size of the array (Incertion Sort) " << std::endl;
    std::cin >> number3;
    std::vector<int> arr2(number3);
    std::cout << "enter the elements of the array" << std::endl;
    for (int i = 0; i < number3; i++) {
        std::cin >> arr2[i];
    }

 
    insertionSort(arr2);

    std::cout << "the array after sorting: " << std::endl;
    for (int i = 0; i < number3; i++) {
        std::cout << arr2[i] << " ";
    }

    return 0;

}

