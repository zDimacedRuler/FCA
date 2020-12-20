/*
 * Program Name: Find the max money Dan can earn by completing Harold's
 * Homework. However each homework has a deadline associated with it and it
 * takes 1 unit amount of time to complete a homweork.
 *
 * Inputs:
 * input1: No. of tasks
 * input2: An array of money associated with each task
 * input3: An array representing deadline of each task
 *
 * Output:
 * Max amount of money Dan can earn
 *
 * */

#include<iostream>
using namespace std;

int maxMoneyEarned(int n, int tasks[], int deadline[]){
    int sum=0;
    int maxDeadline= deadline[n-1];
    int num=n;
    while(maxDeadline>0 && num>0){
        int money=0, moneyIndex = -1;
        for(int i=n-1; i>=0; i--){
            if(deadline[i]>= maxDeadline){
                if(money == 0){
                    money = tasks[i];
                    moneyIndex = i;
                }
                else if(money < tasks[i]){
                    money = tasks[i];
                    moneyIndex = i;
                }
            }
        }
        sum += money;
        tasks[moneyIndex] = -1;
        maxDeadline--;
        num--;
    }
    return sum;
}

int main(){
    int input1;
    cin>>input1;
    int input2[input1], input3[input1];
    for(int i=0; i<input1; i++){
       cin>>input2[i];
    }
    for(int i=0; i<input1; i++){
       cin>>input3[i];
    }
    cout<<maxMoneyEarned(input1, input2, input3)<<endl;
    return 0;
}

