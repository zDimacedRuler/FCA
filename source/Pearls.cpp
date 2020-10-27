/*
 * Program Name: The no. of necklace that can be formed such that there is min
 * of 1 and max X pearls in the necklace, where each pearl has their own
 * magnificent coefficient. And the pearls should be in non-decreasing order
 * of their magnificence.
 *
 * Inputs:
 * input1: X, max no. of pearls that can be used
 * input2: Starting magnificent coefficient  of the pearls
 * input3: Ending magnificent coefficient of the pearls
 *
 * Output:
 * The no. of necklace possible
 *
 * */

#include<iostream>
using namespace std;

int fact(int n);

int nCr(int n, int r) {
    return fact(n) / (fact(r) * fact(n - r));
}

int fact(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

int finSol(int n, int start, int end) {
    int l=end-start+1;
    int sum=0;
    //This formula seems to work, Dont know why :D
    for(int i=1; i<=l; i++){
        sum += nCr(n+i-1, i);
    }
    return sum;
}

int main() {
    int input1, input2, input3;
    cin>>input1>>input2>>input3;
    cout<<finSol(input1, input2, input3)<<endl;
    return 0;
}
