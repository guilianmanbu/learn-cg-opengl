// oordSetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GLTest001.h"
#include "oordSetDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CoordSetDlg

IMPLEMENT_DYNCREATE(CoordSetDlg, CFormView)

//DEL CoordSetDlg::CoordSetDlg()
//DEL 	: CFormView(CoordSetDlg::IDD)
//DEL {
//DEL 	//{{AFX_DATA_INIT(CoordSetDlg)
//DEL 		// NOTE: the ClassWizard will add member initialization here
//DEL 	//}}AFX_DATA_INIT
//DEL }

CoordSetDlg::~CoordSetDlg()
{
}

void CoordSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CoordSetDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CoordSetDlg, CFormView)
	//{{AFX_MSG_MAP(CoordSetDlg)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CoordSetDlg diagnostics

#ifdef _DEBUG
void CoordSetDlg::AssertValid() const
{
	CFormView::AssertValid();
}

void CoordSetDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CoordSetDlg message handlers
