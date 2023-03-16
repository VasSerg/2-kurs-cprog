#include "pbPlots.hpp"
#include "supportLib.hpp"
#include <vector>
#include <iostream>
#include <random>
#include <string>
#include <map>

using namespace std;

void DrawGraph(vector<double> x,vector<double> y,string name){
    RGBABitmapImageReference *imageRef = CreateRGBABitmapImageReference();

    StringReference *errorMessage = CreateStringReferenceLengthValue(0, L' ');

    DrawScatterPlot(imageRef, 900, 900, &x, &y, errorMessage );
    vector<double> *pngData = ConvertToPNG(imageRef->image);
    WriteToFile(pngData, name +".png");
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
 unsigned int JSHash(const char* str, unsigned int length)
 {
     unsigned int hash = 1315423911;
     unsigned int i = 0;

     for (i = 0; i < length; ++str, ++i)
     {
         hash ^= ((hash << 5) + (*str) + (hash >> 2));
     }

     return hash;
 }
 unsigned int PJWHash(const char* str, unsigned int length)
 {
     const unsigned int BitsInUnsignedInt = (unsigned int)(sizeof(unsigned int) * 8);
     const unsigned int ThreeQuarters = (unsigned int)((BitsInUnsignedInt * 3) / 4);
     const unsigned int OneEighth = (unsigned int)(BitsInUnsignedInt / 8);
     const unsigned int HighBits =
         (unsigned int)(0xFFFFFFFF) << (BitsInUnsignedInt - OneEighth);
     unsigned int hash = 0;
     unsigned int test = 0;
     unsigned int i = 0;

     for (i = 0; i < length; ++str, ++i)
     {
         hash = (hash << OneEighth) + (*str);

         if ((test = hash & HighBits) != 0)
         {
             hash = ((hash ^ (test >> ThreeQuarters)) & (~HighBits));
         }
     }

     return hash;
 }
 unsigned int ELFHash(const char* str, unsigned int length)
 {
     unsigned int hash = 0;
     unsigned int x = 0;
     unsigned int i = 0;

     for (i = 0; i < length; ++str, ++i)
     {
         hash = (hash << 4) + (*str);

         if ((x = hash & 0xF0000000L) != 0)
         {
             hash ^= (x >> 24);
         }

         hash &= ~x;
     }

     return hash;
 }
 unsigned int BKDRHash(const char* str, unsigned int length)
 {
     unsigned int seed = 131; /* 31 131 1313 13131 131313 etc.. */
     unsigned int hash = 0;
     unsigned int i = 0;

     for (i = 0; i < length; ++str, ++i)
     {
         hash = (hash * seed) + (*str);
     }

     return hash;
 }
 unsigned int SDBMHash(const char* str, unsigned int length)
 {
     unsigned int hash = 0;
     unsigned int i = 0;

     for (i = 0; i < length; ++str, ++i)
     {
         hash = (*str) + (hash << 6) + (hash << 16) - hash;
     }

     return hash;
 }
 unsigned int DJBHash(const char* str, unsigned int length)
 {
     unsigned int hash = 5381;
     unsigned int i = 0;

     for (i = 0; i < length; ++str, ++i)
     {
         hash = ((hash << 5) + hash) + (*str);
     }

     return hash;
 }
 unsigned int DEKHash(const char* str, unsigned int length)
 {
     unsigned int hash = length;
     unsigned int i = 0;

     for (i = 0; i < length; ++str, ++i)
     {
         hash = ((hash << 5) ^ (hash >> 27)) ^ (*str);
     }

     return hash;
 }
 unsigned int APHash(const char* str, unsigned int length)
 {
     unsigned int hash = 0xAAAAAAAA;
     unsigned int i = 0;

     for (i = 0; i < length; ++str, ++i)
     {
         hash ^= ((i & 1) == 0) ? ((hash << 7) ^ (*str) * (hash >> 3)) :
             (~((hash << 11) + ((*str) ^ (hash >> 5))));
     }

     return hash;
 }



 void CheckHash(unsigned int (*HashFunc)(const char* str, unsigned int length), string ind ) {
    //put the main of the "first hash"
     random_device rd;
     mt19937 gen(rd());
     uniform_int_distribution<> distr(65, 122);

    vector<double> x;
    vector<double> z;
    int lim = 3906250;

    for (int y = 10; y <= lim; y *= 5) {
        const int cycles = y;
        vector<long long int> hah;
        int len;
        const char* s;
        string h;
        for (int i = 0; i < cycles; i++) {

            h = "";
            len = 15;

            for (int n = 0; n < len; ++n)
                h += (char)distr(gen);

            s = h.c_str();

            hah.push_back(HashFunc(s, len));
        }

        map<long long int, int> count;

        for (int i = 0; i < cycles; i++)
            count[hah[i]]++;

        double coun = 0;
        for (auto i : count) {
            if (i.second > 1)
                coun += i.second;
        }
        cout << coun;
        x.push_back(y);
        z.push_back(coun);

        if (y == lim) {

            vector<double> r;
            vector<double> t;


            for (auto i : count) {
                r.push_back(i.first);
                t.push_back(i.second);
            }
            string nam2 = ind + "2 graph";
            DrawGraph(r, t, nam2);
        }
    }

    string nam = ind + "1 graph";
    DrawGraph(x, z, nam);



 }



 int main() {
     CheckHash(&RShashh, "0_");
     cout << endl;
     CheckHash(&JSHash, "1_");
     cout << endl;
     CheckHash(&PJWHash, "2_");
     cout << endl;
     CheckHash(&ELFHash, "3_");
     cout << endl;
     CheckHash(&BKDRHash, "4_");
     cout << endl;
     CheckHash(&SDBMHash, "5_");
     cout << endl;
     CheckHash(&DJBHash, "6_");
     cout << endl;
     CheckHash(&DEKHash, "7_");
     cout << endl;
     CheckHash(&APHash, "8_");
     cout << endl;
     cout << endl;


  
    return 0;
 }

