
# Complex.hpp 
 这是一个库，包含复数类 Complex, 实现了复数的基本运算(加减乘除)， 包括对单个复数求实部的方法 Complex::get_real, 求虚部的方法Complex::get_imag, 求模长的方法Complex::get_mod, 求辐角弧度值的方法Complex::get_arg， 求共轭复数的方法Complex::cg，以及输出复数对象的字符串表示的方法Complex::get_str.为了方便调试还增加了将复数对象的字符串表示打印到控制台的方法Complex::show.

 示例代码：
``` C++ 
#include "Complex"  // 导入复数库

int main() {
    Complex a(3, 3);    // 设 a = 3 + 3j 
    Complex b(0, 1);    // 设 b = j

    Complex c = a + b;  // 求 c = a + b

    c.show();           // 将c打印到屏幕上

    return 0；
}
```
