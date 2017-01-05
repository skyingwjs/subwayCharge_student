#include "stdafx.h"
#include <iostream>
#include "subwayGlobalDef.h"
#include "subwayMacro.h"
#include "subwayCard.h"
#include "subwayline.h"
#include "subwayPrice.h"
#include "subwayCommon.h"
#include "subwayError.h"
#include "subwayCmdParse/subwayCmdParse.h"
#include "subwayOutput/subwayOutput.h"
using namespace std;

/*
@ ������Ʊ
@ ��Σ�unCmd, ��������
@ ����: returnStr
@ ����ֵ: ��
*/
void ProcCreateSingleTicketCmd(UN_CMD &unCmd, char returnStr[MAX_SEND_BUFFER_LENGTH])
{
    //��ȡ����վ��������� GetSubwayStationDis
	unsigned int dis = 0;
	unsigned int cardNo = 0;
	unsigned int basePrice = 0;

	EN_RETURN_CODE returnCode = GetSubwayStationDis(unCmd.stCmdSingleTicket.dstStation, unCmd.stCmdSingleTicket.srcStation, dis);
	
	if (returnCode == EN_RETURN_SUCC)
	{
		//��ȡ����վ���Ļ���Ʊ��  GetBasePrice
		basePrice = GetBasePrice(dis);
		//�쵥�̿� AssignCard
		returnCode = AssignCard(cardNo, EN_CARD_TYPE_SINGLE, basePrice);
	}
    //����ַ���
    GetOutputResultStr(EN_CMD_TYPE_SINGLE_TICKET, returnCode, cardNo, EN_CARD_TYPE_SINGLE, basePrice, returnStr);
    return;
}