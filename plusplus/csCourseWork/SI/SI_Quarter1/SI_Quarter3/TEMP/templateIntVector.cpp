#include <iostream>
#include <cstdlib>

using namespace std;

// typedef int T;
typedef string T;
template <typename T>
class IntVector{
    
    private:
    unsigned sz;
    unsigned cap;
    T *data;
    
    public:
    IntVector(){
        sz = 0;
        cap = 0;
        data = NULL;
    }
    IntVector(unsigned size){
        sz = size;
        cap = size;
        data = new T[size]();
    }
    IntVector(unsigned size, T value){
        sz = size;
        cap = size;
        data = new T[size];
        for(int q = 0; q < size; ++q){
            data[q] = value;
        }
    }
    
    unsigned size() const{
        return sz;
    }
    unsigned capacity() const{
        return cap;
    }
    bool empty() const{
        if(sz > 0){
            return 0;
        }
        else{
            return 1;
        }
    }
    const T & at(unsigned index) const{
    //returns value at parameter index
        if(index >= sz){
            exit(1);
        }
        else{
            return this->data[index];
        }
    }
};

void testa1(){
    IntVector<int> qq;
    cout << "Test a1: default constructor" << endl;
    cout << "sz: " << qq.size() << endl << "cap: " <<
        qq.capacity() << endl;
    cout << "------------------------" << endl;
}
void testa2(){
    IntVector<int> qq(5);
    cout << "Test a2: construc with size" << endl;
    cout << "sz: " << qq.size() << endl << "cap: " <<
        qq.capacity() << endl;
        
    cout << "Value at 3: " << qq.at(3) << endl;
    cout << "------------------------" << endl;
}
void testa3(){
    IntVector<int> qq(100);
    cout << "Test a3: construc with size" << endl;
    cout << "sz: " << qq.size() << endl << "cap: " <<
        qq.capacity() << endl;
    cout << "Value at 3: " << qq.at(3) << endl;
    cout << "------------------------" << endl;
}
void testa4(){
    IntVector<int> qq(5,100);
    cout << "Test a4: construc with size and val" << endl;
    cout << "sz: " << qq.size() << endl << "cap: " <<
        qq.capacity() << endl;
    cout << "------------------------" << endl;
}
void testa5(){
    IntVector<int> qq(10,10);
    cout << "Test a5: construc with size and val" << endl;
    cout << "sz: " << qq.size() << endl << "cap: " <<
        qq.capacity() << endl;
    cout << "Value at 3: " << qq.at(3) << endl;
}

void testb1(){
    IntVector<string> qq;
    cout << "Test b1: default constructor" << endl;
    cout << "sz: " << qq.size() << endl << "cap: " <<
        qq.capacity() << endl;
    cout << "------------------------" << endl;
}
void testb2(){
    IntVector<string> qq(5);
    cout << "Test b2: construc with size" << endl;
    cout << "sz: " << qq.size() << endl << "cap: " <<
        qq.capacity() << endl;
        
    cout << "Value at 3: " << qq.at(3) << endl;
    cout << "------------------------" << endl;
}
void testb3(){
    IntVector<string> qq(100);
    cout << "Test b3: construc with size" << endl;
    cout << "sz: " << qq.size() << endl << "cap: " <<
        qq.capacity() << endl;
    cout << "Value at 3: " << qq.at(3) << endl;   
    cout << "------------------------" << endl;
}
void testb4(){
    IntVector<string> qq(5,"literal");
    cout << "Test b4: construc with size and val" << endl;
    cout << "sz: " << qq.size() << endl << "cap: " <<
        qq.capacity() << endl;
    cout << "------------------------" << endl;
}
void testb5(){
    IntVector<string> qq(10,"literal");
    cout << "Test b5: construc with size and val" << endl;
    cout << "sz: " << qq.size() << endl << "cap: " <<
        qq.capacity() << endl;
    cout << "Value at 3: " << qq.at(3) << endl;
}


int main(){
    
    testa1();
    testa2();
    testa3();
    testa4();
    testa5();
    
    testb1();
    testb2();
    testb3();
    testb4();
    testb5();
    
    return 0;
}