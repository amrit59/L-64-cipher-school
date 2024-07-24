#include<iostream>
using namespace std;

void merge(int *arr, int start, int end)
{
    //We need to actually merge the 2 sorted arrays which we have received
    //The array actually has been sorted till start to mid and also from mid to end but, now we need to merge(combine these)
    //It will be easier for us if there are the 2 sorted arrays seperately
    //So we create 2 sorted arrays

    int mid = (start+end)/2;
    int len1,len2;
    len1 = mid - start + 1;  //This is the size of the first sorted array present(from start to mid)
    len2 = end - mid;   //This is the size of the first sorted(from mid to end)

    //Creating the new arrays of size which we found 
    int *arr1 = new int[len1];
    int *arr2 = new int[len2];
    //Creating the arrays by copying the elements

    int main_arr_index;     //So that we can keep track of which element of the main array we can currently transversing
    main_arr_index = start;
    int i;
    for(i=0;i<len1;i++)
    {
        arr1[i] = arr[main_arr_index];
        main_arr_index++;
    }
    for(i=0;i<len2;i++)
    {
        arr2[i] = arr[main_arr_index];
        main_arr_index++;
    }
    //Now we have copied both the arrays, we need to completely sort the main array

    int index_1,index_2;
    index_1 = 0;
    index_2 = 0;
    main_arr_index = start;

    //We only need to increase the index of the elements which is less actually getting placed in the main array

    while(index_1<len1 && index_2<len2)
    {
        if(arr1[index_1] < arr2[index_2])
        {
            //This means the element in arr1 is lesser, so since we are sorting by increasing order, this will be placed in the arr
            arr[main_arr_index] = arr1[index_1];
            main_arr_index++;
            index_1++;
        }
        else
        {
            arr[main_arr_index] = arr2[index_2];
            main_arr_index++;
            index_2++;
        }
    }
    //Now this is till one of the array is completely iterated
    //After which you have to place the left over elements of the other array in the main array which is what we are doing below

    while(index_1<len1)
    {
        arr[main_arr_index] = arr1[index_1];
        main_arr_index++;
        index_1++;
    }
    while(index_2<len2)
    {
        arr[main_arr_index] = arr2[index_2];
        main_arr_index++;
        index_2++;
    }

    
}
void mergeSort(int *arr, int start, int end)
{
    //The recursion needs to have a base case :
    //What is base case : The base case is when there is only 1 element :

    if(start >= end)    //This implies there is only 1 element and now we cannot split it further
    {
        return;
    }
    int mid;
    mid = (start+end)/2;

    //we are also using the same code to sort the smaller code
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);

    //But after we have sorted the smaller arrays, we need to merge them to get the bigger arrays
    merge(arr,start,end);
}
int main()
{
    int size_arr;

    int arr[5] = {1,5,3,10,4};

    size_arr = 5;

    mergeSort(arr,0,size_arr-1);
    int k;
    for(k=0;k<size_arr;k++)
    {
        cout<<arr[k]<<" ";
    }
}
