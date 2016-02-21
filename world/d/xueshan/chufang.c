//Cracked by Roath
//standroom.c used by weiqi...others may hate this format:D
//chufang.c

#include <room.h>
inherit ROOM;
//#include <ansi.h>

int do_add(string);
int do_jian(string);
int do_make_ice(string);

int temperature;

void create ()
{
	set ("short", "厨房");
	set ("long", @LONG

这里是雪山派的厨房。雪山弟子性格凶残者极多，常将所获之物
生吞活剥。所以这里经常不开灶，屋子角落处摆着一口大铁锅(guo)，
是雪山弟子作汤用的，旁边还有一个白瓷盆(pen)。
LONG);

	set("item_desc", 
        (["guo" : 
             " 一口大铁锅，往里面加东西用(add)，煎药用(jian yao)。\n", 
          "pen" : 
             "一只白瓷盆，盆中盛满了清水，要想制冰(make_ice)用它就可以了。\n", 
        ]));


	set("exits", 
	([ //sizeof() == 4
		"west" : __DIR__"shanpo",
	]));
	
	set("objects", 
	([ //sizeof() == 1
                "/d/obj/food/xueli" : 3,
                "/d/obj/food/zongzi" : 1,
	]));

        set("resource", ([ /* sizeof() == 1 */
         "water" : 1,
         ]));

        create_door("west", "厨房门", "east", DOOR_CLOSED);
        set("no_clean_up", 0);

        set("cook/allow",0);
        set("cook/shui",0);
        set("cook/she",0);
        set("cook/wugong",0);
        set("cook/zhizhu",0);
        set("cook/hama",0);
        set("cook/xie",0);

	setup();
}


void init()
{                                             
        add_action("do_make_ice", "make_ice");
        add_action("do_add", "add");
        add_action("do_jian", "jian");
}

int do_add(string arg)
{
        string item_name;
        object who = this_player();
        object me = this_object();
        object item;

        if(!arg) return notify_fail("你要将什么东西加进锅里？\n");
        if( sscanf(arg, "%s in guo", item_name)!=1 )
                return notify_fail("用法：add <> in guo。\n");

        if (item_name=="water")
          {
          message_vision( "$N往锅里舀了一勺水。\n",who);
          me->set("cook/allow",1);
          me->set("cook/shui",1);
          return 1;
          }

        item=present(item_name, who);
        if (! present(item_name, who)) return notify_fail("你身上没有这东西。\n");

        if ( item->query("cook/allow") !=1 ) 
        return notify_fail("这锅是用来煎药的，别什么东西都往里扔。\n");
        if ( item->query("cook/type") == "shui") me->set("cook/allow",1);
        message_vision( "$N将一"+item->query("unit")+item->query("name")+"扔进锅里。\n",who);
        set("item_desc/guo" , " 一口大铁锅(add)，煎药用(jian yao)，"
             +"里面乱七八糟的不知放了些什么。\n");

        if (me->query("cook/"+item->query("cook/type")) < item->query("cook/value"))
           me->set("cook/"+item->query("cook/type"),item->query("cook/value"));
        destruct(item);
        return 1;
}

int do_jian(string arg)
{
        object me = this_object();
        object who = this_player();
        object tang;
        int prices;
 
        if(!arg || arg != "yao") return notify_fail("煎啥？\n");
        if ( !me->query("cook/allow") ) return notify_fail("锅里连水都没有，怎么煎？\n");

        prices=me->query("cook/shui")*me->query("cook/she")*me->query("cook/xie")
                   *me->query("cook/hama")*me->query("cook/zhizhu")*me->query("cook/wugong");

        tang=new("/d/xueshan/obj/tang");
        if( !prices ) tang->set("name","刷锅水"); 
        tang->set("prices",prices); 
        message_vision( "$N在锅里胡乱搅了搅，捞上来一碗"+tang->query("name")+"。\n",who);
        tang->move(environment(who));

        me->set("cook/allow",0);
        me->set("cook/shui",0);
        me->set("cook/she",0);
        me->set("cook/wugong",0);
        me->set("cook/zhizhu",0);
        me->set("cook/hama",0);
        me->set("cook/xie",0);

        set("item_desc/guo" , " 一口大铁锅(add)，煎药用(jian yao)。\n");

        return 1;
}


int do_make_ice(string arg)
{
        object me = this_object();
        object who = this_player();
        int ii;

        if (who->query_skill_mapped("force")!="ningxie-force")
                return notify_fail("只有用冰谷凝血功才能制水成冰。\n");
        if (who->query("force")<100)
                return notify_fail("你内力不继，心有余而力不足。\n");

        temperature=0;
        message_vision("$N伸出右手食指，插入瓷盆。\n",who);
        who->start_busy(10);
        call_out ("freezing",10,who);
        me->add("force", -100);

        return 1;
}


int freezing (object who)
{
  object bing;
  string *msg = ({
  "水面便浮起一丝丝白气。\n",
  "瓷盆外面冒出股股寒气。\n",
  "瓷盆边上起了一层白霜。\n",
  "水面结成一片片薄冰。\n",
  "冰越结越厚。\n",
});

  temperature=temperature+10;
  if (temperature<200)
    {
     if (who->query("force")<100) 
       {
        message_vision("$N大汗淋漓，盆中的水却还没结成冰，$N难过的站了起来。\n",who);
        temperature=0;
        return 1;
       } 
     else 
       {
        message_vision(msg[random(sizeof(msg))],who);
        who->add("force", -100);
        who->start_busy(10);
        call_out ("freezing",10,who);
        return 1;
       }
    }
  else 
    {
    message_vision("一盏茶时分，一瓷盆清水都化成了一块结结实实的玄冰。\n",who);
    bing=new("/d/xueshan/obj/xuanbing");
    bing->move(environment(who));
    return 1;
    } 
}


