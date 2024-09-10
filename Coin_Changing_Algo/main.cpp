#include <iostream>
using namespace std;
int main(){
    int n,cost;
    int c[3] = {2,5,10};
    cin>>n;
    cin>>cost;
    int arr[n+1][cost+1];

    for(int i=0;i<n;i++){
        for(int j=0;j<cost;j++){
            arr[i][0] = 1;
            if(j<c[i]){
                arr[i][j] = arr[i-1][j];
            }
            else{
                arr[i][j] = arr[i-1][j];
                arr[i][j-c[i]];
            }
        }
    }

    cout<<arr[3][cost];
}