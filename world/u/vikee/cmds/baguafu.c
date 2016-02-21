#include <ansi.h>
inherit ITEM;
void init();
void create()
{
  set_name("八卦符", ({"bagua fu", "fu",}));
  set_weight(100);
  set("unit", "张");
  set("value", 0);
        setup();
}

void init()
{
  add_action("do_direct","direct");
}
int do_direct (string arg)
{
  object me = this_player();
  if (!arg) return notify_fail("用法：direct <direction>\n");
  write ("你用朱笔在八卦符上写下 "HIR+arg+ NOR" 。\n");
  set("dir",arg);
  return 1;
}
