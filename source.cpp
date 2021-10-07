#include "Strophoid.h"
#include <strstream>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <exception>
#include <cmath>
double const PI = 3.1415926535;

namespace Project2 {

    Strophoid::Strophoid(double par){

        double A;
        std::cout << "Enter values for the parameter(a)\n";
        std::cin >> A;

        if(A == 0)
            throw std::logic_error("Invalid parameter");
        a = A;
    }
    Strophoid::~Strophoid() = default;

    double plus() { std::cout << "\nLoop area is " <<std::endl; return 2 + PI / 2; }
    double minus() {        std::cout << "\nArea between asymptote and branches of the strophoid is "<< std::endl;  return 2 - PI / 2; }


    Strophoid& Strophoid::setA(double par) { // установка переменной
        if (par == 0)
            throw std::logic_error("Invalid parameter");
        a = par;
        return *this;
    }

    bool Strophoid::correctGetInt(double &a) const {
        std::cin >> a;
        if (!std::cin.good()) { // проверка на правильность ввода
            std::cin.clear();
            std::cin.ignore();
            return false;
        } else {
            return true;
        }
    }

    double Strophoid::getNum() const{
        double number;
        while (!correctGetInt(number)) { ///!!!!!!!!!!!!
            std::cout << "You are wrong or wrong number! Enter number again!" << std::endl;
        }
        return number;
    }

    double Strophoid::dist(double x) const {
        if(x >= 360 || x < 0)
            throw std::logic_error("Invalid angle");
        x = x * PI / 180;
        if (x == PI/2 || x == 3*PI/2)
            throw std::logic_error("Invalid angle");
        double res = (-1) * a * cos(2 * x) / cos(x);
        return std::abs(res);
    }

    void Strophoid::S(double f()) const{
        std::cout<<a * a * f();
    }

    double Strophoid::V() const {
        double r = a * a * a * PI * (2 * log(2) - 4.0 / 3.0);
        if(r<0){
            r = r* (-1);
        }
        std::cout << "\nThe volume of figure produced by rotating the loop around the Ox axis is : "<< r;
        std::cout << std::endl; // объем при вращении
    }

    double Strophoid::findY(double x) const {
        if (a > 0)
            if (x >= a || x < (-1)*a)
                throw std::logic_error("Invalid x");
        if (a < 0)
            if (x > (-1)*a || x <= a)
                throw std::logic_error("Invalid x");
        if (a == x || (-1) * a == x)
            return 0;
        return x * sqrt((a + x) / (a - x));
    }


    void D_dist(Strophoid STR){
        int fl3;
        int ptr3;

        do {
            std::cout << "\nEnter angle to calculate the distance from the center in polar coordinate system: "
                      << std::endl;
            double x;
            x = STR.getNum();
            ptr3 = std::cin.good();
            if (!ptr3)
                continue;
            try {
                double res = STR.dist(x);
                std::cout << "L = " << res << std::endl;;
            }
            catch (std::logic_error &ex) {
                std::cout << ex.what() << std::endl;
            }

            std::cout << "Press 1 for enter x or press 0\n";
            fl3 = STR.getNum();

        } while (fl3);
    }

    void D_find_Y(Strophoid STR){
        int fl2;
        int ptr2;

        do {

            std::cout << "\nEnter x to calculate value y(x): " << std::endl;
            double x;
            x = STR.getNum();
            ptr2 = std::cin.good();
            if (!ptr2)
                continue;
            try {
                double res = STR.findY(x); // нахождение у по х
                std::cout << "y1 = " << res;
                if (res != 0)
                    std::cout << ", y2 = " << (-1) * res;
                std::cout << std::endl;
            }
            catch (std::logic_error &ex) {
                std::cout << ex.what() << std::endl;
            }

            std::cout << "Press 1 for enter x or press 0\n";
            fl2 = STR.getNum();

        } while (fl2);

    }

    void Strophoid::formula() const {
        std::cout << "\nYour strophoid is: " << std::endl;
        const char* s1 = "y ^ 2 * (x - ) + x ^ 2 * (x + ) = 0\n"; // создаем шаблон
        int l = strlen(s1) + 1;
        char num[20];
        sprintf(num, "%.2f", a);
        l += strlen(num)*2;
        char* s = new char[l];
        if (a < 0) {
            double val = (-1)*a;
            sprintf(s, "y ^ 2 * (x + %.2f)", val);
            int k = strlen(s);
            sprintf(s + k, " + x ^ 2 * (x - %.2f) = 0", val);
        }
        else {
            sprintf(s, "y ^ 2 * (x - %.2f)", a);
            int k = strlen(s);
            sprintf(s + k, " + x ^ 2 * (x + %.2f) = 0", a);
        }
        std::cout << s << std::endl; // вывод формулы
        delete[] s;// очищение буфера s

    }

    void D_set(Strophoid STR){
        double A;
        int fl2;
        int fl1;
        int fl4;
        std::cout << "If you right new parametr press 1 else press 0\n";
        fl4 = STR.getNum();
        if (fl4) {
            A = 0;
            do {
                std::cout << "\nEnter new parametr to continue: " << std::endl;
                A = STR.getNum();
                fl2 = 0;
                if (std::cin.good()) {
                    try {
                        STR.setA(A);
                    }
                    catch (std::logic_error &ex) {
                        std::cout << ex.what() << std::endl;
                        fl2 = 1;
                        continue;
                    }
                } else
                    fl1 = 0;
            } while (fl2);
        } else
            return;

    }


//    void funcChangeA(Strophoid line) {
//
//        double a;
//        std::cout << "Enter values for the parameter(a)\n";
//        std::cin >> a;
//        line.setA(a);
//    }
}

