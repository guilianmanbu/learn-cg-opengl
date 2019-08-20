// CoordSetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GLTest001.h"
#include "CoordSetDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCoordSetDlg dialog


CCoordSetDlg::CCoordSetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCoordSetDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCoordSetDlg)
	m_WinSize = 0.0f;
	//}}AFX_DATA_INIT
}


void CCoordSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCoordSetDlg)
	DDX_Text(pDX, IDC_EDIT1, m_WinSize);
	DDV_MinMaxFloat(pDX, m_WinSize, 1.f, 100.f);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCoordSetDlg, CDialog)
	//{{AFX_MSG_MAP(CCoordSetDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCoordSetDlg message handlers
