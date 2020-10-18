/*
 * Program Name: Alt Tab Program
 *
 * Inputs:
 * input1: N, denoting no. of application open
 * input2: k, denoting no. of tab pressed
 * input3: An array containing items from 1-N
 *
 * Output: Array containing new configuration of items
 *         after k tabs
 *
 * */

#include<iostream>
using namespace std;

struct Result {
    int output1[100];
};

Result altTab(int input1, int input2, int input3[]) {
    Result result = {.output1 = {0}};
    //Make input2 point to the index of the element in input3
    input2-=1;
    //Allow rotation in the alt tab tray
    input2 = input2 % input1;
    result.output1[0] = input3[input2];
    for(int i=0; i<input1; i++) {
        if(i < (input2))
            result.output1[i+1] = input3[i];
        else if(i > (input2))
            result.output1[i] = input3[i];
    }
    return result;
}

int main() {
    int i,input1,input2, input3[100];
    cin>>input1>>input2;
    for(i=0;i<input1;i++)
        cin>>input3[i];
    Result result = altTab(input1, input2, input3);
    for(i=0;i<input1;i++)
        cout<<result.output1[i]<<" ";
    cout<<endl;
    return 0;
}
