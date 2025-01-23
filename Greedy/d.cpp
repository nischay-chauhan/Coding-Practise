/* Lemonade Change
Problem Statement: Given an array representing a queue of customers and the value of bills they hold, determine if it is possible to provide correct change to each customer. Customers can only pay with 5$, 10$ or 20$ bills and we initially do not have any change at hand. Return true, if it is possible to provide correct change for each customer otherwise return false.
  */

#include <bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int> bills) {
  int five =0;
  int ten = 0;
  for(int i = 0 ; i < bills.size(); i++){
    if(bills[i] == 5){
      five++;
    }else if (bills[i] == 10){
      if(five == 0){
        return false;
      }
      five--;
      ten++;
    }else{
      if(five > 0 && ten > 0){
        five--;
        ten--;
      }else if(five > 0){
        five--;
      }else{
        return false;
      }
    }
  }
  return true;
}

int main() {
  vector<int> bills = {5,5,5,10,20};
  if(lemonadeChange(bills))
        cout << "It is possible to provide change for all customers." << endl;
    else
        cout << "It is not possible to provide change for all customers." << endl;
    return 0;
  return 0;
}