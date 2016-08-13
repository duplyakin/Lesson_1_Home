#include <cstdio>

void insertionSort(int array[], size_t size) {
  for (size_t i = 1; i < size; ++i) {
    int key = array[i];
    int j = i - 1;
    while (j >= 0 && array[j] > key) {
      int temp = array[j];
      array[j] = array[j + 1];
      array[j + 1] = temp;
      --j;
    }
  }
}

void printArray(int array[], size_t size) {
  printf("(");
  const char* delimiter = "";
  for (int i = 0; i < size; ++i) {
    printf("%s", delimiter);
    printf("%d", array[i]);
    delimiter = ", ";
  }
  printf(") \n");
}

int main(int argc, char** argv) {
  DBG("[Lesson 1]: 14");
  int array[] = {5, -2, 0, 7, 1, -3, 4, -9, -3, -1, 0, -5, 6};
  size_t size = sizeof(array) / sizeof(array[0]);
  insertionSort(array, size);

  int array1[size]; 
  for (int i = 0; i < size; ++i) {
    array1[i] = array[i];
  }
  printArray(array1, size);

  /*
  //note: 

  //Если сделать так, то будет double free or corruption 
  int* array1 = new int[size];
  array1 = array;
  printArray(array1, size);
  delete[] array1;*/
  DBG("[Lesson 1]: 14 [END]"); 
  return 0;
}
