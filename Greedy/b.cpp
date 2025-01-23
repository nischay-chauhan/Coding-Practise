/* Freactional Knapsack */
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int val;
    int wt;
};

class Sol {
    public:
        bool static comp(Item a, Item b){
            return (a.val * 1.0 / a.wt) > (b.val * 1.0 / b.wt);
        }
        
        double fractionalKnapsack(int W, vector<Item> items) {
            sort(items.begin(), items.end(), comp);
            
            int totalVal = 0;
            for (Item item : items) {
                if (W <= 0) break;
                
                int curVal = min(W, item.wt);
                totalVal += (curVal * 1.0 / item.wt) * item.val;
                W -= curVal;
            }
            
            return totalVal;
        }
};

int main(){
    int n = 3 , weight = 50;
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
    Sol obj;
    cout << obj.fractionalKnapsack(weight, items);
        
}