#include <ansi.h>
#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", HIR "红" HIY "砂阵" NOR);   
  set ("long", @LONG   
诗云：“红砂一撮道无穷，八卦炉中玄妙功；万象包罗为一处，方知截教有鸿蒙。”
红沙阵乃十绝之首，作法更精，内按天地人叁寸，中分叁气，内藏红砂叁斗，看似红砂，
着身利刃，上不知天，下不知地，中不知人；若人仙冲入此阵，风雷运处，飞砂伤人，
立刻骸鼻俱;成齑粉，纵有神仙佛祖遭此，再不能逃。
LONG);

    set("exits", ([ 
               "south" : __DIR__"huaxue",
               "north" : __DIR__"gate",
                 ]));
  set("objects", ([ 
  __DIR__"npc/guard" : 2,
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
 tell_object(this_object(), HIR "\n\n漫天红砂向你吹来。\n\n" NOR);
 ob->receive_damage("kee", random(100)+100);
 ob->receive_damage("sen", random(100)+100);
 COMBAT_D->report_status(ob);
 COMBAT_D->report_sen_status(ob);
 if( environment(ob) == this_object())
 call_out("blowing",random(30)+1, ob);
}
 else
 return 1;
}
int valid_leave(object me, string dir)
{
        object a;
        if (dir == "north") {
                if(objectp(a=present("guard", environment(me))) &&
living(a) )
                return
notify_fail("算了吧，守卫不会随便让你进去的。\n");
        }
        return 1;
}
