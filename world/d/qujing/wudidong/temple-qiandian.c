// Room: /d/qujing/wudidong/temple-qiandian.c
// created 6-20-97 pickle
inherit ROOM;

void create ()
{
  set ("short", "小庙前殿");
  set ("long", @LONG

小庙依山而造，远看颇为风雅，进来却发现不然。正殿里四壁透风，
房顶漏水，几座难以辨认的泥像个个缺胳膊少腿。眼见你走进来，也
没有个知客僧来欢迎。南边还有间后殿，也是残破不堪。只有东边一
间房子还看的过去。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "east" : "一扇紧闭的木门，可以敲门(knock)看看有没有人。
",
]));
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"temple-houdian",
  "north" : __DIR__"road1",
]));
  set("light_up", 1);

  setup();
}

void init()
{
  add_action("do_knock", "knock");
}

int do_knock()
{
  object me=this_player();
  string myrespect=(string)RANK_D->query_respect(me);

  if (me->query("obstacle/wudidong") != "done")
  {
      message_vision("只听门后传来一阵惊叫：你、你、你是什么妖怪？杀人啦！救命啊！\n", me);
      return 1;
  }
  message_vision("只听“吱”的一声，房门被拉开了一条缝。\n", me);
  message_vision("一个和尚探出头来四处看了看，见到是$N，紧张的脸上露出一丝笑容。\n", me);
  message_vision("和尚道：原来是"+myrespect+"。可把我给吓坏了。\n", me);
  message_vision("和尚打开门，把$N拉了进去，又急忙把门关上了。\n",me);
  me->move(__DIR__"bedroom");
  return 1;
}






