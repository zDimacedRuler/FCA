/*
 * Program Name: Find min no. of points one should pick to reduce all the
 * points to min no. of points
 *
 * Inputs:
 * input1: X, no. of sets
 * input2: Array consisting X pairs
 *
 * Output:
 * Min no. of points
 *
 * */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Pair{
    int x;
    int y;
};

int minimumPoints(int x, int pairs[][2]){
    vector<Pair> sets;
    //stucture to hold different intersecting pairs
    sets.push_back({pairs[0][0], pairs[0][1]});
    for(int i=1;i<x;i++){
        bool added= false;
        for(auto itr= sets.begin(); itr!= sets.end(); itr++){
            //find intersecting pairs
            if(pairs[i][0]<= itr->y){
                //perform intersection between the two pairs
                if(pairs[i][1]< itr->y)
                    itr->y= pairs[i][1];
                if(pairs[i][0]> itr->x)
                    itr->x = pairs[i][0];
                added= true;
            }
        }
        //Add a new pair, If no intersection occured
        if(!added)
            sets.push_back({pairs[i][0], pairs[i][1]});
    }

    //print each intersecting pair
    for(Pair p : sets)
        cout<<"x:"<<p.x<<" y:"<<p.y<<endl;

    //no. of intersecting pair is the result
    return sets.size();
}

int main(){
    int i, j, input1;
    cin>>input1;
    int input2[input1][2];
    for(i=0; i<input1; i++)
        for(j=0; j<2; j++)
            cin>>input2[i][j];
    cout<<minimumPoints(input1, input2)<<endl;
    return 0;
}

