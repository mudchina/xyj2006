
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// create by snowcat.c 2/8/1997

#include <ansi.h>

#define DEBUG 0

#define REWARD 19

#define STEP_PREPARE 0
#define STEP_FIGHT   1
#define STEP_FINISH  2

#define MODE_SINGLE_SD 0
#define MODE_SINGLE_LT 1
#define MODE_TEAM_LT   2
#define MODE_TEAM_DZ   3
#define MODE_TEAM_XH   4
string *modes = ({
  "个人散打",
  "个人擂台",
  "门派擂台",
  "门派对阵",
  "门派循环赛",
});
string *mode_hints = ({
  "由任意两名玩家上场较量",
  "玩家依次上场与擂主较量，赢者为新擂主",
  "每门派的选手依次上场打擂，该选手赢了为本门派擂主",
  "每门派的选手按弱强等级分类，各门派间的同级选手较量",
  "每门派的选手依次与别的门派所有选手较量",
});

#define FAMILY_NONE     0
#define FAMILY_FANGCUN  1
#define FAMILY_MOON     2
#define FAMILY_PUTUO    3
#define FAMILY_HELL     4
#define FAMILY_JJF      5
#define FAMILY_LONGGONG 6
#define FAMILY_WUDIDONG 7
#define FAMILY_XUESHAN  8
#define FAMILY_SHUSHAN  9
#define FAMILY_PANSI  10
#define FAMILY_HYD  11
string *families = ({
  "混合门派",
  "方寸山三星洞",
  "月宫",
  "南海普陀山",
  "阎罗地府",
  "将军府",
  "东海龙宫",
  "陷空山无底洞",
  "大雪山",
  "蜀山剑派",
  "盘丝洞",
  "火云洞",

});

