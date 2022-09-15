#include <iostream>
using namespace std;
int main() {
    int w, h;
    int el;
    cout << "Please write matrix dimensions (value<=100)" << endl;
    cout << "Height: ";
    cin >> w;
    cout << "Width: ";
    cin >> h;
    const int maxWidth = 100;
    const int maxHeight = 100;
    float gauss[maxWidth][maxHeight];
    //Я почитал интернет - это единственный способ обработать массив вводимой величины, не используя динамический vector
    //Так как размер массива должен быть известен до компиляции (видимо оно подстраивается для создания такого размера
    //ещё во время компиляции)
    cout << "Please write matrix values" << endl;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << i << " " << j << ": ";
            cin >> gauss[j][i];
        }
    }
    if (h < w + 1)
        cout << "Equasion system has more than one solution";
    else {
        if (w + 1 < h)
            cout << "Equasion system has duplicate equations or no solutions";
        else {
            //forth
            for (int j = 0; j < w; j++) {
                for (int b = j + 1; b < h; b++) {
                    if (gauss[j][j] != 0) {
                        float k = gauss[b][j] / gauss[j][j];

                        for (int a = j; a < h; a++) {
                            //cout << "prev: " << b << " " << a << " " << j << endl;
                            //cout << "prev: " << gauss[b][a] << endl;
                            gauss[b][a] -= gauss[j][a] * k;
                            //cout << "K: " << k << endl << "curr: " << gauss[b][a] << endl;
                        }
                    }
                }
            }

            //back
            for (int j = h - 2; j > 0; j--) {
                for (int b = j - 1; b > -1; b--) {
                    if (gauss[j][j] != 0) {
                        float k = gauss[b][j] / gauss[j][j];
                        //cout << "prev: " << b << " " << j << endl;
                        //gauss[b][j] -= gauss[j][j] * k;
                        gauss[b][h - 1] -= gauss[j][h - 1] * k;
                    }
                }
            }


            //show matrix
            //for (int i = 0; i < w; i++) {
                //for (int j = 0; j < h; j++) {
                    //cout << gauss[i][j] << " ";
                //}
                //cout << endl;
            //}

            cout << "Your answers are: ";
            for (int i = 0; i < w; i++) {
                cout << gauss[i][h - 1] / gauss[i][i] << " ";
            }

        }


        return 0;
    }
}
