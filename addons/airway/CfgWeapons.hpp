class CfgWeapons {
    class ACE_ItemCore;
    class CBA_MiscItem_ItemInfo;

    class ACM_GuedelTube: ACE_ItemCore {
        scope = 2;
        author = "Blue";
        picture = QPATHTOF(ui\guedeltube_ca.paa);
        displayName = CSTRING(GuedelTube);
        descriptionShort = CSTRING(GuedelTube_Desc);
        ACE_isMedicalItem = 1;
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 1;
        };
    };

    class ACM_GuedelTube_Used: ACM_GuedelTube {
        scope = 1;
        displayName = "Canule de Guedel (Usagée)";
        descriptionShort = "Usagé !";
    };

    class ACM_IGel: ACM_GuedelTube {
        picture = QPATHTOF(ui\igel_ca.paa);
        displayName = CSTRING(IGel);
        descriptionShort = CSTRING(IGel_Desc);
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 2;
        };
    };

    class ACM_IGel_Used: ACM_IGel {
        scope = 1;
        displayName = "Masque à i-gel (Usagé)";
        descriptionShort = "Usagé !";
    };

    class ACM_NPA: ACM_GuedelTube {
        picture = QPATHTOF(ui\npa_ca.paa);
        displayName = CSTRING(NPA);
        descriptionShort = CSTRING(NPA_Desc);
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 1.4;
        };
    };

    class ACM_NPA_Used: ACM_NPA {
        scope = 1;
        displayName = "NPA (Usagé)";
        descriptionShort = "Usagé !";
    };

    class ACM_SuctionBag: ACM_GuedelTube {
        picture = QPATHTOF(ui\suctionbag_ca.paa);
        displayName = CSTRING(SuctionBag);
        descriptionShort = CSTRING(SuctionBag_Desc);
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 4;
        };
    };

    class ACM_ACCUVAC: ACM_SuctionBag {
        picture = QPATHTOF(ui\accuvac_ca.paa);
        displayName = CSTRING(ACCUVAC);
        descriptionShort = CSTRING(ACCUVAC_Desc);
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 20;
        };
    };
};