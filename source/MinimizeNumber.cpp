/*
 * Program Name: Minimize a no. with atmost k swaps of only adjacent digits
 *
 * Inputs:
 * input1: N, Length of String
 * input2: String of digits to be minimized
 * input3: K, no. of swaps
 *
 * Output:
 * Minimum no. that can be formed
 *
 * Similar to: https://www.geeksforgeeks.org/find-maximum-number-possible-by-doing-at-most-k-swaps/
 * Example:
 * input: 4 4321 2
 * output: 2431
 *
 * */

#include<iostream>
#include<cstring>
using namespace std;

void minimizeNumber(int n, char str[], int k, char result[]){
    if(k==0)
        return;
    for(int i=0; i<n-1; i++){
        int j =i+1;
        if(str[i]>str[j]){
            swap(str[i],str[j]);
            if(strcmp(str,result)<0){
                strcpy(result, str);
            }
            minimizeNumber(n, str, k-1, result);
            swap(str[i], str[j]);
        }
    }
}

int main(){
    int n, k;
    cin>>n;
    char str[n], result[n];
    cin>>str;
    strcpy(result, str);
    cin>>k;
    minimizeNumber(n, str, k, result);
    cout<<result<<endl;
    return 0;
}
