#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>

using namespace std;

void rearange_vec( vector<int> &list, int j, int min);
void insert_sort(vector<int> &list);

int main() {
  int num;
  int l_size=1000;
  vector<int> list;

  srand(1234);//time(NULL));

  cout << "The unsorted list is:" << endl;
  // assign random list
  for( int i=0; i<l_size; i++) {
    num=rand()%1000;
    list.push_back(num);
    cout << list[i] << "  ";
  }
  cout << endl;

  insert_sort(list);//sort list

  cout << "The sorted list is:" << endl;
  for( int i=0; i<l_size; i++) {
    cout << list[i] << "  ";
  }
  cout << endl;


  return 0;
}

void insert_sort(vector<int> &list) {
   int cur=0; // current position in the list
   int toinsert,tomove; // tomove is the element to be insert, toinsert is the position to be insert.
   cout<<"sorting..."<<endl;
   cout<<"list size is:"<<list.size()<<endl;

   while(true) {
      if( cur==list.size()) break;
      //j=cur; //j is the element to be insert
      bool has_min=false;
      for (int i=cur; i<list.size(); i++) {
         if(list[i]<list[cur]){
           tomove=i;
           has_min=true;
           break;
         }
      }
      if(has_min){
         for (int i=cur; i>=0; i--) {
            if(list[i]<=list[tomove]) {
              toinsert=i+1;//it has to be at the right of the value smaller than itslef
              break;
            }
            else toinsert=0;
         }
         //cout <<"cur="<<cur <<" tomove="<< tomove<<" toinsert="<<toinsert<<endl;
         rearange_vec(list,tomove,toinsert);
      }
      //else for (int i=0; i<list.size();i++) cout << list[i]<<"  ";
      cur++;
      //cout<<endl;
   }
}

void rearange_vec( vector<int> &list, int j, int min) {
   vector<int> temp;  // temperory vector for insertion
   //rearange the list
   for (int i=0; i<min; i++) {
      temp.push_back(list[i]);
   }
   temp.push_back(list[j]);
   for (int i=min; i<j; i++) {
      temp.push_back(list[i]);
   }
   for (int i=j+1; i<list.size(); i++) {
      temp.push_back(list[i]);
   }
   list=temp;
   //for (int i=0; i<list.size();i++) cout << list[i]<<"  ";//print out the vecot

}

