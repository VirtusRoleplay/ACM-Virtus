#include "\a3\ui_f\hpp\defineCommonGrids.inc"

#define IDC_TRANSFUSIONMENU                       86000
#define IDC_TRANSFUSIONMENU_PATIENTNAME           86001
#define IDC_TRANSFUSIONMENU_SELECTIONTEXT         86002
#define IDC_TRANSFUSIONMENU_SELECTION_INV_TEXT    86003
#define IDC_TRANSFUSIONMENU_LEFTLISTPANEL         86004
#define IDC_TRANSFUSIONMENU_RIGHTLISTPANEL        86005
#define IDC_TRANSFUSIONMENU_BUTTON_STOPIV         86006
#define IDC_TRANSFUSIONMENU_BUTTON_MOVEBAG        86006
#define IDC_TRANSFUSIONMENU_BUTTON_REMOVEBAG      86006

#define IDC_TRANSFUSIONMENU_BG_IO_TORSO           86010
#define IDC_TRANSFUSIONMENU_BG_IO_RIGHTARM        86011
#define IDC_TRANSFUSIONMENU_BG_IO_LEFTARM         86012
#define IDC_TRANSFUSIONMENU_BG_IO_RIGHTLEG        86013
#define IDC_TRANSFUSIONMENU_BG_IO_LEFTLEG         86014
#define IDC_TRANSFUSIONMENU_BG_IV_RIGHTARM_UPPER  86020
#define IDC_TRANSFUSIONMENU_BG_IV_RIGHTARM_MIDDLE 86021
#define IDC_TRANSFUSIONMENU_BG_IV_RIGHTARM_LOWER  86022
#define IDC_TRANSFUSIONMENU_BG_IV_LEFTARM_UPPER   86023
#define IDC_TRANSFUSIONMENU_BG_IV_LEFTARM_MIDDLE  86024
#define IDC_TRANSFUSIONMENU_BG_IV_LEFTARM_LOWER   86025
#define IDC_TRANSFUSIONMENU_BG_IV_RIGHTLEG_UPPER  86026
#define IDC_TRANSFUSIONMENU_BG_IV_RIGHTLEG_MIDDLE 86027
#define IDC_TRANSFUSIONMENU_BG_IV_RIGHTLEG_LOWER  86028
#define IDC_TRANSFUSIONMENU_BG_IV_LEFTLEG_UPPER   86029
#define IDC_TRANSFUSIONMENU_BG_IV_LEFTLEG_MIDDLE  86030
#define IDC_TRANSFUSIONMENU_BG_IV_LEFTLEG_LOWER   86031


#define BODY_BACKGROUND_IV(bodypart,site,sidc) \
    class BodyBackground_IV_##bodypart##_##site##: BodyBackground_IO_Torso { \
        idc = sidc; \
        text = QPATHTOEF(gui,data\body_image\##bodypart##_iv_##site##.paa); \
    }

#define ACE_BODYPART(part) localize 'STR_ACE_Medical_GUI_##part##'
#define BODYPART_PART(part,loc) QUOTE(format [ARR_3('%1 (%2)',ACE_BODYPART(part),C_LLSTRING(IV_##loc##))])