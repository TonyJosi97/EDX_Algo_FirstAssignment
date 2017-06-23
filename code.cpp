/*
MIT License

Copyright (c) 2017 Tony Josi

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/




/*
Written By: Tony Josi
Date:       21/6/17
*/


//SOLUTION

#include <iostream>
#include <vector>
using namespace std;


void merge(vector<int> & num, vector<int> & weights, int l, int r, int m)
   {
   
      int li,ri,sizel,sizer;
      sizel = m - l + 1;
      sizer = r - m;
      int lar[sizel];
      int rar[sizer];
      int lnum[sizel];
      int rnum[sizer];

      for(int i = 0; i < sizel; i++)
      {
         lar[i] = weights[l + i];
         lnum[i] = num[l + i];
      }

      for(int i = 0; i < sizer; i++)
      {
         rar[i] = weights[m + 1 + i];
         rnum[i] = num[m + 1 + i];
      }
   
      li = 0;
      ri = 0;
      int k = l;

      while((li < sizel) && (ri < sizer))
      {

         if(lar[li] > rar[ri])
         {
            weights[k] = lar[li];
            num[k] = lnum[li];
            li++;
         }

         else if(lar[li] == rar[ri])
         {
            weights[k] = lar[li];
            if(lnum[li] > rnum[ri])
            {
               num[k] = lnum[li];
               li++;
            }
            else
            {
               num[k] = rnum[ri];
               ri++;
            }
         }

         else
         {
            weights[k] = rar[ri];
            num[k] = rnum[ri];
            ri++;
         }
         k++;
         
      }
      
      while(li < sizel)
      {
         weights[k] = lar[li];
         num[k] = lnum[li];
         li++;
         k++;
      }
   
      while(ri > sizer)
      {
         weights[k] = rar[ri];
         num[k] = rnum[ri];
         ri++;
         k++;
      }
   
   }



   void sort(vector<int> & num, vector<int> & weights, int l, int r)
   {
      if(l < r)
      {
         int m;
         m = (l + r)/2;
         sort(num,weights,l,m);
         sort(num,weights,m+1,r);
         merge(num,weights,l,r,m);
      }
   }
   
   void customSort(vector<int> & num, vector<int> & weights,int start,int end)
   {
      sort(num,weights,start,end);
   }

//Main Function to test the CustomSort()
 
int main() 
{

   vector<int> weights; 
   vector<int> num;
   int i,size,numm;
   cin>>size;
   cout<<"weights:\n";
   for(i = 0; i < size; i++)
   {
      cin>>numm;
      weights.push_back(numm);
   }
   cout<<"Numbers: \n";
   for(i = 0; i < size; i++)
   {
      cin>>numm;
      num.push_back(numm);
   }
   
   customSort(num,weights,0,(size-1));
   cout<<"\n\n\n";
   for(i = 0; i < size; i++)
   {
      cout<<num[i]<<"\n";
   }
   cout<<"\n\nWeights:\n";
   for(i = 0; i < size; i++)
   {
      cout<<weights[i]<<"\n";
   }
   return 0;
}
