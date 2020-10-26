/*
 * Program Name: Find prime no.s greater than (N+1)/2
 *
 * Inputs:
 * N, denoting no. of users in network from 2-N+1
 *
 * Output:
 * Total no. of groups i.e., prime no. greater than (N+1)/2
 * */

#include<iostream>
using namespace std;

bool isPrime(int x){
    for(int i=2;i<x;i++)
        if(x%i==0)
            return false;
    return true;
}

int friendGroups(int n){
    if(n<=2)
        return n;
    int i=(n+1)/2+1;
    int groups=0;
    while(i<=n+1){
        if(isPrime(i))
            groups++;
        i++;
    }
    return groups+1;
}

int main(){
    int input;
    cin>>input;
    cout<<friendGroups(input)<<endl;
    return 0;
}
