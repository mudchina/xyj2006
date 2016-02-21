// by snowcat jan 22 1998

#include <ansi.h>
#include <quest.c>

// the quest format is the following mapping:
// daoxing :     type     name     id            object         amount
//--------------------------------------------------------------------
//  1000   : ({ "find",  "秘笈",   "mi ji" ,     "",             "1" }), 
//  5000   : ({ "give",  "灾民",   "zai min" ,   "银子(silver)", "5" }), 
// 12000   : ({ "kill",  "白骨精", "baigu jing", "",             "3" });
 
//找一本秘笈，救济灾民五两银子，三打白骨精．．．．．．

mapping quests_give = ([
       5 : ({ "give", "女孩",         "girl",        "",                     "1" }),
      10 : ({ "give", "男孩",         "boy",         "",                     "1" }),
      15 : ({ "give", "小女孩",       "kid",         "",                     "1" }),
      20 : ({ "give", "小男孩",       "kid",         "",                     "1" }),
      25 : ({ "give", "苦力",         "kuli",        "",                     "1" }),
      30 : ({ "give", "酸秀才",       "suan xiucai", "",                     "1" }),
      40 : ({ "give", "游客",         "youke",       "",                     "1" }),
      45 : ({ "give", "路人",         "luren",       "",                     "1" }),
      50 : ({ "give", "江湖艺人",     "yi ren",      "银子(silver)",         "1" }),
      55 : ({ "give", "浣衣女",       "girl",        "银子(silver)",         "1" }),
      60 : ({ "give", "阿七婆",       "aqi po",      "",                     "1" }),
      65 : ({ "give", "农夫",         "farmer",      "",                     "1" }),
      70 : ({ "give", "樵夫",         "qiao fu",     "",                     "1" }),
     100 : ({ "give", "庙祝",         "miao zhu",    "黄金(gold)",           "1" }),
     110 : ({ "give", "妇人",         "woman",       "黄金(gold)",           "1" }),
     121 : ({ "give", "赵秀才",       "xiucai",      "〖三字经〗(book)",     "1" }),
     122 : ({ "give", "钱秀才",       "xiucai",      "〖三字经〗(book)",     "1" }),
     123 : ({ "give", "孙秀才",       "xiucai",      "〖三字经〗(book)",     "1" }),
     124 : ({ "give", "李秀才",       "xiucai",      "〖三字经〗(book)",     "1" }),
     125 : ({ "give", "周秀才",       "xiucai",      "〖三字经〗(book)",     "1" }),
     126 : ({ "give", "吴秀才",       "xiucai",      "〖三字经〗(book)",     "1" }),
     127 : ({ "give", "郑秀才",       "xiucai",      "〖三字经〗(book)",     "1" }),
     128 : ({ "give", "王秀才",       "xiucai",      "〖三字经〗(book)",     "1" }),
     130 : ({ "give", "轿夫",         "jiaofu",      "银子(silver)",         "1" }),
     135 : ({ "give", "轿夫头",       "jiaofu tou",  "银子(silver)",         "1" }),
     140 : ({ "give", "唢呐手",       "suona shou",  "银子(silver)",         "1" }),

    1000 : ({ "give", "学童",         "xue tong",    "〖三字经〗(book)",     "1" }),
    2000 : ({ "give", "小童",         "kid",         "〖三字经〗(book)",     "1" }),
    3000 : ({ "give", "吃客",         "chi ke",      "炸鸡腿(jitui)",        "1" }),
    4000 : ({ "give", "农家女",       "nongjia nu",  "银子(silver)",         "1" }),
    5000 : ({ "give", "书呆子",       "shudai zi",   "〖三字经〗(book)",     "1" }),

    6000 : ({ "give", "少妇",         "woman",       "银子(silver)",         "1" }),
    7000 : ({ "give", "中年妇女",     "woman",       "银子(silver)",         "1" }),
    8000 : ({ "give", "老妇人",       "old woman",   "银子(silver)",         "1" }),
    9000 : ({ "give", "老妇",         "lao fu",      "银子(silver)",         "1" }),

   10000 : ({ "give", "渔夫",         "yu fu",       "钢叉(gang cha)",       "1" }),
   11000 : ({ "give", "樵夫",         "qiao fu",     "大板斧(bigaxe)",       "1" }),
   12000 : ({ "give", "妇女",         "fu nu",       "粉红绸衫(pink cloth)", "1" }),
   13000 : ({ "give", "街头小商人",   "shang ren",   "黄金(gold)",           "1" }),
   14000 : ({ "give", "乞丐",         "qi gai",      "银子(silver)",         "1" }),
   15000 : ({ "give", "艺人",         "yi ren",      "银子(silver)",         "1" }),
   16000 : ({ "give", "车夫",         "che fu",      "银子(silver)",         "1" }),
   17000 : ({ "give", "路人",         "luren",       "银子(silver)",         "1" }),
   18000 : ({ "give", "老婆婆",       "old woman",   "银子(silver)",         "1" }),

   21000 : ({ "give", "摇铃水客",     "yaoling shuike", "银子(silver)",         "1" }),
   22000 : ({ "give", "卖菜妇女",     "maicai funu", "竹筐(kuang)",          "1" }),
   23000 : ({ "give", "苦行僧",       "kuxing sen",  "饭(fan)",              "1" }),
   24000 : ({ "give", "脚夫",         "jiao fu",     "圆口布鞋(shoes)",      "1" }),
   25000 : ({ "give", "读书人",       "dushu ren",   "〖三字经〗(book)",     "1" }),
   26000 : ({ "give", "女佣",         "nu yong",     "银子(silver)",         "1" }),
   27000 : ({ "give", "女仆",         "nu pu",       "银子(silver)",         "1" }),
   28000 : ({ "give", "男仆",         "nan pu",      "银子(silver)",         "1" }),
   29000 : ({ "give", "饥民",         "ji min",      "银子(silver)",         "1" }),

   31000 : ({ "give", "瘦子",         "shou zi",     "银子(silver)",         "1" }),
   32000 : ({ "give", "断肠妇人",     "duanchang furen", "银子(silver)",         "1" }),

   41000 : ({ "give", "穷和尚",       "he shang",    "银子(silver)",         "1" }),
   42000 : ({ "give", "瘦和尚",       "he shang",    "银子(silver)",         "1" }),
   43000 : ({ "give", "小和尚",       "heshang",     "银子(silver)",         "1" }),
   44000 : ({ "give", "老和尚",       "heshang",     "银子(silver)",         "1" }),
   45000 : ({ "give", "守寺僧",       "shousi seng", "短弯刀(duan wan dao))","1" }),
   46000 : ({ "give", "书生",         "shu sheng",   "银子(silver)",         "1" }),

   52000 : ({ "give", "挑灯夫",       "tiaodeng fu", "银子(silver)",         "1" }),
   55000 : ({ "give", "送油客",       "songyou ke",  "黄金(gold)",           "1" }),

   62000 : ({ "give", "铁匠",         "tie jiang",   "金瓜(golden hammer)",  "1" }),
   63000 : ({ "give", "茶客",         "cha ke",      "绿茶(lu cha)",         "1" }),

   71000 : ({ "give", "村民",         "cun min",     "〖金刚经〗(jingang)",  "1" }),
   72000 : ({ "give", "香客",         "xiang ke",    "〖金刚经〗(jingang)",  "1" }),
   73000 : ({ "give", "农人",         "nong ren",    "〖金刚经〗(jingang)",  "1" }),
   74000 : ({ "give", "农妇",         "nong fu",     "〖金刚经〗(jingang)",  "1" }),
   75000 : ({ "give", "居民",         "ju min",      "银子(silver)",         "1" }),
   76000 : ({ "give", "市民",         "shi min",     "银子(silver)",         "1" }),

   80001 : ({ "give", "赵二哥",       "lie hu",      "筋骨粉(jingu fen)",    "1" }),
   80002 : ({ "give", "赵三哥",       "lie hu",      "筋骨粉(jingu fen)",    "1" }),
   80003 : ({ "give", "赵二叔",       "lie hu",      "筋骨粉(jingu fen)",    "1" }),
   80004 : ({ "give", "赵三叔",       "lie hu",      "筋骨粉(jingu fen)",    "1" }),
   80005 : ({ "give", "赵二伯",       "lie hu",      "筋骨粉(jingu fen)",    "1" }),
   80006 : ({ "give", "赵三伯",       "lie hu",      "筋骨粉(jingu fen)",    "1" }),
   80007 : ({ "give", "钱二哥",       "lie hu",      "筋骨粉(jingu fen)",    "1" }),
   80008 : ({ "give", "钱三哥",       "lie hu",      "筋骨粉(jingu fen)",    "1" }),
   80009 : ({ "give", "钱二叔",       "lie hu",      "跌打丸(dieda wan)",    "1" }),
   80010 : ({ "give", "钱三叔",       "lie hu",      "跌打丸(dieda wan)",    "1" }),
   80011 : ({ "give", "钱二伯",       "lie hu",      "跌打丸(dieda wan)",    "1" }),
   80012 : ({ "give", "钱三伯",       "lie hu",      "跌打丸(dieda wan)",    "1" }),
   80013 : ({ "give", "孙二哥",       "lie hu",      "跌打丸(dieda wan)",    "1" }),
   80014 : ({ "give", "孙三哥",       "lie hu",      "跌打丸(dieda wan)",    "1" }),
   80015 : ({ "give", "孙二叔",       "lie hu",      "跌打丸(dieda wan)",    "1" }),
   80016 : ({ "give", "孙三叔",       "lie hu",      "跌打丸(dieda wan)",    "1" }),
   80017 : ({ "give", "孙二伯",       "lie hu",      "金创药(jinchuang yao)", "1" }),
   80018 : ({ "give", "孙三伯",       "lie hu",      "金创药(jinchuang yao)", "1" }),
   80019 : ({ "give", "李二哥",       "lie hu",      "金创药(jinchuang yao)", "1" }),
   80020 : ({ "give", "李三哥",       "lie hu",      "金创药(jinchuang yao)", "1" }),
   80021 : ({ "give", "李二叔",       "lie hu",      "金创药(jinchuang yao)", "1" }),
   80022 : ({ "give", "李三叔",       "lie hu",      "金创药(jinchuang yao)", "1" }),
   80023 : ({ "give", "李二伯",       "lie hu",      "金创药(jinchuang yao)", "1" }),
   80024 : ({ "give", "李三伯",       "lie hu",      "金创药(jinchuang yao)", "1" }),

  100000 : ({ "give", "花钿",         "ban niang",   "黄金(gold)",           "1" }),
  100010 : ({ "give", "香玉",         "ban niang",   "钻石戒指(zuan jie)",   "1" }),
  100020 : ({ "give", "小真",         "ban niang",   "金戒指(jin jie)",      "1" }),
  100020 : ({ "give", "珠怜",         "ban niang",   "描龙玉佩(yu pei)",     "1" }),

  110000 : ({ "give", "蒲牢",         "pu lao",      "水晶腰牌(yao pai)",    "1" }),
  120000 : ({ "give", "狴犴",         "bi an",       "水晶腰牌(yao pai)",    "1" }),
  130000 : ({ "give", "睚眦",         "ya zi",       "水晶腰牌(yao pai)",    "1" }),
  140000 : ({ "give", "霸下",         "ba xia",      "水晶腰牌(yao pai)",    "1" }),
  150000 : ({ "give", "螭吻",         "chi wen",     "水晶腰牌(yao pai)",    "1" }),
  160000 : ({ "give", "饕餮",         "tao tie",     "水晶腰牌(yao pai)",    "1" }),
  170000 : ({ "give", "蚣蝮",         "gong fu",     "水晶腰牌(yao pai)",    "1" }),
  180000 : ({ "give", "金猊",         "jin ni",      "水晶腰牌(yao pai)",    "1" }),
  190000 : ({ "give", "椒图",         "shu tu",      "水晶腰牌(yao pai)",    "1" }),

  200000 : ({ "give", "曹国舅","cao guojiu",  "【太乙真经】(taiyi zhenjing)","1" }),
  210000 : ({ "give", "韩湘子","han xiangzi", "【太乙真经】(taiyi zhenjing)","1" }),
  220000 : ({ "give", "汉钟离","han zhongli", "【太乙真经】(taiyi zhenjing)","1" }),
  230000 : ({ "give", "何仙姑","he xiangu",   "【太乙真经】(taiyi zhenjing)","1" }),
  240000 : ({ "give", "蓝采和","lan caihe",   "【太乙真经】(taiyi zhenjing)","1" }),
  250000 : ({ "give", "铁拐李","tieguai li",  "【太乙真经】(taiyi zhenjing)","1" }),
  260000 : ({ "give", "张果老","zhang guolao","【太乙真经】(taiyi zhenjing)","1" }),
  270000 : ({ "give", "吕洞宾","lu dongbin",  "【太乙真经】(taiyi zhenjing)","1" }),

]);


