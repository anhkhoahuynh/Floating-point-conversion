#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>
#include <iomanip>

using namespace std;
typedef union {

    float f;
    struct
    {
        unsigned int fraction : 23;
        unsigned int exponent : 8;
        unsigned int sign : 1;

    } raw;
} myfloat;

void float2bi(int n, int i)
{
    int k;
    for (k = i - 1; k >= 0; k--) 
    {
        if ((n >> k) & 1)
        {
            wcout << "1";
        }
        else
        { 
            wcout << "0";
        }
    }
}

void display_result_float2bi(myfloat var)
{
    wcout << var.raw.sign << " | ";
    float2bi(var.raw.exponent, 8);
    wcout << " | ";
    float2bi(var.raw.fraction, 23);
    wcout << "\n";
}


bool checkfloatnum(wstring decnum)
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

unsigned int bi2float(unsigned int* arr, int low, int high)
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

void display_result_bi2float(unsigned int arr[32])
{
    myfloat var;
    unsigned int f = bi2float(arr, 9, 31);
    var.raw.fraction = f;
    f = bi2float(arr, 1, 8);
    var.raw.exponent = f;
    var.raw.sign = arr[0];
    wcout << L"----------------------- " << endl;
    wcout << L"Giá trị float của dãy bit trên là: " << var.f << endl;//dòng này cho phép thể hiện số float ở dạng rút gọn.
    wcout << fixed << setprecision(150)<< L"Hoặc viết ở dạng đầy đủ là: " << var.f << endl;
    //dùng setprecision để thể hiện đầy đủ kết quả mà không thể hiện theo dạng e mũ. Chọn số lượng ký tự là 150 
    // vì số lượng ký tự dài nhất là 149 tương ứng với giá trị denorm nhỏ nhất 1.4.10^-45.
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


void menu()
{
    wstring str;
    wcout << L"----*----*----*----\nNhập số tương ứng với từng loại chuyển đổi theo số chấm động chính xác đơn:\n[1] Từ số thực sang dãy nhị phân\n[2] Từ dãy nhị phân sang số thực\n----*----*----*----\nNhập số bạn chọn: ";
    wcin >> str;
    while (str != L"1" && str != L"2")
    {
        wcin.clear();
        wcin.ignore();
        wcout << L"Chỉ được phép nhập ký tự 1-2 tương ứng với từng loại chuyển đổi.\nVui lòng nhập lại: ";
        wcin >> str;
    }
    int choice = stoi(str);
    switch (choice)
    {
    case 1:
    {
        wcout << L"Bạn đã chọn phép chuyển đổi từ số thực sang dãy nhị phân. Hãy nhập số bạn muốn chuyển đổi: ";
        myfloat floatnum;
        wstring stringnum;
        do
        {
            wcin >> stringnum;
            if (checkfloatnum(stringnum) == false)
            {
                wcout << L"Nhập sai định dạng.\n";
            }
        } while (checkfloatnum(stringnum) == false);
        floatnum.f = (float)_wtof(stringnum.c_str());
               wcout << "IEEE 754 representation of ";
        wcout << fixed << setprecision(6) << floatnum.f << " is : " << endl;
        display_result_float2bi(floatnum);
    }
    break;
    case 2:
    {
        wcout << L"Bạn đã chọn phép chuyển đổi từ dãy nhị phân sang số thực. Hãy nhập số bạn muốn chuyển đổi: ";
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
        display_result_bi2float(bi_array);
    }
    break;
    }
}


int main()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    wstring tieptuc;
    wcout << L"Môn Hệ Thống Máy Tính - Phần khảo sát số chấm động\nTên SV: Huỳnh Anh Khoa\nMSSV: 21880228" << endl;
    do {
        menu();
        wcout << L"\n-------------------\nBạn muốn tiếp tục hay kết thúc?\n[0] Tiếp tục\n[Nút khác bất kỳ] Thoát\n-------------------" << std::endl;
        wcin >> tieptuc;
    } while (tieptuc == L"0");
}
