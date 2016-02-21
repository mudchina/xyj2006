//Cracked by Roath

//  妖神之争 １。０
//  by happ@YSZZ 2000.4.14

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

山以石为骨，石作土为精，烟霞含宿润，苔藓助鲜青。嵯峨势耸
欺蓬莱，幽静花香若海嬴，几树乔松栖野鹤，数株衰柳语山莺。

LONG);

  set("exits", ([
        "southwest"     : __DIR__"shanlu2",
        "southeast" : "/d/qujing/village/road4",
      ]));
  set("outdoors",1);
  setup();
}
