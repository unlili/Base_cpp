#define WIN32_LEAN_AND_MEAN  //防止windows.h和WinSock2.h冲突
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include<iostream>
#include<windows.h>
#include<WinSock2.h>
using std::cout;
using std::cin;
/* #pragma comment(lib,"ws2_32.lib")  //WSAStartup()需要的静态库 */

int main()
{
	//启动windows socket 2.x 环境
	WORD ver = MAKEWORD(2, 2);//创建版本号
	WSADATA dat;
	WSAStartup(ver, &dat);

	//1 建立一个socket
	SOCKET _sock = socket(AF_INET, SOCK_STREAM, 0);/*ipv4，数据流,TCP*/
	if (INVALID_SOCKET == _sock)
	{
		cout << "建立socket失败。。。" << "\n";
	}
	else
	{
		cout << "建立socket成功。。。" << "\n";
	}


	//2 连接服务器
	sockaddr_in  _sin = {};
	_sin.sin_family = AF_INET;
	_sin.sin_port = htons(4567);
	_sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");


	int ret = connect(_sock, (sockaddr *)&_sin, sizeof(sockaddr_in));
	if (SOCKET_ERROR == ret)
	{
		cout << "建立socket失败。。。" << "\n";
	}
	else
	{
		cout << "建立socket成功。。。" << "\n";
	}


	for (;;)
	{
		char cmdBuf[128] = {};
		cout << "请输入命令" << "\n";
		cin >> cmdBuf;	//3 用户输入请求命令


		//处理请求
		if (0 == strcmp(cmdBuf, "exit")){
			break;
		}
		else {
			//向服务端发送请求	
			send(_sock, cmdBuf, strlen(cmdBuf) + 1, 0);
		}

		//6 接受信息
		char recvBuf[128] = {};
		int nken = recv(_sock, recvBuf, 128, 0);/*socket  buffer  buffer大小  默认*/
		if (nken>0)
			cout << recvBuf << "\n";
		else
			cout << "接收失败" << "\n";
	}

	//7 关闭
	closesocket(_sock);

	//关闭windows socket 2.x 环境
	WSACleanup();
	cout << "任务结束";
	system("pause");
	return 0;
}
