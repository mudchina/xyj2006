#include <ansi.h>
#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", HIW "寒冰阵" NOR);   
  set ("long", @LONG   
诗云：“玄功就号寒冰，一座刀山上下凝；若是神仙逢此阵，连皮带骨尽无凭。”
名为寒水，实为刀山；内藏玄妙，中有风雷，上有冰山如狼牙，下有冰块如刀剑。
若神仙入此阵，风雷动处，上下一磕，四肢立成齑粉，纵有异术，离免此难。
LONG);

    set("exits", ([ 
               "east" : __DIR__"luohun",
               "west" : __DIR__"dilie",
               "north" : __DIR__"huaxue",
               "south" : __DIR__"fenghou",
                 ]));
    set("objects",([
                    __DIR__"npc/xiannpc" : 1,
                    __DIR__"npc/monpc" : 1,
                 ]));
    setup();
}
void init()
{ object ob;
 if( interactive( ob = this_player()))
 call_out("blowing", random(30) + 1, ob);
}
int blowing(object ob)
{
 int i;
 int damage;
        if(  ob && environment(ob) == this_object())
{
 tell_object(this_object(), HIW "\n\n你被冰冻得动弹不得。\n\n" NOR);
 ob->start_busy(3);
 if( environment(ob) == this_object())
 call_out("blowing",random(30)+1, ob);
}
 else
 return 1;
}
void reset()
{
 ::reset();
        remove_call_out("blowing");
}
