#pragma once

#define LEFT 0x00000001
#define RIGHT 0x00000002
#define UP 0x000000004
#define DOWN 0x00000008

#define A_KEY 0x00000010
#define B_KEY 0x00000020


#define DEFINE_SINGLETON(X)\
private: X();\
static X* pInstance;\
public: static X* GetInstance();\

#define IMPLEMENT_SINGLETON(x) 