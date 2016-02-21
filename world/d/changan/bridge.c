inherit ROOM;

void create ()
{
  set ("short", "泾水桥");
  set ("long", @LONG

此桥高跨泾水之上，气势非凡。桥身以汉白玉造就，既美观
又坚固。桥上车水马龙，川流不息。桥下泾水清澈见底，时
有游鱼跃起。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"sbridge",
  "north" : __DIR__"nbridge",
]));
  set("outdoors", 1);

  setup();
}

void init()
{
        add_action("do_jump", "jump");
}
int do_jump(string arg)
{       
        object me;
        me=this_player();

        if ( !arg || ((arg != "bridge") ))
                return notify_fail("你要往哪跳？\n");
        else
message_vision("$N叹了口气，眼一闭，往桥下跳去．．．\n",me);

if( me->query("family") && (string)me->query("family/family_name")!="阎罗地府" ) {
                me->move(__DIR__"inwater");
		message_vision("只听「噗嗵」一声，$N从桥上掉到水中．\n",
me);
                return 1;
                }
                me->move("/d/death/gate");
		message_vision("四处刮起阴风，现出$N的影子．\n", me);
                return 1;
}

