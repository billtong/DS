#pragma once
#include<iostream>
#include<vector>

using std::vector;

template <typename T>
void swap(vector<T> & arr, int i, int j)
{
    T temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

template <typename T>
class CSort
{
public:
    static void SelectionSort(vector<T> & arr)
    {
        for(int i = 0; i < arr.size(); i++)
        {
            int select = i;
            for (int j = i + 1; j < arr.size(); j++)
            {
                if (arr[select] > arr[j])
                    select = j;
            }
            swap(arr, i, select);
        }
    }

    static void BinaryInsertionSort(vector<T> &arr)
    {
        for(int i = 1; i < arr.size(); i++)
        {
            int left = 0;
            int right = i;
            T target = arr[i];
            while (left < right)
            {
                int mid = (left + right) / 2;
                if (target >= arr[mid])
                    left = mid + 1;
                else
                    right = mid;
            }
            for (int j = i; j > right; j--)
                swap(arr, j, j-1);
        }
    }

    static void MergeSort(vector<T> &arr)
    {
        vector<T> temp(arr.size());
        CSort<T>::MergeSortRec(arr, 0, arr.size()-1, temp);
    }

private:

    static void MergeSortRec(vector<T> &arr, int start, int end, vector<T> temp)
    {
        if(end - start <= 8) {
            vector<T> v(&arr[start], &arr[end+1]);  //caution: [start, end+1)
            CSort<T>::BinaryInsertionSort(v);
            for(int i = start; i <= end; i++)
                arr[i] = v[i-start];
            return;
        }
        int middle = (start + end) / 2;
        CSort<T>::MergeSortRec(arr, start, middle, temp);
        CSort<T>::MergeSortRec(arr, middle + 1, end, temp);
        CSort<T>::Merge(arr, start, middle, end, temp);
    }


    static void Merge(vector<T> &arr, int start, int middle, int end, vector<T> temp)
    {
        int i, j, k;
        for(i = start, j = start, k = middle + 1; j <= middle && k <= end; i++)
        {
            if (arr[j] < arr[k])
                temp[i] = arr[j++];
            else
                temp[i] = arr[k++];
        }
        while(j <= middle)
            temp[i++] = arr[j++];
        while(k <= end)
            temp[i++] = arr[k++];
        for(i = start; i <= end; i++)
            arr[i] = temp[i];
    }
};

