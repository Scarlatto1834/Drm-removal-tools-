// Halo 2 Vista XLiveless
// Allows for debugging the game in single player, multiplayer is NULLED
// Creds: Listener, Rick, and Seemaan. I don't know any of them, but Listeners GTA IV wrapper helped me
//    and me for reversing the rest of the exports and stripping unneeded ones

#include <Winsock2.h>
#include <windows.h>

// Export symbols are stripped, must use ordinals only

/*
halo2.exe imports from xlive.dll

Imports Table:
  xlive.dll
  OrigFirstThunk:  0040F0AC (Unbound IAT)
  TimeDateStamp:   00000000 -> Wed Dec 31 19:00:00 1969
  ForwarderChain:  00000000
  First thunk RVA: 0039B000
  Ordn  Name
     1
     2
     3
     5
     4
     6
     7
     8
    11
    12
    13
    14
    15
    18
    20
    22
    24
    27
    37
    38
    39
    40
    51
    52
    53
    54
    55
    56
    57
    60
    63
    65
    66
    69
    70
    72
    73
    75
    84
   472
   473
   651
   653
  1082
  1083
  5000
  5001
  5002
  5003
  5007
  5008
  5010
  5011
  5016
  5018
  5019
  5022
  5024
  5028
  5029
  5030
  5212
  5215
  5230
  5231
  5233
  5234
  5236
  5237
  5238
  5251
  5252
  5254
  5256
  5260
  5261
  5262
  5263
  5265
  5270
  5276
  5277
  5278
  5280
  5300
  5303
  5305
  5308
  5310
  5312
  5314
  5318
  5325
  5326
  5327
  5330
  5331
  5336
  5344
  5345
  5332
  5315

xlive.dll exports

exports table:

  Name:            xlive.dll
  Characteristics: 00000000
  TimeDateStamp:   49EEC4F4 -> Wed Apr 22 03:19:16 2009
  Version:         0.00
  Ordinal base:    00000001
  # of functions:  000014F5
  # of Names:      00000000

  Entry Pt  Ordn  Name
  000C9538     1
  000C954E     2
  000C9556     3
  000C956F     4
  000C9582     5
  000C9598     6
  000C95B1     7
  000C95D0     8
  000C95EF     9
  000C9608    10
  000C9621    11
  000C963A    12
  000C9653    13
  000C9669    14
  000C9682    15
  000C96A1    16
  000C96C0    17
  000C96D3    18
  000C96EF    19
  000C9714    20
  000C9736    21
  000C9761    22
  000C977D    23
  000C97A2    24
  000C97C4    25
  000C9808    26
  000C9813    27
  000C9818    28
  000C9823    29
  000C9828    30
  000C9833    31
  000C983E    32
  000C9849    33
  000C9BEC    34
  000C97EF    35
  000C9BF7    37
  000C9C02    38
  000C9BF7    39
  000C9C02    40
  000C8D94    51
  000C8DA7    52
  000C8DAF    53
  000C8DC5    54
  000C8DDB    55
  000C9122    56
  000C9135    57
  000C914E    58
  000C9167    60
  000C9180    62
  000C9199    63
  000C91AC    64
  000C91C2    65
  000C91D5    66
  000C91E8    67
  000C9201    68
  000C9214    69
  000C9233    70
  000C9267    71
  000C9280    72
  000C9293    73
  000C92A6    75
  000C92AE    76
  000C92C1    77
  000C92D7    78
  000C92F0    79
  000C9309    81
  000C931F    82
  000C9335    83
  000C9348    84
  00138915   472
  00137302   473
  0013712C   474
  0013737A   476
  00136FCB   477
  0013701B   478
  00137050   479
  0014005A   651
  0013F59A   652
  0013F5E0   653
  0013A741  1082
  0013A769  1083
  0013549A  5000
  0013918A  5001
  00138A56  5002
  001326EC  5003
  0013A461  5005
  00139260  5006
  001393A4  5007
  000D177B  5008
  0012F36F  5010
  0012F388  5011
  0012F356  5012
  0012F113  5016
  0012F166  5017
  0012F190  5018
  0012F1D8  5019
  0012F21B  5020
  0012F263  5021
  0013BED9  5022
  0013A96C  5023
  0013C3FE  5024
  0013A842  5025
  0013CC4B  5026
  0013C635  5027
  000E2557  5028
  000E1D25  5029
  0013662D  5030
  000CB8B8  5031
  0013D945  5032
  0012E162  5034
  0012E452  5035
  0012E722  5036
  0012E90A  5037
  0012EAFE  5038
  000E261D  5039
  000CA01A  5206
  000CA54D  5208
  000CA4AB  5209
  000CA67E  5210
  000CA77A  5212
  000CA22B  5214
  000C9E92  5215
  000CA0EA  5216
  000D8A6B  5230
  000D81F0  5231
  000D929F  5233
  000DA98E  5234
  000DA7F1  5235
  000D826C  5236
  000D82B3  5237
  000D82DE  5238
  000CA18C  5250
  00135EB2  5251
  000CA13C  5252
  000C9C0D  5254
  000C9D73  5255
  000C9C64  5256
  0013ADB3  5257
  0013A7F5  5258
  0013B03A  5259
  000C9DDE  5260
  000CAF04  5261
  000CAF87  5262
  000CAF4A  5263
  000CAFB3  5264
  000CB0B2  5265
  000CA391  5266
  000CB7D0  5267
  000C9DB9  5270
  000C9FD5  5271
  000CB551  5273
  000CB59B  5274
  000C9EF4  5275
  000CAEB4  5276
  000CADD3  5277
  000CA92E  5278
  000CB4A9  5279
  000CA859  5280
  000CB1FF  5281
  000CB4FA  5282
  000CB305  5284
  000CB3FD  5285
  000CB37F  5286
  000CB159  5287
  000CB6F5  5288
  000CB66B  5289
  000CB5EF  5290
  000CB1D9  5291
  000CAD4A  5292
  000CAE07  5293
  0012F2A6  5294
  0012F2FE  5295
  0013A947  5296
  00134B8E  5297
  00136A35  5298
  000C9EC3  5299
  000CD43B  5300
  000CCD5D  5303
  000CE8B7  5304
  000CCB48  5305
  000CC917  5306
  000CE8B7  5307
  000CC49B  5308
  000CE99D  5309
  000CD0E9  5310
  000CD13F  5311
  000CBB0F  5312
  000CC168  5313
  000CEA58  5314
  000CBC59  5315
  000CBD67  5316
  000CE22B  5317
  000CDBB6  5318
  000CDF78  5319
  000CE0B2  5320
  000CDE4B  5321
  000CD5DD  5322
  000CE7EF  5323
  005595DD  5324
  000CD954  5325
  000CD891  5326
  000CD7BF  5327
  000CE716  5328
  000CE19F  5329
  000CD695  5330
  000CEACF  5331
  000CDCFF  5332
  000CDAD4  5333
  000CD147  5334
  005599AC  5335
  000CDA1A  5336
  000CEBD1  5337
  000CC25F  5338
  000CEB46  5339
  000CBFFC  5340
  000CC37D  5341
  000CE620  5342
  000CE595  5343
  000CE8DE  5344
  000CC69E  5345
  000CCF47  5346
  000DAB6E  5347
  000DAD85  5348
  000DABF4  5349
  000DAC57  5350
  000DAFD6  5351
  000DB202  5352
  000DB14C  5354
  000DB2D1  5355
  000DB375  5356
  000DB403  5357
  000DB091  5358
  0013A9B5  5359
  000DAEB7  5360
  000D7189  5361
  000CA317  5365

*/

int __stdcall XWSAStartup(WORD wVersionRequested, LPWSADATA lpWsaData) { // xlive_1
  lpWsaData->wVersion = 2;
  return 0;
}

void __stdcall XWSACleanup(){ // xlive_2
}

SOCKET __stdcall XSocketCreate(int af, int type, int protocol) { // xlive_3
  return INVALID_SOCKET;
}

int __stdcall XSocketClose(SOCKET s) {	//xlive_4
  return 0;
}

int __stdcall XSocketShutdown(SOCKET s, int how) {	// xlive_5
  return 0;
}

int __stdcall XSocketIOCTLSocket(SOCKET s, long cmd, long * argp) { // xlive_6
  return 0;
}

int __stdcall XSocketSetSockOpt(SOCKET s, DWORD, DWORD, DWORD, DWORD) {	//	xlive_7
  return 0;
}

int __stdcall XLive_8_Unk(int a1, int a2, int a3, void *a4, int a5){ // xlive_8
  return 0;
}

SOCKET __stdcall XSocketBind(SOCKET s, sockaddr_in * addr, int * addrlen) { // xlive_11 
  return INVALID_SOCKET;
}

int __stdcall XSocketConnect(SOCKET s, sockaddr_in * addr, int * addrlen) { // xlive_12 
  return 0;
}

int __stdcall XSocketListen(SOCKET s, int backlog) { // xlive_13
  return 0;
}

SOCKET __stdcall XSocketAccept(SOCKET s, sockaddr_in * addr, int * addrlen) { // xlive_14
  return INVALID_SOCKET;
}

int __stdcall XSocketSelect(int n, void *, void *, void *, void *) { // xlive_15
  return 0;
}

int __stdcall XSocketRecv(SOCKET s, char * buf, int len, int flags) { // xlive_18
  return 0;
}

int __stdcall XSocketRecvFrom(SOCKET s, char * buf, int len, int flags, sockaddr_in * from, int fromlen) { // xlive_20
  return 0;
}

int __stdcall XSocketSend(SOCKET s, char * buf, int len, int flags) { // xlive_22
  return 0;
}

int __stdcall XSocketSendTo(SOCKET s, char * buf, int len, int flags, sockaddr_in * to, int tolen) { // xlive_24
  return 0;
}

int __stdcall XWSAGetLastError() { // xlive_27
  return WSAENETDOWN; // 0 ?
}

int __stdcall XLive_37_Unk(int){ // xlive_37
  return 0;
}

WORD __stdcall XSocketNTOHS(WORD n) {	// xlive_38 
	return ((n&0xFF00) >> 8)|((n&0xFF) << 8);
}

DWORD __stdcall XSocketNTOHL(DWORD n) { // xlive_39
	return ((n&0xFF000000) >> 24)|((n & 0x00FF0000) >> 8)|((n&0x0000FF00) << 8)|((n & 0x000000FF) << 24);
}

__int16 __cdecl XLive_40_Unk(__int16 a1){ // xlive_40
  return 0;
}

int __stdcall XNetStartup(void *){ // xlive_51
  return 0;
}

int __stdcall XNetCleanup(){ // xlive_52
  return 0;
}

int __stdcall XLive_53_Unk(BYTE *a1, HCRYPTPROV a2){ // xlive_53
  return 0;
}
int __stdcall XLive_54_Unk(BYTE *a1, int a2){ // xlive_54
  return 0;
}
int __stdcall XLive_55_Unk(int a1, void *a2){ // xlive_55
  return 0;
}

int __stdcall XLive_56_Unk(int a1){ // xlive_56
  return 0;
}

int __stdcall XNetXnAddrToInAddr(DWORD, DWORD, DWORD * p){ // xlive_57
  *p = 0;
  return 0;
}

int __stdcall XLive_60_Unk(unsigned int a1, void *a2, int a3){ // xlive_60
  return 0;
}

int __stdcall XNetUnregisterInAddr(DWORD){	// xlive_63
  return 0;
}

int __stdcall XLive_65_Unk(unsigned int a1){ // xlive_65
  return 0;
}

int __stdcall XNetGetConnectStatus(DWORD){ // xlive_66
  return 0;	
}

DWORD __stdcall XLive_69_Unk(DWORD, DWORD, DWORD, DWORD, DWORD){ // xlive_69
  return 0; 
}

DWORD __stdcall XLive_70_Unk(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD){ // xlive_70
  return 0;
}

DWORD __stdcall XLive_72_Unk(DWORD){ // xlive_72
  return 0;
}

DWORD __stdcall XNetGetTitleXnAddr(DWORD * pAddr) {	// xlive_73
	*pAddr = 0x0100007F;	// 127.0.0.1
	return 4; 
}

DWORD __stdcall XNetGetEthernetLinkStatus() { // xlive_75
	return 1; 
}

DWORD __stdcall XLive_84_Unk(DWORD) { // xlive_84
  return 0;
}

int __stdcall XLive_472_Unk(int, int, int){ // xlive_472
  return 0;
}

int __stdcall XLive_473_Unk(int a1, int a2, int a3){ //xlive_473
  return 0;
}

int __stdcall XNotifyGetNext(DWORD, DWORD, DWORD, DWORD){ // xlive_651
	return 0;
}

int __stdcall XLive_653_Unk(DWORD a1){ // xlive_653
  return 0;
}

DWORD __stdcall XGetOverlappedExtendedError(void *) { // xlive_1082
	return 0;
}

DWORD __stdcall XGetOverlappedResult(void *, DWORD * pResult, DWORD) { // xlive_1083
	if (pResult)
		*pResult = 0;	// 0 elements enumerated
	return 0;
}

int __stdcall XLiveInitialize(DWORD) {	// xlive_5000
	return 0;
}

int __stdcall XLiveInput(DWORD * p) { // xlive_5001
	p[5] = 0;
	return 1;	// -1 ?
}


int __stdcall XLiveRender() { // xlive_5002
	return 0;
}

int __stdcall XLiveUninitialize() { // xlive_5003 
	return 0;
}

int __stdcall XLiveOnResetDevice(DWORD) { // xlive_5007
	return 0;
}

int __stdcall XHVCreateEngine(DWORD, DWORD, DWORD) { // xlive_5008
	return -1;	// disable live voice
}

int __stdcall XLive_5010_Unk(int a1, int a2, int a3){ // xlive_5010
  return 0;
}

int __stdcall XLive_5011_Unk(int a1){ // xlive_5011
  return 0;
}

struct FakeProtectedBuffer {
	DWORD	dwMagick;	
	int		nSize;
	DWORD	__fill[2]; // To match buffer size in Rick's wrapper
	BYTE	bData[4];
};

DWORD __stdcall XLivePBufferAllocate(int size, FakeProtectedBuffer ** pBuffer){ // xlive_5016
	*pBuffer = (FakeProtectedBuffer *)malloc (size+16);
	if (!*pBuffer) {
		return E_OUTOFMEMORY;
	}

	(*pBuffer)->dwMagick = 0xDEADDEAD;	// some arbitrary number
	(*pBuffer)->nSize = size;
	return 0;
}

DWORD __stdcall XLive_5018_Unk(FakeProtectedBuffer * pBuffer, int offset, BYTE * value){ // xlive_5018
	if (!pBuffer || pBuffer->dwMagick != 0xDEADDEAD || !value || offset < 0 || offset > pBuffer->nSize)
		return 0;
	*value = pBuffer->bData[offset];
	return 0;
}

DWORD __stdcall XLive_5019_Unk(FakeProtectedBuffer * pBuffer, int offset, BYTE value){ // xlive_5019
	if (!pBuffer || pBuffer->dwMagick != 0xDEADDEAD || offset < 0 || offset > pBuffer->nSize)
		return 0;
	pBuffer->bData[offset] = value;
	return 0;
}

int __stdcall XLiveGetUpdateInformation(DWORD){ // xlive_5022
  return -1; // no update
}

int __stdcall XLiveUpdateSystem(DWORD){ // xlive_5024 
  return -1; // no update
}

int __stdcall XLive_5028_Unk(int, int, int){ // xlive_5028
  return 0;
}

int XLive_5029_Unk(int){ // xlive_5029
  return 0;
}

int __stdcall XLivePreTranslateMessage(DWORD) {	// xlive_5030
  return 0;
}

int __stdcall XLive_5212_Unk(int a1, unsigned int a2, int a3, int a4, int a5, int a6, unsigned int a7, int a8, unsigned int a9, int a10, int a11, int a12, int a13){ // xlive_5212
  return 0;
}

int __stdcall XShowGuideUI(DWORD){ // xlive_5215
  return 1;
}

int __stdcall XLive_5230_Unk(int a1, __int32 a2, int a3, int a4, int a5, char a6, int a7, int a8, int a9, unsigned int a10, unsigned int a11, unsigned int a12, unsigned int a13, unsigned int a14, int a15, int a16){ // xlive_5230
  return 0;
}

int __stdcall XLive_5231_Unk(int *a1, int a2, signed int a3, int a4){ // xlive_5231
  return 0;
}

int __stdcall XLive_5233_Unk(int a1, signed int a2, unsigned int a3, int a4, int a5){ // xlive_5233
  return 0;
}

int __stdcall XLive_5234_Unk(int a1, int a2, int a3, int a4, void *a5, int a6, int a7, int a8, int a9, int a10, int a11){ // xlive_5234
  return 0;
}

int __stdcall XLive_5236_Unk(int a1, int a2){ // xlive_5236
  return 0;
}

int __stdcall XLive_5237_Unk(int a1){ // xlive_5237
  return 0;
}

int __stdcall XLive_5238_Unk(BYTE *a1, int a2){ // xlive_5238
  return 0;
}

int __stdcall XCloseHandle(DWORD){ // xlive_5251
	return 0;
}

int __stdcall XShowGamerCardUI(DWORD, DWORD, DWORD){ // xlive_5252
	return 0;
}
int __stdcall XCancelOverlapped(DWORD){ // xlive_5254
	return 0;
}

int __stdcall XEnumerate(HANDLE hEnum, void * pvBuffer, DWORD cbBuffer, DWORD *, void * pOverlapped){ // xlive_5256
	return 0;	// some error ? 
}

int __stdcall XShowSigninUI(DWORD, DWORD){ // xlive_5260
	return 0;
}


int __stdcall XUserGetXUID(DWORD, DWORD * pXuid){ // xlive_5261
	pXuid[0] = pXuid[1] = 0x10001000; 
	return 0; // ???
}


int __stdcall XUserGetSigninState(DWORD){ // xlive_5262 
	return 1; // eXUserSigninState_SignedInLocally
}


int __stdcall XUserGetName(DWORD dwUserId, char * pBuffer, DWORD dwBufLen){ // xlive_5263
	if (dwBufLen < 8)
		return 1;
	memcpy (pBuffer, "Player1", 8);
	return 0;
}

int __stdcall XLive_5265_Unk(DWORD user, DWORD priv, PBOOL b){ // xlive_5265
	*b = false;
	return 0;
}

HANDLE __stdcall XNotifyCreateListener(DWORD l, DWORD h){ // xlive_5270
	return (HANDLE)1; // any non-zero value. (zero treated as fatal error)
}

int __stdcall XLive_5276_Unk(DWORD, DWORD, DWORD, DWORD){ // xlive_5276
	return 0;
}

int __stdcall XLive_5277_Unk(DWORD, DWORD, DWORD){ //xlive_5277
	return 0;
}

DWORD __stdcall XLive_5278_Unk(DWORD, DWORD, DWORD){ //xlive_5278
	return 0;
}

DWORD __stdcall XLive_5280_Unk(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, PHANDLE phEnum){ // xlive_5280
	*phEnum = INVALID_HANDLE_VALUE;
	return 0;
}

DWORD __stdcall XSessionCreate(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD){ // xlive_5300
	return -1;
}

DWORD __stdcall XStringVerify(DWORD, DWORD, DWORD, DWORD, DWORD, WORD * pResult, DWORD){ // xlive_5303
  *pResult = 0;
  return 0;
}

DWORD __stdcall XLive_5305_Unk(DWORD, DWORD, DWORD, DWORD, DWORD){ // xlive_5305
  return 0;
}

int __stdcall XLive_5308_Unk(int a1, int a2, int a3, int a4){ // xlive_5308
  return 0;
}

int __stdcall XOnlineStartup(){ // xlive_5310
  return 0; 
}

DWORD __stdcall XLive_5312_Unk(DWORD, DWORD, DWORD, DWORD, DWORD){ // xlive_5312
  return 0;
}

int __stdcall XLive_5314_Unk(DWORD, DWORD, DWORD, DWORD){ // xlive_5314
  return 0;
}

int __stdcall XLive_5315_Unk(DWORD, DWORD){ // xlive_5315
  return 1;
}

int __stdcall XSessionStart(DWORD, DWORD, DWORD){ // xlive_5318
  return 0;
}

DWORD __stdcall XLive_5325_Unk(DWORD, DWORD, DWORD, DWORD){ // xlive_5325
  return 0;
}

DWORD __stdcall XLive_5326_Unk(DWORD, DWORD, DWORD, DWORD, DWORD){ // xlive_5326
  return 0;
}

DWORD __stdcall XLive_5327_Unk(DWORD, DWORD, DWORD, DWORD, DWORD){ // xlive_5327
  return 0;
}

DWORD __stdcall XLive_5330_Unk(DWORD, DWORD){ // xlive_5330
  return 0;
}

struct XUSER_READ_PROFILE_SETTINGS{
  DWORD	dwLength;
  BYTE* pSettings;
};

DWORD __stdcall XUserReadProfileSettings(DWORD dwTitleId, DWORD dwUserIndex, DWORD dwNumSettingIds, 
					DWORD* pdwSettingIds, DWORD* pcbResults, XUSER_READ_PROFILE_SETTINGS* pResults, DWORD pOverlapped){ // xlive_5331
	if (*pcbResults < 1036) {
		*pcbResults = 1036;	// TODO: make correct calculation by IDs.
		return ERROR_INSUFFICIENT_BUFFER;
	}
	memset (pResults, 0, *pcbResults);
	pResults->dwLength = *pcbResults-sizeof (XUSER_READ_PROFILE_SETTINGS);
	pResults->pSettings = (BYTE *)pResults+sizeof (XUSER_READ_PROFILE_SETTINGS);
	return 0;
}

int __stdcall XSessionEnd(DWORD, DWORD){ // xlive_5332
  return 0;
}

DWORD __stdcall XLive_5336_Unk(DWORD, DWORD, DWORD, DWORD){ // xlive_5336
  return 0;
}

DWORD __stdcall XLive_5344_Unk(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD){ // xlive_5344
	return 0;
}

DWORD __stdcall XLive_5345_Unk(DWORD dwUserIndex, DWORD, DWORD, DWORD, DWORD, DWORD, void *){ // xlive_5345
	return 0;
}

bool __stdcall DllMain(HMODULE hMod, unsigned long ulReason, void* pvReserved)
{
  switch(ulReason)
  {
    case DLL_PROCESS_ATTACH:
      break;

    case DLL_PROCESS_DETACH:
      break;

    case DLL_THREAD_ATTACH:
      break;

    case DLL_THREAD_DETACH:
      break;
  }
  return true;
}