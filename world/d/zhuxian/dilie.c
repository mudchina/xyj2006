#include <ansi.h>
#include <room.h>

inherit ROOM;                                                        

void create ()
{
  set ("short", HIB "地烈阵" NOR);   
  set ("long", @LONG   
地烈成分浊厚，上雷下火太无情；就是五行乾健体，难逃骨化与形倾。
    中藏凝厚之体，外现隐跃之妙，变化多端，内隐一首红，招动有火起；
    凡人仙进此阵，再无复生之理，纵有五行妙术，怎逃此厄？
LONG);

    set("exits", ([ 
               "south" : __DIR__"tianjue",
               "east" : __DIR__"hanbing",
               "north" : __DIR__"jinguang",
             ]));
    setup();
}
void init()
{object ob;
 if( interactive( ob = this_player()))
 call_out("blowing", random(20) + 1, ob);
}
int blowing(object ob)
{
 int i;
 int damage;
        if(  ob && environment(ob) == this_object())
{
 tell_object(this_object(), HIB "\n\n地上突然冒出数道烈火。\n\n" NOR);
 COMBAT_D->report_status(ob);
 ob->receive_damage("kee", random(100)+50);
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
