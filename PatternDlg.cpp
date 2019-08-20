// PatternDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GLTest001.h"
#include "PatternDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPatternDlg dialog


CPatternDlg::CPatternDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPatternDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPatternDlg)
	m_iPattern = -1;
	//}}AFX_DATA_INIT
}


void CPatternDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPatternDlg)
	DDX_Radio(pDX, IDC_RADIO1, m_iPattern);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPatternDlg, CDialog)
	//{{AFX_MSG_MAP(CPatternDlg)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPatternDlg message handlers

void CPatternDlg::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	
}
