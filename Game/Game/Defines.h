#pragma once

#define LEFT 0x00000001
#define RIGHT 0x00000002
#define UP 0x000000004
#define DOWN 0x00000008

#define A_KEY 0x00000010
#define B_KEY 0x00000020

//��ư Ű�� ����

#define WINCX 1200
#define WINCY 800


#define GAMESIZE_X 600
#define GAMESIZE_Y 800

//���� ���� ũ�� ����

#define NULL nullptr

#define SAFE_DELETE(x)   if(x != nullptr) {delete x; x=nullptr; }
#define SAFE_RELEASE(x)  if(x != nullptr) { x->Release(); }
//

#define DECLARE_SINGLETON(X)\
private: X();~X();\
static X* pInstance;\
public: static X* GetInstance();\
//�̱��� ������� ����ȭ




#define IMPLEMENT_SINGLETON(X)\
X* X::pInstance = NULL;\
X* X::GetInstance(){if(pInstance == nullptr){ pInstance = new X();} return pInstance; }\
//�̱��� c++���� ����ȭ 



