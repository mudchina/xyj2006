#include <ansi.h>
#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", HIW "落魂阵" NOR);   
  set ("long", @LONG   
诗曰：“白纸摇黑气生，成妙术透虚盈；从来不信神仙体，入阵魂消魄自倾。”
乃闭生门，开死户，中藏天地厉气，结聚而成；内有白纸一首，上画符印，若神仙入
阵内，白旌展动，魂魄消散，倾刻而灭，不论神仙，随入随灭。
LONG);

    set("exits", ([ 
               "north" : __DIR__"lie",
               "west" : __DIR__"hanbing",
               "south" : __DIR__"hongshui",
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
 tell_object(this_object(), HIW "\n\n阵中白旌展动，你显然有点魂不守舍了。\n\n" NOR);
 COMBAT_D->report_sen_status(ob,1);
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
