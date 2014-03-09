// kanren.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです。
//

#pragma once

#ifndef __AFXWIN_H__
	#error このファイルを PCH に含める前に、'stdafx.h' を含めてください。
#endif

#include "resource.h"		// メイン シンボル


// CkanrenApp:
// このクラスの実装については、kanren.cpp を参照してください。
//

class CkanrenApp : public CWinApp
{
public:
	CkanrenApp();

// オーバーライド
	public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CkanrenApp theApp;
