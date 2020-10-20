/*
 * Program Name: Find no. of distinct flowers in the first K pots
 *
 * Inputs:
 * input1: N, no. of flower pots
 * input2: K, no. of pots to visit
 * input3: Array of pots denoting the different flowers.
 * Note-Same flower will have same index
 *
 * Output:
 * No. of different flower in first K pots
 *
 * */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int sheenaFlowers(int n, int k, int flowers[]){
    map<int, int> distintFlowerMap;
    for(int i=0;i<k;i++){
        if(distintFlowerMap.find(flowers[i])==distintFlowerMap.end())
            distintFlowerMap.insert({flowers[i], 1});
    }
    return distintFlowerMap.size();
}

int main(){
    int i, input1, input2;
    cin>>input1>>input2;
    int input3[input1];
    for(i=0; i<input1; i++)
        cin>>input3[i];
    cout<<sheenaFlowers(input1, input2, input3)<<endl;
    return 0;
}

