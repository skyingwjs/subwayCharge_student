#if _SUBWAY_LLT
#include <gtest/gtest.h>
#include "mockcpp/mockcpp.hpp"
#include "subwayCmdProc/include/subwayQueryLineProc.h"
#include "subwayCmdParse/subwayCmdParse.h"

using namespace testing;

class subwayQueryLineTest : public testing::Test
{
public:
	//测试套级别事件
	//在测试套中包含的用例运行前运行一次
	static void SetUpTestCase()
	{
	}

	//在测试套中包含的用例运行全部运行结束后运行一次
	static void TearDownTestCase()
	{
	}

	//测试用例级别的事件
	//测试套中的每个用例开始运行前调用一次
	void SetUp()
	{
		//为减小测试测试套内用例之间的影响，这个可进行一些初始化动作
		//InitSubwayLine();
	}

	//测试套中每个用例结束后运行一次
	void TearDown()
	{
		//可进行一些动态内存的释放操作
	}
};

//测试查询地铁线路，输入L，成功
TEST_F(subwayQueryLineTest, QueryLineTest_ReturnSucc)
{
	//1 变量定义,初始化


	//2  用户写自己的测试流程，调用被测函数
	char returnStr[MAX_SEND_BUFFER_LENGTH];
	//UN_CMD &unCmd = NULL;
	//UN_CMD tmo = UN_CMD;
	//ProcQueryLineCmd(tmo, returnStr);

	EXPECT_TRUE("地铁线路：S0<->S1<->S2<->S3<->S4<->S5<->S6<->S7<->S8<->S9<->S10<->S11<->S12<->S13<->S14<->S15<->S16" == returnStr);

	//3  可以使用gtest的断言来进行用例通过与否的判断

}

#endif
