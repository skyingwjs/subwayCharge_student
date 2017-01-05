#include "stdafx.h"
#include <iostream>
#include "list.h"
#include "subwayGlobalDef.h"
#include "subwayMacro.h"
#include "subwayCard.h"
using namespace std;

Subway_Card subway_card[MAX_CARD_NUM];

char card_type_str[MAX_CARD_TYPE_NUM + 1][16]{
	"����Ʊ",
	"����Ʊ",
	"��ͨ��",
	"δ֪��"
};

//����
//��ʼ����������Ϣ
void InitSingleCard(unsigned int cardNo)
{
	subway_card[cardNo].card_balance = 0;
	subway_card[cardNo].card_flag = 0;
	subway_card[cardNo].card_No = 200;
	subway_card[cardNo].card_type = EN_CARD_TYPE_BUTT;
}

//����
//�жϿ����Ƿ���Ч
EN_RETURN_CODE IsInvalidCard(unsigned int &cardNo)
{
	if (cardNo > MAX_CARD_NUM - 1 || cardNo < 0)
		return EN_RETURN_INVALID_CARD;
	if (0 == subway_card[cardNo].card_flag)
		return EN_RETURN_INVALID_CARD;
	return EN_RETURN_SUCC;
}


/*
@ ��ʼ�����п���Ϣ
@ ����ֵ: ��
*/
void InitCardManagerInfo()
{
	int i = 0;
	for (; i < 100; ++i)
	{
		InitSingleCard(i);
	}
}
/*
@ ���������俨�źͿ���Ϣ
@ ��Σ�enCard,������; charge: ��ֵ
@ ����: cardNo, ����Ŀ���
@ ����ֵ: EN_RETURN_SUCC������ɹ�; EN_RETURN_CARD_OVERLOW, ����ʧ��;
*/
EN_RETURN_CODE AssignCard(unsigned int &cardNo, EN_CARD_TYPE enCard, unsigned int charge)
{
	int i = 0;
	for (; i < MAX_CARD_NUM; ++i)
	{
		if (0 == subway_card[i].card_flag)
		{
			cardNo = i;
			subway_card[i].card_flag = 1;
			break;
		}
	}
	if (MAX_CARD_NUM == i)
		return EN_RETURN_CARD_OVERLOW;

	return EN_RETURN_SUCC;
}

/*
@ ��ֵ
@ ��Σ�cardNo,����; recharge: ��ֵ
@ ����: ��
@ ����ֵ: EN_RETURN_SUCC���ɹ�; ����, ʧ��;
*/
EN_RETURN_CODE RechargeCard(unsigned int cardNo, unsigned int recharge)
{
	unsigned int balance_temp;
	EN_CARD_TYPE enCard_temp;
	EN_RETURN_CODE ret;
	ret = GetCardInfo(cardNo, balance_temp, enCard_temp);
	if (EN_RETURN_INVALID_CARD == ret)
		return EN_RETURN_INVALID_CARD;
	if (subway_card[cardNo].card_balance + recharge > MAX_BALANCE)
		return EN_RETURN_RECHARGE_OVERFLOW;
	subway_card[cardNo].card_balance += recharge;
	return EN_RETURN_SUCC;
}

/*
@ ��ȡ�����
@ ��Σ�cardNo,����; 
@ ����: balance: ���
        enCard:  ������
@ ����ֵ: EN_RETURN_SUCC���ɹ�; EN_RETURN_INVALID_CARD, ʧ��;
*/
EN_RETURN_CODE GetCardInfo(unsigned int cardNo, unsigned int &balance, EN_CARD_TYPE &enCard)
{
	if (EN_RETURN_INVALID_CARD == IsInvalidCard(cardNo))
		return EN_RETURN_INVALID_CARD;
	balance = subway_card[cardNo].card_balance;
	enCard = subway_card[cardNo].card_type;
	return EN_RETURN_SUCC;
}

/*
@ ���۷�
@ ��Σ�cardNo,����; enCard, ������; deductPrice, �۷�Ʊ��
@ ����: balance, �۷Ѻ�����
@ ����ֵ: EN_RETURN_SUCC���ɹ�; EN_RETURN_INVALID_CARD, EN_RETURN_BALANCE_NOT_ENOUGH, ʧ��;
*/
EN_RETURN_CODE DeductCard(unsigned int cardNo, EN_CARD_TYPE enCard, unsigned int deductPrice, unsigned int &balance)
{
	if (EN_RETURN_INVALID_CARD == IsInvalidCard(cardNo))
		return EN_RETURN_INVALID_CARD;
	if (subway_card[cardNo].card_balance - deductPrice < 0)
		return EN_RETURN_BALANCE_NOT_ENOUGH;
	if (subway_card[cardNo].card_type == EN_CARD_TYPE_SINGLE)
	{
		//���ٸ���Ϣ
		DeleteCard(cardNo);
	}
	subway_card[cardNo].card_balance -= deductPrice;
	return EN_RETURN_SUCC;
}

/*
@ ɾ������Ϣ
@ ��Σ�cardNo,����; 
@ ����: ��
@ ����ֵ: 0���ɹ�; -1, ʧ��;
*/
int DeleteCard(unsigned int cardNo)
{
	InitSingleCard(cardNo);
	return 0;
}

/*
@ ��ȡ�������ַ���
@ ��Σ�enCard,������; 
@ ����: ��
@ ����ֵ: �������ַ���;
*/
char* GetCardTypeStr(EN_CARD_TYPE enCard)
{
    return card_type_str[enCard];
}

/*
@ ���ݿ������ַ���, ʶ������
@ ��Σ�cardType,      �������ַ���; 
@ ����: enCard,        ������
@ ����ֵ: EN_RETURN_SUCC���ɹ�; EN_RETURN_INPUT_INVALID_CARDTYPE, ʧ��;
*/
EN_RETURN_CODE GetCardType(char cardType[], EN_CARD_TYPE &enCard)
{
    

    return EN_RETURN_SUCC;
}