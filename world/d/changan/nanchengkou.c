// Room: /changan/nanchengkou.c
//cglaem...12/12/96.

inherit ROOM;

//#define FILE __DIR__"npc/qianmian"

void create ()
{
  set ("short", "南城口");
  set ("long", @LONG

这里是长安的南城口。往北望去已可看到南城门络绎不绝的人流及城
口守卫的官兵。南去一桥高跨泾水，而天际处终南山麓淡淡地横过你
的视野，不由人不赞叹这长安城地处天地钟秀之汇冲，不愧是王都之
气象。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  //"west" : __DIR__"wside1",
  "south" : __DIR__"nbridge",
  "north" : "/d/city/zhuque-s4",
  //"east" : __DIR__"eside1",
//  "southeast" : "/d/eastway/jinshi",
]));
        set("objects", 
        ([ //sizeof() == 1
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 3,
        ]));


  set("outdoors", 1);

  setup();
}






