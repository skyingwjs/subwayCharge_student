#include "stdafx.h"
#include <iostream>
#include "list.h"
#include "subwayGlobalDef.h"
#include "subwayMacro.h"
#include "subwayCard.h"
using namespace std;

Subway_Card subway_card[MAX_CARD_NUM];

char card_type_str[MAX_CARD_TYPE_NUM + 1][16]{
	"单程票",
	"老年票",
	"普通卡",
	"未知卡"
};

//新增
//初始化单个卡信息
void InitSingleCard(unsigned int cardNo)
{
	subway_card[cardNo].card_balance = 0;
	subway_card[cardNo].card_flag = 0;
	subway_card[cardNo].card_No = 200;
	subway_card[cardNo].card_type = EN_CARD_TYPE_BUTT;
}

//新增
//判断卡号是否有效
EN_RETURN_CODE IsInvalidCard(unsigned int &cardNo)
{
	if (cardNo > MAX_CARD_NUM - 1 || cardNo < 0)
		return EN_RETURN_INVALID_CARD;
	if (0 == subway_card[cardNo].card_flag)
		return EN_RETURN_INVALID_CARD;
	return EN_RETURN_SUCC;
}


/*
@ 初始化所有卡信息
@ 返回值: 无
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
@ 开卡，分配卡号和卡信息
@ 入参：enCard,卡类型; charge: 充值
@ 出参: cardNo, 分配的卡号
@ 返回值: EN_RETURN_SUCC，分配成功; EN_RETURN_CARD_OVERLOW, 分配失败;
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
@ 充值
@ 入参：cardNo,卡号; recharge: 充值
@ 出参: 无
@ 返回值: EN_RETURN_SUCC，成功; 其他, 失败;
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
@ 获取卡余额
@ 入参：cardNo,卡号; 
@ 出参: balance: 余额
        enCard:  卡类型
@ 返回值: EN_RETURN_SUCC，成功; EN_RETURN_INVALID_CARD, 失败;
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
@ 卡扣费
@ 入参：cardNo,卡号; enCard, 卡类型; deductPrice, 扣费票价
@ 出参: balance, 扣费后的余额
@ 返回值: EN_RETURN_SUCC，成功; EN_RETURN_INVALID_CARD, EN_RETURN_BALANCE_NOT_ENOUGH, 失败;
*/
EN_RETURN_CODE DeductCard(unsigned int cardNo, EN_CARD_TYPE enCard, unsigned int deductPrice, unsigned int &balance)
{
	if (EN_RETURN_INVALID_CARD == IsInvalidCard(cardNo))
		return EN_RETURN_INVALID_CARD;
	if (subway_card[cardNo].card_balance - deductPrice < 0)
		return EN_RETURN_BALANCE_NOT_ENOUGH;
	if (subway_card[cardNo].card_type == EN_CARD_TYPE_SINGLE)
	{
		//销毁该信息
		DeleteCard(cardNo);
	}
	subway_card[cardNo].card_balance -= deductPrice;
	return EN_RETURN_SUCC;
}

/*
@ 删除卡信息
@ 入参：cardNo,卡号; 
@ 出参: 无
@ 返回值: 0，成功; -1, 失败;
*/
int DeleteCard(unsigned int cardNo)
{
	InitSingleCard(cardNo);
	return 0;
}

/*
@ 获取卡类型字符串
@ 入参：enCard,卡类型; 
@ 出参: 无
@ 返回值: 卡类型字符串;
*/
char* GetCardTypeStr(EN_CARD_TYPE enCard)
{
    return card_type_str[enCard];
}

/*
@ 根据卡类型字符串, 识别卡类型
@ 入参：cardType,      卡类型字符串; 
@ 出参: enCard,        卡类型
@ 返回值: EN_RETURN_SUCC，成功; EN_RETURN_INPUT_INVALID_CARDTYPE, 失败;
*/
EN_RETURN_CODE GetCardType(char cardType[], EN_CARD_TYPE &enCard)
{
    

    return EN_RETURN_SUCC;
}