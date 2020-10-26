/*
 * Program Name: Find no. of marbles in the missing bowl. Given N%2==0 and sum
 * of marbles in the first and last bowl is equal sum of marbles in second
 * and second last bowl and so on. The first and last bowl is in their
 * positions
 *
 * Inputs:
 * input1: N-1 bowls.
 * input2: Array containing the no of marbles in each N-1 bowls
 *
 * Output:
 * No. of marbles in the missing bowl
 * */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int missingMarble(int n, int bowls[]){
    int marbles = 0, i;
    int sum = bowls[0]+bowls[n-1];
    set<int> marblesSet;
    for(i=0;i<n/2;i++)
        marblesSet.insert(bowls[i]);
    for(i=n/2;i<n;i++)
        if(marblesSet.find(sum-bowls[i])==marblesSet.end()){
            marbles = sum - bowls[i];
            break;
        }
    return marbles;
}

int main(){
    int i, input1;
    cin>>input1;
    int input2[input1];
    for(i= 0; i< input1; i++)
        cin>>input2[i];
    cout<<missingMarble(input1, input2)<<endl;
    return 0;
}
