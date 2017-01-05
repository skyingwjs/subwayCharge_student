#if _SUBWAY_LLT
#include <gtest/gtest.h>
#include "mockcpp/mockcpp.hpp"
#include "subwayCmdProc/include/subwayQueryLineProc.h"
#include "subwayCmdParse/subwayCmdParse.h"

using namespace testing;

class subwayQueryLineTest : public testing::Test
{
public:
	//�����׼����¼�
	//�ڲ������а�������������ǰ����һ��
	static void SetUpTestCase()
	{
	}

	//�ڲ������а�������������ȫ�����н���������һ��
	static void TearDownTestCase()
	{
	}

	//��������������¼�
	//�������е�ÿ��������ʼ����ǰ����һ��
	void SetUp()
	{
		//Ϊ��С���Բ�����������֮���Ӱ�죬����ɽ���һЩ��ʼ������
		//InitSubwayLine();
	}

	//��������ÿ����������������һ��
	void TearDown()
	{
		//�ɽ���һЩ��̬�ڴ���ͷŲ���
	}
};

//���Բ�ѯ������·������L���ɹ�
TEST_F(subwayQueryLineTest, QueryLineTest_ReturnSucc)
{
	//1 ��������,��ʼ��


	//2  �û�д�Լ��Ĳ������̣����ñ��⺯��
	char returnStr[MAX_SEND_BUFFER_LENGTH];
	//UN_CMD &unCmd = NULL;
	//UN_CMD tmo = UN_CMD;
	//ProcQueryLineCmd(tmo, returnStr);

	EXPECT_TRUE("������·��S0<->S1<->S2<->S3<->S4<->S5<->S6<->S7<->S8<->S9<->S10<->S11<->S12<->S13<->S14<->S15<->S16" == returnStr);

	//3  ����ʹ��gtest�Ķ�������������ͨ�������ж�

}

#endif
