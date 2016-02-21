// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "普济寺");
  set ("long", @LONG

普济寺门口前挤满了面黄饥瘦的灾民，在等待寺里一天一次的
开众施舍。寺里面有几位虔诚的客人在烧香，寺后传来一阵阵
木鱼声。
    
LONG);

  set("exits", ([
        "south"    : __DIR__"jiedao2",
      ]));
  set("objects", ([
        __DIR__"npc/monk" : 1,
      ]));
  setup();
}

