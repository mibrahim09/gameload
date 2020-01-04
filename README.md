# GameLoadInfo Encrypting/Decrypting tool

This is a tool I wrote in C++ to decrypt/encrypt a file in a chinese game. 
I've reversed the exe and got the decrypting key from it and then made the encrypting key of it.

Its pretty much easy to use just put the tool and the ini file in the same folder and launch the tool. 
You have 2 options:

1. Decrypt (Requires the GameLoadInfo.dat).
2. Encrypt (Requires the GameLoadInfo.ini).

This file controls the links and the buttons in the Play.exe.

Here is an example of the Decrypted file.

```[1]
GameReg=SOFTWARE\Tqdigital\Conquer\English
GameName=Conquer
GameProcess=Conquer.exe
GameBmp=data2\playskin\logo\Conquer.png
GameServer=server.dat
DisplayName=Conquer
GamePath=
GameType=
GameFlash=
GameNetType=13
GameSupport=1
GameRunType=0
GameHot=0
GameSoftType=0
GameDes=
GameTypeDes=
GameNotOut=1
GameUrl=http://co.99.com/
AdvUrl=http://co.99.com/gamer/hotevents.shtml
UpdateUrl=http://co.99.com/gamer/gamer.shtml
StartUrl=https://co.99.com/gamer/2019/
DownUrl=http://co.99.com/gamer/gamer.shtml
ExitUrl=http://co.99.com/signout/
SkinUrl=http://antistat.99.com/ndlogin/newskin/zfen.dat
GameWebUrl=https://co.99.com/downloads/
GameLanguage=English
ButtonFunFacebookUrl=https://www.facebook.com/ConquerOnline
ButtonFunTiktokUrl=https://www.tiktok.com/share/user/6652913494315794438
ButtonFunTwitterUrl=https://twitter.com/Conquer_Online
ButtonFunYoutubeUrl=https://www.youtube.com/c/ConquerOnlineOfficial```