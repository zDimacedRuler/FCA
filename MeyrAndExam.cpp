/*
 * Program Name: Edit the marks assigned to questions such that each qquestion
 * has distinct max marks and total marks is as low as possible. Each question
 * should have atleast as much marks as it originally had.
 *
 * Inputs:
 * input1: N, no. of questions
 * input2: Array containing orignal marks assigned
 *
 * Output:
 * Min totals marks
 *
 * */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxMarks(int n, int marks[]){
    int sum=0;
    map<int, int> distinctMarks;
    sort(marks, marks+n);
    for(int i=n-1; i>=0; i--){
        int temp=marks[i];
        //find a distinct greater no. than the current one
        while(distinctMarks.find(temp)!=distinctMarks.end())
            temp++;
        distinctMarks.insert({temp, 1});
        sum+=temp;
        marks[i]=temp;
    }
    return sum;
}

int main(){
    int i, input1;
    cin>>input1;
    int input2[input1];
    for(i=0; i<input1; i++)
        cin>>input2[i];
    cout<<maxMarks(input1, input2)<<endl;
    for(i=0; i<input1; i++)
        cout<<input2[i]<<" ";
    cout<<endl;
    return 0;
}

