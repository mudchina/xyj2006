//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5

inherit ROOM;

#include <ansi.h>
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);
int do_hear();
#include <ansi.h>
void create()
{
        set("short", HIY"大殿"NOR);
        set("long", @LONG
        这里是蜀山剑派的大殿，是会客的地点。供着元始天尊、太上道
君和天上老君的神像，香案上香烟缭绕。靠墙放着几张太师椅，地上放着
几个蒲团。东北是掌门休息室，南边是练武的广场，北边是后殿。
LONG);

        set("valid_startroom", 1);
        set("exits", ([
                "south" : __DIR__"square",
                "north" : __DIR__"houdian",
                "northeast" : __DIR__"zhmroom",
        ]));

        set("objects", ([
                __DIR__"npc/jiansheng" : 1,
        ]));

        setup();
//      replace_program(ROOM);
}

void init()
{
   object where=this_object();

    remove_call_out("check_time");
   check_time(where);
   add_action("do_hear","hear");
}
void check_time(object where)
{

   mixed *local = localtime((time()-900000000)*60);
   int t = local[2] * 60 + local[1];
   int phase=((int)(t/120));
   if(phase==0&&(!query("jiangjing"))) jiang_jing(where);
if(phase==7&&query("jiangjing")) finish_jing(where);
   call_out("check_time",60,where);
}

void jiang_jing(object where)
{
message("channel:es",CYN+"◇"WHT"蜀山派"CYN"◇"WHT"剑圣[Jian sheng]"CYN"：现在开始传授我们蜀山的仙术。\n"+NOR,users());
tell_object(where,"剑圣说道：蜀山仙术能吸取山中灵气。\n");
tell_object(where,"修炼后能突破凡人之躯，御剑飞行，追风逐月，星海飞驰，\n");
tell_object(where,"修炼仙术目的是希望能参透天地间永恒的奥秘，以达到天人合一的境界。\n");

   tell_object(where,"注意：山外有山，天外有天。\n");
   set("jiangjing",1);
}
void finish_jing(object where)
{
   tell_object(where,"蜀山派说道：回去试试你的仙术进展如何。\n");
   set("jiangjing",0);
     set ("long", @LONG
   蜀山派弟子安静的坐着 ，他们在听剑圣说些什么。
LONG);
}
int do_hear()
{
 object yao;
   object me=this_player();

   if(me->is_busy())
      return notify_fail("你正忙着呢。\n");
   if(!query("jiangjing"))
      return notify_fail("剑圣还没开始传授飞仙之术呢。\n");

 if((string)me->query("family/family_name")!="蜀山派")
      return notify_fail("外派弟子不得来听讲。\n");
   if(me->query("faith")>40000)
      return notify_fail("你的飞仙之术已经有所造诣了。\n");

    tell_object(me,"你在旁边听着，听着。不禁对飞仙之术有所领悟。\n");
   me->start_busy(5);
   me->improve_skill("zixia-shengong",random((int)(me->query("spi")+me->query("int"))/2));
   me->improve_skill("taoism",random((int)(me->query("spi")+me->query("int"))/2));
//  me->add("faith",1);
//  me->add("combat_exp",30);
//  me->add("potential",10);
   me->receive_damage("kee",20);
   me->receive_damage("sen",20);
   return 1;
}
int valid_leave(object me, string dir)
{
        if (me->query("family/master_id") == "master swordsman")        
        return ::valid_leave(me, dir);
   if (dir == "northeast" ) {
        if (objectp(present("master swordsman", environment(me))))
   return notify_fail("一股神秘的力量阻止了你，也许是剑圣的力量。\n");
        }   
        return ::valid_leave(me, dir);
}
