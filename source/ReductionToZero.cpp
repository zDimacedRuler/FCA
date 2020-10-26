/*
 * Program Name: Minimum no. of steps to reduce a no. to zero.
 *
 * Inputs:
 * inpu1: The number N
 *
 * Output:
 * Minimum no. of steps to reduce the no to zero
 *
 * */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool isPrime(int n){
    for(int i=2;i<n;i++)
        if(n%i==0)
            return false;
    return true;
}

int countSteps(int steps, vector<int> &primeNos, int n){
    cout<<"n:"<<n<<" steps:"<<steps<<endl;
    //For numbers <= 3;no of steps to reduce it to 0 is its value
    if(n<=3)
        return steps+n;

    for(auto itr = primeNos.rbegin(); itr != primeNos.rend(); itr++){
        if(n%*itr==0){
            //Finding the largest prime divisor and replacing it
            n=*itr;
            //Reduce n by 1 as n being a prime will have no prime divisor
            n-=1;
            steps+=2;
            break;
        }
    }
    return countSteps(steps, primeNos, n);
}

int reduction(int n){
    //For numbers <= 3;no of steps to reduce it to 0 is its value
    if(n<=3)
        return n;
    int steps = 0;
    vector<int> primeNos;
    int i = 2;
    //create a list of prime no.s for finding largest prime divisor of n
    while(i<=n/2){
        if(isPrime(i))
            primeNos.push_back(i);
        i++;
    }
    //Reduce n by 1 as n being a prime will have no prime divisor
    if(isPrime(n)){
        n=n-1;
        steps++;
    }
    return countSteps(steps, primeNos, n);
}

int main(){
    int input1;
    cin>>input1;
    cout<<reduction(input1)<<endl;
    return 0;
}

