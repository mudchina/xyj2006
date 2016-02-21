#include <ansi.h>
#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", HIR "烈阵" NOR);   
  set ("long", @LONG   
诗曰：“燧人方有空中火，养丹砂炉内藏；坐守离宫为首领，红招动化空亡。”
内藏叁火，有叁昧火，空中火，石中火，叁火并为一气；中有叁首红,若神仙进此阵内，
叁展动，叁火齐飞，须火成为灰烬，纵有避火真言，难躲叁昧真火。
LONG);

    set("exits", ([ 
               "west" : __DIR__"huaxue",
               "northeast" : __DIR__"zhuxian",
               "south" : __DIR__"luohun",
                 ]));
    set("objects",([
                    __DIR__"npc/xiannpc" : 1,
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
 tell_object(this_object(), HIR "\n\n一个火球在你身上爆炸。\n\n" NOR);
 COMBAT_D->report_status(ob);
 COMBAT_D->report_sen_status(ob);
 ob->receive_damage("kee", random(100)+50);
 ob->receive_damage("sen", random(100)+50);
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
