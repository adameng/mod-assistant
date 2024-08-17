#ifndef MOD_ASSISTANT_H
#define MOD_ASSISTANT_H

#include "Chat.h"
#include "Config.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedGossip.h"

enum
{
    ASSISTANT_GOSSIP_HEIRLOOM        = 100,
    ASSISTANT_GOSSIP_GLYPH           = 200,
    ASSISTANT_GOSSIP_GEM             = 400,
    ASSISTANT_GOSSIP_CONTAINER       = 500,
    ASSISTANT_GOSSIP_FLIGHT_PATHS    = 600,
    ASSISTANT_GOSSIP_UTILITIES       = 700,
    ASSISTANT_GOSSIP_PROFESSIONS     = 800,
    ASSISTANT_GOSSIP_INSTANCES       = 900,

    ASSISTANT_GOSSIP_TEXT            = 48,

    ASSISTANT_VENDOR_HEIRLOOM_WEAPON = 9000000,
    ASSISTANT_VENDOR_HEIRLOOM_ARMOR  = 9000001,
    ASSISTANT_VENDOR_HEIRLOOM_OTHER  = 9000002,
    ASSISTANT_VENDOR_GLYPH           = 9000003,
    ASSISTANT_VENDOR_GEM             = 9000023,
    ASSISTANT_VENDOR_CONTAINER       = 9000030,

    PROFESSION_LEVEL_APPRENTICE      = 75,
    PROFESSION_LEVEL_JOURNEYMAN      = 150,
    PROFESSION_LEVEL_EXPERT          = 225,
    PROFESSION_LEVEL_ARTISAN         = 300,
    PROFESSION_LEVEL_MASTER          = 375,
    PROFESSION_LEVEL_GRAND_MASTER    = 450,

    INSTANCE_TYPE_HEROIC             = 0,
    INSTANCE_TYPE_RAID               = 1,

    GLYPH_WARRIOR                    = 0,
    GLYPH_PALADIN                    = 1,
    GLYPH_HUNTER                     = 2,
    GLYPH_ROGUE                      = 3,
    GLYPH_PRIEST                     = 4,
    GLYPH_DEATH_KNIGHT               = 5,
    GLYPH_SHAMAN                     = 6,
    GLYPH_MAGE                       = 7,
    GLYPH_WARLOCK                    = 8,
    GLYPH_DRUID                      = 9
};

#define GOSSIP_HEIRLOOMS "我看看传家宝"
#define GOSSIP_HEIRLOOMS_WEAPONS "我看看武器"
#define GOSSIP_HEIRLOOMS_ARMOR "我看看装备"
#define GOSSIP_HEIRLOOMS_OTHER "我看看其他的"

#define GOSSIP_GLYPHS "我看看雕文"
#define GOSSIP_GLYPHS_MAJOR "我看看大型雕文"
#define GOSSIP_GLYPHS_MINOR "我看看小型雕文"

#define GOSSIP_GEMS "我看看宝石"
#define GOSSIP_GEMS_META "我想要一些元宝石"
#define GOSSIP_GEMS_RED "我想要一些红宝石"
#define GOSSIP_GEMS_BLUE "我想要一些蓝宝石"
#define GOSSIP_GEMS_YELLOW "我想要一些黄宝石"
#define GOSSIP_GEMS_PURPLE "我想要一些紫宝石"
#define GOSSIP_GEMS_GREEN "我想要一些绿宝石"
#define GOSSIP_GEMS_ORANGE "我想要一些橙宝石"

#define GOSSIP_CONTAINERS "我看看包包"

#define GOSSIP_UTILITIES "我需要专业服务"
#define GOSSIP_UTILITIES_NAME "我要改名"
#define GOSSIP_UTILITIES_APPEARANCE "我要改外貌"
#define GOSSIP_UTILITIES_RACE "我要改种族"
#define GOSSIP_UTILITIES_FACTION "我要改职业"
#define GOSSIP_UTILITIES_IN_PROGRESS "在尝试执行其他功能之前，您必须先完成先前激活的功能。"
#define GOSSIP_UTILITIES_DONE "现在您可以退出登录，继续使用已激活的功能。"

#define GOSSIP_FLIGHT_PATHS "我需要开飞行点"
#define GOSSIP_FLIGHT_PATHS_KALIMDOR_EASTERN_KINGDOMS "卡利姆多和东方王国"
#define GOSSIP_FLIGHT_PATHS_OUTLAND "外域"
#define GOSSIP_FLIGHT_PATHS_NORTHREND "北境"

#define GOSSIP_PROFESSIONS "我需要改变专业技能"
#define GOSSIP_PROFESSIONS_CHOOSE "我需要改变技能等级"
#define GOSSIP_PROFESSIONS_FIRST_AID "急救"
#define GOSSIP_PROFESSIONS_BLACKSMITHING "锻造"
#define GOSSIP_PROFESSIONS_LEATHERWORKING "制皮"
#define GOSSIP_PROFESSIONS_ALCHEMY "炼金"
#define GOSSIP_PROFESSIONS_HERBALISM "草药"
#define GOSSIP_PROFESSIONS_COOKING "烹饪"
#define GOSSIP_PROFESSIONS_MINING "采矿"
#define GOSSIP_PROFESSIONS_TAILORING "裁缝"
#define GOSSIP_PROFESSIONS_ENGINEERING "工程"
#define GOSSIP_PROFESSIONS_ENCHANTING "附魔"
#define GOSSIP_PROFESSIONS_FISHING "钓鱼"
#define GOSSIP_PROFESSIONS_SKINNING "剥皮"
#define GOSSIP_PROFESSIONS_INSCRIPTION "铭文"
#define GOSSIP_PROFESSIONS_JEWELCRAFTING "珠宝"

#define GOSSIP_INSTANCES "I want to reset instances"
#define GOSSIP_INSTANCES_HEROIC "I want to reset heroic dungeons"
#define GOSSIP_INSTANCES_RAID "I want to reset raids"
#define GOSSIP_INSTANCES_PLAYER "Just for me"
#define GOSSIP_INSTANCES_GROUP "For my entire group"
#define GOSSIP_INSTANCES_HEROIC_RESET "All heroic dungeons have been reset."
#define GOSSIP_INSTANCES_HEROIC_GROUP_RESET "All of your groups heroic dungeons have been reset."
#define GOSSIP_INSTANCES_RAID_RESET "All raids have been reset."
#define GOSSIP_INSTANCES_RAID_GROUP_RESET "All of your groups raids have been reset."

#define GOSSIP_CONTINUE_TRANSACTION "您希望继续交易吗？"
#define GOSSIP_PREVIOUS_PAGE "返回"

class Assistant : public CreatureScript, WorldScript
{
public:
    Assistant();

    // CreatureScript
    bool OnGossipHello(Player* /*player*/, Creature* /*creature*/) override;
    bool OnGossipSelect(Player* /*player*/, Creature* /*creature*/, uint32 /*sender*/, uint32 /*action*/) override;

    // WorldScript
    void OnAfterConfigLoad(bool /*reload*/) override;

private:
    bool HeirloomsEnabled;
    bool GlyphsEnabled;
    bool GemsEnabled;
    bool ContainersEnabled;

    uint32 GetGlyphId(uint32 /*id*/, bool /*major*/);

    // Utilities
    bool UtilitiesEnabled;
    uint32 NameChangeCost;
    uint32 CustomizeCost;
    uint32 RaceChangeCost;
    uint32 FactionChangeCost;

    bool HasLoginFlag(Player* /*player*/);
    void SetLoginFlag(Player* /*player*/, AtLoginFlags /*flag*/, uint32 /*cost*/);

    // Flight Paths
    bool FlightPathsEnabled[EXPANSION_WRATH_OF_THE_LICH_KING + 1];
    uint32 FlightPathsRequiredLevel[EXPANSION_WRATH_OF_THE_LICH_KING + 1];
    uint32 FlightPathsCost[EXPANSION_WRATH_OF_THE_LICH_KING + 1];

    bool CanUnlockFlightPaths(Player* /*player*/);
    std::vector<int> GetAvailableFlightPaths(Player* /*player*/, uint8 /*expansion*/);
    bool HasAvailableFlightPaths(Player* /*player*/, uint8 /*expansion*/);
    void UnlockFlightPaths(Player* /*player*/, uint8 /*expansion*/);

    // Professions
    bool ApprenticeProfessionEnabled;
    uint32 ApprenticeProfessionCost;
    bool JourneymanProfessionEnabled;
    uint32 JourneymanProfessionCost;
    bool ExpertProfessionEnabled;
    uint32 ExpertProfessionCost;
    bool ArtisanProfessionEnabled;
    uint32 ArtisanProfessionCost;
    bool MasterProfessionEnabled;
    uint32 MasterProfessionCost;
    bool GrandMasterProfessionEnabled;
    uint32 GrandMasterProfessionCost;

    void ListProfession(Player* /*player*/, uint32 /*id*/);
    void SetProfession(Player* /*player*/, uint32 /*id*/);
    bool HasValidProfession(Player* /*player*/);
    bool IsValidProfession(Player* /*player*/, uint32 /*id*/);
    uint32 GetProfessionCost(Player* /*player*/, uint32 /*id*/);

    // Instances
    bool HeroicInstanceEnabled;
    uint32 HeroicInstanceCost;
    bool RaidInstanceEnabled;
    uint32 RaidInstanceCost;

    bool CanResetInstances(Player* /*player*/);
    bool HasSavedInstances(Player* /*player*/, uint8 /*type*/);
    void ResetInstances(Player* /*player*/, uint8 /*type*/);
};

#endif
