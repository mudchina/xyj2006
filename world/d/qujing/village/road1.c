//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.7
//  /d/qujing/village/road1.c

inherit ROOM;

void create ()
{
  set ("short", "乡间小路");
  set ("long", @LONG

一路上风吹落叶，路上印着一些马蹄的脚印，你的心情感到特别的
轻松，自取经以来，你一路投西，历编了青山绿水，看不尽的野花
闲草，你不禁叹息起光阴迅速啊。

LONG);
  set("exits", ([
        "west"  : __DIR__"road2",
        "eastdown" : "/d/qujing/liusha/riverside",
          ]));
  set("outdoors","cz");
  setup();
}

void init()
{
        object me;
    me=this_player();
     if (((me->query("fangcun/panlong_wzg_rsg")=="done")||(me->query("fangcun/panlong_wzg")=="done"))&&(me->query_temp("set_village")!="done"))
	{    
	  me->add_temp("wzg_rulaifo",1);
	  me->set_temp("set_village","done");
	}
	     
}
