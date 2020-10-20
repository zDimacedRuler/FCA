/*
 * Program Name: Find the position of bowl last modified if a marble is added
 * in the last bowl. A bowl cant hold more than 9 marble,
 * so it'll be carried over if one more is added
 *
 * Inputs:
 * input1: N, no. of bowls
 * input2: Array containing the no. of marble in each bowl
 *
 * Output:
 * Last Modified Bowl
 *
 * */

#include<iostream>
using namespace std;

int lastModified(int n, int bowl[]){
    for(int i=n-1; i>=0; i--)
        if(bowl[i]<9)
            return i+1;
    return 0;
}
int main(){
    int i, input1;
    cin>>input1;
    int input2[input1];
    for(i=0; i<input1; i++)
        cin>>input2[i];
    cout<<lastModified(input1, input2)<<endl;
    return 0;
}

