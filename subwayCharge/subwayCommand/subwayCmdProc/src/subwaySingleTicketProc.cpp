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
@ 办理单程票
@ 入参：unCmd, 命令内容
@ 出参: returnStr
@ 返回值: 无
*/
void ProcCreateSingleTicketCmd(UN_CMD &unCmd, char returnStr[MAX_SEND_BUFFER_LENGTH])
{
    //获取两个站点间的里程数 GetSubwayStationDis
	unsigned int dis = 0;
	unsigned int cardNo = 0;
	unsigned int basePrice = 0;

	EN_RETURN_CODE returnCode = GetSubwayStationDis(unCmd.stCmdSingleTicket.dstStation, unCmd.stCmdSingleTicket.srcStation, dis);
	
	if (returnCode == EN_RETURN_SUCC)
	{
		//获取两个站点间的基本票价  GetBasePrice
		basePrice = GetBasePrice(dis);
		//办单程卡 AssignCard
		returnCode = AssignCard(cardNo, EN_CARD_TYPE_SINGLE, basePrice);
	}
    //输出字符串
    GetOutputResultStr(EN_CMD_TYPE_SINGLE_TICKET, returnCode, cardNo, EN_CARD_TYPE_SINGLE, basePrice, returnStr);
    return;
}