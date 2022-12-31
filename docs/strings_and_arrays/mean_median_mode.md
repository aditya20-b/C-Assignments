## AIM:
Find the mean, mode, range, variance and the standard deviation of a set of N integers, and also make the elements of the array unique.

## ALGORITHM:
1. Initialize variables for mean, range, variance, standard deviation, and mode.
2. Declare an integer called `length` to store the size of the array and then based on the `length` create the array
3. Declare a function called `get_input` to get the input values for the array. The function takes in three arguments: the array, the length of the array, and a boolean value to indicate if the elements in the array should be unique or not.
4. Declare a function called `print_array` to print the elements of the array. The function takes in two arguments: the array and its length. Use a for loop to iterate through the array and print each element.
5. Declare the functions called `compute_mean`, `compute_mode`, and `compute_range` to calculate the mean, mode, and range of the array respectively. The functions take in two arguments: the array and its length. Use a for loop to iterate through the array and calculate the mean, mode, and range.
6. Declare a function called `compute_variance` and `compute_std_deviation` to calculate the variance and standard deviation of the array respectively. The functions take in two arguments: the array and its length. Use the functions `compute_mean` and `compute_range` to calculate the variance and standard deviation.
7. In the main function call the function `get_input` to get the input values for the array. Then compute the mean, mode, range, variance, and standard deviation of the array. Finally, print the mean, mode, range, variance, and standard deviation of the array.


## CODE:

```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool is_unique(float *array, int length, float val) {
    for (int i=0; i<length; i++) {
        if (array[i] == val) {
            return false;
        }
    }
    return true;
}

void get_input(float *array, int length, bool unique) {
    float _temp[length]; 
    for (int i=0; i<length; i++) {
        printf("Enter the element %d: ", i+1);
        scanf("%f", &_temp[i]);
        if (is_unique(_temp, i, _temp[i] && unique)) {
            array[i] = _temp[i];
        } else {
            i--;
        }
        // Can also be minfied as
        // is_unique(_temp, i, _temp[i]) ? array[i] = _temp[i] : i--; 
    }
}

void print_array(float *array_val, int array_length) {
    for (int i=0; i<array_length; i++) {
        printf("%0.2f ", array_val[i]);
    }
    printf("\n");
}

float compute_mean(float *array, int length) {
    float sum = 0;
    for (int i=0; i<length; i++) {
        sum = sum + array[i];
    }
    return sum/length;
}

int compute_mode(float *array, int length) {
    float mode = array[0];
    int mode_count = 1;
    for (int i=0; i<length; i++) {
        int count = 1;
        for (int j=i+1; j<length; j++) {
            if (array[i] == array[j]) {
                count++;
            }
        }
        if (count > mode_count) {
            mode = array[i];
            mode_count = count;
        }
    }
    return mode;
}

float compute_range(float *array, int length) {
  float min = array[0];
  float max = array[0];
  for (int i = 1; i < length; i++) {
    if (array[i] < min) {
      min = array[i];
    }
    if (array[i] > max) {
      max = array[i];
    }
  }
  return max - min;
}

float compute_variance(float *array, int length) {
  float mean_val = compute_mean(array, length);
  float variance = 0;
  for (int i = 0; i < length; i++) {
    variance += (array[i] - mean_val) * (array[i] - mean_val);
  }
  return variance / length;
}

float compute_std_deviation(float *array, int length) {
  return sqrt(compute_variance(array, length));
}

int main() {
    float mean, range, variance, std_deviation;
    int mode;
    int length;
    printf("Enter the size of the array: ");
    scanf("%d", &length);
    float *array = (float *) malloc(length * sizeof(float)); 
    get_input(array, length, false);
    print_array(array, length);
    mean = compute_mean(array, length);
    mode = compute_mode(array, length);
    range = compute_range(array, length);
    variance = compute_variance(array, length);
    std_deviation = compute_std_deviation(array, length);
    printf("\nThe mean of the array is %0.3f", mean);
    printf("\nThe mode of the array is %d", mode);
    printf("\nThe range of the array is %0.3f", range);
    printf("\nThe variance of the array is %0.3f", variance);
    printf("\nThe standard deviation of the array is %0.3f", std_deviation);
}
```
## OUTPUT:
```
aditya@LAPTOP:~$ gcc mean_median_mode.c -o mean_median_mode
aditya@LAPTOP:~$ ./mean_median_mode
Enter the size of the array: 5
Enter the element 1: 1
Enter the element 2: 2
Enter the element 3: 3
Enter the element 4: 4
Enter the element 5: 5
1.00 2.00 3.00 4.00 5.00

The mean of the array is 3.000
The mode of the array is 1
The range of the array is 4.000
The variance of the array is 2.000
The standard deviation of the array is 1.414
```
## RESULT:
The mean, mode, range, variance and standard deviation of the array will be printed.