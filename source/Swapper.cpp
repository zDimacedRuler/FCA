/*
 * Program Name: Find the minimum no. of steps to convert a string into a
 * palindrome by swapping only two adjacent characters.
 *
 * Inputs:
 * input1: The string
 *
 * Output:
 * The min no. of steps to convert a string into palindrome, if not possible
 * then return -1
 *
 * */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Function to Count minimum swap
int countSwap(string s)
{
    // calculate length of string as n
    int n = s.length();

    // counter to count minimum swap
    int count = 0;

    // A loop which run till mid of
    // string
    for (int i = 0; i < n / 2; i++) {
        // Left pointer
        int left = i;

        // Right pointer
        int right = n - left - 1;

        // A loop which run from right
        // pointer towards left pointer
        while (left < right) {
            // if both char same then
            // break the loop.
            // If not, then we have to
            // move right pointer to one
            // position left
            if (s[left] == s[right]) {
                break;
            }
            else {
                right--;
            }
        }

        // If both pointers are at same
        // position, it denotes that we
        // don't have sufficient characters
        // to make palindrome string
        if (left == right) {
            return -1;
        }

        // else swap and increase the count
        for (int j = right; j < n - left - 1;
                j++) {
            swap(s[j], s[j + 1]);
            count++;
        }
    }
    return count;
}

int main(){
    string str;
    cin>>str;

    // Function calling
    int ans1 = countSwap(str);

    reverse(str.begin(),str.end());
    int ans2 = countSwap(str);

    cout<<max(ans1,ans2);
    return 0;
}

