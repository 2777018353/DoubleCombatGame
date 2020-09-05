#include "CPlayer.h"

CPlayer::CPlayer(const char* szName) :CAnimateSprite(szName)
{
	m_fSpeedLeft = 0;
	m_fSpeedRight = 0;
	m_fSpeedTop = 0;
	m_fSpeedBottom = 0;

	m_iPlayerState = 0;

	m_iHP = 100;
	m_iMP = 0;
}
/////////////////////////////////////////////////////////////////////////////////
//
// 控制人物移动
// 参数 KeyPress: 是否按下按键(0: 否, 在KeyUp函数中使用; 1: 是, 在KeyDown函数中使用)
// 参数 iKey: 对应的按键
void CPlayer::OnMove(bool KeyPress, int iKey)
{
	if (KeyPress)
	{
		switch (iKey)
		{
		case KEY_W:
			m_fSpeedTop = 10;
			break;
		case KEY_A:
			m_fSpeedLeft = 15;
			break;
		case KEY_S:
			m_fSpeedBottom = 10;
			break;
		case KEY_D:
			m_fSpeedRight = 15;
			break;
		default:
			break;
		}
	}
	else
	{
		switch (iKey)
		{
		case KEY_W:
			m_fSpeedTop = 0;
			break;
		case KEY_A:
			m_fSpeedLeft = 0;
			break;
		case KEY_S:
			m_fSpeedBottom = 0;
			break;
		case KEY_D:
			m_fSpeedRight = 0;
			break;
		default:
			break;
		}
	}

	float fVelX = m_fSpeedRight - m_fSpeedLeft;
	float fVelY = m_fSpeedBottom - m_fSpeedTop;
	SetSpriteLinearVelocity(fVelX, fVelY);
	

	// 速度不为0时, 翻转
	if (fVelX < -0.0001 || fVelX > 0.0001)
	{
		if (fVelX > 0.0001)
			SetSpriteFlipX(0);
		else
			SetSpriteFlipX(1);
	}

	// 无操作时
	if (fVelX == 0 && fVelY == 0 && KeyPress == 0)
	{
		AnimateSpritePlayAnimation("p4standningAnimation", 0);
	}
	// 水平运动时
	if (fVelX != 0 && fVelY == 0 && KeyPress == 1)
	{
		AnimateSpritePlayAnimation("p4runningAnimation", 1);
	}
	// 跳跃时
	if (fVelY < 0)
	{
		AnimateSpritePlayAnimation("p4jumpingAnimation", 1);
	}
}