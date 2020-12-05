/*
 * Program Name: Find no. of valid messsages, where each messge has be like
 * this: 1. begin with '.'
 *       2. end with '-'
 *       3. every '.' must have '-' after it
 *
 * Inputs:
 * input1: No. of messages
 * input2: Sequence of strings
 *
 * Output:
 * No. of valid messages
 *
 * */

#include<iostream>
#include<cstring>
using namespace std;

int countMessages(int n, char messgs[][50]){
    int valid = 0;
    for(int i=0; i<n; i++){
        int len = strlen(messgs[i]);
        cout<<messgs[i]<<endl;
        if(messgs[i][0] == '.' && messgs[i][len-1] == '-'){
            int dots= 0, dashs = 0, j=0;
            for(j=0; j<len; j++){
                if(messgs[i][j] == '.')
                    dots++;
                else if(messgs[i][j] == '-'){
                    if(dots>0)
                        dots--;
                    else
                        break;
                }
            }
            if(dots == 0 && j == len)
                valid++;
        }
    }
    return valid;
}

int main(){
    int input1;
    input1 = 3;
    char input2[input1][50];
    strcpy(input2[0], ".-.-.-");
    strcpy(input2[1], "...---.-");
    strcpy(input2[2], ".--...--.-");
    cout<<countMessages(input1, input2)<<endl;
    return 0;
}

