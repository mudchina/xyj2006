//Cracked by Roath
// create by snowcat.c 12/8/1997
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "寺前");
  set ("long", @LONG

只见万年雷音寺前为一广场，一路铺着明亮的玛瑙花砖，广场
的正面可见无数殿宇蕊宫珠阙紫气瑞瑞。东边有仙猿摘果入桃
林，西边有白鹤栖松立枝头；场南有彩凤双双，向日一鸣天下
瑞，场北是青鸾对对，迎风耀舞世间稀。

LONG);

  set("exits", ([
        "north"   : __DIR__"shandian",
        "south"   : __DIR__"yimen",
      ]));
  set("objects", ([
        __DIR__"npc/anuo" : 1,
        __DIR__"npc/jiaye" : 1,
     ]));
  set("outdoors", __DIR__);

  setup();
}

void init()
{
        object me;
    me=this_player();
     if (((me->query("fangcun/panlong_wzg_rsg")=="done")||(me->query("fangcun/panlong_wzg")=="done"))&&(me->query_temp("wzg_rulaifo")==10))
      	message_vision(HIY"阿傩，迦叶向$N恭身行礼道：施主不辞辛劳,远道献礼，我佛在大雄宝殿已等候多时了．\n"NOR,me);
}

/*
int valid_leave (object who, string dir)
{
  object where = this_object ();
  object anuo = present ("anuo zunzhe",where); 
  object jiaye = present ("jiaye zunzhe",where); 

  if (dir == "north")
    return ::valid_leave (who, dir);

  if (who->query_temp("wzg_rulaifo")==10)
		return ::valid_leave (who, dir);

  if (who->query_temp("obstacle/lingshan_enter"))
    return ::valid_leave (who, dir);

  if (anuo)
     return notify_fail("阿傩将你轻拦：我佛祖暂不待客也。\n");
   if (jiaye)
        return notify_fail("迦叶将你轻拦：我佛祖暂不待客也。\n");

  return ::valid_leave (who, dir);
}

*/
