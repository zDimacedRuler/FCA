/*
 * Program Name: Reduce special values of candies so that k candies have
 *               same special value, this value is as large as possible.
 *
 * Inputs:
 * input1: N, no of candies
 * input2: K, candies having same speacial values
 * input3: Array representing special values of candies
 *
 * Output:
 * Maximum special value of the candy
 *
 * */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int i, input1, input2;
    cin>>input1>>input2;
    int input3[input1];
    for(i=0; i<input1; i++)
        cin>>input3[i];
    sort(input3, input3+input1);
    cout<<input3[input1-input2]<<endl;
    return 0;
}

