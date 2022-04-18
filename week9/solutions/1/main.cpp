#include "VehicleList.cpp"
#include <iostream>
int main()
{
    Registration r("C1234AB"), r1("XY1111YX");
    r = r1;
    std::cout << r.toString() << " =? " << r1.toString() << " " << std::boolalpha << (r == r1) << '\n';
    Vehicle v("C1234AB", "This is my audi.");

    int listSize;
    std::cout << "Enter list size\n";

    std::cin >> listSize;
    std::cin.ignore();

    VehicleList vl(listSize);
    for (size_t i = 0; i < listSize; i++)
    {
        std::string descr, regnum;
        bool isInserted = false;
        std::cout << "Enter regnum:";
        std::getline(std::cin, regnum);

        std::cout << "Enter description:";
        std::getline(std::cin, descr);
        while (!isInserted)
        {
            try
            {
                vl.insert(regnum.c_str(), descr.c_str());
                isInserted = true;
            }
            catch (const std::exception &e)
            {
                // here we need better messages in the exceptions we throw to know exactly what went wrong
                std::cerr << e.what() << '\n';
            }
        }
    }
    std::cout << "Enter regnum to search\n";
    std::string regnum;
    std::getline(std::cin, regnum);
    std::cout << vl.find(regnum.c_str());
}