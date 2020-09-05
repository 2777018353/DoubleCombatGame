#pragma once
#include "CommonClass.h"
class CPlayer :
    public CAnimateSprite
{
private:
    int         m_iPlayerState;   // ����״̬ 0: ��ֹվ��; 1: �ƶ�; 2: ����
    
    // ����������ٶ�
    float       m_fSpeedLeft;     // ������ٶ�
    float       m_fSpeedRight;    // ���ҵ��ٶ�
    float       m_fSpeedTop;      // ���ϵ��ٶ�
    float       m_fSpeedBottom;   // ���µ��ٶ�

    // ��������
    int         m_iHP;            // ����ֵ
    int         m_iMP;            // ����

public:
    CPlayer(const char* szName);

    // set����
    void SetSpeedLeft(float speed) { m_fSpeedLeft = speed, m_fSpeedRight = 0; }
    void SetSpeedRight(float speed) { m_fSpeedRight = speed, m_fSpeedLeft = 0; }
    void SetSpeedTop(float speed) { m_fSpeedTop = speed, m_fSpeedTop = 0; }
    void SetSpeedBottom(float speed) { m_fSpeedBottom = speed, m_fSpeedBottom = 0; }

    void SetHP(int i) { m_iHP = i; }
    void SetMP(int i) { m_iMP = i; }

    // get����
    float GetLeftSpeed() { return m_fSpeedLeft - m_fSpeedRight; }
    float GetRightSpeed() { return m_fSpeedRight - m_fSpeedLeft; }
    float GetTopSpeed() { return m_fSpeedTop - m_fSpeedBottom; }
    float GetBottomSpeed() { return m_fSpeedBottom - m_fSpeedTop; }

    int GetHP() { return m_iHP; }
    int GetMP() { return m_iMP; }


    void OnMove(bool KeyPress, int iKey);
};

