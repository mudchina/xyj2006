//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.7
//  /d/qujing/huangfeng/road1.c

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "沼泽地");
  set ("long", @LONG

这个地方臭气熏天，时常有些蚊子，臭虫什么的来光顾这里，
地上一滩烂泥已经变成了红色。
LONG);

  set("exits", ([
        "north"   : __DIR__"dongkou",
      ]));
  setup();
}
void init()
{
        object ob = this_player();
        if( !ob->query_temp("winded") )
                return;
        remove_call_out("appear");
        remove_call_out("bite");
        remove_call_out("fly");
        call_out("appear",3,ob);
        call_out("bite",8,ob);
        call_out("fly",12,ob);
}
void appear(object ob)
{
        object wenzi=new(__DIR__"npc/wenzi");
        object where=this_object();
        if( present("wen zi") )
        return;   
        message_vision(HIC"不知从什么地方飞来一只蚊子。\n"NOR,ob);
        wenzi->move(where);
}
void bite(object ob)
{
        message_vision(HIC"忽然蚊子在$N的脸上猛叮了一口。\n"NOR,ob);
        ob->add("kee",-50);
}
void fly(object ob)
{
        object wenzi=present("wen zi");
        message_vision(HIC"蚊子嗡嗡的飞走了。\n"NOR,ob);
        destruct(wenzi);
}
