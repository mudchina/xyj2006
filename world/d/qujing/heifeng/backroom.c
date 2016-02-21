//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/shandao.c

inherit ROOM;

void create ()
{
  set ("short", "后房");
  set ("long", @LONG

这是一间很隐蔽的房子，里面放的都是些大柜子，居然里面全部都是
袈裟，真是满堂绮秀，四壁绫罗，金池长老居然还有此爱好。
LONG);

  set("exits", ([
        "north": __DIR__"dadian",
      ]));
  set("objects", ([
        __DIR__"npc/monk_gm":1,
        ]));
  setup();

}
