#include <iostream>

using namespace std;

template<typename T>
class Test{
    private:
         T x, y;
    public:
        Test(T x, T y);
        T getSum();

};

template <typename T>
Test<T>::Test(T x, T y){
    this->x = x;
    this->y = y;
}

template<typename T>
T Test<T>::getSum(){
    return x + y;
}


int main()
{
    Test<int> t1(10, 20);
    Test <string> t2("First", "Second");

    cout << t1.getSum() << endl;
    cout << t2.getSum() << endl;

    return 0;
}
