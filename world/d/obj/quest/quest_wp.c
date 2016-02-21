//Cracked by Roath
inherit F_CLEAN_UP;

#include <ansi.h>
#include <quest.h>

// the quest format is the following mapping:
// daoxing :     type     name     id            object         amount
//--------------------------------------------------------------------
//  1000   : ({ "find",  "√ÿÛ≈",   "mi ji" ,     "",             "1" }), 
//  5000   : ({ "give",  "‘÷√Ò",   "zai min" ,   "∞◊“¯(silver)", "5" }), 
// 12000   : ({ "kill",  "∞◊π«æ´", "baigu jing", "",             "3" });
 
//’““ª±æ√ÿÛ≈£¨æ»º√‘÷√ÒŒÂ¡Ω“¯◊”£¨»˝¥Ú∞◊π«æ´£Æ£Æ£Æ£Æ£Æ£Æ

mapping quests_weapon = ([
      50 : ({ "find", "≤Àµ∂",         "cai dao",            "", "1" }),
     110 : ({ "find", "Ã˙¥∏",         "hammer",             "", "1" }),
     120 : ({ "find", "ƒæµ∂",         "mu dao",             "", "1" }),
     130 : ({ "find", "ƒæπ˜",         "mu gun",             "", "1" }),
     140 : ({ "find", "ƒæΩ£",         "mu jian",            "", "1" }),
     150 : ({ "find", "ƒæ«π",         "mu qiang",           "", "1" }),
     160 : ({ "find", "ƒæ’»",         "mu zhang",           "", "1" }),
     170 : ({ "find", "π ˜÷¶",       "guishuzhi",          "", "1" }),

     210 : ({ "find", "ÔŸÃ˙π˜",       "bintiegun",          "", "1" }),
     220 : ({ "find", "∆Î√ºπ˜",       "qimeigun",           "", "1" }),
     230 : ({ "find", "÷Ò…®÷„",       "broom",              "", "1" }),
     240 : ({ "find", "ƒæ∞Ù",         "mu bang",            "", "1" }),
     250 : ({ "find", "ƒæ≤Ê",         "fork",               "", "1" }),

     300 : ({ "find", "∑Áªÿ—©ŒËΩ£",   "snowsword",          "", "1" }),
     350 : ({ "find", "æ≈π…Õ–ÃÏ≤Ê",   "tuotian fork",       "", "1" }),

     500 : ({ "find", "Ã˙∏´",         "lumber axe",         "", "1" }),

     700 : ({ "find", "¥Û¬Ì∞Ù",       "mabang",             "", "1" }),
     800 : ({ "find", "ø≥µ∂",         "blade",              "", "1" }),
     900 : ({ "find", "µ∑“©Ë∆",       "yao chu",            "", "1" }),
    2100 : ({ "find", "µ•µ∂",         "blade",              "", "1" }),
    2200 : ({ "find", "≥§«π",         "chang qiang",        "", "1" }),
    2300 : ({ "find", "≥§Ω£",         "sword",              "", "1" }),

    3100 : ({ "find", "÷Ò±ﬁ",         "zhu bian",           "", "1" }),
    3200 : ({ "find", "÷Ò∞“",         "zhu pa",             "", "1" }),
    3300 : ({ "find", " ÏÕ≠Ôµ",       "copper mace",        "", "1" }),
    5000 : ({ "find", "º¿µ∂",         "ji dao",             "", "1" }),
    5500 : ({ "find", "Ω‰µ∂",         "jie dao",            "", "1" }),
    7000 : ({ "find", "¿√“¯ÿ∞ ◊",     "silver dagger",      "", "1" }),
    8000 : ({ "find", "ÃÍµ∂",         "ti dao",             "", "1" }),

   10000 : ({ "find", "…±Õ˛¥Û∞Ù",     "shawei bang",        "", "1" }),
   15000 : ({ "find", "¥Û∞Â∏´",       "bigaxe",             "", "1" }),

   11000 : ({ "find", "ÔÙŒ≤Ω£",       "zhiwei jian",        "", "1" }),
   12000 : ({ "find", "ø›À…’»",       "kusong zhang",       "", "1" }),
   13000 : ({ "find", "‹Í¬‹«π",       "biluo qiang",        "", "1" }),
   14000 : ({ "find", "ª±¥Ã≤Ê",       "huaici cha",         "", "1" }),
   15000 : ({ "find", "¡¯“∂µ∂",       "liuye dao",          "", "1" }),
   16000 : ({ "find", "¬π∆§±ﬁ",       "lupi bian",          "", "1" }),

   21000 : ({ "find", "—„‘∆µ∂",       "yanyun blade",       "", "1" }),
   21500 : ({ "find", "Ã˙’»",         "tie zhang",          "", "1" }),
   22000 : ({ "find", "∏÷≤Ê",         "gang cha",           "", "1" }),
   22500 : ({ "find", "¬πΩ«≤Ê",       "cha",                "", "1" }),
   23000 : ({ "find", "—ÚΩ«≤Ê",       "cha",                "", "1" }),
   23500 : ({ "find", "≈£Ω«≤Ê",       "cha",                "", "1" }),
   24000 : ({ "find", "œ¨Ω«≤Ê",       "cha",                "", "1" }),
   24500 : ({ "find", "µ•»–ÿ∞",       "danren bi",          "", "1" }),
   25000 : ({ "find", "Ì‡ Ø¥∏",       "qingshi chui",       "", "1" }),
   25500 : ({ "find", "”•◊Ï∏´",       "yingzui fu",         "", "1" }),
   26000 : ({ "find", "∞ŸΩ⁄¡¥",       "baijie lian",        "", "1" }),

   31000 : ({ "find", "∞≈Ω∂±ﬁ",       "bajiao bian",        "", "1" }),
   31500 : ({ "find", "—Ó ˜◊Æ",       "yangshu zhuang",     "", "1" }),
   32000 : ({ "find", "—Ó ˜π’",       "yangshu guai",       "", "1" }),
   32500 : ({ "find", "—Ó ˜≤Ê",       "yangshu cha",        "", "1" }),
   33000 : ({ "find", "¡¯Ãı±ﬁ",       "liutiao bian",       "", "1" }),
   33500 : ({ "find", " Ø≤˘µ∂",       "shichan dao",        "", "1" }),
   34000 : ({ "find", "¬πΩ«≤Ê",       "lujiao cha",         "", "1" }),
   34500 : ({ "find", "¥Ãª±Ôµ",       "cihuai jian",        "", "1" }),
   35000 : ({ "find", "∫Ï”ß«π",       "hongying qiang",     "", "1" }),
   35500 : ({ "find", "ª®Û√Ω£",       "huazhu jian",        "", "1" }),
   36000 : ({ "find", "∞˛∆§±ﬁ",       "bopi bian",          "", "1" }),
   36500 : ({ "find", "ø™…Ω∏´",       "kaishan fu",         "", "1" }),
   37000 : ({ "find", "«‡ Ø¥∏",       "qingsho chui",       "", "1" }),
   37500 : ({ "find", "÷˛…Ω∞“",       "zhushan pa",         "", "1" }),
   38000 : ({ "find", "ªÎÃ˙’»",       "huntie zhang",       "", "1" }),
   38500 : ({ "find", "¥Úπ∑π˜",       "daguo gun",          "", "1" }),
   39000 : ({ "find", "≈£Ω«»–",       "niujiao ren",        "", "1" }),

   41000 : ({ "find", "Ωπœ",         "golden hammer",      "", "1" }),
   41500 : ({ "find", "≥§Õ‰µ∂",       "chang wan dao",      "", "1" }),
   42000 : ({ "find", "∂ÃÕ‰µ∂",       "duan wan dao",       "", "1" }),
   42500 : ({ "find", "‘¬—¿Õ‰µ∂",     "yueya wan dao",      "", "1" }),
   43000 : ({ "find", "≈£π«∞Ù",       "niugu bang",         "", "1" }),
   43500 : ({ "find", "≈£Õ∑µ∂",       "niutou dao",         "", "1" }),
   44000 : ({ "find", "≈£Ω«≤Ê",       "niujiao cha",        "", "1" }),

   51000 : ({ "find", "Ωµ∂",         "jin dao",            "", "1" }),
   51500 : ({ "find", "¬´ª®≤›",       "luhua cao",          "", "1" }),
   52000 : ({ "find", "’∂Õ∑µ∂",       "zhantou dao",        "", "1" }),
   52500 : ({ "find", "Ã˙æ£º¨",       "tie jingji",         "", "1" }),
   53000 : ({ "find", "Ã˙¡¥",         "tie lian",           "", "1" }),
   53500 : ({ "find", "∂ÃÃ˙◊¶",       "tie zhua",           "", "1" }),
   54000 : ({ "find", "≥§Ã˙◊¶",       "tie zhua",           "", "1" }),
   54500 : ({ "find", "Ã˙«Ú",         "tie qiu",            "", "1" }),
   55000 : ({ "find", "œÛ—¿Ω£",       "xiangya jian",       "", "1" }),
   55500 : ({ "find", "ª¢Õ∑µ∂",       "hutou dao",          "", "1" }),
   56000 : ({ "find", "¡˙–Î≤Ê",       "longxu cha",         "", "1" }),
   56500 : ({ "find", "÷Ì‚≤—¿",       "zhu liaoya",         "", "1" }),
   57000 : ({ "find", "∑ÔŒ≤±ﬁ",       "fengwei bian",       "", "1" }),
   57500 : ({ "find", "‘ß—Ïπ˜",       "yuanyang gun",       "", "1" }),
   58000 : ({ "find", "‘ß—Ïπ˜",       "yuanyang gun",       "", "1" }),

   62000 : ({ "find", "∑˜≥æ",         "fuchen",             "", "1" }),
   63000 : ({ "find", "∆ﬂ≥›∞“",       "qichi pa",           "", "1" }),
   64000 : ({ "find", "Ω‰µ∂",         "jie dao",            "", "1" }),
   65000 : ({ "find", "«‡Õ≠≤Ê",       "qingtong cha",       "", "1" }),
   66000 : ({ "find", "∑®¥∏",         "fa chui",            "", "1" }),
   67000 : ({ "find", "◊œ‘∆Ω£",       "ziyun jian",         "", "1" }),
   68000 : ({ "find", "…’ªπ˜",       "shaohuo gun",        "", "1" }),

   71000 : ({ "find", "“¯≤Ê",         "silver fork",        "", "1" }),
   72000 : ({ "find", "÷˛–«∞“",       "zhuxing pa",         "", "1" }),
   73000 : ({ "find", "À´Õ∑√¨",       "shuangtou mao",      "", "1" }),
   74000 : ({ "find", "∏Ω£",         "ge jian",            "", "1" }),
   75000 : ({ "find", "–¬‘¬µ∂",       "xinyue dao",         "", "1" }),

   81000 : ({ "find", "Œ⁄∑ÔÔµ",       "wufeng jian",        "", "1" }),
   82000 : ({ "find", "÷Ò’»",         "zhu zhang",          "", "1" }),
   91000 : ({ "find", "»˝≥›∏÷≤Ê",     "sanchi gangcha",     "", "1" }),
   92000 : ({ "find", HIY"ª∆Õ≠Ï¯’»"NOR, "huangtong chanzhang", "", "1" }),
  100000 : ({ "find", "–°Ωπø∞Ù",     "xiao jingu bang",    "", "1" }),
  110000 : ({ "find", "–°æ≈≥›ÓŸ",     "xiao jiuchi pa",     "", "1" }),
  120000 : ({ "find", "Ã´““÷Òµ∂",     "taiyi zhu dao",      "", "1" }),
  130000 : ({ "find", "–°Ωµ—˝’»",     "xiao xiangyao zhang","", "1" }),
  140000 : ({ "find", "Àƒ√˜≤˘",       "siming chan",        "", "1" }),
  150000 : ({ "find", "≥˛Â˙Ω£",       "chufei sword",       "", "1" }),
  160000 : ({ "find", "∞À±¶Õ≠¥∏",     "hammer",             "", "1" }),
  200000 : ({ "find", "‘¬—¿≤˘",       "moon fork",          "", "1" }),
  210000 : ({ "find", "–˚ª®∏´",       "xuanhua fu",         "", "1" }),
  220000 : ({ "find", "°ÒΩµ§…∞°Ò",   "jindan sha",         "", "1" }),
  300000 : ({ "find", "Û¥¡˙π’",       "panlong guai",       "", "1" }),
  310000 : ({ "find", "µ„∏÷«π",       "diangang qiang",     "", "1" }),

  400000 : ({ "find", "–Âª®’Î",       "xiuhua zhen",        "", "1" }),
  410000 : ({ "find", "∞À∞Í√∑ª®¥∏",   "meihua hammer",      "", "1" }),
  420000 : ({ "find", "±Ã”ÒÀ´«π",     "jade spear",         "", "1" }),
  430000 : ({ "find", "«‡∑ÊΩ£",       "qingfeng sword",     "", "1" }),
  440000 : ({ "find", "Œﬁ≥£∞Ù",       "wuchang bang",       "", "1" }),

  500000 : ({ "find", "–”ª®÷¶",       "xinghua zhi",        "", "1" }),
  510000 : ({ "find", "π≈ÃŸ’»",       "guteng zhang",       "", "1" }),

  600000 : ({ "find", "æ≈≥›∂§ÓŸ",     "ding pa",            "", "1" }),
  610000 : ({ "find", RED"¿¶œ…À˜"NOR, "kunxian suo",        "", "1" }),

  700000 : ({ "find", "∂Ã»Ì¿«—¿∞Ù",   "langya bang",        "", "1" }),
  710000 : ({ "find", YEL"ª¢Œ≤±ﬁ"NOR, "tiger mace",         "", "1" }),

  800000 : ({ "find", "Ãƒª®Ω£",       "tanghua jian",       "", "1" }),
  810000 : ({ "find", " ®Õ»π«",       "shitui gu",          "", "1" }),
  820000 : ({ "find", "∫¸π«¥Ã",       "hugu ci",            "", "1" }),
  830000 : ({ "find", "√∑ª®¬πΩ«",     "meihualu jiao",      "", "1" }),
  840000 : ({ "find", "≈£Œ≤",         "niu wei",            "", "1" }),
  850000 : ({ "find", "ø≥…Ωµ∂",       "kanshan dao",        "", "1" }),

  900000 : ({ "find", "Ω∏’◊¡",       "jingang zhuo",       "", "1" }),
  910000 : ({ "find", "≥‡¡˙’∂",       "dragon blade",       "", "1" }),
  920000 : ({ "find", "¡˙Ω«≤Ê",       "dragon fork",        "", "1" }),
  930000 : ({ "find", "Œ⁄¡˙Ôµ",       "dragon mace",        "", "1" }),
  940000 : ({ "find", "¡˙≥›ÓŸ",       "dragon rake",        "", "1" }),
  950000 : ({ "find", "¡˙π««π",       "dragon spear",       "", "1" }),
  970000 : ({ "find", "≈Ã¡˙π˜",       "dragon stick",       "", "1" }),
  980000 : ({ "find", "¡˙»™Ω£",       "dragon sword",       "", "1" }),
  990000 : ({ "find", "»Ì¡˙ΩÓ",       "dragon whip",        "", "1" }), 
 1000000 : ({ "find", "Ó·∏´",         "yue fu",             "", "1" }),
 1100000 : ({ "find", "¥Ûµ∂",         "da dao",             "", "1" }),
 1200000 : ({ "find", "¥Ûπ˜",         "da gun",             "", "1" }),
 1300000 : ({ "find", "ªœΩ…˛",       "huangjin sheng",     "", "1" }),
 1400000 : ({ "find", "æ…∞◊≤º¥Ó∞¸",   "da bao",             "", "1" }),
 1600000 : ({ "find", "◊œΩ∫Ï∫˘¬´",   "hu lu",              "", "1" }),
 1700000 : ({ "find", "—Ú÷¨”Òæª∆ø",   "jing ping",          "", "1" }),
 2200000 : ({ "find", "∆–Ã·’»",       "puti zhang",         "", "1" }),
 2300000 : ({ "find", HIY"æ≈ª∑Œ˝’»"NOR, "nine-ring staff",  "", "1" }),
]);

void create()
{
  seteuid(getuid());
  m_keys=order_list(keys(quests_weapon));
}

mapping query_quest(object who)
{
  mapping quest;
  int i;
  string* info;
  string *strs = ({
    "$NœÎœÎÀµµ¿£∫ΩÒÃÏŒ“’˝◊º±∏«Î»À»•’“",
    "$Nœ∏œÎ¡À“ªœ¬Àµµ¿£∫±æ√≈”–»ÀœÎ“™ ≤√¥",
    "$Nµ„Õ∑Àµµ¿£∫’‚¿Ô…–»±–©",
    "$NœÎœÎÀµµ¿£∫ø…∑Ò∞Ô±æ√≈—∞µ√",
  });  
  
  i = quest_accurate_index (m_keys, who->query("combat_exp"));
  i = quest_random_index (m_keys, i);
  info=quests_weapon[m_keys[i]];
  
  quest=(["quest":"’“"+info[IDX_NAME]]);
  quest+=(["quest_msg":strs[random(sizeof(strs))]+info[IDX_NAME]+
           "£¨ƒ„ø…∑Ò»•—∞“ª–©¿¥£ø\n"]);
  quest+=(["bonus":log10(who->query("combat_exp"))*50+10]);
  quest+=(["reward_msg":"$N–¶µ¿£∫≤ª¥Ì≤ª¥Ì£¨”–¿Õƒ„¡À°£\n"]);
  return quest;
}
