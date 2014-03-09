// kanren.cpp : �A�v���P�[�V�����̃N���X������`���܂��B
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


// CkanrenApp �R���X�g���N�V����

CkanrenApp::CkanrenApp()
{
	// TODO: ���̈ʒu�ɍ\�z�p�R�[�h��ǉ����Ă��������B
	// ������ InitInstance ���̏d�v�ȏ��������������ׂċL�q���Ă��������B
}


// �B��� CkanrenApp �I�u�W�F�N�g�ł��B

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


// CkanrenApp ������

BOOL CkanrenApp::InitInstance()
{
	CWinApp::InitInstance();

	//              EXT              DESC                ICON
	SetFileType(    _T(".ts")       , _T("*** .ts ***")                           , NULL );
	SetFileType(    _T(".mp4")      , _T("�����^�X�N (mp4)")                      , NULL );

	SetFileType(    _T(".cnf")      , _T("�ݒ�")                                  , NULL );
	SetFileType(    _T(".conf")     , _T("�ݒ�")                                  , NULL );
	SetFileType(    _T(".cpp")      , _T("C++ �\�[�X�t�@�C��")                    , NULL );
	SetFileType(    _T(".cxx")      , _T("C++ �\�[�X�t�@�C��")                    , NULL );
	SetFileType(    _T(".c")        , _T("C �\�[�X�t�@�C��")                      , NULL );
	SetFileType(    _T(".h")        , _T("C �w�b�_�t�@�C��")                      , NULL );
	SetFileType(    _T(".hpp")      , _T("C++ �w�b�_�t�@�C��")                    , NULL );
	SetFileType(    _T(".hxx")      , _T("C++ �w�b�_�t�@�C��")                    , NULL );
	SetFileType(    _T(".pm")       , _T("Perl ���W���[��")                       , NULL );
	SetFileType(    _T(".mod")      , _T("���W���[�����ԃt�@�C��")                , NULL );
	SetFileType(    _T(".order")    , _T("���W���[�����ԃt�@�C��")                , NULL );
	SetFileType(    _T(".symvers")  , _T("�J�[�l��EXPORT���X�g")                  , NULL );
	SetFileType(    _T(".bas")      , _T("VB���W���[��")                          , NULL );
	SetFileType(    _T(".txt")      , _T("�e�L�X�g")                              , NULL );
	SetFileType(    _T(".tsv")      , _T("TSV �e�L�X�g")                          , NULL );
	SetFileType(    _T(".csv")      , _T("CSV �e�L�X�g")                          , NULL );
	SetFileType(    _T(".inc")      , _T("include")                               , NULL );
	SetFileType(    _T(".hoge")     , _T("�e�L�X�g hoge")                         , NULL );
	SetFileType(    _T(".def")      , _T("���W���[����`�t�@�C��")                , NULL );
	SetFileType(    _T(".asm")      , _T("�A�Z���u��")                            , NULL );
	SetFileType(    _T(".sh")       , _T("�V�F���X�N���v�g")                      , NULL );
	SetFileType(    _T(".vbs")      , _T("VB�X�N���v�g")                          , NULL );
	SetFileType(    _T(".log")      , _T("���O�t�@�C��")                          , NULL );
	SetFileType(    _T(".img")      , _T("img")                                   , NULL );
	SetFileType(    _T(".bin")      , _T("bin")                                   , NULL );
	SetFileType(    _T(".tmp")      , _T("�e���|����")                            , NULL );
	SetFileType(    _T(".crf")      , _T("�����J ���X�|���X �t�@�C��")            , NULL );
	SetFileType(    _T(".swp")      , _T("�X���b�v")                              , NULL );
	SetFileType(    _T(".a")        , _T("�ÓI�A�[�J�C�o�I�u�W�F�N�g")            , NULL );
	SetFileType(    _T(".ko")       , _T("�h���C�o")                              , NULL );
	SetFileType(    _T(".ld")       , _T("�}�b�s���O���[��")                      , NULL );
	SetFileType(    _T(".ilk")      , _T("�C���N�������^�� �����N���t�@�C��")   , NULL );
	SetFileType(    _T(".iln")      , _T("�C�����C���֐��t�@�C��")                , NULL );
	SetFileType(    _T(".ncb")      , _T("�p�[�T�[���t�@�C��")                  , NULL );
	SetFileType(    _T(".obj")      , _T("�ÓI�����N�I�u�W�F�N�g")                , NULL );
	SetFileType(    _T(".o")        , _T("�ÓI�����N�I�u�W�F�N�g")                , NULL );
	SetFileType(    _T(".pch")      , _T("�v���R���p�C���ς݃w�b�_")              , NULL );
	SetFileType(    _T(".aps")      , _T("���\�[�X �t�@�C���̃o�C�i����")         , NULL );
	SetFileType(    _T(".pdb")      , _T("�f�o�b�O�p��̓f�[�^�x�[�X")            , NULL );
	SetFileType(    _T(".sbr")      , _T("�\�[�X�u���E�U�t�@�C��")                , NULL );
	SetFileType(    _T(".bsc")      , _T("�\�[�X�u���E�U�f�[�^�x�[�X�t�@�C��")    , NULL );
	SetFileType(    _T(".exp")      , _T("�G�N�X�|�[�g �t�@�C��")                 , NULL );
	SetFileType(    _T(".hpj")      , _T("�󋵈ˑ��w���v �v���W�F�N�g �t�@�C��")  , NULL );
	SetFileType(    _T(".res")      , _T("�R���p�C�����ꂽ���\�[�X �t�@�C��")     , NULL );
	SetFileType(    _T(".clw")      , _T("Class Wizard �X�e�[�^�X�t�@�C��")       , NULL );
	SetFileType(    _T(".bak")      , _T("�o�b�N�A�b�v")                          , NULL );


	::SHChangeNotify(SHCNE_ASSOCCHANGED, 
		((SHCNF_IDLIST) & SHCNF_TYPE) /* | SHCNF_FLUSHNOWAIT */
		, NULL, NULL); 


	return FALSE;
}
