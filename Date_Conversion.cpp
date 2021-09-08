// Date_Conversion.cpp: 实现文件
//

#include "pch.h"
#include "Calculate_atom.h"
#include "Date_Conversion.h"
#include "afxdialogex.h"


// Date_Conversion 对话框

IMPLEMENT_DYNAMIC(Date_Conversion, CDialogEx)

Date_Conversion::Date_Conversion(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG9, pParent)
	, y1(_T(""))
	, m1(_T(""))
	, d1(_T(""))
	, y2(_T(""))
	, m2(_T(""))
	, d2(_T(""))
{

}

Date_Conversion::~Date_Conversion()
{
}

void Date_Conversion::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, y1);
	DDX_Text(pDX, IDC_EDIT2, m1);
	DDX_Text(pDX, IDC_EDIT4, d1);
	DDX_Text(pDX, IDC_EDIT5, y2);
	DDX_Text(pDX, IDC_EDIT6, m2);
	DDX_Text(pDX, IDC_EDIT7, d2);
}


BEGIN_MESSAGE_MAP(Date_Conversion, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &Date_Conversion::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &Date_Conversion::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &Date_Conversion::OnBnClickedButton4)
END_MESSAGE_MAP()


// Date_Conversion 消息处理程序

class date

{

public:



    date(int year = 1990, int month = 1, int day = 1)

        :_year(year)

        , _month(month)

        , _day(day)

    {


    }

    date(const date& d)

    {

        _year = d._year;

        _month = d._month;

        _day = d._day;

    }

   
    bool isLeapyear(int year)

    {

        if ((year % 4 == 0) && (year % 100 != 0))

        {

            return true;

        }

        else

        {

            if (year % 400 == 0)

                return true;

            else

                return false;

        }

    }

    int Getmonthday(int year, int month)

    {

        int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

        if (isLeapyear(year) && month == 2)

            return a[month - 1] + 1;

        else

            return a[month - 1];

    }

    bool isinvalid(int year, int month, int day)

    {

        if (year >= 1900)

        {

            if (month > 0 && month <= 12)

            {

                if (day > 0 && (day <= Getmonthday(year, month)))

                    return true;

                else

                    return false;

            }

            else

                return false;

        }

        else

            return false;

    }



    bool operator ==(const date& d)

    {

        if (_year == d._year)

        {

            if (_month == d._month)

            {

                if (_day == d._day)

                    return true;

                else

                    return false;

            }

            return false;

        }

        else

            return false;

    }

    bool operator !=(const date& d)

    {

        return !(*this == d);

    }

    bool operator >(const date& d)

    {

        if (_year > d._year)

        {

            return true;

        }

        else

        {

            if (_month > d._month)

                return true;

            else

            {

                if (_day > d._day)

                    return true;

                else

                    return false;

            }



        }



    }

    date operator +(int day)

    {



        int nowday = _day + day;

        while (nowday >= Getmonthday(_year, _month))

        {

            nowday = nowday - Getmonthday(_year, _month);

            if (_month == 12)

            {



                _year++;

                _month = 1;

            }

            else

            {



                _month++;

            }



        }

        _day = nowday;

        return (*this);



    }

    date  operator -(int day)

    {

        int sumday = _day;

        while (sumday < day)

        {

            sumday = sumday + Getmonthday(_year, _month);

            if (_month == 1)

            {

                _month = 12;

                _year--;

            }

            else

            {

                _month--;

            }

        }

        _day = sumday - day;

        return (*this);

    }

    int operator -(date const& d)

    {

        int count = 0;

        if (*this > d)

        {

            while (*this != d)

            {

                count++;

                *this = *this - 1;

            }





        }

        else

        {

            while (*this != d)

            {

                count++;

                *this = *this + 1;

            }

        }

        return count;



    }



private:

    int _year;

    int _month;

    int _day;

};



bool IsLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
void Date_Conversion::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	//获取系统时间
	CTime tm;
	tm = CTime::GetCurrentTime();//获取系统日期
	str = tm.Format("现在北京时间是%Y年%m月%d日");
	MessageBox(str,CString("当前日期"), MB_OK);
}


void Date_Conversion::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
    int count=0;
	int year = int(atof(y1));
	int month = int(atof(m1)); 
	int day = int(atof(d1));
	int year2 = int(atof(y2));
	int month2 = int(atof(m2));
	int day2 = int(atof(d2));
    date A(year, month, day);
    date B(year2, month2, day2);
    count = A - B;
    CString m;
    m.Format(_T("%d"),count);
    MessageBox(CString("第一个日期与第二个日期的差值为：")+m, CString("日期差值"));
	UpdateData(FALSE);
}


void Date_Conversion::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码

	
}
