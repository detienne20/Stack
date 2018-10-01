
//  main.cpp
//  Stack_For_Regular_Languages
// COP3530 Data Structures and Algorithms Project 1
// Evaluate if a given string is in a regular language L. To do this write a stack code yourself (Do not use the library stack).Be sure to take advantage of a stacks LIFO nature. You are not allowed to count the input string in any manner.Include the code for your stack as part of the source code you submit.

#include <iostream>
#include "stack_p1.h"
#include "stacks_for_regular_languages.h"

using namespace std;



int main()
{
    
    
    /*-------- Testing stack_p1 ------- */
    
    stack_p1<int> s; //defining new stack
    
    s.push(10);
    s.push(20);
    
    cout<<s.peek()<<" ";
    while(!s.isEmpty())
    {
        cout<<s.pop()<<" ";
    }
    cout<<s.isEmpty()<<" ";
    
    //Output - 20 20 10 1
    
    /*-------- End of Testing stack_p1 ------- */
    
    /*-------- Testing L1, L2, L3, L4 -------*/
    
    char arr1[10]="ABABBA";
    char arr2[10]="AAABBB";
    char arr3[10]="ABAB";
    char arr4[10]="ABBABB";
    
    stacks_for_regular_languages obj;
    
    cout<<obj.L1(arr1) <<" ";
    cout<<obj.L2(arr2) <<" ";
    cout<<obj.L3(arr3) <<" ";
    cout<<obj.L4(arr4) <<" ";
    
    //Output - 1 1 1 1
    
    cout<<obj.L2(arr3) <<" ";
    cout<<obj.L3(arr4) <<" ";
    
    //Output - 0 0
    
    /*-------- End of Testing L1, L2, L3, L4 ------- */
    
    return 0;
    
    
}



