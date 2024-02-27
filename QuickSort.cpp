//
// Created by Sebastian Chacon on 2/12/24.
//
#include "stuff.h"
#include "QuickSort.h"
using namespace std;

void quickSort(vector<Stuff>& s)
{
    int size = s.size();
    if( size < 2)
        return;

    int pivot = size - 1;
    int i = -1;

    for(int j = 0; j < pivot; ++j)
    {
        if(s[pivot] < s[j])
        {
            ++i;
            swap(s[i], s[j]);
        }
    }

    swap(s[i+1], s[pivot]);
    pivot = i + 1;

   vector<Stuff> a(s.begin(), s.begin() + pivot);
   vector<Stuff> b(s.begin() + pivot + 1, s.end());

    quickSort(a);
    quickSort(b);

    s.clear();
    s.insert(s.end(), a.begin(), a.end());
    s.push_back(s[pivot]);
    s.insert(s.end(), b.begin(), b.end());

}

void quickSort2(vector<Stuff>& s)
{
        if (s.size() < 2)
            return;
        int pivot;
        if (s.size() == 2)
        {
            if (s[0] < s[1])
                swap(s[0], s[1]);
            return;
        }
        int first = s.size() - 3;
        int second = s.size() - 2;
        int third = s.size() - 1;


        if ((s[second] < s[first] && s[third] < s[second]) || (s[second] < s[third] && s[first] < s[second]))
            pivot = second;
        else if ((s[first] < s[second] && s[third] < s[first]) || (s[first] < s[third] && s[second] < s[first]))
            pivot = first;
        else
            pivot = third;

        swap(s[pivot], s[s.size() - 1]);
        pivot = s.size() - 1;

        int i = -1;
        for (int j = 0; j < s.size(); ++j)
        {
            if (s[pivot] < s[j])
            {
                ++i;
                swap(s[j], s[i]);
            }
        }
        swap(s[pivot], s[i + 1]);
        pivot = i + 1;

        vector<Stuff> a(s.begin(), s.begin() + pivot);
        vector<Stuff> b(s.begin() + pivot + 1, s.end());

        quickSort2(a);
        quickSort2(b);

        s.clear();
        s.insert(s.end(), a.begin(), a.end());
        s.push_back(s[pivot]);
        s.insert(s.end(), b.begin(), b.end());

}

void quickSort3(vector<Stuff>& s, int num){

    if(s.size() < 2)
        return;

    int pivot = s.size() - 1;
    int i = -1;
    for(int j = 0; j < pivot; ++j)
        if (s[pivot] < s[j])
        {
            ++i;
            swap(s[j], s[i]);
        }


    swap(s[pivot], s[i + 1]);
    pivot = i + 1;

    vector<Stuff> a(s.begin(), s.begin() + pivot);
    vector<Stuff> b(s.begin() + pivot + 1, s.end());
    if(a.size() > num)
        quickSort3(a, num);

    else if(a.size() <= num)
    {
        for(int o = 1; o < a.size(); ++o)
        {
            Stuff temp = a[o];
            int j = o - 1;
            while (j >= 0 && a[j] < temp)
            {
                a[j + 1] = a[j];
                --j;
            }
            a[j+1] = temp;
        }

    }
    if(b.size() > num)
        quickSort3(b, num);

    else if(b.size() <= num)
    {
        for(int p = 1; p < b.size(); ++p)
        {
            Stuff temp = b[p];
            int j = p - 1;
            while (j >= 0 && b[j] < temp) {
                b[j+1] = b[j];
                --j;
            }
            b[j + 1] = temp;
        }
    }


    s.clear();
    s.insert(s.end(), a.begin(), a.end());
    s.push_back(s[pivot]);
    s.insert(s.end(), b.begin(), b.end());


}
void quickSort4(vector<Stuff>& s, float p)
{
    p = max(0.0f, min(1.0f, p));

    if (s.size() < 2)
        return;
    int pivot = s.size() - 1;
    int i = -1;
    for (int j = 0; j < pivot; ++j)
    {
        if (s[pivot] < s[j])
        {
            ++i;
            swap(s[j], s[i]);
        }
    }
    swap(s[pivot], s[i + 1]);
    pivot = i + 1;

    vector<Stuff> a(s.begin(), s.begin() + pivot);
    vector<Stuff> b(s.begin() + pivot + 1, s.end());

    if (a.size() < p * (double)s.size())
    {
        for (int o = 1; o < a.size(); ++o)
        {
            Stuff temp = a[o];
            int j = o - 1;
            while (j >= 0 && a[j] < temp)
            {
                a[j + 1] = a[j];
                --j;
            }

            a[j + 1] = temp;
        }
    }
    else
        quickSort4(a, p);

    if (b.size() < p * (double)s.size())
    {
        for (int n = 1; n < b.size(); ++n)
        {
            Stuff temp = b[n];
            int j = n - 1;
            while (j >= 0 && b[j] < temp)
            {
                b[j + 1] = b[j];
                --j;
            }
            b[j + 1] = temp;
        }
    }

    else
        quickSort4(b, p);

    s.clear();
    s.insert(s.end(), a.begin(), a.end());
    s.push_back(s[pivot]);
    s.insert(s.end(), b.begin(), b.end());
}


