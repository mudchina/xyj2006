//Cracked by Roath
// Room: /moon/ontop.c
//cglaem...12/13/96.

inherit ROOM;

void create ()
{
  set ("short", "月门");
  set ("long", @LONG

一个月牙状的小门，那门栏窗格，俱是细雕新鲜花样，并无朱粉涂饰，一
色水磨群墙；下面白石台阶，凿成梅花样。左右一望，皆雪白粉墙，下面
虎皮石，随势砌去。门口有一株桂树(tree)，郁郁苍苍。空气虽冷，却有
花香习习，令人精神备爽。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "tree" : "一株高耸入云的大桂树 。上面无数的桂花
正散发出阵阵清香，不知道怎样才能采集到。
",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"obj/guishuzhi" : 1,
  __DIR__"npc/girl" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"road1",
  "down" : __DIR__"tree2",
]));

  setup();
}


int valid_leave(object me, string dir)
{
	object wugang;
	
    if (me->query("gender") == "男性" && dir == "north" ) {
        if(objectp(wugang=present("wu gang", environment(me))) && living(wugang) )
            return notify_fail("桂花树后转出吴刚，伸出一把大板斧拦住你道：\n慢着...院子里住的全是女人，你跑进去想干什么？\n");
    }
    return ::valid_leave(me, dir);
}
