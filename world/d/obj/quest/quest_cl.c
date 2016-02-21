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

mapping quests_cloth = ([
      10 : ({ "find", "粗布衣",         "linen",              "", "1" }),
      20 : ({ "find", "皮背心",         "pi beixin",          "", "1" }),
      30 : ({ "find", "皮袍",           "pipao",              "", "1" }),
      40 : ({ "find", HIG"轻纱长裙"NOR, "skirt",             "", "1" }),
     100 : ({ "find", "兵服",           "cloth",              "", "1" }),
     200 : ({ "find", "碧水霓裳",       "nichang",            "", "1" }),
     300 : ({ "find", "马褂",           "magua",              "", "1" }),
     500 : ({ "find", "青缎袄",         "ao",                 "", "1" }),
     600 : ({ "find", "绸袍",           "choupao",            "", "1" }),
     700 : ({ "find", "长袍",           "changpao",           "", "1" }),
     800 : ({ "find", "桃符纸",         "paper seal",         "", "1" }),
    1000 : ({ "find", "宫袍",           "gong pao",           "", "1" }),
    1100 : ({ "find", "宫裙",           "gong qun",           "", "1" }),
    2000 : ({ "find", "粉红绸衫",       "pink cloth",         "", "1" }),
    3000 : ({ "find", "五色梅浅红裙",   "pink skirt",         "", "1" }),
    4000 : ({ "find", "长袍",           "chang pao",          "", "1" }),
    4100 : ({ "find", "披毯",           "pi tan",             "", "1" }),
    4200 : ({ "find", "白披毯",         "bai pitan",          "", "1" }),
    4300 : ({ "find", "彩色披毯",       "caise pitan",        "", "1" }),
    4400 : ({ "find", "紫绒披风",       "zirong pifeng",      "", "1" }),
    4500 : ({ "find", "醋坛子",         "tanzi",              "", "1" }),
    5100 : ({ "find", "阿拉伯长袍",     "chang pao",          "", "1" }),
    5200 : ({ "find", "太极道袍",       "cloth",              "", "1" }),
    6100 : ({ "find", "印花裙",         "skirt",              "", "1" }),
    6200 : ({ "find", "束腰筒裙",       "skirt",              "", "1" }),
    6300 : ({ "find", "水染彩裙",       "skirt",              "", "1" }),
    6400 : ({ "find", "宽身素长裙",     "skirt",              "", "1" }),
    6500 : ({ "find", "短袍裙",         "skirt",              "", "1" }),
    7100 : ({ "find", "白袍",           "bai pao",            "", "1" }),
    7200 : ({ "find", "官袍",           "guan pao",           "", "1" }),
    7300 : ({ "find", "翡红裙",         "hong qun",           "", "1" }),
    7400 : ({ "find", "大花袍",         "hua pao",            "", "1" }),
    7500 : ({ "find", "水印花裙",       "hua qun",            "", "1" }),
    7600 : ({ "find", "犀牛皮衣",       "xiniu piyi",         "", "1" }),
    7700 : ({ "find", "鸟毛",           "niao mao",           "", "1" }),
    8100 : ({ "find", "衙役服",         "yayi cloth",         "", "1" }),
    8200 : ({ "find", "犀皮背心",       "xipi beixin",        "", "1" }),
    8300 : ({ "find", "牛皮衣",         "niupi yi",           "", "1" }),
    8400 : ({ "find", "熊皮短袍",       "xiongpi duanpao",    "", "1" }),
    8500 : ({ "find", "虎皮裙",         "hupi qun",           "", "1" }),
    8600 : ({ "find", "狼皮裤",         "langpi qun",         "", "1" }),
    8700 : ({ "find", "猪毛",           "zhu mao",            "", "1" }),
    8800 : ({ "find", "死老鼠",         "dead mouse",         "", "1" }),
    8900 : ({ "find", "西瓜皮",         "xigua pi",           "", "1" }),  
    9000 : ({ "find", "战袍",           "zhan pao",           "", "1" }),
   10000 : ({ "find", "八卦道袍",       "bagua pao",          "", "1" }),
   12000 : ({ "find", "破布头",         "po butou",           "", "1" }),
   13000 : ({ "find", "用过的牙签",     "used yaqian",        "", "1" }),
   14000 : ({ "find", "大石头",         "big stone",          "", "1" }),
   15000 : ({ "find", "断笔",           "duan bi",            "", "1" }),
   20000 : ({ "find", "狼皮裙",         "wolf skirt",         "", "1" }),
   21000 : ({ "find", "锦花袍",         "jinhua pao",         "", "1" }),
   21500 : ({ "find", "菜刀",           "cai dao",            "", "1" }),
   22000 : ({ "find", "兽皮裙",         "shoupi qun",         "", "1" }),
   23000 : ({ "find", HIG "芭蕉裙" NOR, "palm skirt",         "", "1" }),
   31000 : ({ "find", "黑罴皮",         "heipi pi",           "", "1" }),
   32000 : ({ "find", "棕熊皮",         "zongxiong pi",       "", "1" }),
   33000 : ({ "find", "青狈皮",         "qingbei pi",         "", "1" }),
   34000 : ({ "find", "猛犸皮",         "mengma pi",          "", "1" }),
   41000 : ({ "find", "牦牛皮",         "maoniu pi",          "", "1" }),
   42000 : ({ "find", "水牛皮",         "shuiniu pi",         "", "1" }),
   43000 : ({ "find", "野象皮",         "yexiang pi",         "", "1" }),
   44000 : ({ "find", "公鹿皮",         "gonglu pi",          "", "1" }),
   45000 : ({ "find", "豺皮",           "chai pi",            "", "1" }),
   47000 : ({ "find", "铁甲",           "iron armor",         "", "1" }),
   51000 : ({ "find", "花豹皮",         "huabao pi",          "", "1" }),
   52000 : ({ "find", "白虎皮",         "baihu pi",           "", "1" }),
   53000 : ({ "find", "黑虎皮",         "heihu pi",           "", "1" }),
   54000 : ({ "find", "金狮皮",         "jinshi pi",          "", "1" }),
   55000 : ({ "find", "卷毛狮皮",       "juanmao pi",         "", "1" }),
   56000 : ({ "find", "山猫皮",         "shanmao pi",         "", "1" }),
   60000 : ({ "find", "虎皮披风",       "tiger surcoat",      "", "1" }),
   70000 : ({ "find", "大红蟒袍",       "mangpao",            "", "1" }),
   71001 : ({ "find", "厚棉裤",         "cloth",              "", "1" }),
   71002 : ({ "find", "厚棉袄",         "cloth",              "", "1" }),
   71003 : ({ "find", "厚麻裤",         "cloth",              "", "1" }),
   72043 : ({ "find", "细锦长裙",       "skirt",              "", "1" }),
   72044 : ({ "find", "细缎长裙",       "skirt",              "", "1" }),
   72111 : ({ "find", "花棉短裙",       "skirt",              "", "1" }),
   72244 : ({ "find", "细缎薄裙",       "skirt",              "", "1" }),
   80047 : ({ "find", "紫花细纱战裙",   "skirt",              "", "1" }),
   80049 : ({ "find", "紫花麻纱战裙",   "skirt",              "", "1" }),
   90000 : ({ "find", "太极道袍",       "cloth",              "", "1" }),
  120000 : ({ "find", "渌水罗衣",       "fancy skirt",        "", "1" }),
  300000 : ({ "find", "降魔袍",         "xiangmo pao",        "", "1" }),
  310000 : ({ "find", "锦绣战袍",       "zhanpao",            "", "1" }),
  320000 : ({ "find", "黄虎皮",         "huang hupi",         "", "1" }),
  350000 : ({ "find", "兽皮披风",       "shoupi pifeng",      "", "1" }),
  550000 : ({ "find", HIY"蟒龙袍"NOR,   "long pao",           "", "1" }),
  700000 : ({ "find", "大红蟒袍",       "mangpao",            "", "1" }),
  750000 : ({ "find", "葛布长袍",       "cloth",              "", "1" }),
  800000 : ({ "find", HIY "蟒龙袍" NOR, "long pao",           "", "1" }),
 2000000 : ({ "find", HIY"五彩天衣"NOR, "tian yi",            "", "1" }),
 2200000 : ({ "find", HIY"锦镧袈裟"NOR, "jinlan jiasha",      "", "1" }),

]);

void create()
{
  seteuid(getuid());
  m_keys=order_list(keys(quests_cloth));
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
  info=quests_cloth[m_keys[i]];
  
  quest=(["quest":"找"+info[IDX_NAME]]);
  quest+=(["quest_msg":strs[random(sizeof(strs))]+info[IDX_NAME]+
           "，你可否去寻一些来？\n"]);
  quest+=(["bonus":log10(who->query("combat_exp"))*40+10]);
  quest+=(["reward_msg":"$N笑道：不错不错，有劳你了。\n"]);
  return quest;
}
