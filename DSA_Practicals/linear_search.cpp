#include <iostream>
using namespace std;

int linear_search(int a[], int n, int x) 
{
    for (int i = 0; i < n; i++)
    {

        if (a[i] == x) 
        {
            return i;
        }
    }

    return -1; 
}

int main() {

   int n;
   int a[20]; 
    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    int x;
    cout << "Enter the target element to search for: ";
    cin >> x;
    

    int location = linear_search(a, n, x);
    

    if (location != -1) {
        cout << "Element " << x << " found at index: " << location << endl;
    } else {
        cout << "Element " << x << " not found in the array." << endl;
    }
    
    return 0;
}