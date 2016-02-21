// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/jiangtang.c

inherit ROOM;

void create ()
{
  set ("short", "讲经堂");
  set ("long", @LONG

满室锦绣，一屋威严。佛前案上摆满仙果仙花，素品佳肴。
辉煌宝烛，条条金焰射虹霓：馥郁真香，道道玉烟飞彩雾。
那菩萨正领着门人诵读《法华经》。

LONG);

  set("exits", ([
        "south"    : __DIR__"chanyuan",
	"north" : __DIR__"changjing",
      ]));

  set("objects", ([
      __DIR__"npc/lingjipusa": 1,       
          __DIR__"npc/daoren":2,
	]));
  setup();
}