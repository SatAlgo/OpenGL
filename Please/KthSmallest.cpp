#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=0; i<n-1; i++){
        int mini=i;
        for(int j=i; j<n; j++){
            if(arr[j]<arr[mini]){
                mini = j;
            }
        }
        swap(arr[i],arr[mini]);
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    for(int i=0; i<arr.size()-1; i++){
        if(arr[i]==arr[i+1]){
            arr.erase(arr.begin()+i);
            i--;
        }
    }

    n = arr.size();

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int k;
    cin>>k;

    cout<<arr[k]<<endl;

    return 0;
}