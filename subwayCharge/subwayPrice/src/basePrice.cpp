#include "stdafx.h"
#include <iostream>
#include  <sstream>
#include "subwayMacro.h"
#include "include/basePrice.h"
using namespace std;

/*
@ ��ȡ����Ʊ��, ������վ�����վ��֮��������̷ּ�����
@ -1, ��ѯ����Ʊ��ʧ��; ����, ����Ʊ��
*/
int GetBasePrice(unsigned int meters)
{
	if (meters < 0) 
	{
		return -1;
	}
	else if (meters <= 3000) 
	{
		return 2;
	}
	else if (meters <= 5000) 
	{
		return 3;
	}
	else if (meters <= 14000) 
	{
		return 4;
	}
	else 
		return 5;
}