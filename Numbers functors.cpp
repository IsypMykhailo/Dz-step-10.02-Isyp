// Numbers functors.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class vector_functor {
private:

public:   
    
    int operator ()(vector<int> v) {
        const int n = 10;
        for (int i = 0; i < 10; i++)
            v.push_back(rand() % 10);
        vector<int>::iterator beg = v.begin();
        vector<int>::iterator end = v.end();
        while (beg != end)
            cout << *(beg++) << ' ';
        cout << "\nMax element: " << *std::max_element(v.begin(), v.end()) << endl;
        cout << "\nMin element: " << *std::min_element(v.begin(), v.end()) << endl;

        sort(v.begin(), v.end());
        cout << endl;
        cout << "Sort from min to max\n";
        for (int i=0; i<n; i++)
        {
            cout << v[i] << ' ';
        }
        cout << "\n\n";
        cout << "Sort from max to min\n";
        sort(v.begin(), v.end(), greater<int>());

        for (int i=0; i<n; i++)
        {
            cout << v[i] << ' ';
        }

        int inc;
        int red;
        cout << "\nEnter a const to increase the vector: ";
        cin >> inc;
        for(int i=0; i<=inc; i++) v.push_back(15);
        for (int i = 0; i < v.size(); i++) { cout << v[i] << " "; }
        cout << "\nEnter a const to reduce the vector: ";
        cin >> red;
        for (int i = 0; i <= red; i++) v.pop_back();
        for (int i = 0; i < v.size(); i++) { cout << v[i] << " "; }

        int search{};
        cout << "\nEnter a number to find and delete: ";
        cin >> search;
        auto found{ find(v.begin(), v.end(), search) };
        
        if (found == v.end())
        {
            std::cout << "Could not find " << search << '\n';
        }
        else
        {
            v.erase(found);
        }
        for (int i = 0; i < v.size(); i++) { cout << v[i] << " "; }
        return 0;
    }
    
};

int main()
{
    vector<int> v;
    vector_functor n;
    n(v);
}