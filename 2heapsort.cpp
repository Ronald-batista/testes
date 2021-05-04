#include <iostream>
#include <stdlib.h>
#include <random>

using namespace std;
#define SIZE 10 // 10000000

typedef struct {
    int num;
    char string[];
} record_type;

void fill_registration(record_type vector[]);
void showArray(record_type vector[]);
void print(record_type vector, int i);
void heapsort(record_type v[], int n);
void build_max_heap (record_type v[], int n);
void max_heapfy (record_type v[], int i, int n);
void swap(record_type v[], int a, int b);


// Main Program
int main (int argc, char **argv) {
    record_type *registry;
    registry = (record_type *) calloc(SIZE, sizeof(record_type));
    
    fill_registration(registry); // fill registry vector
   // showArray(registry); //Before ordering
    cout << "Division" << endl;
    heapsort(registry,SIZE-1);
    showArray(registry); // After ordering
    free(registry); // Clear allocated memory

}

//-------------------------------------------------------------------------------

void max_heapfy (record_type r[], int i, int n) {
    int left = 2 * i;
    int right = 2 * i  + 1;
    int larger;

    if (left <= n && r[left].num > r[i].num){
        larger = left;
    }else{
        larger = i;
    }
    if (right <= n && r[right].num > r[larger].num)
        larger = right;
    if (larger != i){
        swap(r,i,larger);
        max_heapfy(r,larger,n);
    }
}

//-------------------------------------------------------------------------------

void build_max_heap (record_type r[], int n) {
    int i;
    for (i = n/2; i >= 0; i--)
        max_heapfy(r,i,n);
}

//-------------------------------------------------------------------------------

void heapsort(record_type r[], int n){
    int i;
    build_max_heap(r,n);
    for (i = n; i >= 1; i--){
        swap(r, 0, i);
        n--;
        max_heapfy(r,0,n);
    }
}

//-------------------------------------------------------------------------------
// Swap two array content
void swap(record_type r[], int a, int b){
    int aux = r[a].num;
    r[a].num = r[b].num;
    r[b].num = aux;
}

//-------------------------------------------------------------------------------
// Generates a "Random" Number to fill array
void fill_registration(record_type r[]){
    int i;
    std::random_device device;
    std::mt19937 gen{device()};
    std::uniform_int_distribution<int> dist{-2147483648, 2147483647}; // range data type int
    for(i=0; i < SIZE; i++){      
        r->num =dist(gen);
        r++;
    }
}

//-------------------------------------------------------------------------------

void showArray(record_type vector[]){
    int i;
    for(i=0; i < SIZE; i++){
        print(vector[i], i);
    }
}

//-------------------------------------------------------------------------------

void print(record_type vector, int i){
    cout <<  "index "<< i << ": " <<"[ " << vector.num ;
    cout << ", " << vector.string << " ]" << endl;
}

