#include<bits/stdc++.h>
using namespace std;

#define MAX_SIZE 3
int Lqueue[MAX_SIZE];
int front = -1, rear = -1;

int main(){

    int choice, item;
    cout<<"1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n";
    while(1){
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1: 
                if(rear == MAX_SIZE - 1){
                    cout<<"Overflow & Exit !!\n";
                    return 0;
                }else{
                    cout<<"Enter the element: ";
                    cin>>item;
                    if(front == -1){
                        front = rear = 0;
                    }else{
                        rear++;
                    }
                Lqueue[rear] = item;
                cout<<"Element inserted.\n";
                }
            break;

            case 2:
                if(front == -1){
                    cout<<"Underflow & Exit !!\n";
                    return 0;
                }else{
                    item = Lqueue[front];
                    if(front == rear){
                        front = rear = -1;
                    }else{
                        front++;
                    }
                    cout<<"Element deleted.\n";
                }
            break;

            case 3:
                if(front == -1){
                    cout<<"LQueue is empty.\n";
                }else{
                    cout<<"LQueue elements: \n";

                    for(int i = front; i<=rear; i++){
                        cout<<Lqueue[i]<<" ";
                    }
                    cout<<endl;
                }
            break;

            case 4:
                cout<<"Exit\n";
                return 0;
            
            default:
                cout<<"Invalid choice !!";
                return 0;
                
        }
    }

    return 0;
}