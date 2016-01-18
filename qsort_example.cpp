#include <iostream>

using namespace std;

/* Example of: In-place Quicksort function in C++ */
// Allan Bowhill (2016)
// clang++ qsort_example.cpp


// array printing function
// array is enclosed in []
// pivot is enclosed in ()
// innermost left index position is prefixed by {L}
// innermost right index position is prefixed by {R}

void print(int * ary, int sz, int left_idx = 0, int right_idx = 14, int pivot_idx = 14)
   {
   cout << "[";
   for (int i=0; i< sz; ++i)
      {
      if (i == left_idx)
         cout << "{L}";

      if (i == right_idx)
         cout << "{R}";
     
      if (i == pivot_idx)
         cout << "(";

      cout << ary[i];

      if (i == pivot_idx)
         cout << ")";

      if (i != sz-1) 
         cout << ",";
      }
   cout << "]";
   }


int qsort(int * ary, const int sz)
   {
   // return error on bad inputs
   if (ary == nullptr || sz < 1)
      return 0;

   // don't bother sorting for one element array
   if (sz < 2)
     return 1;
     
   int pivot_idx = sz-1;   // pivot index, always last element
   int left_idx = -1;      // place left index to left of element zero
   int right_idx = sz;     // place right index on pivot
   const int pivot = ary[pivot_idx]; // pivot value
   
   // print array "before" bucketing
   print(ary, sz, left_idx, right_idx, pivot_idx);

   // Pivot index is always identified as the last element in the array.
   // Array elements are evaluated and bucketed (swapped in place)
   // to a stacks of contiguous values either on the left side of the array
   // (less or equal to pivot) or right (greater than pivot). The left and
   // right pointers are progressed inward to point to the innermost element
   // closing a contiguous block of left or right bucketd data. Index progression
   // halts when the next value to advance-to would not be a conforming left or
   // right value to the block. When both stacks have found their stopping-point,
   // and they are not looking at the same index ahead, a swap is made between
   // the two blocking index-ahead values corresponding to each stack, and the
   // process continues. When no more values can be scanned or swapped, the
   // left stack is recursed followed by the right stack. The unordered bucketing
   // of left and right values is done in-place in the array, so when it's
   // complete, the array is fully sorted.
   
   for (int i=0; i < sz-1 && left_idx + 1 < right_idx - 1; ++i)
      {      
      while (ary[left_idx +1] < pivot)
         left_idx++;

      while (ary[right_idx - 1] > pivot)
	   right_idx--;

      swap( ary[left_idx + 1], ary[right_idx - 1] );
      }

   // record the new index of relocated pivot on left stack
   pivot_idx = left_idx + 1;

   // print array after bucketing
   cout << " > ";
   print(ary, sz, left_idx, right_idx, pivot_idx); 
   cout  << endl;

   // recurse the left stack
   qsort(ary, pivot_idx);

   // recurse the right stack
   qsort(&ary[right_idx], sz-right_idx);

   return 1;
   }


// Usage

int main (void)
   {
   // sample array to sort 
   int sz = 14;
   int ary[15] = {7,10,3,5,1,13,11,200,4,66,122,45,9898,100};

   cout << "UNSORTED INPUT ARRAY: ";
   for (int i=0; i< sz; ++i) { cout << ary[i] << ","; }
   cout << endl;

   // pass-in array and size, sort is done in-place
   // * returns 1 for success
   // * returns 0 on error
   if ( qsort(ary,sz) )
     {
     cout << "SORTED RESULT: ";
     for (int i=0; i< sz; ++i) { cout << ary[i] << ","; }
     cout << endl;
     }
   else 
      return -1;
   }


