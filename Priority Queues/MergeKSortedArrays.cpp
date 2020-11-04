Merge K sorted arrays
Given k different arrays, which are sorted individually (in ascending order). You need to merge all the given arrays such that output array should be sorted (in ascending order).
Hint : Use Heaps.
Input Format :
Line 1 : Integer K
Line 2 : Arrays 1 size (n1)
Line 3 : Array 1 elements (separated by space)
Line 4 : Array 2 size (n2)
and so on for next arrays
Sample Input 1 :
4
3
1 5 9
2
45 90
5
2 6 78 100 234
1
0
Sample Output 1 :
0 1 2 5 6 9 45 78 90 100 234


/************************************************ SOLUTION **************************************************************************/
    
//Better time complexity
#include<queue>
#include<utility>
#include<queue>
vector<int> mergeKSortedArrays(vector<vector<int>*> input){
    priority_queue<pair<int,pair<int,int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;
    int size=input.size();
    for(int i=0;i<size;i++){
        pq.push({input[i]->at(0),{i,0}});
    }
    vector<int> ans;
  while(!pq.empty()){
      pair<int,pair<int,int>> current=pq.top();
      pq.pop();
      int i=current.second.first;
      int k=current.second.second;
      ans.push_back(current.first);
      if(k+1<input[i]->size()){
          pq.push({input[i]->at(k+1),{i,k+1}});
      }
  }
    return ans;
}


#include<queue>
vector<int> mergeKSortedArrays(vector<vector<int>*> input){
    vector<int>output;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<input.size(); i++){
        vector<int>* q = input[i];
        for(int j=0; j<q->size(); j++)
            pq.push(q->at(j));
    }
    while(!pq.empty()){
        output.push_back(pq.top());
        pq.pop();
    }
    return output;
}
