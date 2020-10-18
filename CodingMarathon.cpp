/*
 * Program Name: Calculate the sum of the marks of top K scores from the list
 *
 * Inputs:
 * input1: N, total no of participants
 * input2: K, Top scores
 * input3: Array with scores of N participants
 *
 * Output:
 * Sum of marks of top K scorers from the list
 *
 * */


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int i, input1, input2;
    cin>>input1>>input2;
    int input3[input1];
    for(i=0;i<input1;i++)
        cin>>input3[i];
    //sort in decending order
    sort(input3, input3+input1, greater<int>());
    int sum = 0;
    for(i=0;i<input2;i++)
        sum += input3[i];
    cout<<sum<<endl;
    return 0;
}

