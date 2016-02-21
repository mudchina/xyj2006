//Cracked by Roath
inherit F_CLEAN_UP;

#include <ansi.h>
#include <quest.h>

// the quest format is the following mapping:
// daoxing :     type     name     id            object         amount
//--------------------------------------------------------------------
//  1000   : ({ "find",  "秘笈",   "mi ji" ,     "",             "1" }), 
//  5000   : ({ "give",  "灾民",   "zai min" ,   "白银(silver)", "5" }), 
// 12000   : ({ "kill",  "白骨精", "baigu jing", "",             "3" });
 
//找一本秘笈，救济灾民五两银子，三打白骨精．．．．．．

mapping quests_furniture = ([
      50 : ({ "find", "菜刀",         "blade",              "", "1" }),
     110 : ({ "find", "醋坛子",       "tanzi",              "", "1" }),
     120 : ({ "find", "油瓶",         "youping",            "", "1" }),
     130 : ({ "find", "布袋",         "bag",                "", "1" }),
     140 : ({ "find", "饭盒",         "fan he",             "", "1" }),
     210 : ({ "find", "竹扫帚",       "broom",              "", "1" }),
     220 : ({ "find", "雪饮杯",       "snowglass",          "", "1" }),
     330 : ({ "find", "戒尺",         "ruler",              "", "1" }),
    1100 : ({ "find", "挂毯",         "gua tan",            "", "1" }),
    1200 : ({ "find", "锡壶",         "xi hu",              "", "1" }),
    1300 : ({ "find", "锡碗",         "xi wan",             "", "1" }),
    1400 : ({ "find", "雕木斜靠椅",   "yi zi",              "", "1" }),
    1500 : ({ "find", "镂空木桌",     "zhuo zi",            "", "1" }),
    2000 : ({ "find", "浴巾",         "yu jin",             "", "1" }),
    3000 : ({ "find", "水罐",         "shui guan",          "", "1" }),
    4100 : ({ "find", "油葫芦",       "you hulu",           "", "1" }),
    4200 : ({ "find", "青竹筒",       "qingzhu tong",       "", "1" }),
    5100 : ({ "find", "竹篓",         "zhu lou",            "", "1" }),
    5200 : ({ "find", "水酒罐",       "jiu guan",           "", "1" }),
    5300 : ({ "find", "清白老酒壶",   "jiu hu",             "", "1" }),
    5400 : ({ "find", "白瓷花盆",     "hua pen",            "", "1" }),
    5500 : ({ "find", "青石花瓶",     "hua ping",           "", "1" }),
    5600 : ({ "find", "烫花竹篮",     "zhu lan",            "", "1" }),
    5700 : ({ "find", "细条竹篓",     "zhu lou",            "", "1" }),
    5800 : ({ "find", "银药盏",       "yin yaozhan",        "", "1" }),
    5850 : ({ "find", "白布",         "bai bu",             "", "1" }),
    5900 : ({ "find", "花布",         "hua bu",             "", "1" }),

    6000 : ({ "find", "荷花灯",       "deng long",          "", "1" }),
    6100 : ({ "find", "莲花灯",       "deng long",          "", "1" }),
    6800 : ({ "find", "梦幻灯",       "deng long",          "", "1" }),
    6850 : ({ "find", "云雾灯",       "deng long",          "", "1" }),
    6900 : ({ "find", "金鱼灯",       "deng long",          "", "1" }),
    6950 : ({ "find", "仙鹤灯",       "deng long",          "", "1" }),

    8038 : ({ "find", "紫漆兽脚桌",   "table",              "", "1" }),

    9000 : ({ "find", "兽皮",         "shou pi",            "", "1" }),

   25000 : ({ "find", "净瓶",         "jingping",           "", "1" }),
   
   30000 : ({ "find", "镇妖锤",       "mallet",             "", "1" }),
   35000 : ({ "find", HIC"摄魂匣"NOR, "camera",             "", "1" }),
   40000 : ({ "find", "一堆杂草",     "zai cao",            "", "1" }),
   45000 : ({ "find", "玻璃盘子",     "panzi",              "", "1" }),
 1800000 : ({ "find", "黄金匣子",     "xiazi",              "", "1" }),
]);

void create()
{
  seteuid(getuid());
  m_keys=order_list(keys(quests_furniture));
}

mapping query_quest(object who)
{
  mapping quest;
  int i;
  string* info;
  string *strs = ({
    "$N想想说道：今天我正准备请人去找",
    "$N细想了一下说道：本门有人想要什么",
    "$N点头说道：这里尚缺些",
    "$N想想说道：可否帮本门寻得",
  });  
  
  i = quest_accurate_index (m_keys, who->query("combat_exp"));
  i = quest_random_index (m_keys, i);
  info=quests_furniture[m_keys[i]];
  
  quest=(["quest":"找"+info[IDX_NAME]]);
  quest+=(["quest_msg":strs[random(sizeof(strs))]+info[IDX_NAME]+
           "，你可否去寻一些来？\n"]);
  quest+=(["bonus":log10(who->query("combat_exp"))*40+10]);
  quest+=(["reward_msg":"$N笑道：不错不错，有劳你了。\n"]);
  return quest;
}

