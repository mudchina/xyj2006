// Room: /d/jjf/guest_cabinet.c
// 6-30-97 pickle

inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "西厢阁楼");
  set ("long", @LONG

秦将军没有女儿，于是西厢就留给了来京城小住的亲朋好友。小几上
的一对羊脂玉瓶里插的满满的都是晶莹剔透的白菊，不知哪里放了个
香炉，吐着一缕似有似无的暗香。一个家将站在楼梯口，守着上楼的
路。也不知楼上住的是哪位贵客。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/luochun" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"pavillion",
  "up" : __DIR__"guest_cabinet2",
]));

  setup();
}
int valid_leave(object me, string dir)
{
    object guard, *inv, letter;
    int i;

    if(dir != "up")
        return ::valid_leave(me, dir);
    inv=all_inventory(me);
    i=sizeof(inv);
    me->delete_temp("condition/carrying_player");
    if(objectp(present("luo chun", environment(me))))
	guard=present("luo chun", environment(me));
    if(!guard) return ::valid_leave(me,dir);
    while (i--)
    {
        if (userp(inv[i]))
            me->add_temp("condition/carrying_player", 1);
        continue;
    }
    if(me->query_temp("condition/carrying_player"))
    {
        return notify_fail(CYN "罗春喝道：呔！若想上楼，先把背上的那个放下了！\n"NOR);
    }
    if (!(letter=present("shu xin", me)
       && letter->query("header")=="秦琼至罗成") 
     && me->query("family/master_id")!="luo cheng"
     && guard)
    {
        return notify_fail(CYN "罗春喝道：呔！楼上乃贵人居住之处，不得擅闯！\n"NOR);
    }

    //finally...
    return ::valid_leave(me, dir);
}
