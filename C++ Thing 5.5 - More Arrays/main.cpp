//
//  main.cpp
//  C++ Thing 5.5 - More Arrays
//
//  Created by William Holt on 10/2/13.
//  Copyright (c) 2013 William Holt. All rights reserved.
//

#include <iostream>
using namespace std;

void readArray(int arr[], int length)
{
    for (int count = 0; count<length; count++)
    {
        cout << "Enter number: ";
        cin >> arr[count];
    }
}

int getMaxPos(int arr[], int length)
{
    int max = 0;
    for (int count = 0; count < length; count++)
    {
        if (arr[max] < arr[count])
        {
            max = count;

        }
    }
    return max;
}

int mode (int arr[], int length)
{
    int count[1000];
    for (int i = 0; i < length; i++)
    {
        count[i] = 0;
        int j = 0;
        while ((j < i) && (arr[i] != arr[j]))
        {
            if (arr[i] != arr[j])
            {
                ++j;
            }
        }
        ++(count[j]);
    }
    int maxrepeat = 0;
    for (int i = 1; i < length; ++i)
    {
        if (count[i] > count[maxrepeat]) maxrepeat = i;
    }
    return arr[maxrepeat];
}


int main(int argc, const char * argv[])
{
    int size;
    cout << "How big do you want your array?: ";
    cin >> size;

    if (size >= 51)
    {
       cout << "Enter a size that is less than 51!" << endl;
       cout << "Enter your new size: " << endl;
       cin >> size;
    }

    int data[size];

    readArray(data, size);

    cout << "The max value " << "(" << data[getMaxPos(data, size)] << ") occupies space # " << getMaxPos(data, size) << " (starting from zero!)" << endl;
    cout << "The most common value is: " << mode(data, size) << endl;

    return 0;
}
