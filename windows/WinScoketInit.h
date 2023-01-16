/**************************************************************************
*	Copyright 2020-2030 OnePeaceAllBlue Co.,Ltd
*	All right reserved. See COPYRIGHT for detailed Information
*
*	@file		WinSocketInit.h
*	@brief		winsocket��������ͷ��������ļ�
*	@note		
*
		* @author		tonytao
		* @date			2022-06-15
		* @history		�޸���ʷ
			@author��	tonytao
			@date:		2022-06-15
			@brief:		����
***************************************************************************/

#pragma once
#include <WinSock2.h>
#include <iostream>

#pragma comment(lib,"ws2_32.lib")


class WinScoketInit
{
public:
	WinScoketInit();

	~WinScoketInit();

private:
	WSADATA wsaData;
};

