#include <ansi.h>
#include <room.h>

inherit ROOM;                                                        

void create ()                                                       
{
  set ("short", HIB "天绝阵" NOR);   
  set ("long", @LONG   
天地叁寸颠倒推，玄中玄妙更难猜；神仙若遇天绝阵，顷刻肢体化成灰。
若人入此阵内，有雷鸣之处，化作灰尘；仙道若逢此处，肢体震为粉碎。
LONG);

    set("exits", ([ 
               "north" : __DIR__"dilie",
               "southwest" : __DIR__"luxian",
               "east" : __DIR__"fenghou",
]));
    set("objects",([
        __DIR__"npc/xiannpc" : 1,
       ]));
    setup();
}
void init()
{ object ob;
 if( interactive( ob = this_player()))
 call_out("blowing", random(10) + 1, ob);
}
int blowing(object ob)
{
 int i;
 int damage;
        if(  ob && environment(ob) == this_object())
{
 tell_object(this_object(), HIR "\n\n一道狂雷闪过，你觉得一阵眩晕。\n\n" NOR);
 COMBAT_D->report_sen_status(ob,1);
 ob->receive_damage("sen", random(50)+50);
 if( environment(ob) == this_object())
 call_out("blowing",random(20)+1, ob);
}
 else
 return 1;
}
void reset()
{
 ::reset();
        remove_call_out("blowing");
}
