#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
		mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
int main() {
	int i,j,m,n;
	cout<<"Enter number of elemnets to be added in tape:\n";
	cin>>n;
	int a[n];
	cout<<"Enter elements:\n";
	for(i=0;i<n;i++)
		cin>>a[i];
	mergeSort(a,0,n-1);
	cout<<"Enter number of tapes:\n";
	cin>>m;
	vector<vector<ll> >v(m);
	for(i=0;i<n;i++)	
		v[i%m].push_back(a[i]);
	for(i=0;i<m;i++)
	{
		cout<<"Tape "<<i+1<<" contains:";
		for(j=0;j<v[i].size();j++)
			cout<<v[i][j]<<" ";
		cout<<endl;		
	}	
	return 0;
}
