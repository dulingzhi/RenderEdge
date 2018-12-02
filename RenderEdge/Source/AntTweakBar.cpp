#include "AntTweakBar.h"
#include "Engine.h"


CAntTweakBar* AntTweakBar = nullptr;

CAntTweakBar::CAntTweakBar(IDirect3DDevice9* pDevice)
{
	m_pDevice = pDevice;
	bActive = true;

	OnResetDevice();
}

CAntTweakBar::~CAntTweakBar()
{
	TwTerminate();
}


//void CAntTweakBar::OnResetDevice()
//{
//	
//}

void CAntTweakBar::OnLostDevice()
{
	TwTerminate();
}

bool CAntTweakBar::OnGetMessage(HWND ah_Wnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (!bActive)
		return false;

	return TwEventWin(ah_Wnd, uMsg, wParam, lParam);
}

void CAntTweakBar::Render()
{
	if (!bActive)
		return;

	TwDraw();
}

void CAntTweakBar::SetActive(bool value)
{
	bActive = value;

	if (bActive)
	{
	}
}

bool CAntTweakBar::GetActive()
{
	return bActive;
}