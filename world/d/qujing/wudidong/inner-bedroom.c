// inner-bedroom.c
// created by mes
// updated 6/97 by pickle

inherit ROOM;

int do_push(string arg);
void reset();

void create ()
{
  set ("short", "寝室");
  set ("long", @LONG

这里便是玉鼠精的卧室了。掀开水红挑绣的软帘，只见锦笼纱罩，说
不尽的精致华丽，连脚下踩的砖都是一色的雪白凿花。当窗一张小小
床榻，软纱为帐，轻罗为衾，绣的都是一对一对的五彩鸳鸯。梳妆台
上摆着各式胭脂水粉，明镜中映出对面墙上挂的一幅画像(picture)，
粉面含嗔，玉容整肃。墙角里有扇石门(men)，不知通向何处。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"bedroom-gate",
]));
  set("item_desc", ([ /* sizeof() == 2 */
		     "picture" : "
图上画得正是玉鼠精。只见她手中握着两只骷髅。图的右上角写着两行小字。

死一生，亲不认。
马分尸，窍流血。

",
		     "men": "
一扇沉重的石门。\n",
]));

  setup();
}
void init()
{
  add_action("do_push", "push");
  add_action("do_push", "tui");
}
int do_push(string arg)
{
  object me=this_player();
  int myeffstr=me->query_skill("unarmed",1)/10-2+me->query("str");
  int mystr=me->query_str();
  int myforce=me->query("maximum_force");

  if ( !arg || ((arg !="men") ))
    return notify_fail("你要推什么？ \n");
//  if(mystr <50||myeffstr<20)
  if(mystr <30||myeffstr<20)
    return notify_fail("你力气太小了，推不动！ \n");
  if (random(myforce)>500)
    {
      message_vision("$N推石门时用力过猛，似乎受了内伤。\n", me);
//      me->add_maximum_force(-myforce/100);
    }
  message_vision("$N一推石门，突然间，一阵阴风把$N推到了另一间房间去了。\n", me);
  me->move(__DIR__"cave1");
  message_vision("石门翻转处，$N走了过来。\n", me);
  return 1;
}
