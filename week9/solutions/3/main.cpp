#include "Shop.cpp"

int main()
{
    Item i("Bql hlqb simit", 1.90);
    // std::cout << i;
    // std::cin >> i;
    // std::cout << i;

    Shop s;
    s.addItem(i);
    s.addItem({"Kiselo mlqko na baba", 1.65});
    s.addItem({"Olio Biser", 6});

    s.saveToFile("Shop.txt");
    std::fstream is("Shop.txt");
    Shop s2(is);
    is.close();
    s2.addItem({"Biskviti belvita", 1});
    std::cout << s2;
}