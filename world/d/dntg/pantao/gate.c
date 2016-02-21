inherit ROOM;

void create ()
{
  set ("short", "蟠桃园园门");
  set ("long", @LONG
两扇两丈多高的朱漆描金大门虽设而长开，门内是一片
郁郁葱葱的桃树林，种着连天上神仙思之都垂涎三尺的千年
蟠桃。门前站着一位白发苍苍的土地公公，正笑容可掬地看
着你。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tudi" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"pan2c",
  "southwest" : __DIR__"pan3c",
  "northwest" : __DIR__"pan1c",
  "east" :   "/d/dntg/yaochi/wmj6",
]));

  setup();
}

int valid_leave(object me, string dir)
{
        object tudi;
    if ( dir == "west" || dir=="southwest" || dir=="northwest") {
        if(objectp(tudi=present("tu di", environment(me))) && living(tudi) && me->query_temp("dntg/pantao")!="doing" && me->query("dntg/pantao")!="done" )
            return notify_fail("土地公公拦在你面前：笑咪咪地说：蟠桃园胜地，不接待外客，尊驾请回。\n");
    }
    return ::valid_leave(me, dir);
}
