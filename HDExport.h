
#ifndef _HDEXPORT_H
#define  _HDEXPORT_H

#define HDAPI _stdcall


extern "C"
{
	// 获得最后一次函数调用错误代码
	int HDAPI Hd_GetSDKLastError();

	// 创建屏幕
	int HDAPI Hd_CreateScreen(int nWidth, int nHeight, int nColor, int nGray, int nCardType, void *pExParamsBuf, int nBufSize);

	// 创建节目
	int HDAPI Hd_AddProgram( void *pBoderImgPath, int nBorderEffect, int nBorderSpeed, void *pExParamsBuf, int nBufSize);

	// 创建区域
	int HDAPI Hd_AddArea(int nProgramID, int nX, int nY, int nWidth, int nHeight, void *pBoderImgPath,  int nBorderEffect, int nBorderSpeed, void *pExParamsBuf, int nBufSize);
	
	// 创建图片区域项
	int HDAPI Hd_AddImageAreaItem(int nAreaID, void *pPaths, int nShowEffect, int nShowSpeed, int nClearType, int nStayTime, void *pExParamsBuf, int nBufSize);

	// 添加简单文本区域项
	int HDAPI Hd_AddSimpleTextAreaItem(int nAreaID, void *pText, int nTextColor, int nBackGroupColor, int nStyle, void *pFontName, int nFontHeight, 
		int nShowEffect, int nShowSpeed, int nClearType, int nStayTime, void *pExParamsBuf, int nBufSize);

	// 添加时间区域项
	int HDAPI Hd_AddTimeAreaItem(int nAreaID, int nShowMode, int bShowDate, int nDateStyle,  int bShowWeek, int nWeekStyle, 
		int bShowTime, int nTimeStyle, int nTextColor, void *pFontName, int nFontHeight, int nDiffHour, int nDiffMin, void *pExParamsBuf, int nBufSize);

	// 添加农历区域项
	int HDAPI Hd_AddChineseCalendarAreaItem(int nAreaID, int nLanguage, int nShowType, int bShowHeavenly, int nHeavenlyColor, int bShowCalendar, 
		int nCalendarColor, int bShowSolarTerms, int nSolarTermsColor, int bShowFestival, void *pFontName, int nFontHeight, void *pExParamsBuf, int nBufSize);

	// 添加温湿度区域项
	int HDAPI Hd_AddTempAndHumiAreaItem(int nAreaID, int nSensorType, int bUseTemperature, void *pTemperatureText, int nTemperatureTextColor, int nTemperatureX, int nTemperatureY,
		int nTemperatureUnit, int nTemperatureUnitColor, int nTemperatureOffset, int nTemperatureValueColor, int bUseHumidity, void *pHumidityText, int nHumidityTextColor, int nHumidityX, int nHumidityY,
		int nHumidityUnit, int nHumidityUnitColor, int nHumidityOffset, int nHumidityValueColor,
		void *pFontName, int nFontHeight, void *pExParamsBuf, int nBufSize);

	// 添加计时区域
	int HDAPI Hd_AddCountAreaItem(int nAreaID, int nCountMode, int nShowMode, int nAlignment, int nYear, int nMonth, int nDay, int nHour, int nMinute, int nSecond, int nValueColor, int nUnitColor,
		int bShowDay, int bShowHour, int bShowMinute, int bShowSecond, int bShowMS, int bAddUp, int bCycletiming, int nX, int nY, void *pFontName, int nFontHeight, void *pExParamsBuf, int nBufSize);

	// 添加计数区域
	int HDAPI Hd_AddDigitAreaItem(int nAreaID, int nInitialState, int nAlignment, int nMin, int nMinDecimalValue, int nMax, int nMaxDecimalValue, int nDecimalDigit, int nColor,
		int nTransitionTreshold, int nTransitionTresholdDecimalValue, int bUseMinImage, void *pMinImagePath, int bUseMaxImage, void *pMaxImagePath, int	bSaveDigit, int nX, int nY, void *pFontName, int nFontHeight, void *pExParamsBuf, int nBufSize);


	// 创建实时区域
	int HDAPI Hd_CreateRealtimeArea(int nX, int nY, int nWidth, int nHeight, void *pImgPath, int nUseRealTime,  int bOnlyShowRealtimeArea,  int bSave, int nLivetime, void *pExParamsBuf, int nBufSize);

	// 发送命令数据
	int HDAPI Hd_SendCommand(int nSendType, void *pStrParams, int nCommandType, void *pConText, int nTextLen, void *pDeviceGUID, void *pOutConText, int *pOutConTextLen, void *pExParamsBuf, int nBufSize);

	// 发送屏幕数据
	int HDAPI Hd_SendScreen(int nSendType, void *pStrParams, void *pDeviceGUID, void *pExParamsBuf, int nBufSize);

	// 发送实时区域数据
	int HDAPI Hd_SendRealTimeArea(int nSendType, void *pStrParams, void *pDeviceGUID, void *pExParamsBuf, int nBufSize);

	// 获得颜色
	int HDAPI Hd_GetColor(int r, int g, int b);

	// 保存屏幕打包数据、屏幕信息数据到指定目录
	int HDAPI Hd_SaveScreen(void *pDirPath);

	// 发送屏幕数据到指定设备。（如果使用了新版实时区域，则需使用该函数发送屏幕数据） 
	int HDAPI Hd_Rt_SendScreen(int nSendType, void *pStrParams, void *pDeviceGUID, void *pExParamsBuf, int nBufSize);

	// 添加实时区域到屏幕
	int HDAPI Hd_Rt_AddRealAreaToScreen(int nX, int nY, int nWidth, int nHeight, int nMaxPageCount);

	// 发送实时文本
	int HDAPI Hd_Rt_SendRealTimeText(int nSendType, void *pStrParams, int nRealTimeAreaIndex, int nMaxPage, int nColor, int nGray, int nX, int nY, int nWidth, int nHeight,
		void *pText, int nTextColor, int nBackGroupColor, int nStyle, void *pFontName, int nFontHeight, int nShowEffect, int nShowSpeed,
		int nStayTime, int nLiveTime, int bSaveToFlash, void *pDeviceGUID);

	// 发送实时图片
	int HDAPI Hd_Rt_SendRealTimeImage(int nSendType, void *pStrParams, int nRealTimeAreaIndex, int nMaxPage, int nColor, int nGray, int nX, int nY, int nWidth, int nHeight,
		void *pPaths,int nShowEffect, int nShowSpeed, int nStayTime, int nLiveTime, int bSaveToFlash, void *pDeviceGUID);

	// 设置屏幕参数
	int HDAPI Hd_SetScreenParam(int bUseTimerSwitch, int nBootuUpTime, int nShutDownTime, int nBrightnessMode, int nCustomBrightValue);

	// 设置节目参数
	int HDAPI Hd_SetProgramParam(int nProgramID, int nPlayMode, int nPlayLength, void *pBorderPath,
		int nBordernSpeed, int nBordernEffect, int nWeekPlayFlag, int nSpecifedTimeEnabled,
		int nTimeStart, int nTimeEnd, int nSpecifedDateEnabled, unsigned int nDateStart, unsigned int nDateEnd);
	
	////////////////////////////////////////////////////////////////////////////
	// 命令函数集
	// 获得串口设备波特率
	int HDAPI Cmd_GetBaudRate(int nPort, int *pBaudRate, void *pDeviceGUID);

	// 设置串口设备波特率
	int HDAPI Cmd_SetBaudRate(int nPort, int nSrcBaudRate, int nDestBaudRate, void *pDeviceGUID);

	// 获取屏幕参数 屏宽 屏高 颜色 灰度级别 卡类型
	int HDAPI Cmd_GetScreenParam(int nSendType, void *pStrParams, int *pWidth, int *pHeight, int *pColor, int *pGray, int *pCardType,  void *pDeviceGUID);

	// 测试控制卡是否在线
	int HDAPI Cmd_IsCardOnline(int nSendType, void *pStrParams, void *pDeviceGUID);

	// 清空显示屏数据
	int HDAPI Cmd_ClearScreen(int nSendType, void *pStrParams, void *pDeviceGUID);

	// 重启控制卡
	int HDAPI Cmd_RestartCard(int nSendType, void *pStrParams, void *pDeviceGUID);

	// 测试显示屏
	int HDAPI Cmd_TestScreen(int nSendType, void *pStrParams, int nStyle, void *pDeviceGUID);

	// 校准时间
	int HDAPI Cmd_AdjustTime(int nSendType, void *pStrParams, void *pDeviceGUID);

	// 设置亮度
	int HDAPI Cmd_SetLuminance(int nSendType, void *pStrParams, int nLuminance, void *pDeviceGUID);

	// 屏幕控制 开、关屏 播放 暂停
	int HDAPI Cmd_ScreenCtrl(int nSendType, void *pStrParams, int nCtrlCode, void *pDeviceGUID);

	// 定时开关机
	int HDAPI Cmd_TimeSwitch(int nSendType, void *pStrParams, int nUse, int nBootuUpTime, int nShutDownTime, void *pDeviceGUID);

	// 节目切换
	int HDAPI Cmd_SwitchProgram(int nSendType, void *pStrParams, int nProgramIndex, void *pDeviceGUID);

	// 设置设备IP
	int HDAPI Cmd_SetIP(void *pSrcIP, void *pDestIP, void *pDestMask, void *pDestGateway, void *pDeviceGUID);

	// 清空实时区域
	int HDAPI Cmd_ClearRealtimeArea(int nSendType, void *pStrParams, void *pDeviceGUID);

	// 设置计数区域状态
	int HDAPI Cmd_SetDigitState(int nSendType, void *pStrParams, int nAreaIndex, int nCmdType, int nValue, int nDecimaValue, void *pDeviceGUID);

	// 设置计时区域状态
	int HDAPI Cmd_SetCountState(int nSendType, void *pStrParams, int nAreaIndex, int nCmdType, void *pDeviceGUID);

	//////////////////////////////////////////////////////////////////////////////
	// 高级导出函数，仅当自己实现通迅时使用

	// 准备屏幕发送包并获得总包数
	int HDAPI Ad_PrepareScreenData(int *pTotalPacks, void *pDeviceGUID, void *pExParamsBuf, int nBufSize);

	// 获得屏幕发送包
	int HDAPI Ad_GetScreenSendPack(int nPackIndex, void *pOut, int *pLen);

	// 准备实时区域发送数据包并返回总包数
	int HDAPI Ad_PrepareRealtimeAreaData(int *pTotalPacks, void *pDeviceGUID,  void *pExParamsBuf, int nBufSize);

	// 获得实时区域发送包
	int HDAPI Ad_GetRealtimeAreaSendPack(int nPackIndex, void *pOut, int *pLen);

	// 获得通用命令数据包
	int HDAPI Ad_GetCommandPack(int nCommandType, void *pConText, int nTextLen, void *pOut, int *pnLen, void *pDeviceGUID, void *pExParamsBuf, int nBufSize);

	// 解析返回包
	int HDAPI Ad_ResolveReturnPack(void *pSrcData, int nSrcLen, void *pOutConText, int *pOutConTextLen);

	//////////////////////////////////////////////////////////////////////////////


	// 保存单个节目数据到指定目录
	int HDAPI hd_SaveSingleProgramData(int nProgramID, void *pDirPath);

	// 从指定目录模板节目数据按指定参数生成节目数据
	int HDAPI hd_CloneNewSingleProgramData(void *pDirPath, void *pCloneFileName, int nPlayMode, int nPlayLength,
		int nWeekPlayFlag, int nSpecifedTimeEnabled, int nTimeStart, int nTimeEnd, int nSpecifedDateEnabled,
		unsigned int nDateStart, unsigned int nDateEnd, void *pDestGUID, void *pSrcGUID, int nActionType);

	// 发送屏幕数据
	int HDAPI Hd_SendScreenFromFile(int nSendType, void *pStrParams, void *pScreenFilePath, void *pProgramFilePath, void *pDeviceGUID);
};
#endif