/*
 * Program Name: Min no. of days for confidence to reach D. Each day only one
 * exercise can be performed. The same exercise can be repeated again.
 *
 * Inputs:
 * input1: D, final confidence level
 * input2: K, where set of K prime no. is the no. of excercises.
 *
 * Output:
 * No. of days required to reach exactly D confidence, if not possible then -1
 * */

#include<iostream>
#include<limits.h>
using namespace std;

bool isPrime(int n) {
    for(int i=2;i<n;i++)
        if(n%i==0)
            return false;
    return true;
}

int findMinDays(int confidence, int index, int exercises[], int days) {
    //cout<<"Confidence:"<<confidence<<" Index:"<<index<<" Excercise:"<<exercises[index]<<" Days:"<<days<<endl;
    int i, result;
    for(i=index; i>=0;i--){
        if(confidence>=exercises[i]){
            confidence-=exercises[i];
            if(confidence==0)
                return 1;
            result = findMinDays(confidence, index, exercises, days+1);
            if(result>0)
                return result+1;
            confidence+=exercises[i];
        }
    }
    return 0;
}

int main(){
    int input1, input2, i, j, days=0;
    cin>>input1>>input2;
    int exercises[input2];
    i = 0; j = 2;
    while (i<input2) {
        if(isPrime(j)){
            exercises[i]=j;
            i++;
        }
        j++;
    }
    for(i=0;i<input2;i++)
        cout<<exercises[i]<<" ";
    cout<<endl;
    int min = findMinDays(input1, input2-1, exercises, days);
    if(days==0)
        cout<<-1<<endl;
    else
        cout<<min<<endl;
    return 0;
}

