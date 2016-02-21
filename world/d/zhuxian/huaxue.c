#include <ansi.h>
#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", RED "化血阵" NOR);   
  set ("long", @LONG   
黄风卷起黑沙飞，天地无光动杀灭；任你仙人闻此气，涓涓滴血溅征衣。
吾此阵法用先天灵气，中有风雷，内藏数斗黑沙。但神仙入阵，雷响处风卷黑沙，
些须着处，立化血水，纵是神仙难逃利害。
LONG);

    set("exits", ([ 
               "west" : __DIR__"jinguang",
               "south" : __DIR__"hanbing",
               "east" : __DIR__"lie",
               "north" : __DIR__"hongsha",
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
 tell_object(this_object(), CYN "\n\n一阵狂风卷着黑沙向你吹来。\n\n" NOR);
 ob->receive_damage("kee", random(100)+50);
 ob->receive_damage("sen", random(100)+50);
 COMBAT_D->report_status(ob);
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
