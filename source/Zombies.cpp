/*
 * Program Name: Find a city that is perfect, a city where gcd of city[i] and
 * city[i+1] is 1 and city[i] has more no. of zombies than city[i+1].
 *
 * Inputs:
 * input1: No. of cities
 * input2: An array representing percentage of zombies in each city
 *
 * Output:
 * index of leftmost perfect city 'i'
 *
 * */

#include<iostream>
using namespace std;

int gcd(int a, int b){
    if(a%b==0)
        return b;
    return gcd(b, a%b);
}

int findPerfectCity(int n, int cities[]){
    for(int i=0; i<n-1; i++){
        if(cities[i]>cities[i+1])
            if(gcd(cities[i], cities[i+1])==1)
                return i;
    }
    return -1;
}

int main(){
    int i, input1;
    cin>>input1;
    int input2[input1];
    for(i=0; i<input1; i++)
        cin>>input2[i];
    cout<<findPerfectCity(input1, input2)<<endl;
    return 0;
}

