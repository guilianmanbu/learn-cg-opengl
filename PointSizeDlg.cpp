// PointSizeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GLTest001.h"
#include "PointSizeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPointSizeDlg dialog


CPointSizeDlg::CPointSizeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPointSizeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPointSizeDlg)
	m_Size = 0.0f;
	m_min = 0.0f;
	m_max = 0.0f;
	m_step = 0.0f;
	//}}AFX_DATA_INIT
}


void CPointSizeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPointSizeDlg)
	DDX_Text(pDX, IDC_EDIT1, m_Size);
	DDX_Text(pDX, IDC_EDIT2, m_min);
	DDX_Text(pDX, IDC_EDIT3, m_max);
	DDX_Text(pDX, IDC_EDIT4, m_step);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPointSizeDlg, CDialog)
	//{{AFX_MSG_MAP(CPointSizeDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPointSizeDlg message handlers
