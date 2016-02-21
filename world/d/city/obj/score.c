// score by cnd 2000

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(""HIY"仙侣情缘排行榜"NOR"", ({"score"}));
        set("long", "仙侣情缘的各种排名，可以用read来看。\n");
     set("no_get", "你拿不起来这样东西。\n");
}

void init()
{
  add_action("do_read","read");
//  add_action("do_list","list");
}

//int do_list(string arg)
//{
//string type;
//  type="/adm/daemons/toptend"->query_type();
//  write(type);
//  return 1;
//}

int do_read(string type)
{
 write("/adm/daemons/toptend"->topten_query(type));
return 1;

}
