#include <iostream>
#include <sstream>

using namespace std;

class SimpleVector{
    private: // the base address of the array
             int *item;
             // size of the array
             int size;
             // number of elements in the array
             int numElements;
    public:
       // Overloaded constructor
       SimpleVector(int size){
            this->size = size;
            this->numElements = 0;
            this->item = new int[this->size];

       }
       // default constructor
       SimpleVector():SimpleVector(10){

       }
       void pushBack(int);
       int getSize() const;
       int getNumElements() const;
       int& operator[](int);
       friend ostream& operator << (ostream &, const SimpleVector&);
       ~SimpleVector(){
           delete [] item;
           cout << "Destructor called..." << endl;
       }
       SimpleVector& operator=(const SimpleVector& rho);
       SimpleVector(const SimpleVector& rho);
};

SimpleVector::SimpleVector(const SimpleVector& rho){
    this->item = new int[rho.size];
    this->size = rho.size;
    this->numElements = rho.numElements;
    for(int i = 0; i < this->size; ++i){
        this->item[i] = rho.item[i];
    }

}

SimpleVector& SimpleVector::operator=(const SimpleVector& rho){
    if (this != &rho){
        delete [] this->item;
        this->item = new int[rho.size];
        this->size = rho.size;
        this->numElements = rho.numElements;
        for(int i = 0; i < this->size; ++i){
            this->item[i] = rho.item[i];
        }
    }

}
ostream& operator << (ostream &out, const SimpleVector& sv){
    out << "[";
    for(int i = 0; i < sv.numElements; ++i){
        if (i == sv.numElements - 1)
            out << sv.item[i];
        else
            out << sv.item[i] << ", ";

    }
    out << "]";
    return out;
}

int& SimpleVector::operator[](int index){
        return item[index];
}

int SimpleVector::getSize() const{
    return this->size;
}
int SimpleVector::getNumElements() const{
    return this->numElements;
}


void SimpleVector::pushBack(int v){
    if (numElements >= size){
        // double  the size of the array
        // keeping the existing elements intact
        int newSize = size * 2;
        int *temp = new int [newSize];
        for(int i = 0; i < numElements; i++){
            temp[i] = item[i];
        }
        delete [] item;
        item = temp;
        this->size = newSize;
    }

    item[numElements++] = v;
}

void process(SimpleVector sv){
    sv.pushBack(1);
    sv.pushBack(2);
}

int main()
{
   SimpleVector sv1(3);
   sv1.pushBack(10);
   sv1.pushBack(20);
   SimpleVector sv2(sv1);

   //sv2 = sv1; // sv2.operator=(sv1)
   //sv1 = sv1;
   process(sv2);


   return 0;
}
