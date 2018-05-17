
#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 65536
#define ITEMS_PER_BYTE 8
#define MAX_INDEX MAX_VALUE/ITEMS_PER_BYTE

int isBitSet(char devList[], int deviceNumber){
    int index = deviceNumber/ITEMS_PER_BYTE;
    int bitPos = deviceNumber % ITEMS_PER_BYTE;
    return  devList[index] & 1 << (bitPos);
}

void setBitValue(char devList[], int deviceNumber){
    int index = deviceNumber/ITEMS_PER_BYTE;
    int bitPos = deviceNumber % ITEMS_PER_BYTE;
    devList[index] |= 1 << (bitPos);
}

int main() {

    char *deviceList = (char *)calloc(MAX_INDEX, sizeof(char));
    char input;
    int deviceNumber;

    
    do {
        printf("Enter c to continue or q to quit\n");
        scanf("%[^\n]", &input);
        if (input == 'c' || input == 'C') {
            printf("Enter device number\n");
            scanf("%d", &deviceNumber);
            if (deviceNumber < 0 || deviceNumber >= MAX_VALUE) {
                printf("Invalid Device Number\n");
                break;
            } else {
                if (isBitSet(deviceList, deviceNumber)) {
                    printf("Duplicate entry. Exiting\n");
                    break;
                } else {
                    setBitValue(deviceList, deviceNumber);
                }
            }
        } else if (input == 'q' || input == 'Q'){
            printf("Success..No duplicates found\n");
            break;
        } else {
            printf("Invalid input\n");
            break;
        }
    } while (1);
    free(deviceList);
}



