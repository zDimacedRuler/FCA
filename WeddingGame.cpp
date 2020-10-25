/*
 * Program Name: Min no. of sets that can be formed such that each set is
 * formed using consecutive digits and no digit can be used more than once.
 * Also, in each set no. should be less than y.
 *
 * Inputs:
 * input1: N, no. of digits in string
 * input2: Y, no. should not be greater than this
 * input3: S, the string of digits
 *
 * Output:
 * Min no. of sets
 *
 * */

#include<iostream>
using namespace std;

int minSets(int n, int y,char *digits){
    int sets =0, temp =digits[0]-'0';
    for(int i=1;i<n;i++){
        int num = digits[i]- '0';
        if((temp*10+num)> y){
            if(temp<=y) // for case: 4 4 5678
                sets++;
            temp= num;
        } else if((temp*10+num)==y){ // for case: 4 123 1234
            sets++;
            temp= 0;
        } else{
            temp= temp*10+num;
        }
    }
    if(temp<=y)// for the '4' in case: 4 4 1234
        sets++;
    return sets;
}

int main(){
    int n, y;
    cin>>n>>y;
    char digits[n+1];
    cin>>digits;
    digits[n]='\0';
    cout<<minSets(n, y, digits)<<endl;
    return 0;
}
