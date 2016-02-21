//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.7
//  /d/qujing/huangfeng/road1.c

inherit ROOM;

void create ()
{
  set ("short", "山坡下");
  set ("long", @LONG

此时，你已经来到了山脚下，周围的有些草十分的缠脚，你只好
一边拨开草，一边继续前行，风吹草动，似乎草丛里面藏着什么。

LONG);
  set("exits", ([
        "west"  : __DIR__"shanlu2",
        "east"  : __DIR__"shanlu1",
      ]));
  set("outdoors","hfd");
  setup();
}

void init()
{
        object ob = this_player();
        object tiger=new(__DIR__"npc/tiger");
        
        if( present("lao hu",environment(ob)))
                return;
        if( ob->query("obstacle/hfd") == "done" )
                return;
        if(!ob->query("obstacle/yz") )
                return;
        message_vision("忽然一只猛虎从草丛里面跳了出来。\n",ob);
        tiger->move(environment(ob));
}        
