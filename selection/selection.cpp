#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <iostream>

using namespace std;

void select_sort(vector<int> &list) {
   int cur=0; // current position in the list
   int min;
   int temp;  // the postion of minimum, temp for swapping
   cout<<"sorting..."<<endl;
   cout<<"list size is:"<<list.size()<<endl;

   while(true) {
      if( cur==list.size()) break;
      min=cur;
      for (int i=cur+1; i<list.size(); i++) {
         if(list[i]<list[cur] && list[i]<list[min]) min=i;
      } 
      //swapping
      temp=list[cur];
      list[cur]=list[min];
      list[min]=temp;
      cur++;
   }
}

int main() {
  double start=double(clock());

  int num=1;
  int l_size=100000;
  vector<int> list;

  srand(1234);//time(NULL));

  cout << "The unsorted list is:" << endl;
  // assign random list
  for( int i=0; i<l_size; i++) {
    num=rand()%100;
    list.push_back(num);
    //cout << list[i] << "  ";
  }
  cout << endl;

  select_sort(list);//sort list

  cout << "The sorted list is:" << endl;
  /*for( int i=0; i<l_size; i++) {
    cout << list[i] << "  ";
  }
  cout << endl;*/

  double finish=double(clock());
  double elapsed=finish-start;
  cout << "Using time=" << elapsed/CLOCKS_PER_SEC << "sec" <<endl;

  return 0;
}
