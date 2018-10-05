#pragma once

#define LEFT 0x00000001
#define RIGHT 0x00000002
#define UP 0x000000004
#define DOWN 0x00000008

//��ư Ű�� ����

//���� ���� ũ�� ����

#define STR_DEFAULT 256

#define DEFAULT_COLOR D3DCOLOR_ARGB(255,255,255,255)





#define SAFE_DELETE(x)   if(x != nullptr) {delete x; x=nullptr; }
#define SAFE_RELEASE(x)  if(x != nullptr) { x->Release(); }
//

#define DECLARE_SINGLETON(X)\
private: X();\
public: ~X();\
static X* pInstance;\
public: static X* GetInstance();\
//�̱��� ������� ����ȭ




#define IMPLEMENT_SINGLETON(X)\
X* X::pInstance = NULL;\
X* X::GetInstance(){if(pInstance == nullptr){ pInstance = new X();} return pInstance;}\
//�̱��� c++���� ����ȭ 

#define DEGREE_TO_RADIAN 3.141592 / 180

#include <windows.h>

extern HWND g_hWnd;