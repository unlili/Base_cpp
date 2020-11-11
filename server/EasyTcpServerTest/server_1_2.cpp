#define WIN32_LEAN_AND_MEAN  //防止windows.h和WinSock2.h冲突
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include<iostream>
#include<windows.h>
#include<WinSock2.h>
using std::cout;
/* #pragma comment(lib,"ws2_32.lib")  //WSAStartup()需要的静态库 */

//数据包
struct DataPackge 
{
	int _age;
	char _name[32];
};

int main()
{
	//启动windows socket 2.x 环境
	WORD ver = MAKEWORD(2, 2);//创建版本号
	WSADATA dat;
	WSAStartup(ver, &dat);

	//1 建立一个socket
	SOCKET _sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);/*ipv4，数据流,TCP*/

	//2 绑定端口 bind  --> 绑定可能是不成功的
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET;
	_sin.sin_port = htons(4567);//host to net unsigned short
	_sin.sin_addr.S_un.S_addr = INADDR_ANY;//inet_addr("127.0.0.1");
	if (SOCKET_ERROR == bind(_sock, (sockaddr*)&_sin, sizeof(sockaddr_in)))
	{
		cout << "绑定失败。。。" << "\n";
	}
	else
	{
		cout << "绑定成功。。。" << "\n";
	}

	//3 监听网络端口 listen
	if (SOCKET_ERROR == listen(_sock, 5))  /*socket 人数*/
	{
		cout << "监听网络端口失败。。。" << "\n";
	}
	else
	{
		cout << "监听网络端口成功。。。" << "\n";
	}

	//4 accept 等待接受客户端连接 accept
	sockaddr_in clientAddr = {};
	int  clientAddrLen = sizeof(clientAddr);
	SOCKET _cSock = INVALID_SOCKET;//返回客户端socket

	_cSock = accept(_sock, (sockaddr *)&clientAddr, &clientAddrLen);
	if (_cSock == INVALID_SOCKET)
	{
		cout << "接受到无效客户端socket。。。" << "\n";
	}
	cout << "新客户端加入: socket = "<<_cSock << "IP = " << inet_ntoa(clientAddr.sin_addr) << "\n";

	char _recvBuf[128] = {};//接收客户端请求缓冲区


	for (;;)
	{
		//5 接收客户端请求 recv
		int nLen = recv(_cSock, _recvBuf, 128, 0);
		if (nLen <= 0)
		{
			cout << "客户端已退出" << "\n";
			break;
		}
		cout << "收到请求" << _recvBuf << "\n";


		//6 处理请求
		if (0 == strcmp(_recvBuf, "getName"))
		{
			char * msgBuf = "Xiao Qiang.\n";
			send(_cSock, msgBuf, strlen(msgBuf) + 1, 0);

		}
		else if (0 == strcmp(_recvBuf, "getAge"))
		{
			char * msgBuf = "80.\n";
			send(_cSock, msgBuf, strlen(msgBuf) + 1, 0);

		}
		else if (0 == strcmp(_recvBuf, "getInfo"))
		{
			DataPackge dp{ 80,"草泥马" };
			send(_cSock, (const char *)&dp, sizeof(dp), 0);
		}
		else
		{
			char * msgBuf = "???.\n";
			send(_cSock, msgBuf, strlen(msgBuf) + 1, 0);/*1客户端socket，2数据，3数据长度+'\0'， 4不知道是啥*/
		}

	}
																			
	//6 关闭socket 
	closesocket(_sock);


	//关闭windows socket 2.x 环境
	WSACleanup();

	cout << "任务结束";
	system("pause");
	return 0;
}
