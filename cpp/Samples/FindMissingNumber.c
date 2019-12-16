#include <stdio.h>

int findMissingNumber(int arr[]) {
    int first = 0;
    int last = 9;
    int middle = (last - first) / 2;

    while (last - first > 1) {
        if ((middle - first) != (arr[middle] - arr[first])) {
            last = middle;
            middle = (last - first) / 2;
        }

        else if ((last - middle) != (arr[last] - arr[middle])) {
            first = middle;
            middle = (last - first) / 2;
        }

        printf("Looping!\n");
    }

    return arr[first] + 1;
}

int main() {
    int arr[10];
    int i = 0;

    scanf(("%d %d %d %d %d %d %d %d %d %d"), &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6], &arr[7], &arr[8], &arr[9]);

    for (i = 0; i != sizeof(arr) / sizeof(arr[0]); ++i) {
        printf("%d\n", arr[i]);
    }

    int sum = (arr[9] * (arr[9] + 1)) / 2;
    int firstSum = (arr[0] * (arr[0] + 1)) / 2;

    int theorySum = sum - firstSum + arr[0];

    for (i = 0; i != sizeof(arr) / sizeof(arr[0]); ++i) {
        theorySum -= arr[i];
    }

    printf("Sum: %d\n", sum);
    printf("First Sum: %d\n", firstSum);
    printf("Missing Number: %d\n", theorySum);

    int *ptrArr = arr;
    printf("Missing Number (New): %d\n", findMissingNumber(ptrArr));

    return 0;
}
