/*
 * Program Name: Find the max no. of groups that can be formed such that only
 * consecutive students can form a group and each group should have atleat two
 * students with same compatiblity factor.
 *
 * Inputs:
 * input1: N, denotes no. of students
 * input2: Array of size N, where ith element denotes compatibility of ith
 * student
 *
 * Output:
 * Max no. of groups that can be formed
 *
 * */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int maximumGroups(int n, int students[]){
    int groups=0;
    set<int> compatibleGroup;
    for(int i=0;i<n;i++){
        if(compatibleGroup.find(students[i])==compatibleGroup.end())
            compatibleGroup.insert(students[i]);
        else{
            //make a group whenever a student with same compatiblity is found
            groups++;
            compatibleGroup.clear();
        }
    }
    return groups;
}

int main(){
    int i, input1;
    cin>>input1;
    int input2[input1];
    for(i=0;i<input1;i++)
        cin>>input2[i];
    cout<<maximumGroups(input1, input2)<<endl;
    return 0;
}
