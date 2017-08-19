#pragma once

#include "YYUT.h"

struct Frustum
{
	XMFLOAT3 Origin;				//ԭ��
	XMFLOAT4 Orientation;			//����
	float RightSlope;				//��ƽ��Ƕȣ�����FOV��һ�룬����������
	float LeftSlope;				//��ƽ��ĽǶȣ�FOV��һ�룬����
	float TopSlope;					//��ƽ��ĽǶȣ�
	float BottomSlope;				//��ƽ��ĽǶ�
	float Near, Far;					//��ƽ�棬Զƽ��
};
//������͸��ͶӰ��������׶���������Ϊ��׼�ĶԳ�͸��ͶӰ����
void ComputeFrustumFromProjection(Frustum *pOut, CXMMATRIX projection);