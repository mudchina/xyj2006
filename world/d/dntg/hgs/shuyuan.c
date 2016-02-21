// Room: /d/4world/shuyuan.c
inherit ROOM;

void create()
{
  set ("short", "西城书院");
  set ("long", @LONG

这是傲来国中唯一的书院。傲来本是民风淳朴，虽人人礼谦有，
于大唐之文彩天下却不可同提。书院是数年前从中原来的一位
秀才所开，城中来学的人也是不少。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"east1",
]));
  set("objects", ([
                __DIR__"npc/xiucai": 1]) );

  set("no_clean_up", 1);
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
        if(!(ob = present("lan tuyu", environment(me))))
                return
notify_fail("只有巫师或有师徒关系的人能察看他人的技能。\n");
        if ( (arg != "lan") )
                return
notify_fail("只有巫师或有师徒关系的人能察看他人的技能。\n");
        else
write("
蓝图郁目前所学过的技能：

  读书识字 (literate)                      - 已有小成  40/    0

\n");
                return 1;
}

