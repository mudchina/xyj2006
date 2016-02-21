// Room: /d/4world/huofang.c
inherit ROOM;

void create ()
{
  set ("short", "仓库");
  set ("long", @LONG

这里不知是那家商号的仓库，周围密密麻麻堆放着些箱子。仓库中
做工的人很多，大多是光着脚的青年汉子。一趟又一趟的搬运着货
物。墙上贴着张大报，大意是缺人手，要请人来工作(work)。
LONG);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/man" : 3,
]));

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"west1",
]));

  setup();
}
void init()
{
        add_action("do_work", "work");
}

int do_work(string arg)
{
        object ob;
        object me;

        me = this_player();

   if (! me->query_temp("working_in_liangdian")) {
message_vision("$N从车上卸下一袋袋的大米，又垒在墙边，累的腰酸腿疼！\n",me);
        me->add("kee",-20);
        me->add("sen",-20);
        ob = new("/obj/money/silver");
        ob->move(me);
        message_vision("旁边过来个工头笑眯眯地对$N说：辛苦啦，这是你的工钱。\n",me);
        me->set_temp("working_in_liangdian",1);
        call_out ("reset_work",1,me);
    } else
    {
        message_vision("旁边的壮汉赶紧把$N扶起来：先歇一会儿。\n",me);
    }
        return 1;
}
void reset_work (object me)
{
        me->set_temp("working_in_liangdian",0);
}

