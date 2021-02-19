#include <iostream>
using namespace std;

int findp(int a[],int start, int end){
    if(start == end){
        return start;
    }
    int p1, p2;
    int mid = (start+end)/2;
    if(a[start]<a[end]){
        return start;
    }
    if(a[start]<a[mid]){
        return findp(a,mid+1,end);
    }
    if(a[start]>a[mid]){
        return findp(a,start,mid);
    }
    if(a[end]<a[mid]){
        return findp(a,mid+1,end);
    }
    p1=findp(a,start,mid);
    p2=findp(a,mid+1,end);
    if(a[p1]<=a[p2]){
        return p1;
    }
    return p2;
}

int bin_search(int a[], int start, int end, int k){
    if(k<a[start] || k>a[end]){
        return -1;
    }
    if(a[start]==k){
        return start;
    }
    if(a[end]==k){
        return end;
    }
    int mid = (start+end)/2;
    if(k<=a[mid]){
        return bin_search(a,start,mid,k);
    }
    return bin_search(a,mid+1,end,k);
}

int searchInRotatedArray(int a[],int n, int k){
    int p=findp(a,0,n-1);
    if(p==0){
        return bin_search(a,0,n-1,k);
    }
    int first=bin_search(a,0,p-1,k);
    if(first>=0){
        return first;
    }
    return bin_search(a,p,n-1,k);
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,i,k;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
        cin>>a[i];
        cin>>k;
        cout<< searchInRotatedArray(a,n,k)<< endl;
    }
	return 0;
}