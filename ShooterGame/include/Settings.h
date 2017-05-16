#pragma once

#pragma region Application Settings
#ifdef _DEBUG
	#define APPTITLE "Base Defender - (Debug)"
#else
	#define APPTITLE "Base Defender"
#endif // _DEBUG
#define SCREENWIDTH 1080
#define SCREENHEIGHT 720
#define FULLSCREEN false
#pragma endregion

#pragma region Game State Manager
enum class eGameStateID { SPLASH_STATE, GAME_STATE, PAUSE_STATE };
#pragma endregion