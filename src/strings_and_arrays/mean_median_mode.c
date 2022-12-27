/*
Write user-defined functions to find the mean, mode, range, variance and the standard deviation
of a set of N integers, and also make the elements of the array unique.
Use a menu driven program to demonstrate the same.
*/

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



