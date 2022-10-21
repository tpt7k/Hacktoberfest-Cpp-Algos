#include <bits/stdc++.h>
using namespace std;

int binarySearch(int *input, int n, int val)
{
    int start = 0;
    int end = n - 1;
    int mid;

    while (start <= end)
    {
        mid = (start + end) / 2;

        if (input[mid] == val)
        {
            return mid;
        }
        else if (input[mid] < val)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}
int main()
{

    int size;
    cout << "Enter the size of the array";
    cin >> size;
    int *input = new int[size];
    cout << "Enter the elements of array: ";
    for (int i = 0; i < size; ++i)
    {
        cin >> input[i];
    }

    char ch;
    do
    {
        int val;
        cout << "\nEnter the element you want to search? ";
        cin >> val;
        int ret = binarySearch(input, size, val);
        if (ret != -1)
            cout << "Element found at position: " << ret + 1 << endl;
        else
            cout << "Element not found " << endl;
        cout << "Do you want to search other element(Y or N): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    delete[] input;
    return 0;
}