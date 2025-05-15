#include<bits/stdc++.h>
using namespace std;

#define MAX_SIZE 5
int Lstack[MAX_SIZE];
int top = -1;

void push(int item){
    if(top == MAX_SIZE){
        cout<<"Stack Overflow!!"<<endl;
    }else{
        Lstack[++top] = item;
        cout<<"Element inserted."<<endl;
    }
}

void pop(){
    if(top==-1){
        cout<<"Stack Underflow!!"<<endl;
    }else{
        int item = Lstack[top--];
        cout<<"Element deleted"<<endl;
    }
}

void display(){
    if(top==-1){
        cout<<"The syack is empty"<<endl;
    }else{
        cout<<"Stack elements: ";
        for(int i=0; i<=top; i++){
            cout<<Lstack[i]<<" ";
        }
        cout<<endl;
    }
}


int main(){

    int choice, item;
    cout<<"1.Push\n2.Pop\n3.Displaay\n4.Exit\n";
    
    while(1){
        cout<<"Enter you choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter value to push: ";
                cin>>item;
                push(item);
            break;

            case 2:
                pop();
            break;

            case 3:
                display();

            break;

            case 4:
                cout<<"Exit";
                return 0;

            default:
                cout<<"Enter valid choice!!";
                return 0;
        
        }
    }

    return 0;
}