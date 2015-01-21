#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <iostream>

using namespace std;

vector<int> merge(vector<int> left, vector<int> right) {
  vector<int> combine;
  //For testing without sorting
  //for(int i=0; i<left.size();i++) combine.push_back(left[i]);
  //for(int i=0; i<right.size();i++) combine.push_back(right[i]);

  int l=0, r=0;
  //Sorting from here
  while(l<left.size()) {
    if(r>=right.size()){
      break;
    }
    if(right[r]<=left[l]) {
      combine.push_back(right[r]);
      r++;
    }
    else {
      combine.push_back(left[l]);
      l++;
    }
  }

  //push the rest up
  while(r<right.size()) {
    combine.push_back(right[r]);
    r++;
  }

  while(l<left.size()) {
    combine.push_back(left[l]);
    l++;
  }

  /*if (l==left.size()) {
    while(r<right.size()) {
      combine.push_back(right[r]);
      r++;
    }
  }*/

  //cout<<"combine=";
  //for(int i=0; i<combine.size(); i++) cout<<combine[i]<<"  ";
  //cout<<endl;

  return combine;
}

vector<int> merge_sort(vector<int> list) {
  vector<int> left, right;
  if(list.size()==1) {
    //cout<<list[0]<<endl;
    return list;
  }

  for(int i=0; i<int (list.size()/2);i++) left.push_back(list[i]);
  for(int i=int(list.size()/2);i<list.size();i++) right.push_back(list[i]);
  left=merge_sort(left);
  right=merge_sort(right);

  //for(int i=0; i<list.size();i++) cout<<list[i]<<"  ";
  //cout<<endl;

  return merge(left,right);

}

int main() {
  double start=double(clock());

  int num=1;
  int l_size=200;
  vector<int> list,sorted_list;

  srand(1234);//time(NULL));

  cout << "The unsorted list is:" << endl;
  // assign random list
  for( int i=0; i<l_size; i++) {
    num=rand()%100;
    list.push_back(num);
    cout << list[i] << "  ";
  }
  cout << endl;

  cout<<"sorting..."<<endl;
  cout<<"list size is:"<<list.size()<<endl;

  sorted_list=merge_sort(list);//sort list

  cout << "The sorted list is:" << endl;
  for( int i=0; i<sorted_list.size(); i++) {
    cout << sorted_list[i] << "  ";
  }
  cout << endl;

  double finish=double(clock());
  double elapsed= finish - start;

  cout << "Using time=" << elapsed/CLOCKS_PER_SEC << "sec" <<endl;

  return 0;
}
