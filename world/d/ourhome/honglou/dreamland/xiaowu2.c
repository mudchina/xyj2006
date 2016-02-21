
//xiaowu2.c 寻木剑
inherit ROOM;
int do_find(string arg);
void create()
{
        set("short", "小茅屋");
        set("long", @LONG
这是一个简陋的小茅屋，东面墙上挂着一柄宝剑，想来主人当年也是叱咤风云。
西面墙上贴着一首诗：
        仙灵岛上别洞天，池中孤莲伴月眠。
        一朝风雨落水面，愿君拾得惜相怜。
LONG
        );
   set("exits", ([
      "east" : __DIR__"xiaowu",
   ]));
   setup();
}
void init()
{
 add_action("do_find","xunzhao");
}
int do_find(string arg)
{
 object who=this_player();
 object ob;

 if(who->is_busy()) return notify_fail("你正忙着呢！\n");
 if(!who->query("search_for_mujian"))
    return notify_fail("这里是别人的家，你想作贼吗？\n");
        if(!arg || arg != "木剑")
           return notify_fail("你要找什么？\n");
        who->start_busy(3);
 message_vision("$N到处仔细的翻寻，不过什么都没找到！\n",who);
 message_vision("$N决定再仔细找找。\n",who);
 if(random(3) == 2)
 {
  message_vision("$N把手伸到床下摸索，突然，$N的手碰到了一样硬物。\n",who);
  message_vision("$N将其抽出一看，果然是柄木剑。\n",who);
  ob = new(__DIR__"obj/mujian");
  ob->move(who);
 }
 else
     return notify_fail("你费了半天劲，还是什么都没找到！\n");
 return 1;
}
