#include <ansi.h>
#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", HIY "金光阵" NOR);   
  set ("long", @LONG   
宝镜非铜又非金，不向炉中火内寻；纵有天仙逢此阵，须臾形化更难禁。
贫道金光阵内，夺日月之精，藏天地之气，中有二十一面宝，用二十一根高，
每一面应在高顶上，一镜上有一套。若人仙入;阵，将此套拽起，雷声震动镜子，
只一二转，金光射出，照住其身，立刻化为浓血，纵会飞;腾，难越此阵。
LONG);

    set("exits", ([ 
               "south" : __DIR__"dilie",
               "northwest" : __DIR__"juexian",
               "east" : __DIR__"huaxue",
                 ]));
    set("objects",([
        __DIR__"npc/monpc" : 1,
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
 tell_object(this_object(), HIY "\n\n千万道金光照向你，你一阵头晕。\n\n" NOR);
 COMBAT_D->report_sen_status(ob);
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
