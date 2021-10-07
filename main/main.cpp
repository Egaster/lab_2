#include <Strophoid.h>
#include <iostream>
int main(){
    int choice;
    double A;
    std::cout << "Enter values for the parameter(a)\n";
    std::cin >> A;
    Project2::Strophoid STR(A);
    int fl1 = 1;
    char *s = nullptr;

    do {
        std::cout<<std::endl;
        std::cout<<std::endl;

        std::cout<<"1.Вывод формулы\n";
        std::cout<<"2.Вернуть радиус кривизны в узловой точке.\n";
        std::cout<<"3.Вернуть площадь петли AOM1.\n";
        std::cout<<"4.Вернуть площадь между ветвями OU’, OV’ и асимптотой\n";
        std::cout<<"5.Вернуть объем тела, произведенного вращением петли около оси OX.\n";
        std::cout<<"6.Вернуть координату y в декартовой системе координат, принадлежащую строфоиде в зависимости от x.\n";
        std::cout<<"7.Вернуть расстояние до центра в полярной системе координат в зависимости от угла.\n";
        std::cout<<"8.Задание новых параметров линии.\n";
        std::cout<<"0.Выход\n";

        choice = STR.getNum();
        switch (choice) {

            case 1:
                STR.formula();
                break;

            case 2:
                STR.curv_rad();
                break;

            case 3:
                STR.S(Project2::minus);// площадь петли
                break;


            case 4:
                STR.S(Project2::plus);
                break;


            case 5:
                STR.V();
                break;


            case 6:
                Project2::D_find_Y(STR);
                break;

            case 7:
                Project2::D_dist(STR);
                break;


            case 8:
                D_set(STR);
                break;


            case 0:
                break;

                std::cin.clear();


            default:
                std::cout<<"Неверно выбран пункт меню\n";
                break;

        }

    } while (choice != 0);


    return 0;
}

