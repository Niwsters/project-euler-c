#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define NAME_MAX_LENGTH 256
#define NAMES_MAX 10000

struct Names {
    char items[NAMES_MAX][NAME_MAX_LENGTH];
    size_t len;
};

// Function to swap the position of two elements
void merge(char arr[][NAME_MAX_LENGTH],int low,int mid,int high) //Merging the Array Function
{
    int nL= mid-low+1;
    int nR= high-mid;

    char L[nL][NAME_MAX_LENGTH];
    char R[nR][NAME_MAX_LENGTH];
    int i;
    for(i=0;i<nL;i++) {
        strcpy(L[i],arr[low+i]);
    }
    for(i=0;i<nR;i++) {
        strcpy(R[i],arr[mid+i+1]);
    }
    int j=0,k;
    i=0;
    k=low;
    while(i<nL&&j<nR) {
        if(strcmp(L[i],R[j])<0)strcpy(arr[k++],L[i++]);
        else strcpy(arr[k++],R[j++]);
    }
    while(i<nL)strcpy(arr[k++],L[i++]);
    while(j<nR)strcpy(arr[k++],R[j++]);

}

void mergesort(char arr[][NAME_MAX_LENGTH],int low,int high) //Main MergeSort function
{
    if(low<high) {
        int mid=(low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

void sort(struct Names *names) {
    mergesort(names->items, 0, names->len-1);
}

uint32_t score(char name[NAME_MAX_LENGTH]) {
    uint32_t score = 0;
    for (size_t i=0; i<strlen(name); i++) {
        score = score + name[i] - 'A' + 1;
    }
    return score;
}

int main() {
    FILE *file = fopen("data/names.txt", "r");

    char buffer[NAME_MAX_LENGTH];
    for (int i=0; i<NAME_MAX_LENGTH; i++) {
        buffer[i] = '\0';
    }

    struct Names names;
    names.len = 0;
    for (size_t i=0; i<NAMES_MAX; i++) {
        for (size_t j=0; j<NAME_MAX_LENGTH; j++) {
            names.items[i][j] = '\0';
        }
    }

    char c = '\0';
    size_t len = 0;
    while ((c = fgetc(file)) != EOF) {
        if (len >= NAME_MAX_LENGTH) {
            exit(1);
        }

        if (c == ',') {
            strcpy(names.items[names.len++], buffer);
            for (int i=0; i<len; i++) {
                buffer[i] = '\0';
            }

            len = 0;
        }

        if (c != ',' && c != '"') {
            buffer[len++] = c;
        }
    }
    strcpy(names.items[names.len++], buffer);

    fclose(file);

    sort(&names);

    uint32_t sum;
    for (size_t i=0; i<names.len; i++) {
        sum = sum + score(names.items[i]) * (i+1);
    }

    printf("%u %lu\n", sum, names.len);

    return 0;
}
