#include <iostream>
#include <string>
#include <cstdlib>
#include <typeinfo>

using namespace std;

template <typename T=float, typename T2 = int>
class matrix
{
private:
    T** M;
    T2** M2;
    int x;
    int y;
    string matrixName;

public:
    //Default constructor
    matrix()
    {
        x,y = 0;
        matrixName = "";
        M = nullptr;
        M2 = nullptr;
    }
    matrix(string input_matrixName)
    {
        x,y = 0;
        matrixName = input_matrixName;
        M = nullptr;
        M2 = nullptr;
    }
    //Constructor
    matrix(const int input_x, const int input_y, string input_matrixName)
    {
        x = input_x;
        y = input_y;
        matrixName = input_matrixName;

        M = (T**) new T*[x];
        for (int i=0; i<x; i++)
            M[i] = (T*)new T[y];
        for (int i=0; i<x; i++){
            for (int j=0; j<y; j++)
                M[i][j]=0;
        }
        M2 = (T2**) new T2*[x];
        for (int i=0; i<x; i++)
            M2[i] = (T2*)new T2[y];
        for (int i=0; i<x; i++){
            for (int j=0; j<y; j++)
                M2[i][j]=0;
        }
    }
    //Copy constructor
    matrix(const matrix& _matrix)
    {
        x = _matrix.x;
        y = _matrix.y;

        M = (T**) new T*[x];
        for (int i=0; i<x; i++)
            M[i] = (T*)new T[y];
        for (int i=0; i<x; i++){
            for (int j=0; j<y; j++)
                M[i][j]=_matrix.M[i][j];
        }
        M2 = (T2**) new T2*[x];
        for (int i=0; i<x; i++)
            M2[i] = (T2*)new T2[y];
        for (int i=0; i<x; i++){
            for (int j=0; j<y; j++)
                M2[i][j]=_matrix.M2[i][j];
        }
    }
    //destructor
    ~matrix()
    {
        if(y>0){
            for (int i=0; i<x; i++)
                delete[] M[i];
        }
        if (x>0)
            delete[] M;
    }

    randomize()
    {
        for (int i=0; i<x; i++)
            M[i] = (T*)new T[y];
        for (int i=0; i<x; i++){
            for (int j=0; j<y; j++)
                M[i][j]=rand() % 1000 ;
        }
    }

    matrix operator=(const matrix& _matrix)
    {
        if(y>0){
            for (int i=0; i<x; i++)
                delete[] M[i];
        }
        if (x>0)
            delete[] M;

        if(y>0){
            for (int i=0; i<x; i++)
                delete[] M2[i];
        }
        if (x>0)
            delete[] M2;

        x = _matrix.x;
        y = _matrix.y;
        
        M = (T**) new T*[x];
        for (int i=0; i<x; i++)
            M[i] = (T*)new T[y];
        for (int i=0; i<x; i++){
            for (int j=0; j<y; j++){
                M[i][j]=_matrix.M[i][j];
                cout << typeid(reinterpret_cast<T2>(_matrix.M2[i][j])).name();
            }
        }
        M2 = (T2**) new T2*[x];
        for (int i=0; i<x; i++)
            M2[i] = (T2*)new T2[y];
        for (int i=0; i<x; i++){
            for (int j=0; j<y; j++){
                M2[i][j]=_matrix.M2[i][j];
                M2[i][j]=reinterpret_cast<T2>(_matrix.M2[i][j]);
            }
        }
        //cout << typeid(M2[0][0]).name();

        return *this;
    }

    

    matrix operator+(matrix& m)
    {
        x = m.x;
        y = m.y;
        matrix temp(x, y, "");
        if(y>0){
            for (int i=0; i<x; i++)
                delete[] temp.M[i];
        }
        if (x>0)
            delete[] temp.M;

        temp.M = (T**) new T*[x];
        for (int i=0; i<x; i++){
            temp.M[i] = (T*)new T[y];
            for (int j=0; j<y; j++)
                temp.M[i][j] = M[i][j] + m.M[i][j];
        }
        return temp;
    }

    matrix operator*(const matrix& m)
    {

        x = m.x;
        y = m.y;
        matrix temp(x, y, "");
        if(y>0){
            for (int i=0; i<x; i++)
                delete[] temp.M[i];
        }
        if (x>0)
            delete[] temp.M;

        temp.M = (T**) new T*[x];
        for (int i=0; i<x; i++){
            temp.M[i] = (T*)new T[y];
            for (int j=0; j<y; j++)
                temp.M[i][j] = M[i][j] * m.M[i][j];
        }
        return temp;
    }

    friend ostream& operator<<(ostream &os, const matrix<T> &m)
    {
        os << m.matrixName << ":" << endl;
        os << "[";
        for(int i=0; i<m.x; i++){
            for (int j=0; j<m.y; j++)
                if (j != m.y-1)
                    os << m.M[i][j] << " ";
                else
                    os << m.M[i][j] << "]";
            os << endl;
        }
        return os;
    }
};


int main(){
    // constructor

    matrix<float> A(4, 4, "myAMatrix"); // ¡°myAMatrix¡± means the name of matrix
    matrix<float> B(4, 4, "myBMatrix"); // ¡°myBMatrix¡± means the name of matrix


    // randomize entries
    A.randomize();
    B.randomize();

    matrix<float> C("myCMatrix");
    C = A;

    // overloaded operator* for matrix-matrix multiplication
    matrix<float> D ("myDMatrix");
    D = A * B;

    // overloaded operator| for left matrix division
    matrix<int> E ("myEMatrix");
    //E = A + B;

    // stream out to standard out
    cout << A << endl;
    cout << B << endl;
    cout << C << endl;
    cout << D << endl;
    //cout << E << endl;
    
    float f = 1;
    int i = 0;
    cout << typeid(f).name() << endl;
    //cout << typeid((typeid(f).name())).name();
    bool flag = typeid(f).name() == typeid(i).name();
    return 0;
}
