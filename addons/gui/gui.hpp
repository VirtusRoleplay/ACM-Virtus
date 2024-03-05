class RscText;
class RscButton;
class RscPicture;
class RscListBox;
class RscActivePicture;
class RscButtonMenu;
class RscControlsGroup;
class RscControlsGroupNoScrollbars;

class ACEGVAR(medical_gui,BodyImage): RscControlsGroupNoScrollbars {
    class controls {
        class Background;
        class Torso_ChestSeal: Background {
            idc = IDC_BODY_TORSO_CHESTSEAL;
            text = QPATHTOF(data\body_image\torso_chestseal.paa);
            colorText[] = {1, 0.95, 0, 1};
            show = 0;
        };
        class Head_GuedelTube: Torso_ChestSeal {
            idc = IDC_BODY_HEAD_GUEDELTUBE;
            text = QPATHTOF(data\body_image\head_guedeltube.paa);
            colorText[] = {0.19, 0.91, 0.93, 1};
        };
        /*class Head_iGel: Head_GuedelTube {
            idc = IDC_BODY_HEAD_IGEL;
            text = QPATHTOF(data\body_image\head_igel.paa);
        };*/
        class RightArm_PulseOximeter: Background {
            idc = IDC_BODY_RIGHTARM_PULSEOX;
            text = QPATHTOF(data\body_image\rightarm_pulseoximeter.paa);
            colorText[] = {0.3, 0.8, 0.8, 1};
            show = 0;
        };
        class LeftArm_PulseOximeter: RightArm_PulseOximeter {
            idc = IDC_BODY_LEFTARM_PULSEOX;
            text = QPATHTOF(data\body_image\leftarm_pulseoximeter.paa);
        };
        class Torso_AED_Pads: Background {
            idc = IDC_BODY_TORSO_AED_PADS;
            text = QPATHTOF(data\body_image\torso_aed_pads.paa);
            colorText[] = {0.18, 0.6, 0.96, 1};
            show = 0;
        };
        class RightArm_AED_VitalsMonitor: Torso_AED_Pads {
            idc = IDC_BODY_RIGHTARM_AED_VITALS;
            text = QPATHTOF(data\body_image\rightarm_aed_vitals_monitor.paa);
        };
        class LeftArm_AED_VitalsMonitor: RightArm_AED_VitalsMonitor {
            idc = IDC_BODY_LEFTARM_AED_VITALS;
            text = QPATHTOF(data\body_image\leftarm_aed_vitals_monitor.paa);
        };
        class Torso_IO: Torso_ChestSeal {
            idc = IDC_BODY_TORSO_IO;
            text = QPATHTOF(data\body_image\torso_fast_io.paa);
            colorText[] = {0.2, 0.6, 0.2, 1};
        };
        class Torso_Pneumothorax: Torso_ChestSeal {
            idc = IDC_BODY_TORSO_PNEUMOTHORAX;
            text = QPATHTOF(data\body_image\torso_pneumothorax.paa);
            colorText[] = {1, 1, 1, 1};
        };
        class RightArm_IV: Torso_IO {
            idc = IDC_BODY_RIGHTARM_IV;
            text = QPATHTOF(data\body_image\rightarm_iv.paa);
        };
        class LeftArm_IV: RightArm_IV {
            idc = IDC_BODY_LEFTARM_IV;
            text = QPATHTOF(data\body_image\leftarm_iv.paa);
        };
        class RightLeg_IV: RightArm_IV {
            idc = IDC_BODY_RIGHTLEG_IV;
            text = QPATHTOF(data\body_image\rightleg_iv.paa);
        };
        class LeftLeg_IV: RightArm_IV {
            idc = IDC_BODY_LEFTLEG_IV;
            text = QPATHTOF(data\body_image\leftleg_iv.paa);
        };
    };
};

class ACE_Medical_Menu {
    class Controls {
        class BodyLabelLeft: RscText {
            idc = IDC_SIDE_LABEL_LEFT;
            show = 0;
        };
        class BodyLabelRight: BodyLabelLeft {
            idc = IDC_SIDE_LABEL_RIGHT;
        };
    };
};