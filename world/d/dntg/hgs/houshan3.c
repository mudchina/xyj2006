// Room: /4world/houshan3

inherit ROOM;

void create ()
{
  set ("short", "后山");
  set ("long", @LONG

花果山后山中的一小块平地。要下山得穿过南面一片树丛。东
面面是一片桃树林，黄澄澄的猕猴桃显然已经熟透，一阵果香
飘来，你口水都流了出来。不过桃林边上有两只大马猴，满怀
敌意地注视着你。
LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/ma-yuanshuai" : 1,
  __DIR__"npc/liu-yuanshuai" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"houshan2",
  "east" : __DIR__"houshan4",
  "north" : "/d/pansi/tao_in",
]));

  setup();
}

int valid_leave(object me, string dir)
{
	object mys, lys;
    if(dir=="east"){
        if(objectp(mys=present("ma yuanshuai", environment(me)))&&
           objectp(lys=present("liu yuanshuai", environment(me)))
           && living(mys) && living(lys) )
	return notify_fail("马流二元帅嘴里一阵吱吱乱叫，恶狠狠地把你拦住了。\n");
        if(objectp(mys=present("ma yuanshuai", environment(me)))&&living(mys))
	return notify_fail("马元帅嘴里一阵吱吱乱叫，恶狠狠地把你拦住了。\n");
        if(objectp(lys=present("liu yuanshuai", environment(me)))&&living(lys))
            return notify_fail("流元帅嘴里一阵吱吱乱叫，恶狠狠地把你拦住了。\n");
    }
    return ::valid_leave(me, dir);
}



