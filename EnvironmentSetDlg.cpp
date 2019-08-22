// EnvironmentSetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GLTest001.h"
#include "EnvironmentSetDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEnvironmentSetDlg dialog


CEnvironmentSetDlg::CEnvironmentSetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEnvironmentSetDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEnvironmentSetDlg)
	m_depthFlag = FALSE;
	m_lightFlag = FALSE;
	m_light0 = FALSE;
	m_light1 = FALSE;
	m_lightModelFlag = FALSE;
	m_colorMaterialFlag = FALSE;
	m_emissionFlag = FALSE;
	m_fogMode = -1;
	//}}AFX_DATA_INIT
}


void CEnvironmentSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEnvironmentSetDlg)
	DDX_Check(pDX, IDC_CHECK1, m_depthFlag);
	DDX_Check(pDX, IDC_CHECK2, m_lightFlag);
	DDX_Check(pDX, IDC_CHECK3, m_light0);
	DDX_Check(pDX, IDC_CHECK4, m_light1);
	DDX_Check(pDX, IDC_CHECK7, m_lightModelFlag);
	DDX_Check(pDX, IDC_CHECK8, m_colorMaterialFlag);
	DDX_Check(pDX, IDC_CHECK9, m_emissionFlag);
	DDX_Radio(pDX, IDC_RADIO2, m_fogMode);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEnvironmentSetDlg, CDialog)
	//{{AFX_MSG_MAP(CEnvironmentSetDlg)
	ON_BN_CLICKED(IDC_CHECK1, OnCheckDepth)
	ON_BN_CLICKED(IDC_CHECK2, OnCheckLighting)
	ON_BN_CLICKED(IDC_CHECK3, OnCheckLight0)
	ON_BN_CLICKED(IDC_CHECK4, OnCheckLight1)
	ON_BN_CLICKED(IDC_CHECK7, OnCheckLightModel)
	ON_BN_CLICKED(IDC_CHECK8, OnCheckMatColor)
	ON_BN_CLICKED(IDC_CHECK9, OnCheckEmission)
	ON_BN_CLICKED(IDC_BUTTON1, OnBGColor)
	ON_BN_CLICKED(IDC_RADIO2, OnFogDisable)
	ON_BN_CLICKED(IDC_RADIO3, OnFogLinear)
	ON_BN_CLICKED(IDC_RADIO4, OnFogEXP)
	ON_BN_CLICKED(IDC_RADIO5, OnFogEXP2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEnvironmentSetDlg message handlers


void CEnvironmentSetDlg::OnCheckDepth() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	this->m_pView->m_DepthFlag=this->m_depthFlag;
	this->m_pView->RealEnvironmentSet();
	this->m_pView->Invalidate();
	UpdateData(FALSE);
}

void CEnvironmentSetDlg::OnCheckLighting() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	this->m_pView->m_LightFlag=this->m_lightFlag;
	this->m_pView->RealEnvironmentSet();
	this->m_pView->Invalidate();
	UpdateData(FALSE);
}

void CEnvironmentSetDlg::OnCheckLight0() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	this->m_pView->m_Light0Flag=this->m_light0;
	this->m_pView->RealEnvironmentSet();
	this->m_pView->Invalidate();
	UpdateData(FALSE);
}

void CEnvironmentSetDlg::OnCheckLight1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	this->m_pView->m_Light1Flag=this->m_light1;
	this->m_pView->RealEnvironmentSet();
	this->m_pView->Invalidate();
	UpdateData(FALSE);
}

void CEnvironmentSetDlg::OnCheckLightModel() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	this->m_pView->m_LightModelFlag =this->m_lightModelFlag;
	this->m_pView->RealEnvironmentSet();
	this->m_pView->Invalidate();
	UpdateData(FALSE);
}

void CEnvironmentSetDlg::OnCheckMatColor() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	this->m_pView->m_MaterialColorFlag =this->m_colorMaterialFlag;
	this->m_pView->RealEnvironmentSet();
	this->m_pView->Invalidate();
	UpdateData(FALSE);
}

void CEnvironmentSetDlg::OnCheckEmission() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	this->m_pView->m_MatEmissionFlag =this->m_emissionFlag;
	this->m_pView->RealEnvironmentSet();
	this->m_pView->Invalidate();
	UpdateData(FALSE);
}

void CEnvironmentSetDlg::OnBGColor() 
{
	// TODO: Add your control notification handler code here
	CColorDialog dlg;
	dlg.m_cc.Flags |= CC_RGBINIT|CC_FULLOPEN;
	dlg.m_cc.rgbResult=RGB((GLuint)(this->m_pView->m_iR_BG*255),(GLuint)(this->m_pView->m_iG_BG*255),(GLuint)(this->m_pView->m_iB_BG*255));
	if(IDOK==dlg.DoModal()){
		COLORREF m_clr=dlg.m_cc.rgbResult;  //拿到拾取的颜色
		this->m_pView->m_iR_BG=GetRValue(m_clr)/255.0;
		this->m_pView->m_iG_BG=GetGValue(m_clr)/255.0;
		this->m_pView->m_iB_BG=GetBValue(m_clr)/255.0;
		this->m_pView->RealEnvironmentSet();
		this->m_pView->Invalidate();
	}
}

void CEnvironmentSetDlg::OnFogDisable() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	this->m_pView->m_FogMode=this->m_fogMode;
	this->m_pView->SetFogMode();
	UpdateData(FALSE);
}

void CEnvironmentSetDlg::OnFogLinear() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	this->m_pView->m_FogMode=this->m_fogMode;
	this->m_pView->SetFogMode();
	UpdateData(FALSE);
}

void CEnvironmentSetDlg::OnFogEXP() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	this->m_pView->m_FogMode=this->m_fogMode;
	this->m_pView->SetFogMode();
	UpdateData(FALSE);
}

void CEnvironmentSetDlg::OnFogEXP2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	this->m_pView->m_FogMode=this->m_fogMode;
	this->m_pView->SetFogMode();
	UpdateData(FALSE);
}
