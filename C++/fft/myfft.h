namespace unmesh {
typedef struct Complex {

    public:
    double real;
    double imag;

    Complex() {
        real = 0.0;
        imag = 0.0;
    }

    Complex(double r, double i) {
        real = r;
        imag = i;
    }

    Complex& operator +=(Complex& c) {
        this->real += c.real;
        this->imag += c.imag;
        return *this;
    }

    Complex& operator = (Complex& c) {
        this->real = c.real;
        this->imag = c.imag;
        return *this;
    }

    Complex& operator * (Complex& c) {
        static Complex out;
        out.real = (this->real * c.real) - (this->imag * c.imag);
        out.imag = (this->real * c.imag) + (this->imag * c.real);
        return out;
    }

    Complex& operator *= (Complex& c) {
        this->real = (this->real * c.real) - (this->imag * c.imag);
        this->imag = (this->real * c.imag) + (this->imag * c.real);
        return *this;
    }

    Complex& operator ~() {
        this->imag = -this->imag;
        return *this;
    }

    Complex& operator / (double d) {
        this->real /= d;
        this->imag /= d;
        return *this;
    }

} Complex;
}
