#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <float.h>
using namespace std;

class Complex {
private:
    double r;   // 实部
    double i;   // 虚部
    double mod; // 模长
    double arg; // 辐角
public:
    Complex(double real = 0, double imag = 0) : r(real), i(imag), mod(DBL_MAX), arg(DBL_MAX) {} // 先用DBL_MAX占mod和arg的位置，等到第一次要用到时再计算替换掉

    Complex operator+ (const Complex other) const{
        Complex res;
        res.r = r + other.r;
        res.i = i + other.i;
        return res;
    }

    Complex operator- (const Complex other) const {
        Complex res;
        res.r = r - other.r;
        res.i = i - other.i;
        return res;
    }

    bool operator== (const Complex other) const {
        return (r == other.r) && (i == other.i);
    } 

    bool operator!= (const Complex other) const {
        return (r != other.r) || (i != other.i);
    }

    // conjugate of a Complex number 求共轭复数
    Complex cg() const {               
        Complex res(r, -i);
        return res;
    }

    Complex operator* (const Complex other) const {
        Complex res;
        res.r = r * other.r - i * other.i;
        res.i = r * other.i + i * other.r;
        return res;
    }

    Complex operator/ (const Complex other) const {
        Complex res(r, i);
        return res * other.cg();
    }

    // 输出实部
    double get_real () const {
        return r;
    }

    // 输出虚部
    double get_imag () const {
        return i;
    }

    // 输出模长
    double get_mod () {
        if (mod == DBL_MAX) {
            mod = sqrt(r * r + i * i);
        }
        return mod;
    }

    // 输出辐角，采用弧度制
    double get_arg () {
        if (arg == DBL_MAX) {
            arg = atan2(r, i);
        }
        return arg;
    }

    // print 复数到屏幕上 
    void show () const {
        if (r == 0 || i == 0) {
            if (i == 0) {
                cout << r << endl;
            } else {
                ostringstream i_str_stream;
                i_str_stream << i;
                cout << (i == 1? "\0" : i == -1? "-" : i_str_stream.str()) << 'j' << endl;
            }
            return;
        }
        ostringstream i_str_stream;
        i_str_stream << i;
        cout << r << ((i > 0) ? "+" : "\0") << (i == 1? "\0" : i == -1? "-" : i_str_stream.str()) << 'j' << endl;
    }

    // 将复数表示为字符串输出
    string get_str () const {
        ostringstream Complex_stream;
        if (r == 0 || i == 0) {
            if (i == 0) {
                Complex_stream << r;
            } else {
                ostringstream i_str_stream;
                i_str_stream << i;
                Complex_stream << (i == 1? "\0" : i == -1? "-": i_str_stream.str()) << 'j';
            }
            return Complex_stream.str();
        }
        ostringstream i_str_stream;
        i_str_stream << i;
        Complex_stream << r << ((i > 0) ? "+" : "\0") << (i == 1? "\0" : i == -1? "-": i_str_stream.str()) << 'j';
        //return to_string(r) + ((i > 0) ? "+" : "\0") + to_string(i) + "j";
        return Complex_stream.str();
    }
};

#endif // COMPLEX_HPP