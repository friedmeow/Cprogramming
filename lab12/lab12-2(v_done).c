#include <stdio.h>
#include <stdlib.h>

struct DynaIntArr {
    int capacity;
    int size;
    int *data;
};

void initalArr(struct DynaIntArr *arr);
int addOne(struct DynaIntArr *arr, int value);
int* getOne(struct DynaIntArr *arr, int index);
int removeOne(struct DynaIntArr *arr, int index);
void clearArr(struct DynaIntArr *arr);
void destroyArr(struct DynaIntArr *arr);
void printArr(const struct DynaIntArr *arr);

int main() {
    struct DynaIntArr testArr;
    initalArr(&testArr);

    int opt;
    for(;;) {
        system("cls");
        printf(" -------------------------------------------------\n");
        printf("| 1. Add a value to the dynamic array.           |\n");
        printf("| 2. Get the value of the input index.           |\n");
        printf("| 3. Remove a value from the dynamic array.      |\n");
        printf("| 4. Show all the data of the dynamic array.     |\n");
        printf("| 5. Clear the dynamic array.                    |\n");
        printf("| 6. Destroy the dynamic array.                  |\n");
        printf("| 7. Exit.                                       |\n");
        printf(" -------------------------------------------------\n");
        printf("What are you going to do? -> ");
        scanf("%d",&opt);

        switch(opt) {
            case 1: {
                printf("Please input the value: ");
                int tmpVal;
                scanf("%d", &tmpVal);
                if(!addOne(&testArr, tmpVal)) {
                    printf("Error, Memory insufficient!!\n");
                    system("pause");
                }
                break;
            }
            case 2: {
                printf("Please input the index: ");
                int tmpIdx;
                scanf("%d", &tmpIdx);
                int *theValP = getOne(&testArr, tmpIdx);
                if(theValP) {
                    printf("The value of index %d: %d\n", tmpIdx, *theValP);
                } else {
                    printf("Wrong index!!\n");
                }
                system("pause");
                break;
            }
            case 3: {
                printf("Please input the index: ");
                int tmpIdx;
                scanf("%d", &tmpIdx);
                if(!removeOne(&testArr, tmpIdx)) {
                    printf("Wrong index!!\n");
                    system("pause");
                }
                break;
            }
            case 4:
                printArr(&testArr);
                system("pause");
                break;
            case 5:
                clearArr(&testArr);
                break;
            case 6:
                destroyArr(&testArr);
                break;
            case 7:
                return 0;
            default:
                printf("Wrong input. Please enter an input 1-7.\n");
                break;
        }
        printf("\n");
    }
    destroy(testArr);

    return 0;
}

void initalArr(struct DynaIntArr *arr){
    arr->capacity = 0;
    arr->size = 0;
    arr->data = 0;
}

int addOne(struct DynaIntArr *arr, int value){

    if(arr->capacity == 0)
    {
        arr->data = malloc(sizeof(int));
        arr->capacity++;
    }
    if(arr->capacity == arr->size)
    {
        arr->data = realloc((arr->data),(arr->capacity + 1) * sizeof(int));
        if(arr->data == NULL) return 0;
        arr->capacity++;
    }
    arr->data[arr->size] = value;
    arr->size++;
    return 1;

    /*
     behave:
     if the capacity is enough
     do not allocate new memory space
     just add the new value at end
     else
     allocate new memory space with size + 1
     copy old data into new space
     add the new value at end

     return 0 when action fail
     return 1 when action success
     */

    //return 0;
}

int* getOne(struct DynaIntArr *arr, int index){

    if(index > arr->capacity - 1 || index < 0) return NULL;
    else return &arr->data[index];

    /*
     behave:
     return "the pointer" to the target value
     if the index is invalid, please return null pointer
     */
    //return 0;
}

int removeOne(struct DynaIntArr *arr, int index){
    if(index > arr->capacity - 1 || index < 0) return 0;
    int i = 0;
    for(i = index; i < arr->size ; i++)
    {
        arr->data[i] = arr->data[i+1];
    }
    arr->size--;
    /*
     behave:
     remove the value from the array but do not deallocate the memory

     return 0 when action fail
     return 1 when action success
     */
    return 1;
}

void clearArr(struct DynaIntArr *arr){
    int i = 0;
    for(i = arr->size - 1; i >= 0 ; i--)
    {
        arr->data[i] = NULL;
    }
    arr->size = 0;
    return NULL;
    /*
     behave:
     remove all data	but do not give back the memory space
     */
}

void destroyArr(struct DynaIntArr *arr){
    if(arr->capacity == 0) return NULL;
    else
    {
        free(arr->data);
        arr->capacity = 0;
        arr->size = 0;
    }
    /*
     behave:
     remove all data	and give back the memory space
     */
}

void printArr(const struct DynaIntArr *arr) {
    int i;
    printf("    size: %10d\ncapacity: %10d\n", arr->size, arr->capacity);

    for(i = 0; i < arr->size; i++) printf("%d ", arr->data[i]);

    putchar('\n');
}
