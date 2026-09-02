#include <stdio.h>

int main() {

    int arr[5]={2,4,6,8,10};

    int *p = arr;

    printf("%d\n", *p);

    p++;

    printf("%d\n", *p);

    return 0;
}