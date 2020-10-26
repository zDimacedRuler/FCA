/*
 * Program Name: For a given string and values M, N. What is the no. of turns
 * to get the orignal string back
 *
 * Inputs:
 * input1: Orignal word string
 * input2: Value M
 * input3: Value N
 *
 * Output:
 * No. of turns to get orignal string back
 *
 * */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Function to rotate the string x times
void rotateXTimes(string &word, int x){
    int length = word.size();
    reverse(word.begin(), word.end()-x);
    reverse(word.end()-x, word.end());
    reverse(word.begin(), word.end());
    cout<<word<<endl;
}

//Function to calculate no. of turns required
int turnsRequired(string &orig, int m, int n){
    string copy{orig};
    int turns = 0;
    do{
        rotateXTimes(copy, m);
        turns++;
        if(orig==copy)
            break;
        rotateXTimes(copy, n);
        turns++;
    }while(orig!=copy);
    return turns;
}

int main(){
    string word;
    int m,n;
    cin>>word>>m>>n;
    int turns = turnsRequired(word, m, n);
    cout<<turns<<endl;
    return 0;
}

