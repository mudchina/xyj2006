#include <ansi.h>
#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", RED "红水阵" NOR);   
  set ("long", @LONG   
诗曰：“炉内阴阳真奥妙，成壬癸里边藏；饶君就是金刚体，遇水黏身顷刻亡。”
红水阵内，夺壬癸之精，藏太乙之妙，变幻莫测；中有一八卦台，上有一二个葫芦
任随人仙入阵，将葫芦往下一掷，倾出红水，汪洋无际。若是水溅出一点，黏在身上，
顷刻化为血水，纵是神仙，无术可逃。
LONG);

    set("exits", ([ 
               "west" : __DIR__"fenghou",
               "southeast" : __DIR__"xianxian",
               "north" : __DIR__"luohun",
                 ]));
    set("objects",([
                    __DIR__"npc/monpc" : 1,
                 ]));
    setup();
}
void init()
{ object ob;
 if( interactive( ob = this_player()))
 call_out("blowing", random(20) + 1, ob);
}
int blowing(object ob)
{
 int i;
 int damage;
        if(  ob && environment(ob) == this_object())
{
 tell_object(this_object(), RED "\n\n你不小心沾了一点红水。\n\n" NOR);
 COMBAT_D->report_status(ob);
 ob->receive_damage("kee", random(50)+50);
 ob->receive_wound("kee", 20);
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
