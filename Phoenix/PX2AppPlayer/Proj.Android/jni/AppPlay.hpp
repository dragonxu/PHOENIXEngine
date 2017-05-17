// AppPlay.h

#ifndef APPPLAY_H
#define APPPLAY_H

#include <string>

namespace appplay
{
	
	class NativeCall
	{
	public:
		// general
		static bool Initlize(int width, int height);
		static bool IsInitlized();
		static bool Ternamate();

		static bool WillEnterForeground();
		static bool DidEnterBackground();

		static void OnOdle();

		// touch
		static void OnTouchPressed(int num, int ids[], float xs[], float ys[]);
		static void OnTouchReleased(int num, int ids[], float xs[], float ys[]);
		static void OnTouchMoved(int num, int ids[], float xs[], float ys[]);
		static void OnTouchCancelled(int num, int ids[], float xs[], float ys[]);

		// res path
		static void SetResourcePath(std::string path);
		static void SetDataServerUpdateType(std::string type);
        
        static void SetWriteablePath(std::string path);
		
		// deive id
		static void SetDeviceIDStr(std::string deviceIDStr);
		
		// ip mac
		static void SetIPMac(std::string ip, std::string mac);

		// text
		static void Text_InsertText(const char *text, int length);
		static void Text_DeleteBackward();
		static const char *Text_GetInitContent();

		// bluttooth
		static void BluetoothDiscoveryNewDevice(std::string deviceStr);
		static void BluetoothDiscoveryFinished();
		static void BluetoothConnected();
		static void BluetoothDisConnected();
		static void BluetoothConnectFailed();

	private:
		static bool msIsIntlized;

		// platformsdk
	public:
		static void SetPlatformSDK(std::string str);
		static void OnLoginSuc(int apiID, std::string loginUin, std::string sessionID, std::string nickname);
		static void OnLoginCancel();
		static void OnLoginFailed();
		static void OnGuestOfficialSuc();
		
		// voice
	public:
		static void SetVoiceSDK(std::string strSDK);
		static void OnVoiceRecognizeResults(std::string strRet, std::string strJSON);
	};
	
}

#endif