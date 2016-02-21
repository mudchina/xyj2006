//Cracked by Roath
inherit F_CLEAN_UP;
#include <ansi.h>
#include <quest.h>

mapping quests_armor = ([
      10 : ({ "find", "∆§±≥–ƒ",         "pi beixin",          "", "1" }),
      15 : ({ "find", "°º»≠æ≠°Ω",       "quan jing"           "", "1" }),
      20 : ({ "find", "≈£∆§∂‹",         "leather shield",     "", "1" }),
      30 : ({ "find", "ÃŸº◊",           "teng jia",           "", "1" }),
      40 : ({ "find", "≈£∆§—•",         "leather boots",      "", "1" }),
      50 : ({ "find", "ª®Òﬁ—•",         "flower boots",       "", "1" }),
     100 : ({ "find", "±¯∑˛",           "cloth",              "", "1" }),
     110 : ({ "find", "∆§≈€",           "pipao",              "", "1" }),
     200 : ({ "find", "±ÃÀÆƒﬁ…—",       "nichang",            "", "1" }),
    4100 : ({ "find", "ª¢∆§¥ÛÎ©",       "hupi dachang",       "", "1" }),
    4200 : ({ "find", "”≤ƒæø¯",         "ying mukui",         "", "1" }),
    4300 : ({ "find", "Ã˙ø¯",           "tie kui",            "", "1" }),
    4400 : ({ "find", "≤ºÕ∑ΩÌ",         "tou jin",            "", "1" }),
    4450 : ({ "find", "∑˜≥æ",           "fuchen",             "", "1" }),
    4500 : ({ "find", "∫Ò≈£∆§∂‹",       "houniu pidun",       "", "1" }),
    4600 : ({ "find", "◊œ»ﬁ≈˚∑Á",       "zirong pifeng",      "", "1" }),
    7000 : ({ "find", "œ¨≈£∆§“¬",       "xiniu piyi",         "", "1" }),
    8000 : ({ "find", "—√“€∑˛",         "yayi cloth",         "", "1" }),
    8100 : ({ "find", "œ¨∆§±≥–ƒ",       "xipi beixin",        "", "1" }),
    8200 : ({ "find", "≈£∆§“¬",         "niupi yi",           "", "1" }),
    8300 : ({ "find", "–‹∆§∂Ã≈€",       "xiongpi duanpao",    "", "1" }),
    8400 : ({ "find", "ª¢∆§»π",         "hupi qun",           "", "1" }),
    8500 : ({ "find", "¿«∆§ø„",         "langpi qun",         "", "1" }),
    9000 : ({ "find", "’Ω≈€",           "zhan pao",           "", "1" }),
   11000 : ({ "find", "Ã˙º◊",           "iron armor",         "", "1" }),
   12000 : ({ "find", "—©…Ω∞◊≈€",       "baipao",             "", "1" }),
   13000 : ({ "find", "∞Àÿ‘µ¿≈€",       "bagua pao",          "", "1" }),
   14000 : ({ "find", " ÏÕ≠º◊",         "bronze armor",       "", "1" }),
   20000 : ({ "find", "ÃÏ±¯’Ωº◊",       "heaven armor",       "", "1" }),
   21000 : ({ "find", "¿«∆§»π",         "wolf skirt",         "", "1" }),
   22000 : ({ "find", " ﬁ∆§»π",         "shoupi qun",         "", "1" }),
   23000 : ({ "find", HIG "∞≈Ω∂»π" NOR, "palm skirt",         "", "1" }),
   32500 : ({ "find", "√Õ·Ô∆§",         "mengma pi",          "", "1" }),
   33000 : ({ "find", "Ã˙Õ∑—•",         "tie tou xue",        "", "1" }),
   33500 : ({ "find", "Õ≠Õ∑—•",         "tong tou xue",       "", "1" }),
   34000 : ({ "find", "Ã˙◊¶Ã◊",         "tie zhua tao",       "", "1" }),
   34500 : ({ "find", "Õ≠◊¶Ã◊",         "tong zhua tao",      "", "1" }),
   35000 : ({ "find", "Ã˙ ÷Ã◊",         "tie shou tao",       "", "1" }),
   35500 : ({ "find", "Õ≠ ÷Ã◊",         "tong shou tao",      "", "1" }),
   36000 : ({ "find", "Ã˙Õ∑ø¯",         "tie tou kui",        "", "1" }),
   36500 : ({ "find", "Õ≠Õ∑ø¯",         "tong tou kui",       "", "1" }),
   37000 : ({ "find", "Ã˙ª§ºÁ",         "tie hu jian",        "", "1" }),
   37500 : ({ "find", "Õ≠ª§ºÁ",         "tong hu jian",       "", "1" }),
   38000 : ({ "find", "Ã˙ª§—¸",         "tie hu yao",         "", "1" }),
   38500 : ({ "find", "Õ≠ª§—¸",         "tong hu yao",        "", "1" }),
   39000 : ({ "find", "Ã˙ª§ÕÛ",         "tie hu wan",         "", "1" }),
   39500 : ({ "find", "Õ≠ª§ÕÛ",         "tong hu wan",        "", "1" }),
   40000 : ({ "find", HIY"ª§∑®Ù¬Ùƒ"NOR, "jia sha",            "", "1" }),
   41000 : ({ "find", HIY"Ù¬Ùƒ"NOR,     "jia sha",            "", "1" }),
   41500 : ({ "find", BLK"∫⁄÷•¬ÈÃ¿‘≤"NOR,"blackty",          "", "1" }),
   42000 : ({ "find", "ÍÛ≈£∆§",         "maoniu pi",          "", "1" }),
   43000 : ({ "find", "ÀÆ≈£∆§",         "shuiniu pi",         "", "1" }),
   44000 : ({ "find", "“∞œÛ∆§",         "yexiang pi",         "", "1" }),
   45000 : ({ "find", "π´¬π∆§",         "gonglu pi",          "", "1" }),
   46000 : ({ "find", "≤Ú∆§",           "chai pi",            "", "1" }),
   47000 : ({ "find", "Œ⁄πÍº◊",         "wugui jia",          "", "1" }),
   48000 : ({ "find", "Õı∞Àº◊",         "wangba jia",         "", "1" }),
   49000 : ({ "find", "«ß¡€º◊",         "qianling jia",       "", "1" }),
   49500 : ({ "find", "æﬁ–∑ø«",         "juxie ke",           "", "1" }),
   51000 : ({ "find", "ª®±™∆§",         "huabao pi",          "", "1" }),
   52000 : ({ "find", "∞◊ª¢∆§",         "baihu pi",           "", "1" }),
   53000 : ({ "find", "∫⁄ª¢∆§",         "heihu pi",           "", "1" }),
   54000 : ({ "find", "Ω ®∆§",         "jinshi pi",          "", "1" }),
   55000 : ({ "find", "æÌ√´ ®∆§",       "juanmao pi",         "", "1" }),
   56000 : ({ "find", "…Ω√®∆§",         "shanmao pi",         "", "1" }),
   57000 : ({ "find", "∞◊Ã˙º◊",         "armor",              "", "1" }),
   57001 : ({ "find", "ª“Ã˙º◊",         "armor",              "", "1" }),
   57002 : ({ "find", "«‡Ã˙º◊",         "armor",              "", "1" }),
   57003 : ({ "find", "–‚Ã˙º◊",         "armor",              "", "1" }),
   57004 : ({ "find", "Œ⁄Ã˙º◊",         "armor",              "", "1" }),
   57005 : ({ "find", "∫⁄Ã˙º◊",         "armor",              "", "1" }),
   57010 : ({ "find", "∞◊Õ≠º◊",         "armor",              "", "1" }),
   57011 : ({ "find", "ª“Õ≠º◊",         "armor",              "", "1" }),
   57012 : ({ "find", "«‡Õ≠º◊",         "armor",              "", "1" }),
   57013 : ({ "find", "–‚Õ≠º◊",         "armor",              "", "1" }),
   57014 : ({ "find", "Œ⁄Õ≠º◊",         "armor",              "", "1" }),
   57015 : ({ "find", "∫⁄Õ≠º◊",         "armor",              "", "1" }),
   61000 : ({ "find", "ª¢∆§≈˚∑Á",       "tiger surcoat",      "", "1" }),
   65000 : ({ "find", "ÕÎ◊”Ã˙ø¯",       "wanzi tiekui",      "", "1" }),
   68000 : ({ "find", "’¡ƒæ∂‹",         "zhangmu dun",        "", "1" }),
   69000 : ({ "find", "È™ƒæ∂‹",         "nanmu dun",          "", "1" }),
   70000 : ({ "find", "œ¨≈£∆§∂‹",       "xiniupi dun",        "", "1" }),
   71000 : ({ "find", "–‹∆§∂‹",         "xiongpi dun",        "", "1" }),
   72000 : ({ "find", "œÛ∆§∂‹",         "xiangpi dun",        "", "1" }),
   73000 : ({ "find", "ª¢∆§∂‹",         "hupi dun",           "", "1" }),
   90000 : ({ "find", "Ã´º´µ¿≈€",       "cloth",              "", "1" }),
  100000 : ({ "find", "¡¡“¯º◊",         "silver armor",       "", "1" }),
  110000 : ({ "find", "—Ã¿Ôª±»º◊",     "smoky armor",        "", "1" }),
  120000 : ({ "find", "‰ÀÀÆ¬ﬁ“¬",       "fancy skirt",        "", "1" }),
  200000 : ({ "find", "∞◊¬ﬁ≈€",         "baipao",             "", "1" }),
  210000 : ({ "find", "∞Àÿ‘µ¿≈€",       "bagua pao",          "", "1" }),
  220000 : ({ "find", "Ωª∑À¯◊”º◊",     "golden armor",       "", "1" }),
  300000 : ({ "find", "Ωµƒß≈€",         "xiangmo pao",        "", "1" }),
  310000 : ({ "find", "Ωı–Â’Ω≈€",       "zhanpao",            "", "1" }),
  320000 : ({ "find", "ª∆ª¢∆§",         "huang hupi",         "", "1" }),
  330000 : ({ "find", " ﬁ∆§≈˚∑Á",       "shoupi pifeng",      "", "1" }),
  550000 : ({ "find", HIY"Ú˛¡˙≈€"NOR,   "long pao",           "", "1" }),
  700000 : ({ "find", "¥Û∫ÏÚ˛≈€",       "mangpao",            "", "1" }),
  800000 : ({ "find", HIY "Ú˛¡˙≈€" NOR, "long pao",           "", "1" }),
 2000000 : ({ "find", HIY"ŒÂ≤ ÃÏ“¬"NOR, "tian yi",            "", "1" }),
 2100000 : ({ "find", "‘Ì¬ﬁ≈€",         "purple cloth",       "", "1" }),
 2200000 : ({ "find", HIY"ΩıÔÁÙ¬Ùƒ"NOR, "jinlan jiasha",      "", "1" }),
]);

void create()
{
  seteuid(getuid());
  m_keys=order_list(keys(quests_armor));
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
  info=quests_armor[m_keys[i]];
  
  quest=(["quest":"’“"+info[IDX_NAME]]);
  quest+=(["quest_msg":strs[random(sizeof(strs))]+info[IDX_NAME]+
           "£¨ƒ„ø…∑Ò»•—∞“ª–©¿¥£ø\n"]);
  quest+=(["bonus":log10(who->query("combat_exp"))*50+10]);
  quest+=(["reward_msg":"$N–¶µ¿£∫≤ª¥Ì≤ª¥Ì£¨”–¿Õƒ„¡À°£\n"]);
  return quest;
}
