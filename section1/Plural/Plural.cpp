/*
 * Plural
 * Version 1.0
 * funtion: 建立一个复数类
 */

#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <float.h>
using namespace std;

class Plural {
private:
    double r;   // 实部
    double i;   // 虚部
    double mod; // 模长
    double arg; // 辐角
public:
    Plural(double real = 0, double imag = 0) : r(real), i(imag), mod(DBL_MAX), arg(DBL_MAX) {} // 先用DBL_MAX占mod和arg的位置，等到第一次要用到时再计算替换掉

    Plural operator+ (const Plural other) const{
        Plural res;
        res.r = r + other.r;
        res.i = i + other.i;
        return res;
    }

    Plural operator- (const Plural other) const {
        Plural res;
        res.r = r - other.r;
        res.i = i - other.i;
        return res;
    }

    bool operator== (const Plural other) const {
        return (r == other.r) && (i == other.i);
    } 

    bool operator!= (const Plural other) const {
        return (r != other.r) || (i != other.i);
    }

    // conjugate of a plural number 求共轭复数
    Plural cg() const {               
        Plural res(r, -i);
        return res;
    }

    Plural operator* (const Plural other) const {
        Plural res;
        res.r = r * other.r - i * other.i;
        res.i = r * other.i + i * other.r;
        return res;
    }

    Plural operator/ (const Plural other) const {
        Plural res(r, i);
        return res * other.cg();
    }

    double get_real () {
        return r;
    }

    double get_imag () {
        return i;
    }

    double get_mod () {
        if (mod == DBL_MAX) {
            mod = sqrt(r * r + i * i);
        }
        return mod;
    }

    double get_arg () {
        if (arg == DBL_MAX) {
            arg = atan2(r, i);
        }
        return arg;
    }

    // print 复数到屏幕上 
    void show () {
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
    string get_str () {
        ostringstream plural_stream;
        if (r == 0 || i == 0) {
            if (i == 0) {
                plural_stream << r;
            } else {
                ostringstream i_str_stream;
                i_str_stream << i;
                plural_stream << (i == 1? "\0" : i == -1? "-": i_str_stream.str()) << 'j';
            }
            return plural_stream.str();
        }
        ostringstream i_str_stream;
        i_str_stream << i;
        plural_stream << r << ((i > 0) ? "+" : "\0") << (i == 1? "\0" : i == -1? "-": i_str_stream.str()) << 'j';
        //return to_string(r) + ((i > 0) ? "+" : "\0") + to_string(i) + "j";
        return plural_stream.str();
    }
};

int main () {
    Plural a(1, 2);
    Plural b(3, 4);

    cout << "a = ";
    a.show();
    cout << "b = ";
    b.show();

    Plural c = a + b;
    cout << "a + b = ";
    c.show();

    c = Plural(34, -5); 
    cout << c.get_str() << endl;
    c.show();

    c = a - b;
    cout << "a - b = ";
    c.show();

    cout << "a * b = ";
    c = a * b;
    c.show();

    cout << "a / b = ";
    c = a / b;
    c.show();

    cout << "c.cg() = ";
    c.cg().show();

    return 0;
}