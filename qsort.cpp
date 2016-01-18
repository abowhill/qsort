#include <utility>

int qsort(int * ary, const int sz)
   {
   if (ary == nullptr || sz < 1)
      return 0;

   if (sz < 2)
     return 1;
     
   int pivot_idx = sz-1;
   int left_idx = -1;
   int right_idx = sz;
   const int pivot = ary[pivot_idx];
   
   for (int i=0; i < sz-1 && left_idx + 1 < right_idx - 1; ++i)
      {      
      while (ary[left_idx +1] < pivot)
         left_idx++;

      while (ary[right_idx - 1] > pivot)
	   right_idx--;

      std::swap( ary[left_idx + 1], ary[right_idx - 1] );
      }

   pivot_idx = left_idx + 1;

   qsort(ary, pivot_idx);

   qsort(&ary[right_idx], sz-right_idx);

   return 1;
   }
