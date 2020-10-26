/*
 * Program Name: Find no. of stones that can be brought from Mars such that 
 * none of them are similar to any on earth
 *
 * Inputs:
 * input1: M, denotes size of bag and no. of different weigths present on Mars
 * input2: N, denotes no. of common stones between earth and mars
 * input3: An array, denotes the list of common stones
 *
 * Output:
 * Max no. of unique stones that can be collected from mars
 *
 * */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int maxUniqueStones(int weight, int n, int common[]){
    int maxStones=0, sum=0;
    set<int> commonStones;
    for(int i=0;i<n;i++)
        commonStones.insert(common[i]);
    for(int i=1;i<=weight; i++){
        //skip common stones
        if(commonStones.find(i)==commonStones.end()){
            if(sum+i<=weight){
                cout<<"i:"<<i<<endl;
                sum+=i;
                maxStones++;
            }else
                break;
        }
    }
    return maxStones;
}

int main(){
    int i, input1, input2;
    cin>>input1>>input2;
    int input3[input2];
    for(i=0; i<input2; i++)
        cin>>input3[i];
    cout<<maxUniqueStones(input1, input2, input3)<<endl;
    return 0;
}

