#undef max
#include <iostream>
#include <string>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include <vector>
#include <string.h>
#include <exception>
#undef max


using namespace std;


struct single_floating_point_num {
    int sign[1];
    int exponent[82];
    int significand[23];
};//theo tiêu chuẩn IEEE-754 cho số chính xác đơn

struct decimal_num {
    int sign;
    vector<int> integer_part;
    vector<int> fraction_part;
};

struct checknumresult {
    bool ok_or_not;
    bool can_be_integer;
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
            countpoint ++;
        }
        if (decnum[i] == L'-')
        {
            countnegative ++;
        }
        i++;
    }
    if (countnegative > 1 || countpoint > 1)
    {
        result = false;
    }
    if (countnegative == 1 && decnum[0]!= L'-')
    {
        result = false;
    }
    if (countpoint == 1 && (decnum[0] == L'.' || decnum[decnum.length() - 1] == L'.'))
    {
        result = false;
    }
    return result;
}

decimal_num element_separation(wstring decnum)
{
    decimal_num result;
    wstring after_sign_removal;
    if (decnum[0] == L'-')
    {
        result.sign = 1;
        after_sign_removal = decnum.substr(1);
    }
    else
    {
        result.sign = 0;
        after_sign_removal = decnum;
    }
    int i = 0;
    while (i<after_sign_removal.length() && after_sign_removal[i] != L'.')
    {
        result.integer_part.push_back((int)after_sign_removal[i] - (int)L'0');
        i++;
    }
    int position = after_sign_removal.find(L'.');
    if (position == -1)
    {
        result.fraction_part.push_back(0);
    }
    else
    {
        wstring phanthapphan = after_sign_removal.substr(position + 1);
        for (int i = 0; i < phanthapphan.length(); i++)
        {
            result.fraction_part.push_back((int)phanthapphan[i] - (int)L'0');
        }
    }
    
    return result;
}


int main()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    wstring input;
    wcout << L"Hãy nhập số";
    wcin >> input;
    wstring msg = L"Over range rồi";
    long double convert;
    while (1)
    {
        if (checkdecnum(input) == false)
        {
            wcout << L"NHập sai rồi bé ơi ";
            wcin.clear();
            wcin.ignore();
            wcin >> input;
        }
        else
        {
            break;
        }        
    }
        decimal_num xuat = element_separation(input);
        wcout << xuat.sign << ", ";
        for (int i = 0; i < xuat.integer_part.size(); i++)
        {
            wcout << xuat.integer_part[i];
        }
        wcout << ", ";
        for (int i = 0; i < xuat.fraction_part.size(); i++)
        {
            wcout << xuat.fraction_part[i];
        }

}
