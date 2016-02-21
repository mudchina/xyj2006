inherit ROOM;
void create ()

{
     set("short","仙境");
     set("long",@LONG

这里不知道是哪座大山中的一个山谷。
远处崇山峻岭，气势恢弘，四周苍松翠柏，郁郁葱葱。
旁边一潭春水，倒影着这湖光山色。身边还不时
有珍禽异兽经过。好一处人间仙境！
（-----这些都是纸板做的布景。）
LONG);
      set("exits", ([ /* sizeof() == 1 */
      "west" : __DIR__"zhaoxiangguan",
]));
      set("objects", (["/u/rico/obj/dan":1,]));
      setup();
  set("no_fight", 1);
  set("outside", 1);
  set("no_magic", 1);

        setup();
}

