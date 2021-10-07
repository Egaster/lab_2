#ifndef STROPHOID_H_
#define STROPHOID_H_
#include <cmath>
#include <iostream>

namespace Project2 {
    class Strophoid {
    private:
        double a;
    public:
        Strophoid(double parameter = 1.0); // параметр а
        ~Strophoid();
        Strophoid& setA(double aa); // переустанав.
        double getA() const{ return a; }; // возвр.
        bool correctGetInt(double &a) const;
        double getNum() const;
        double findY(double x) const;
        double dist(double x) const;
        double curv_rad() const{
            std::cout << "\nRadius of curvature in (0,0) is ";
            std::cout<<fabs(a) * sqrt(2) << std::endl; // радиус кривизны;
            return fabs(a) * sqrt(2);
        }
        double S(double f()) const;
        double V()const;
        const char* formula() const;

    };
    void D_find_Y(Strophoid U);
    void D_dist(Strophoid U);
    void D_set(Strophoid U);
    double plus();
    double minus();
    void funcChangeA(Project2::Strophoid line);
    int dialog(const char *msgs[], int menuCount);
}


#endif