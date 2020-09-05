#pragma once
#include "CommonClass.h"
class CPlayer :
    public CAnimateSprite
{
private:
    int         m_iPlayerState;   // 人物状态 0: 静止站立; 1: 移动; 2: 攻击
    
    // 各个方向的速度
    float       m_fSpeedLeft;     // 向左的速度
    float       m_fSpeedRight;    // 向右的速度
    float       m_fSpeedTop;      // 向上的速度
    float       m_fSpeedBottom;   // 向下的速度

    // 基础属性
    int         m_iHP;            // 生命值
    int         m_iMP;            // 蓝条

public:
    CPlayer(const char* szName);

    // set方法
    void SetSpeedLeft(float speed) { m_fSpeedLeft = speed, m_fSpeedRight = 0; }
    void SetSpeedRight(float speed) { m_fSpeedRight = speed, m_fSpeedLeft = 0; }
    void SetSpeedTop(float speed) { m_fSpeedTop = speed, m_fSpeedTop = 0; }
    void SetSpeedBottom(float speed) { m_fSpeedBottom = speed, m_fSpeedBottom = 0; }

    void SetHP(int i) { m_iHP = i; }
    void SetMP(int i) { m_iMP = i; }

    // get方法
    float GetLeftSpeed() { return m_fSpeedLeft - m_fSpeedRight; }
    float GetRightSpeed() { return m_fSpeedRight - m_fSpeedLeft; }
    float GetTopSpeed() { return m_fSpeedTop - m_fSpeedBottom; }
    float GetBottomSpeed() { return m_fSpeedBottom - m_fSpeedTop; }

    int GetHP() { return m_iHP; }
    int GetMP() { return m_iMP; }


    void OnMove(bool KeyPress, int iKey);
};

