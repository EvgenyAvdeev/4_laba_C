#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float* create(int k) {
    float* a;
    a = (float*)malloc(k * sizeof(float));
    for (int i = 0; i < k; i++)
    {
        printf("a[%d] = ", i);
        scanf_s("%f", &a[i]);
    }
    return a;
}
int output(float* a, int k) {
    printf("[");
    for (int i = 0; i < k; i++) {
        printf("%f,",a[i]);
    }
    printf("]\n");
    return 0;
}
float inf(float* a, int k, float x, float y) {
    float min = pow(10, 10);
    for (int i = 0; i < k; i++) {
        if (a[i] >= x && a[i] <= y && a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

float middle(float* a, int k) {
    float sum = 0;
    int count = 0, flag = 0;
    float max = -1 * pow(10, 10);
    for (int i = 0; i < k; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    for (int i = 0; i < k; i++) {
        if (flag > 0) {
            sum += a[i];
            ++count;
        }
        if (a[i] == max) {
            flag++;
        }
    }
    return count != 0 ? sum / count: 0;
}
int main() {
    float* a;
    float  x, y, k;
    printf("Input array size: ");
    scanf_s("%f", &k);
    if (k > 0 && floor(k) == k) {
        printf("Input left and right borders: ");
        scanf_s("%f %f", &x, &y); 
        if (x > y) {
            printf("\nERROR\n");
        }
        else {
            a = create(k); 
            output(a, k); 
            float min = inf(a, k, x, y); 
            float mid = middle(a, k); 
            if (min == pow(10, 10)) {
                printf("Minimum does not exist in the specified range\n");
            }
            else {
                printf("Min = %f\n", min); 
            }
            if (mid != 0) {
                printf("Midle = %f\n", mid); 
            }
            else {
                printf("Middle value does not exist\n");
            }
            free(a); 
        } }
    else {
        printf("\nERROR\n");
    }return 0;
}
