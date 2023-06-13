
// Auto_pilot_objectDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Auto_pilot_object.h"
#include "Auto_pilot_objectDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "Car.h"

int m_nShape = 1;
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CAutopilotobjectDlg 对话框



CAutopilotobjectDlg::CAutopilotobjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AUTO_PILOT_OBJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAutopilotobjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAutopilotobjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON1, &CAutopilotobjectDlg::OnBnClickedButton1)
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON2, &CAutopilotobjectDlg::OnBnClickedButton2)
	ON_WM_LBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON3, &CAutopilotobjectDlg::OnBnClickedButton3)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CAutopilotobjectDlg 消息处理程序

BOOL CAutopilotobjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CAutopilotobjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CAutopilotobjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CAutopilotobjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


Car car1;
Car car2;

void CAutopilotobjectDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	Invalidate(true);
	m_nShape = 1;
	flag = 2;
	car1.clear_memory();
	car2.clear_memory();
	KillTimer(1);
	KillTimer(2);
}


void CAutopilotobjectDlg::OnBnClickedButton2()
{
	CDC* dc = GetDC();
	car1.SetStartPosition(point1. x, point1.y);
	car1.Move(dc, temp_point);
	SetTimer(1, 200, nullptr);
}


void CAutopilotobjectDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (flag == 2)
	{
		flag--;
		point1 = point;
	}
	CDC* pDC = GetDC();
	temp_point = point;
	CBrush* oldBrush, myBrush;
	myBrush.CreateSolidBrush(RGB(0, 0, 0));

	CPen* oldPen, myPen;
	myPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));//wingdi.h

	oldBrush = pDC->SelectObject(&myBrush);
	oldPen = pDC->SelectObject(&myPen);

	pDC->SetBkColor(RGB(0, 0, 0));
	pDC->SetTextColor(RGB(0, 0, 0));

	CRect myRect;
	static CPoint oldPoint;
	const int nRadium = 2;//设定圆的半径

	myRect.left = point.x - nRadium;
	myRect.top = point.y - nRadium;
	myRect.right = point.x + nRadium;
	myRect.bottom = point.y + nRadium;//根据圆心计算圆的范围

	//绘制圆
	pDC->Ellipse(myRect);
	if (m_nShape < 1) {
		pDC->MoveTo(oldPoint);
		pDC->LineTo(point);
	}
	else {
		m_nShape = 0;
	}
	oldPoint = point;
	pDC->SelectObject(oldBrush);
	pDC->SelectObject(oldPen);
	myBrush.DeleteObject();
	myPen.DeleteObject();

	CDialogEx::OnLButtonUp(nFlags, point);
}


void CAutopilotobjectDlg::OnBnClickedButton3()
{
	CDC* pdc = GetDC();
	car2.SetStartPosition(point1.x, point1.y);
	car2.Move(pdc, temp_point);
	SetTimer(2, 200, nullptr);
}


void CAutopilotobjectDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nIDEvent == 1)
	{
		CDC* dc = GetDC();
		car1.Move(dc, temp_point);
		if (fabs(car1.m_x - temp_point.x) <= 6 && fabs(car1.m_y - temp_point.y) <= 6)
			KillTimer(1);
	}
	if (nIDEvent == 2)
	{
		CDC* pdc = GetDC();
		car2.Move(pdc, temp_point);
		if ((fabs(car2.m_x - temp_point.x) <= 6 && fabs(car2.m_y - temp_point.y) <= 6) || (fabs(car2.m_x - car1.m_x) <= 18 && fabs(car2.m_y - car1.m_y) <= 18))
			KillTimer(2);
	}
	CDialogEx::OnTimer(nIDEvent);
}
