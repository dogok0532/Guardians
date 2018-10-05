#pragma once

#define LEFT 0x00000001
#define RIGHT 0x00000002
#define UP 0x000000004
#define DOWN 0x00000008

//버튼 키값 정의

//가로 세로 크기 정의

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
//싱글톤 헤더파일 간략화




#define IMPLEMENT_SINGLETON(X)\
X* X::pInstance = NULL;\
X* X::GetInstance(){if(pInstance == nullptr){ pInstance = new X();} return pInstance;}\
//싱글톤 c++파일 간략화 

#define DEGREE_TO_RADIAN 3.141592 / 180

#include <windows.h>

extern HWND g_hWnd;