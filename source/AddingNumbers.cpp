/*
 * Program Name: Find min cost of adding all no.s in array. By picking two
 * consecutive no.s and adding them, while cost = k*(sum of both no.s)
 *
 * Inputs:
 * input1: Size of array
 * input2: Elements of array
 * input3: Value k
 *
 * Output:
 * Min cost of adding no.s
 *
 * */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int addingCost(int n, int arr[], int k){
    int result=0, i=n, j;
    //i represents the no. of elements in the array left to be added
    while(i>1){
        //sorting to keep the summation min. thus reducing the cost
        sort(arr, arr+i);
        int pairs = i/2;
        for(j=0; j<pairs; j++){
            int sum = arr[j*2]+arr[(j*2)+1];
            result += sum*k;
            arr[j] = sum;
        }
        if(i%2 !=0)
            arr[j]=arr[j*2];
        i=i-pairs;
    }
    return result;
}

int main(){
    int i,input1, input3;
    cin>>input1;
    int input2[input1];
    for(i=0; i<input1; i++)
        cin>>input2[i];
    cin>>input3;
    cout<<addingCost(input1, input2, input3)<<endl;
    return 0;
}

