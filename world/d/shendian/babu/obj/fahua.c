// fahuajing.c
// by repoo

#include <ansi.h>
inherit ITEM;
int close(object me, object ob);
void create()
{
	set_name(RED"法华经"NOR,({"fahua jing", "book"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一本佛经。\n");
		set("unit", "本");
		set("value", 0);
		set("no_get",1);
      }
	setup();
}

void init()
{
            add_action("do_read","read");
	add_action("do_open", "open");
	add_action("do_enter", "enter");
}

int do_read(string arg)
{
         object obj,me=this_player();
		object ob=this_object();
               string place;
       if( arg != "fahua jing" ) return notify_fail("你要看什么？\n");
   if(this_player()->query_temp("babu/tianshen") != "done")
   return notify_fail("你可不能读！\n");
      if(!me->query_temp("fahua_read"))
    {
              place = "/d/shendian/shendian_door.c";
                place = resolve_path(me->query("cwd"), place);
                                obj = load_object(place);
message_vision(HIY"$N摇头晃脑的读着：八部天龙，一天、二龙、三枷楼罗.....\n"+HIW"啪，"+HIR"经书发出淡淡的"+HIB" 蓝光 "+HIR"，掉落在地上。\n"NOR, me);
		ob->set("exit",obj);
		ob->move(environment(me));
         me->set_temp("fahua_read",1);
     me->set_temp("fahua/read","done");
    return 1;
      }
     else
     {
     return notify_fail("读过了还读？\n");
    }
}

int do_open(string arg)
{
	object obj,me=this_player();
	object ob=this_object();
	if(!arg || arg!="fahua jing" )return 0;
	if(!ob->query("exit")) 
		return notify_fail("看过书没有？\n");
	if(ob->query_temp("opened")) 
		return notify_fail("通往众神之殿的大门已经打开了!\n");
	obj=ob->query("exit");
      if(environment(obj))
                obj = environment(obj);
message_vision("$N轻轻将法华经打开，他已经开启了通向众神之殿的大门。\n", me);
      message("channel:rumor",YEL+"\n【"+HIB" 八部天龙 "NOR+YEL"】某人："+me->query("name")+"在"+HIW" "+MISC_D->find_place(environment(me))+""NOR+YEL" "+"阅读法华经，打开了通往众神之殿的大门!\n\n"+NOR,users() );
    me->delete_temp("fahua_read");
	ob->set_temp("opened",1);
        remove_call_out("close");
    call_out("close",60, me,ob);
	return 1;
}

int do_enter(string arg)
{
	object obj,me=this_player();
	object ob=this_object();
	if(!ob->query_temp("opened"))	
		return notify_fail("还是好好读读经书吧!!\n");
   if(this_player()->query_temp("babu/tianshen") != "done")
       return notify_fail("你可不能进!!\n");
	obj=ob->query("exit");
          if(environment(obj))
                obj = environment(obj);
        message_vision(HIC"$N走进了八部天龙的世界。\n"NOR, me);
    me->move(obj);
	tell_room(environment(me), HIC"一道蓝光过后，"+me->name()+"出现在这里。\n", ({me}));
        return 1;
}

int close(object me, object ob)
{
	message_vision("$N消失了... ...\n",ob);
		ob->delete_temp("opened");
		ob->delete("exit");
        destruct(me);
	return 1;
}
