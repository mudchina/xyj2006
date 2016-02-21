//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "汴京铁塔");
  set ("long", @LONG

广场的中间竖立着一座高高的黑色琉璃塔，塔身由于是黑色貌似铁质
铸就。据说一位大仙自西天取经回来之后将汴京铁塔搬到此处，塔的
西边是辰龙道，东南方向是禹王道，东北和西北边分别通向两条热闹
的大街。

LONG);

  set("exits", ([
        "west" : __DIR__"chen2",
     "east" : "/d/southern/wutai/guandao3",
        "southeast" : __DIR__"yuwang1",
        "northeast" : __DIR__"yao5",
        "northwest" : __DIR__"shun5",
      ]));

  set("outdoors", __DIR__);
           set("post_limit", 1);

  setup();
          call_other("/obj/board/kaifeng_b", "???");

}


