//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//qiezidi.c

inherit ROOM;

void create ()
{
   set ("short", "茄子地");
   set ("long", @LONG

五庄观做事的多，吃饭的也不少，所以观内雇了附近的一些农家
来种蔬菜瓜果。这里是茄子地。
LONG);

   set("exits", 
   ([ //sizeof() == 4
     "southwest" : __DIR__"huangguadi",
     "north" : __DIR__"baicaidi",
   ]));

   //create_door("south", "梨花门", "north", DOOR_CLOSED);
   set("outdoors", "wuzhuang");

   setup();
}
