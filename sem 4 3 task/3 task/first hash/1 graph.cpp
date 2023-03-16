#include "pbPlots.hpp"
#include "supportLib.hpp"
#include <vector>
#include <iostream>
#include <random>
#include <string>
#include <map>

using namespace std;

void DrawGraph(vector<double> x,vector<double> y){
    RGBABitmapImageReference *imageRef = CreateRGBABitmapImageReference();

    StringReference *errorMessage = CreateStringReferenceLengthValue(0, L' ');

    DrawScatterPlot(imageRef, 900, 900, &x, &y, errorMessage );
    vector<double> *pngData = ConvertToPNG(imageRef->image);
    WriteToFile(pngData, "plot.png");
    DeleteImage(imageRef->image);

}


 unsigned int RShashh(const char* str, unsigned int length){
   unsigned int b    = 378551;
   unsigned int a    = 63689;
   unsigned int hashh = 0;
   unsigned int i    = 0;

   for (i = 0; i < length; ++str, ++i)
   {
      hashh = hashh * a + (*str);
      a    = a * b;
   }
   return hashh;
}




int main(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(65, 122);

    const int cycles = 10000;
    long long int hah[cycles];
    int len;
    int o = 0;
    const char* s;
    string h;
    for (int i = 0; i < cycles;i++){

        h = "";
        len = 15;

        for(int n=0; n<len; ++n)
            h += (char)distr(gen);

        s = h.c_str();

        hah[o] = RShashh(s,len);
        o++;
    }

    map<long long int, int> count;

    for (int i = 0; i < cycles; i++) 
        count[hah[i]]++;


    vector<double> x;
    vector<double> y;



    for (auto i : count) {
        x.push_back(i.first);
        y.push_back(i.second);
    }
    DrawGraph(x,y);

    return 0;
}





