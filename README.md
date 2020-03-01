# AssaultCube-DirectX-ESP-Overlay
Simple proof of concept on how to draw to an overlay through the use of DirectX in Assault Cube.

- WHAT IS THIS:
  - This small hack finds players on the game map and draws a distance from one self to their person.
    ![alt text](https://github.com/Ctrl-Alt-1337/AssaultCube-DirectX-ESP-Overlay/blob/master/screenshot.jpg)

- HOW TO RUN THE HACK:
	- Download the DirectX Software Development Kit: http://www.microsoft.com/en-us/download/details.aspx?id=6812 (DXSDK_Jun10)
  - If using Visual Studio then Right Click on the project -> Properties -> VC++ Directories
    - -> Add '$(DXSDK_DIR)Include' to the 'Include Directories'
    - -> Add '$(DXSDK_DIR)Lib\x86' to the 'Library Directories'
    - -> Advanced -> Character Set -> Make sure you use 'Use Multi-Byte Character Set'
  - Build through Win32 
  
- OTHER RELEVANT INFO:
	- Base address and offsets for entities (names, positions, health etc.) are found through OllyDbg and Cheat Engine.
  - Relevant WinAPI functions: FindWindowA, GetWindowThreadProcessId, OpenProcess, ReadProcessMemory

- CREDITS:
	- forceinline for the DirectX overlay code: https://github.com/forceinline/cpp-dx9-overlay
	- WorldToScreen: Guidedhacking.com
