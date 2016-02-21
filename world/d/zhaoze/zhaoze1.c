// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short", "火沼死域");
 set("long", @LONG
这里密布的荆棘挂满倒刺，挡在通往沼泽深处的方向。低矮的
小树丛挡住视线，使人辨不清方向。地下布满腐烂的枯叶，松松软
软的。偶尔有一两个气泡从地上的积水下涌出，带出令人作呕的刺
鼻气味。
LONG
 );
 set("exits", ([
  "south" : "/d/changan/eside5",
  "north" : "/d/zhaoze/zhaoze2",
]));
        set("item_desc", ([
                "bush": "这里荆棘(bush)密布，但你似乎可以砍开(chop)它们。\n"
,
                "荆棘": "这里荆棘(bush)密布，但你似乎可以砍开(chop)它们。\n"
,
        ]) );
        set("objects", ([
                __DIR__"npc/monster1" : 1,
       ]) );
 set("coor/x",10);
 set("coor/y",-620);
 set("coor/z",-20);
 setup();
}
void init()
{ object ob;
 if( interactive( ob = this_player()))
 call_out("blowing", random(10) + 1, ob);
 add_action("do_chop","chop");
}
int blowing(object ob)
{
 int i;
 int damage;
        if(  ob && environment(ob) == this_object())
 {
 tell_object(this_object(), HIR "\n\n地下的泥土突然裂开，一团炽热的地火象喷泉
般射出！！\n\n" NOR);
 COMBAT_D->report_status(ob,1);
 ob->receive_wound("kee", random(20)+10);
 if( environment(ob) == this_object())
 call_out("blowing",random(10)+1, ob);
 }
 else
 return 1;
}
void reset()
{
 ::reset();
        remove_call_out("blowing");
        delete("exits/east");
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
        if( !query("exits/east") ) {
        set("exits/east", __DIR__"zhaoze2");
message_vision(sprintf("$N用手中的%s砍出一条向东的路．\n",obj->name()),me);
 me->start_busy(1);
        }
        else
message_vision(sprintf("$N用手中的%s砍向路边的荆棘．\n",obj->name()),me);
        }
        else
         write("你要砍开什么？\n");
                return 1;
}
