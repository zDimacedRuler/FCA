/*
 * Program Name: Find the No. of words that remain the same after shifting
 * them each k times.
 *
 * Inputs:
 * input1: String of words
 * input2: k, no. of times that rotation happens
 *
 * Output:
 * No. of words that remain the same
 *
 * */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Function to rotate the string x times
string rotateXTimes(string word, int x){
    int length = word.size();
    reverse(word.begin(), word.end()-x);
    reverse(word.end()-x, word.end());
    reverse(word.begin(), word.end());
    cout<<word<<endl;
    return word;
}

int rotateWords(string &input1, int k){
    int result = 0;
    istringstream stream{input1};
    string tmp;
    vector<string> words;
    //tokenize the input into seperate words wrt ' '
    while(getline(stream, tmp, ' ')){
        words.push_back(tmp);
    }

    for(string word : words){
        if(word == rotateXTimes(word, k))
            result++;
    }
    return result;
}

int main(){
    string input1;
    int input2;
    getline(cin, input1);
    cin>>input2;
    cout<<rotateWords(input1, input2)<<endl;
    return 0;
}

