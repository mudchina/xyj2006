// Room: /d/4world/schoolbook.c
inherit ROOM;

void create()
{
  set ("short", "书房");
  set ("long", @LONG

书房中整理得相当干净，靠窗摆着一张大的红木书桌，上面还铺着
红色的缎布。桌上摆着些书，还有些文房四宝。一个小花瓶里还插
着些采来的小花。靠墙一个大书架上摆满了书籍。南边可以看到天
井及一些来回走动的家人。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"schoolin",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dongfangying" : 1,
  __DIR__"npc/dongfanger" : 1,
]));

  setup();
}
void init()
{
        add_action("do_skills", "skills");
}

int do_skills(string arg)
{       object ob;
        object me;
        me=this_player();
        if(!me->query("newbie/learn") )
                return
notify_fail("只有巫师或有师徒关系的人能察看他人的技能。\n");
        if ( (arg != "dongfang ying"))
                return
notify_fail("只有巫师或有师徒关系的人能察看他人的技能。\n");
        else
write("
东方英目前所学过的技能：

  基本轻功 (dodge)                         - 马马虎虎  50/    0
  内功心法 (force)                         - 半生不熟  40/    0
  拆招卸力之法 (parry)                     - 马马虎虎  50/    0
  基本剑术 (sword)                         - 马马虎虎  50/    0
  扑击格斗之技 (unarmed)                   - 马马虎虎  50/    0

\n");
                return 1;
}
