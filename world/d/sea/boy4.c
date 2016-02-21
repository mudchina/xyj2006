// hill.c

inherit ROOM;

void create ()
{
  set ("short", "练功堂");
  set ("long", @LONG

屋里十分宽敞，墙上画的是一些叉术分解，靠墙的架子上放了十余
把长枪。地下铺的是裁剪整齐的木块，踩在上面吱吱做响。

LONG);

  set("water", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/long3.c" : 1,
  __DIR__"obj/mucha" : 1,
//   "d/qujing/bibotan/npc/changtuixiabing" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"boy2",
]));
//      
        set("water", 1);
//  
  setup();
}
