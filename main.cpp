#include <windows.h>
#include <stdio.h>
#include "../Add-on API/Add-on API.h"
#include "resource.h"
#include <math.h>

//#define EXT_IPLAYER

addon_info EXTPluginInfo = { L"Pirate Mod", L"1.0.2.3",
                            L"RadWolfie",
                            L"It provide pirate CD keys to enter server.",
                            L"Pirate",
                            L"pirate",
                            NULL,
                            NULL,
                            NULL,
                            NULL};
CNATIVE dllAPI EAO_RETURN WINAPIC EXTOnEAOLoad(unsigned int hash) {
    return EAO_CONTINUE;
}

CNATIVE dllAPI void WINAPIC EXTOnEAOUnload() {
}
CNATIVE dllAPI PLAYER_VALIDATE WINAPIC EXTOnPlayerValidateConnect(PlayerExtended plEx, s_machine_slot mH, s_ban_check banCheckPlayer, bool isBanned, toggle svPass, PLAYER_VALIDATE isForceReject) {
    if (isBanned || svPass == -1) {
        return PLAYER_VALIDATE_DEFAULT;
    }
    return PLAYER_VALIDATE_BYPASS;
}
CNATIVE dllAPI bool EXTOnGameSpyValidationCheck(UINT UniqueID, bool isValid, bool forceBypass) {
    return isValid; //Return false to force bypass gamespy validation check.
}
#include "..\Add-on API\C\expChecker.h"
