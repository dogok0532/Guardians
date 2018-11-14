#pragma once



#define	KEY_DOWN  0x01
#define KEY_RIGHT  0x02
#define	KEY_UP  0x04
#define	KEY_LEFT  0x08

enum eWay
{
	WAY_RIGHT=0,
	WAY_RIGHT_DOWN,
	WAY_DOWN,
	WAY_LEFT_DOWN,
	WAY_LEFT,
	WAY_LEFT_UP,
	WAY_UP,
	WAY_RIGHT_UP,
	WAY_END,
};

enum eStatus
{
					//	반복	직진형	다음Sprite가 있음
	STOP_IDLE,		//	O		X		-
	STOP_AIM,		//	O		-		-
	STOP_FIRE,		//	O		-		O
					//
	CROUCH,			//	-		-		X
	CROUCH_AIM,		//	-		-		X
	CROUCH_FIRE,	//	-		-		O
					//
					//
	WALK,			//	O		O		X
	WALK_AIM,		//	O		O		X
	WALK_FIRE,		//	O		O		O
					//
					//
	THROW_GRANADE,	//	X		O		O
					//
	HIT,			//	X		O		X
	HIT_BLOOD,		//	X		O		X
	HIT_EXPLODE,	//	X		O		X
};