#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <complex.h>
#include <fftw3.h>
using namespace std;


int main(int argc, char* argv[]) {
    
    int N = 10;
    double in2[][2] = {{1,2}, {3,4}, {5,6}};
    fftw_complex *out;
    fftw_plan p;

    out = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * (2)); // no * n1 = 6 = 10/2 + 1

    for (int i = 0; i < 3; ++i){
        p = fftw_plan_dft_r2c_1d(2, in2[i], out, FFTW_ESTIMATE);
        fftw_execute(p);

        for (int i = 0; i < 2 ; ++i) {
            cout << out[i][0] << ", " << out[i][1] << endl;
        }
        fftw_destroy_plan(p);
    }

    fftw_free(out);
    return 0;
}
