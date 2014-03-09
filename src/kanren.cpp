// kanren.cpp : アプリケーションのクラス動作を定義します。
//

#include "stdafx.h"
#include "kanren.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CkanrenApp

BEGIN_MESSAGE_MAP(CkanrenApp, CWinApp)
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()


// CkanrenApp コンストラクション

CkanrenApp::CkanrenApp()
{
	// TODO: この位置に構築用コードを追加してください。
	// ここに InitInstance 中の重要な初期化処理をすべて記述してください。
}


// 唯一の CkanrenApp オブジェクトです。

CkanrenApp theApp;


BOOL SetFileType(LPCTSTR ext, LPCTSTR desc, LPCTSTR icon)
{
	ULONG ulLen;
	CString key;
	CString buff;

	CRegKey reg;
	if(reg.Open(HKEY_CLASSES_ROOT,ext,KEY_READ) != ERROR_SUCCESS) return FALSE;
	ulLen = MAX_PATH;
	if(reg.QueryStringValue(_T(""),key.GetBuffer(MAX_PATH + 1),&ulLen) != ERROR_SUCCESS) return FALSE;
	if(reg.Close()) return FALSE;
	key.ReleaseBuffer();

	if(reg.Open(HKEY_CLASSES_ROOT,key,KEY_READ) != ERROR_SUCCESS) return FALSE;
	ulLen = MAX_PATH;
	if(reg.QueryStringValue(_T(""),buff.GetBuffer(MAX_PATH + 1),&ulLen) != ERROR_SUCCESS) return FALSE;
	buff.ReleaseBuffer();

	if(reg.SetValue(HKEY_CLASSES_ROOT, key, desc, _T(""))) return FALSE;

	if( icon ) {
		if(reg.SetValue(HKEY_CLASSES_ROOT, key + _T("\\DefaultIcon"), icon, _T(""))) return FALSE;
	}

	if(reg.Close()) return FALSE;
	return TRUE;
}


// CkanrenApp 初期化

BOOL CkanrenApp::InitInstance()
{
	CWinApp::InitInstance();

	//              EXT              DESC                ICON
	SetFileType(    _T(".ts")       , _T("*** .ts ***")                           , NULL );
	SetFileType(    _T(".mp4")      , _T("完了タスク (mp4)")                      , NULL );

	SetFileType(    _T(".cnf")      , _T("設定")                                  , NULL );
	SetFileType(    _T(".conf")     , _T("設定")                                  , NULL );
	SetFileType(    _T(".cpp")      , _T("C++ ソースファイル")                    , NULL );
	SetFileType(    _T(".cxx")      , _T("C++ ソースファイル")                    , NULL );
	SetFileType(    _T(".c")        , _T("C ソースファイル")                      , NULL );
	SetFileType(    _T(".h")        , _T("C ヘッダファイル")                      , NULL );
	SetFileType(    _T(".hpp")      , _T("C++ ヘッダファイル")                    , NULL );
	SetFileType(    _T(".hxx")      , _T("C++ ヘッダファイル")                    , NULL );
	SetFileType(    _T(".pm")       , _T("Perl モジュール")                       , NULL );
	SetFileType(    _T(".mod")      , _T("モジュール中間ファイル")                , NULL );
	SetFileType(    _T(".order")    , _T("モジュール中間ファイル")                , NULL );
	SetFileType(    _T(".symvers")  , _T("カーネルEXPORTリスト")                  , NULL );
	SetFileType(    _T(".bas")      , _T("VBモジュール")                          , NULL );
	SetFileType(    _T(".txt")      , _T("テキスト")                              , NULL );
	SetFileType(    _T(".tsv")      , _T("TSV テキスト")                          , NULL );
	SetFileType(    _T(".csv")      , _T("CSV テキスト")                          , NULL );
	SetFileType(    _T(".inc")      , _T("include")                               , NULL );
	SetFileType(    _T(".hoge")     , _T("テキスト hoge")                         , NULL );
	SetFileType(    _T(".def")      , _T("モジュール定義ファイル")                , NULL );
	SetFileType(    _T(".asm")      , _T("アセンブリ")                            , NULL );
	SetFileType(    _T(".sh")       , _T("シェルスクリプト")                      , NULL );
	SetFileType(    _T(".vbs")      , _T("VBスクリプト")                          , NULL );
	SetFileType(    _T(".log")      , _T("ログファイル")                          , NULL );
	SetFileType(    _T(".img")      , _T("img")                                   , NULL );
	SetFileType(    _T(".bin")      , _T("bin")                                   , NULL );
	SetFileType(    _T(".tmp")      , _T("テンポラリ")                            , NULL );
	SetFileType(    _T(".crf")      , _T("リンカ レスポンス ファイル")            , NULL );
	SetFileType(    _T(".swp")      , _T("スワップ")                              , NULL );
	SetFileType(    _T(".a")        , _T("静的アーカイバオブジェクト")            , NULL );
	SetFileType(    _T(".ko")       , _T("ドライバ")                              , NULL );
	SetFileType(    _T(".ld")       , _T("マッピングルール")                      , NULL );
	SetFileType(    _T(".ilk")      , _T("インクリメンタル リンク情報ファイル")   , NULL );
	SetFileType(    _T(".iln")      , _T("インライン関数ファイル")                , NULL );
	SetFileType(    _T(".ncb")      , _T("パーサー情報ファイル")                  , NULL );
	SetFileType(    _T(".obj")      , _T("静的リンクオブジェクト")                , NULL );
	SetFileType(    _T(".o")        , _T("静的リンクオブジェクト")                , NULL );
	SetFileType(    _T(".pch")      , _T("プリコンパイル済みヘッダ")              , NULL );
	SetFileType(    _T(".aps")      , _T("リソース ファイルのバイナリ版")         , NULL );
	SetFileType(    _T(".pdb")      , _T("デバッグ用解析データベース")            , NULL );
	SetFileType(    _T(".sbr")      , _T("ソースブラウザファイル")                , NULL );
	SetFileType(    _T(".bsc")      , _T("ソースブラウザデータベースファイル")    , NULL );
	SetFileType(    _T(".exp")      , _T("エクスポート ファイル")                 , NULL );
	SetFileType(    _T(".hpj")      , _T("状況依存ヘルプ プロジェクト ファイル")  , NULL );
	SetFileType(    _T(".res")      , _T("コンパイルされたリソース ファイル")     , NULL );
	SetFileType(    _T(".clw")      , _T("Class Wizard ステータスファイル")       , NULL );
	SetFileType(    _T(".bak")      , _T("バックアップ")                          , NULL );


	::SHChangeNotify(SHCNE_ASSOCCHANGED, 
		((SHCNF_IDLIST) & SHCNF_TYPE) /* | SHCNF_FLUSHNOWAIT */
		, NULL, NULL); 


	return FALSE;
}
