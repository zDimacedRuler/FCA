/*
 * Program Name: In N soldiers, starting from first every alternate soldier is
 * killed. After reaching the end of circle killing is started again from
 * first. Find the no. of soldiers between the first soldier and the last
 * surviving soldier.
 *
 * Inputs: N, total no. of soldiers
 *
 * Output: R, total no. of soldiers between the first soldier and last
 * surviving soldier.
 * Note- The last even no. soldier is always the last surviving soldier.
 *
 * */

#include<iostream>
using namespace std;

int circleOfDeath(int n){
    if(n%2 == 0)
        return n-1;
    else
        return n-2;
}

int main(){
    int input1;
    cin>>input1;
    cout<<circleOfDeath(input1)<<endl;
    return 0;
}

