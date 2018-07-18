#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include "fft.h"
using namespace std;

void fft(std::vector<Complex> &in, std::vector<Complex> & out) {

    int n = in.size();
    for (int k = 0; k < n ; ++k){

        double realSum = 0.0;
        double imagSum = 0.0;
        for (int t = 0; t < n; ++t) {
            double angle = 2 * M_PI * t * k / n;
            double real = in[t].real * std::cos(angle) + in[t].imag * std::sin(angle);
            double imag = in[t].imag * std::cos(angle) - in[t].real * std::sin(angle);
            realSum += real;
            imagSum += imag;
        }
        out[k].real = realSum;
        out[k].imag = imagSum;
    }
}

void ifft(std::vector<Complex> &in, std::vector<Complex> & out) {

    /*
     * 1. Take Complex conjugate of the input array , call it x'
     * 2. Take fft(x') 
     * 3. Take Complext conjugate of fft(x')
     * 4. Divide it by N
     */
    for (int i = 0; i < in.size(); ++i) {
        in[i] = ~in[i];
    }

    fft(in, out);

    int n = out.size();
    for (int i = 0; i < out.size(); ++i) {
        out[i] = ~out[i];
        out[i] = out[i] / n;
    }
}
void ccorr(std::vector<Complex>& a, std::vector<Complex>& b, std::vector<double>& out) {
    /** Python code
    def ccorr(a,b):
        ifft(np.conj(fft(a)) * fft(b)).real
    */
    assert(a.size() == b.size());
    int n = a.size();

    // 1. Calculate FFT of vector a
    vector<Complex> aOut(n);
    fft(a, aOut);

    // 2. Calculate FFT of vector b
    vector<Complex> bOut(n);
    fft(b, bOut);

    // 3. Calculate complex conjugate of FFT(a)
    for (int i = 0; i < n; ++i) {
        aOut[i] = ~aOut[i];
    }

    // 4. Do complext multiplication of aOut and FFT(b)
    vector<Complex> cOut(n);
    for (int i = 0; i < n; ++i) {
        cOut[i] = aOut[i] * bOut[i];
    }

    // 5. Take inverse FFT of the result
    vector<Complex> inverseFFT(n);
    ifft(cOut, inverseFFT);

    // Copy the output in the output vector
    for (auto c : inverseFFT) {
        out.push_back(c.real);
    }
}

void cconv(std::vector<Complex>& a, std::vector<Complex>& b, std::vector<double>& out) {
    /** Python code
    def ccov(a,b):
        ifft(fft(a) * fft(b)).real
    */
    assert(a.size() == b.size());
    int n = a.size();

    // 1. Calculate FFT of vector a
    vector<Complex> aOut(n);
    fft(a, aOut);

    // 2. Calculate FFT of vector b
    vector<Complex> bOut(n);
    fft(b, bOut);

    // 3. Do complext multiplication of aOut and FFT(b)
    std::vector<Complex> cOut(n);
    for (int i = 0; i < n; ++i) {
        cOut[i] = aOut[i] * bOut[i];
    }

    // 4. Take inverse FFT of the result
    vector<Complex> inverseFFT(n);
    ifft(cOut, inverseFFT);

    // Copy the output in the output vector
    for (auto c : inverseFFT) {
        out.push_back(c.real);
    }
}

int main(int argc, char* argv[]) {
    Complex c1(1, 1);
    Complex c2(2, 2);
    Complex c3(88, 6.5);
    Complex c4(23, 45);

    std::vector<Complex> test;
    test.push_back(c1);
    test.push_back(c2);
    test.push_back(c3);
    test.push_back(c4);

    vector<Complex> out(test.size());

    fft(test, out);

    for (auto o : out) {
        std::cout << o.real << "." << o.imag << "j" << std::endl;
    }

    std::cout << "********************" << std::endl;
    vector<Complex> rev(test.size());
    ifft(test, rev);
    for (auto o : rev) {
        std::cout << o.real << "(" << o.imag << "j)" << std::endl;
    }

    std::cout << "********************" << std::endl;
    Complex a1(14, 0);
    Complex a2(3.6, 0);
    Complex a3(89.7, 0);
    Complex a4(512, 0);
    vector<Complex> a;
    a.push_back(a1);
    a.push_back(a2);
    a.push_back(a3);
    a.push_back(a4);

    Complex b1(78, 0);
    Complex b2(798, 0);
    Complex b3(7.12, 0);
    Complex b4(56.3, 0);
    vector<Complex> b;
    b.push_back(b1);
    b.push_back(b2);
    b.push_back(b3);
    b.push_back(b4);

    vector<double> out1;
    ccorr(a, b, out1);
    for (auto o : out1) {
        //std::cout << o.real << "(" << o.imag << "j)" << std::endl;
        std::cout << o << std::endl;
    }
    std::cout << "********************" << std::endl;

    vector<double> out2;
    cconv(a, b, out2);
    for (auto o : out2) {
        //std::cout << o.real << "(" << o.imag << "j)" << std::endl;
        std::cout << o << std::endl;
    }
    return 0;
}
