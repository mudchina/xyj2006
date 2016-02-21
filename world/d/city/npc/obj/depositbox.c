//box.c

inherit ITEM;

void create()
{
    set_name("铁盒",({"deposit box","box"}));
    set_weight(1000);
    set_max_encumbrance(10000);
    if( clonep() )
         set_default_object(__FILE__);
    else
     {
         set("unit", "只");
         set("long", "这是一只用来寄存东西的铁盒(Deposit box)。\n");
         set("value", 1000);
     }
}
int is_container() { return 1; }

void init ()
{
    add_action("do_mark","mark");
}

int do_mark(string arg)
{
    object who=this_player();
    object me=this_object();
    if (!arg) return notify_fail("你想在铁盒上标记什么?\n");
    if (stringp(me->query("mark"))) 
      tell_object(who,"你将盒子上原有的标记擦去。\n");
    me->set("mark",arg);
    tell_object(who,"你在盒子上刻上“"+arg+"”的字样。\n");
    me->set("long","一个铁盒,上面刻着“"+arg+"”的字样。\n");
    return 1;
}    
