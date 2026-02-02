#include <bits/stdc++.h>
using namespace std;




class Solution
{

private:
    void merge(int arr[], int left, int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int *L = new int[n1];
        int *R = new int[n2];

        // transfar the data from the main array to the two sub arrays
        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left; // i is for left sub array , j is for right sub array , k is for main array and all three are pointers
        while (i < n1 && j < n2)
        {
            // check for which element is smaller and put that in the main array
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

        delete[] L;
        delete[] R;
    }

    void mergeSort(int arr[], int left, int right)
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;

            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            merge(arr, left, mid, right);
        }

        // Note: Cannot determine array size in mergeSort - size is passed as parameters
    }
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        nums1.reserve(nums1.size() + nums2.size());
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        mergeSort(nums1.data(), 0, nums1.size() - 1);

        int mid = nums1.size() / 2;
        if (nums1.size() % 2 == 0)
        {
            return (nums1[mid] + nums1[mid - 1]) / 2.0;
        }
        else
        {
            return nums1[mid];
        }
    }
};

int main()
{
    cout << "Hello World" << endl;
    Solution sol;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
