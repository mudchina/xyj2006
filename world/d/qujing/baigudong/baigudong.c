// Room: 白骨洞,白骨精居住地  
//create by smile 12/10/1998
inherit ROOM;

void create()
{
  set ("short", "白骨洞天");
  set ("long", @LONG

    这里是骷髅夫人白骨精休息的地方。黑森森的，天顶滴
滴哒哒的滴落一些水珠下来，掉在你脸上，用手一抹，一
股血腥味直冲鼻子，不知是血还是水。
        
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "out" : __DIR__"dongnei",
  ]));

  set("objects",([
        __DIR__"npc/baigujing":1,
        __DIR__"npc/kuloubing":2,
                ]));

  set("outdoors", __DIR__"");                   

  setup();
}
