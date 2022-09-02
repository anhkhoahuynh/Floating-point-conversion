/*#include <iostream>
#include <string>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include <exception>
#include <limits>
#include <stdio.h>  
#include <math.h>
#include <ctype.h>


using namespace std;

struct result_bi2dec
{
    float num;
    wstring check_result;
};
bool checkdecnum(wstring decnum)
{
    int i = 0;
    bool result = true;
    int countnegative = 0;
    int countpoint = 0;
    while (i < decnum.length())
    {
        if (decnum[i] != L'0' && decnum[i] != L'1' && decnum[i] != L'2' &&
            decnum[i] != L'3' && decnum[i] != L'4' && decnum[i] != L'5' &&
            decnum[i] != L'6' && decnum[i] != L'7' && decnum[i] != L'8' &&
            decnum[i] != L'9' && decnum[i] != L'.' && decnum[i] != L'-')
        {
            result = false;
            break;
        }
        if (decnum[i] == L'.')
        {
            countpoint++;
        }
        if (decnum[i] == L'-')
        {
            countnegative++;
        }
        i++;
    }
    if (countnegative > 1 || countpoint > 1)
    {
        result = false;
    }
    if (countnegative == 1 && decnum[0] != L'-')
    {
        result = false;
    }
    if (countpoint == 1 && (decnum[0] == L'.' || decnum[decnum.length() - 1] == L'.'))
    {
        result = false;
    }
    return result;
}

wstring kiemtracactruonghop(float a)
{
    switch (fpclassify(a))
    {
    case FP_INFINITE: return L"infinite-overflow";  break;
    case FP_NAN:       return L"NaN";       break;
    case FP_ZERO:      return L"zero";      break;
    case FP_SUBNORMAL:return L"subnormal-underflow"; break;
    case FP_NORMAL:   return L"normal";    break;
    }
}

void printBinary(int n, int i)
{

    // Prints the binary representation
    // of a number n up to i-bits.
    int k;
    for (k = i - 1; k >= 0; k--) {

        if ((n >> k) & 1)
            wcout << "1";
        else
            wcout << "0";
    }
}

typedef union {
    float f;
    struct
    {
        unsigned int mantissa:23;
        unsigned int exponent:8;
        unsigned int sign:1;
    } raw;
} myfloat;

void kiemtraloai(myfloat var)
{
    if (var.raw.exponent == 0 && var.raw.mantissa == 0)
    {
        wcout << "zero";
    }
    if (var.raw.exponent == 0 && var.raw.mantissa != 0)
    {
        wcout << "khong the chuan hoa";
    }
    if (var.raw.exponent == 255 && var.raw.mantissa == 0)
    {
        wcout << "so vo cuc";
    }
    if (var.raw.exponent == 255 && var.raw.mantissa != 0)
    {
        wcout << "NaN";
    }
}
// Function to convert real value
// to IEEE floating point representation
void printIEEE(myfloat var)
{
    wcout << var.raw.sign << " | ";
    printBinary(var.raw.exponent, 8);
    wcout << " | ";
    printBinary(var.raw.mantissa, 23);
    wcout << "\n";
}


bool checkbinum(wstring binum, int length_of_binum)
{
    bool result = true;
    if (binum.length() != length_of_binum)
    {
        return false;
    }
    else
    {
        int i = 0;
        while (i < binum.length())
        {
            if (binum[i] != L'0' && binum[i] != L'1')
            {
                return false;
                break;
            }
            i++;
        }
    }
}

wstring check_special_case(wstring exponent, wstring fraction)
{
    wstring e0 = L"00000000";
    wstring f0 = L"00000000000000000000000";
    wstring e1 = L"11111111";
    if (exponent == e0 && fraction == f0)
    {
        return L"0";
    }
    if (exponent == e1 && fraction == f0)
    {
        return L"Số vô cực";
    }
    if (exponent == e1 && fraction != f0)
    {
        return L"Not a number (NaN)";
    }
    if (exponent == e0 && fraction != f0)
    {
        return L"Là số không thể chuẩn hóa";
    }
    if (exponent == e0 && fraction != f0)
    {
        return L"Là số chuẩn hóa";
    }
    else
    {
        return L"Chưa define";
    }
}

result_bi2dec bi2dec(wstring sign, wstring exponent, wstring fraction)
{
    result_bi2dec final_result;
    wstring special_case_result = check_special_case(exponent, fraction);
    if (special_case_result == L"Là số không thể chuẩn hóa" || special_case_result == L"Là số chuẩn hóa")
    {




    }
    else
    {
    }
    final_result.check_result = special_case_result;
    return final_result;
}








int main()
{

    _setmode(_fileno(stdin), _O_U16TEXT);
   _setmode(_fileno(stdout), _O_U16TEXT);
    myfloat var1;
    myfloat var2;
    myfloat var3;
    var1.f = pow(-1.9888,-127);
    var2.f = pow(-2, -220);
    wcout << "nhap di ma";
     wcout << "IEEE 754 representation of " << fixed << var1.f << " is : " << endl;
    printIEEE(var1);
    wcout << "IEEE 754 representation of " << fixed << var2.f << " is : " << endl;
    printIEEE(var2);
    wcout << "IEEE 754 representation of " << fixed << var2.f << " is : " << endl;
   // printIEEE(var3);
   kiemtraloai(var1);
   wcout  <<"\n";
   kiemtraloai(var2);
   wcout << "\n";
    wcout << (kiemtracactruonghop(var1.f)) <<"\n";
    wcout << (kiemtracactruonghop(var2.f));
    return 0;
}*/

#include <iostream>
#include <string>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include <exception>
#include <stdio.h>  
#include <math.h>
#include <ctype.h>
#include <iomanip>

using namespace std;
typedef union {

    float f;
    struct
    {
        unsigned int mantissa : 23;
        unsigned int exponent : 8;
        unsigned int sign : 1;

    } raw;
} myfloat;

unsigned int bi2dec(unsigned int* arr, int low, int high)
{
    unsigned int f = 0, i;
    for (i = high; i >= low; i--) 
    {
        f = f + arr[i] * pow(2, high - i);
    }
    return f;
}

bool checkbinum(wstring binum, int length)
{
    bool check_result = true;
    if (length != binum.length())
    {
        check_result = false;
    }
    else
    {
        for (int i = 0; i < binum.length(); i++)
        {
            if (binum[i] != L'0' && binum[i] != L'1')
            {
                check_result = false;
                break;
            }
        }
    }
    return check_result;
}

void bi2float(unsigned int arr[32])
{
    myfloat var;
    unsigned int f = bi2dec(arr, 9, 31);
    var.raw.mantissa = f;
    f = bi2dec(arr, 1, 8);
    var.raw.exponent = f;
    var.raw.sign = arr[0];
    wcout << L"Giá trị float của dãy bit trên là: \n";
    wcout <<  var.f << endl;
    //fixed << setprecision(6) <<
}

void display_binum(unsigned int arr[32])
{
    wcout << L"Dãy nhị phân là: " << arr[0] << L" | ";
    for (int i = 1; i < 9; i++)
    {
        wcout << arr[i];
    }
    wcout << L" | ";
    for (int i = 9; i < 32; i++)
    {
        wcout << arr[i];
    }
}

// Driver Code
int main()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    unsigned int bi_array[32];
    do
    {
        wcout << L"Nhập bit tại vị trí số 0 (phần dấu - sign): ";
        wcin >> bi_array[0];
        if (bi_array[0] != 0 && bi_array[0] != 1)
        {
            wcout << L"Chỉ được nhập 1 ký tự 0 hoặc 1.\n";
        }
    } while (bi_array[0] != 0 && bi_array[0] != 1);
    wstring a;
    do
    {
        wcout << L"Nhập dãy bit tại vị trí 1-8 (phần số mũ - exponent): ";
        wcin >> a;
        if (checkbinum(a, 8) == false)
        {
            wcout << L"Chỉ được chứa ký tự 0 hoặc 1, và độ dài chuỗi bit là 8 ký tự.\n";
        }
    } while (checkbinum(a, 8) == false);
    for (int i = 1; i < 9; i++)
    {
        bi_array[i] = (unsigned int)a[i - 1] - 48;
    }
    wstring b;
    do
    {
        wcout << L"Nhập dãy bit tại vị trí 9-32 (phần định trị - fraction): ";
        wcin >> b;
        if (checkbinum(b, 23) == false)
        {
            wcout << L"Chỉ được chứa ký tự 0 hoặc 1, và độ dài chuỗi bit là 23 ký tự.\n";
        }
    } while (checkbinum(b, 23) == false);
    for (int i = 9; i < 32; i++)
    {
        bi_array[i] = (unsigned int)b[i - 9] - 48;
    }
    display_binum(bi_array);
    wcout << "\n";
    bi2float(bi_array);
    return 0;
}
