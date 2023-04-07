// 2_ADDRESS_SORT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <stdio.h>
#include <algorithm>

class address
{
public:

    std::string outAddress();
    void setINFO(std::string k, std::string j, int u, int x) {
        city_name = k;
        street_name = j;
        house_number = u;
        apartment_number = x;
    }
    std::string getCityName() const {
        return city_name;
    }
   
private:

    std::string city_name;
    std::string street_name;
    int house_number;
    int apartment_number;
};


std::string address::outAddress()
{
    return city_name + ", " + street_name + ", " + std::to_string(house_number) + ", " + std::to_string(apartment_number);
}

void sortAddresses(address* mas, int N)
{
    std::sort(mas, mas + N, [](const address& a, const address& b) {
        return a.getCityName() < b.getCityName();
        });
}

int main()
{
    setlocale(LC_ALL, "RU");

    std::string a, b;
    int c = 0; int d = 0;

    std::ifstream fin("in.txt");


    if (fin.fail())
    {
        std::cout << "Error" << std::endl;
    }
    else if (fin.is_open())
    {
        std::ofstream fout("out.txt", std::ios::trunc);
        std::cout << "info from in.txt:" << std::endl;
        int N;
        fin >> N;

        std::cout << N << std::endl;
        fout << N << std::endl;

        address* mas = new address[N];

        for (int i = 0; i < N; i++)
        {
            fin >> a;
            fin >> b;
            fin >> c;
            fin >> d;

            mas[i].setINFO(a, b, c, d);
        }

       sortAddresses(mas, N);

        for (int i = 0; i < N; i++)
        {
            fout << mas[i].outAddress() << std::endl;
            std::cout << mas[i].outAddress() << std::endl;
        }
        
    fin.close();
        delete[]mas;
    }
    return 0;


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
