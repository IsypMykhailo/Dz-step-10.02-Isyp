// country_city.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

class country {
private:
    vector<string> vs;
public:
    void load() {
        ifstream in("text.txt");        
        string s;
        while (in >> s) {
            vs.push_back(s);
        }

        for (int i = 0; i < vs.size(); i++) {

            cout << vs[i] << endl;
        }
    }
    void search() {
        load();
        auto found{ find_if(vs.begin(), vs.end(),
                           [](string str) 
                           {
                             return (str.find("(Belarussia)") != string::npos);
                           }) };

        if (found == vs.end())
        {
            cout << "Nothing found\n";
        }
        else
        {
            std::cout << "\nFound " << *found << '\n';
        }
    }
    void replace_() {
        load();
        string country1 = "(French)Paris";
        string country2 = "(Turkey)Stambul";
        replace(vs.begin(), vs.end(), country1, country2);
        ofstream out("text.txt");
        for (int i = 0; i < vs.size(); i++) { out << vs[i]; }
    }
    void add(string str[10]) {
        ofstream out("text.txt", ios::app);
        out << "\n";
        for (int i = 0; i < 10; i++) { out << str[i] << "\n"; }
    }
    void delete_() {
        vs.erase(vs.begin() + 4);
        ofstream out("text.txt");
        for (int i = 0; i < vs.size(); i++) out << vs[i];
    }
    void count() {
        cout << "Amount of cities: " << vs.size() << endl;
    }

};

int main()
{
    string str[10]{ "(France)Paris", "(England)London", "(Belarussia)Minsk", "(Georgia)Tbilisi", "(Azerbaijan)Baku", "(UAE)Abu-Dabi", "(USA)Washington", "(Canada)Ottawa", "(Mexico)Mehico", "(Spain)Madrid" };
    country c;
    c.load();
    c.add(str);
    c.search();
    c.replace_();
    c.delete_();
    c.count();
}