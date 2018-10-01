// Dania Etienne
// stacks_for_regular_languages.h
// COP3530 Data Structures and Algorithms Project 1
// Evaluate if a given string is in a regular language L. To do this write a stack code yourself (Do not use the library stack).Be sure to take advantage of a stacks LIFO nature. You are not allowed to count the input string in any manner.Include the code for your stack as part of the source code you submit.

#ifndef stacks_for_regular_languages_h
#define stacks_for_regular_languages_h
#include <iostream>
#include"stack_p1.h"

using namespace std;

class stacks_for_regular_languages
{
public:
    bool L1(char * inputString);
    bool L2(char * inputString);
    bool L3(char * inputString);
    bool L4(char * inputString);
};



//L1: { w: w contains equal numbers of A's and B's (in any order) and no other characters}

bool stacks_for_regular_languages::L1(char * inputString){
    if(!*inputString){
        return false;
    }
    stack_p1<char> *S=new stack_p1<char>;  //Create empty stack
    while (*inputString){
        if( (*inputString!='A')&&(*inputString!='B')){
            return false;
        }
        if (S->isEmpty()){
            S->push(*inputString);
        }
        else if(S->peek()==*inputString){
            S->push(*inputString);
        }
        else{
            S->pop();
        }
        inputString++;
    }
    if (S->isEmpty()){// Check if stack is empty.
        return true;
    }
    else {
        return false;
    }
    return false; // Default
};


//L2: { w: w is of the form (A^n)(B^n), for some n >0 }

bool stacks_for_regular_languages::L2(char * inputString){
    if(!*inputString){
        return false;
    }
    stack_p1<char> *S=new stack_p1<char>;
    int flag=0;
    
    while (*inputString){
            if( (*inputString!='A')&&(*inputString!='B') ){
                return false;
            }
            if(*inputString=='A' && flag==1){
                return false;
            }
            if(*inputString=='B'&& S->isEmpty()){
                return false;
            }
            if (*inputString=='A'&& flag==0){
                    S->push(*inputString);
            }
            if(*inputString=='B'&& S->isEmpty()==false && flag==0){
                flag=1;
            }
            if(*inputString=='B'&& S->isEmpty()==false && flag==1){
                S->pop();
            }
                inputString++;
    }
    

    if (S->isEmpty()&&(flag==1)){// Check if stack is empty.
        return true;
    }
    return false; //Default
};

//L3: { w: w is of the form ((A^n)(B^n))^p, for some n, p >0 }

bool stacks_for_regular_languages::L3(char * inputString){
    if(!*inputString){
        return false;
    }
    stack_p1<char> *S=new stack_p1<char>;
    stack_p1<char> *S2=new stack_p1<char>;
    int flag=0;
    
    while (*inputString){
        if( *inputString!='A'&&*inputString!='B' ){
            return false;
        }
        if (S->isEmpty()&& *inputString=='A' && flag==0){//Begin by pushing an A
            S->push(*inputString);
        }
        if(S->isEmpty()==false && *inputString=='A'&& flag==0){ //Keep pushing A's
            S->push(*inputString);
        }
        if(S2->isEmpty() && *inputString=='B'&& flag==0){
            flag=1; //Needs to change at least once.
        }
        if(S2->isEmpty() && *inputString=='B'&& flag==1){
            S2->push(*inputString);
            if(S->isEmpty()){
                return false;
            }
            if(S->isEmpty()==false){
                S->pop();
            }
        }
        if (S2->isEmpty()==false && *inputString=='B'&& flag==1){
            S2->push(*inputString);
            if(S->isEmpty()){
                return false;
            }
            if(S->isEmpty()==false){
                S->pop();}
        }
        if(S->isEmpty() && *inputString=='A'&& flag==1){
            S->push(*inputString);
            if(S2->isEmpty()){
                return false;
            }
            if(S2->isEmpty()==false){
                S2->pop();
            }
        }
        if(S->isEmpty()==false && *inputString=='A'&& flag==1){
            S->push(*inputString);
            if(S2->isEmpty()){
                return false;
            }
            if(S2->isEmpty()==false){
                S2->pop();
            }
        }
        inputString++;
        }
    if (S->isEmpty()&&flag==1){// Check if stack is empty
        return true;
    }
    return false; //Default
};


//L4 { w: w is of the form ((A^n)(B^m))^p, for some m,n,p >0 }

bool stacks_for_regular_languages::L4(char * inputString){
    if(!*inputString){
        return false;
    }
    
    stack_p1<char> *A=new stack_p1<char>;
    stack_p1<char> *B=new stack_p1<char>;
    stack_p1<char> *P=new stack_p1<char>;
    int flag=0;
    bool pattern=false;
    
    while (*inputString){
        if (*inputString=='A'){
            if (flag==0){
                A->push(*inputString);
                P->push(*inputString);
            }
            else if (flag==1){
                pattern=true;
                        if (A->isEmpty()==false&& B->isEmpty()==false){
                            A->pop();
                        }
                        else if (A->isEmpty()&& B->isEmpty()==false ){
                            return false;
                        }
                        else if (A->isEmpty()&&B->isEmpty()){
                            A->push(*inputString);
                        }
                       else if (A->isEmpty()==false && B->isEmpty()){
                            A->push(*inputString);
                       }
                        
                    }
        }
        if ( *inputString=='B'){
            if(flag==0 && pattern==false){
                if(B->isEmpty()){
                    if (A->isEmpty()){
                        return false; // Makes sure we started with A.
                    }
                    else{
                        flag=1;
                        B->push(*inputString); //Keep pushing B's until pattern is found
                        P->push(*inputString);
                    }
                }
                
            }
            else if (flag==1){
                if (pattern==true){
                    if (A->isEmpty()==false&& B->isEmpty()==false){
                        B->push(*inputString);
                    }
                    else if (A->isEmpty()&& B->isEmpty()==false ){
                        B->pop();
                    }
                    else if (A->isEmpty()&&B->isEmpty()){
                        return false;
                    }
                    else if (A->isEmpty()==false && B->isEmpty()){
                        B->push(*inputString);
                    }
                }
                else if (pattern!=true){
                    B->push(*inputString);
                    P->push(*inputString);
                }
   
            }
      
        }
        if( *inputString!='A'&&*inputString!='B'){
            return false;
        }
        inputString++;
    }
 
    if (A->isEmpty()&& B->isEmpty()&& flag==1){
        return true;
    }
    
    if (A->isEmpty()==false && B->isEmpty()==false && flag==1){
        stack_p1<char> *C=new stack_p1<char>; //Create new stack C
 
        while (A->isEmpty()==false){
            C->push(A->pop()); //Push all A's onto stack C
        }
        while(B->isEmpty()==false){ //Push all B's onto stack C
             C->push(B->pop());
        }
        
        while(P->isEmpty()==false){
            if (P->peek()== C->peek()){
                P->pop();
                C->pop();
            }
            else{
                return false;
            }
        }
        if (C->isEmpty()==false){
            return false;
        }
        else {
            return true;
        }
 
    }
  
    return false; //default
    
};
   



#endif /* stacks_for_regular_languages_h */



