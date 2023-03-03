using namespace std;

class Mem1{
public:
    explicit Mem1(size_t len): length(len), dat(new int[len]){
        vec.resize(len);}

    ~Mem1(){

        if (dat != nullptr){
            delete[] dat;
        }
    }

    Mem1(const Mem1& other): length(other.length), dat(new int[other.length]){
        vec = other.vec;

        copy(other.dat, other.dat + length, dat);
    }

    Mem1& operator=(const Mem1& other){
        if (this != &other){
            delete[] dat;

            length = other.length;
            dat = new int[length];
            copy(other.dat, other.dat + length, dat);

            vec = other.vec;
        }
        return *this;
    }

    size_t Length() const{
        return length;
    }

    size_t length;
    int* dat;
    vector<int> vec;
};

class Mem2{
public:

     Mem2(size_t len): length(len), dat(new int[len]){
        vec.resize(len);}

    ~Mem2(){
        if (dat != nullptr){
            delete[] dat;
        }
    }


    Mem2(Mem2&& other) noexcept: dat(nullptr), length(0){
        dat = other.dat;
        length = other.length;
        vec = other.vec;

        other.vec.clear();
        other.dat = nullptr;
        other.length = 0;
    }

    Mem2& operator=(Mem2&& other) noexcept {
        if (this != &other){
            delete[] dat;

            dat = other.dat;
            length = other.length;
            vec = other.vec;

            other.vec.clear();
            other.dat = nullptr;
            other.length = 0;
        }
        return *this;
    }


    size_t Length() const{
        return length;
    }

    size_t length;
    int* dat;
    vector<int> vec;
};
