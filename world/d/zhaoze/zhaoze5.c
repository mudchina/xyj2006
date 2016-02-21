
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short", "火沼深处");
 set("long", @LONG
天色越发昏暗，到处弥漫着暗红色的蒸气。这里气温极高，所有
的植物都呈现出一种焦黄的颜色。地下的泥土更见松软，每一步都有
陷下去的危险。
LONG
 );
 set("exits", ([
  "east" : __DIR__"zhaoze4",
]));
        set("item_desc", ([
            "bush": "这里荆棘(bush)密布，但你似乎可以砍开(chop)它们。\n",
            "荆棘": "这里荆棘(bush)密布，但你似乎可以砍开(chop)它们。\n"
        ]) );
        set("objects", ([
                __DIR__"npc/monster3" : 1,
       ]) );
 set("coor/x",0);
 set("coor/y",-630);
 set("coor/z",-20);
 setup();
}
void init()
{ object ob;
 if( interactive( ob = this_player()))
 call_out("blowing", random(8) + 1, ob);
 add_action("do_chop","chop");
}
int blowing(object ob)
{
 int i;
 int damage;
        if(  ob && environment(ob) == this_object())
 {
tell_object(this_object(), HIR "\n\n一个巨大的火球＂轰隆＂一声从地下爆出！！
\n\n" NOR);
        damage = random(20)+10 - ob->query_temp("apply/armor_vs_spells");
        if(damage > 0 ) {
        ob->receive_wound("kee", damage);
        COMBAT_D->report_status(ob,1);
        }
 if( environment(ob) == this_object())
 call_out("blowing",random(8)+1, ob);
 }
 else
 return 1;
}
void reset()
{
 ::reset();
        remove_call_out("blowing");
        delete("exits/south");
}
int valid_leave(object me, string dir)
{
        remove_call_out("blowing");
 return 1;
}
int do_chop(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要砍开什么？\n");
                return 1;
        }
        if( arg == "bush" || arg == "荆棘" )
        {
        me = this_player();
        obj = me->query_temp("weapon");
        if( !obj )
        {
        write("你空着手，怎么砍？\n");
        return 1;
        }
        if( !query("exits/south") ) {
        set("exits/south", __DIR__"zhaoze6");
message_vision(sprintf("$N用手中的%s砍出一条向南的路．\n",obj->name()),me);
 me->start_busy(1);
        }
        else
message_vision(sprintf("$N用手中的%s砍向路边的荆棘．\n",obj->name()),me);
        }
        else
         write("你要砍开什么？\n");
                return 1;
}
