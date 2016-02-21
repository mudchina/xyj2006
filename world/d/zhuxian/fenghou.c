#include <ansi.h>
#include <room.h>


inherit ROOM;

void create ()
{
  set ("short", HIC "风吼阵" NOR);   
  set ("long", @LONG   
诗曰：“风吼阵中兵刃窝，暗藏奇玄妙若天；伤人不怕神仙体，消尽浑身血肉多。”
吾风吼阵中藏玄妙，按地水火风之数，内有风火，此风火乃先天之气，叁昧真火，百万兵刃
从中而出。若神仙进此阵，风火交作，万刃齐攒，四肢立成齑粉；怕他有倒海移山之异术。
难免身体化成脓血。
LONG);

    set("exits", ([ 
               "west" : __DIR__"tianjue",
               "north" : __DIR__"hanbing",
               "east" : __DIR__"hongshui",
//               "south" : __DIR__"entrance",
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
 tell_object(this_object(), HIC "\n\n一阵狂风吹过，你觉得眼睛都睁不开了。\n\n" NOR);
 ob->receive_damage("sen", random(50)+50);
 COMBAT_D->report_sen_status(ob);
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
