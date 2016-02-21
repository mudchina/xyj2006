//Cracked by Roath
inherit ROOM;

void create ()
{
  set ("short", "后院");
  set ("long", @LONG

后院十分清静，面前一带粉垣，有千百翠竹遮映，墙下忽开一隙，得泉一
派，沟开仅尺许，灌入墙内，绕阶缘屋至前院，盘旋竹下而出。中间有一
张木桌及几只小木凳，桌上摆着各色果品点心。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "table" : "桌上摆着各色果品点心，十分诱人。
",
]));
  set("objects", ([ /* sizeof() == 5 */
  __DIR__"obj/woodtable" : 1,
  __DIR__"obj/woodseat" : 2,
  __DIR__"obj/guihuageng" : 1,
  __DIR__"obj/snowglass" : 2,
  __DIR__"obj/xueli" : 1,
]));
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wulang.c",
]));

  setup();
}
void init()
{
        add_action("do_serve", "serve");
	add_action("do_stand", "stand");
	add_action("do_sit", "sit");
}

int valid_leave()
{
        if((present("snowglass", this_player())))
            return notify_fail("此杯乃嫦娥心爱之物，带走不妥吧。\n");
    return ::valid_leave();
}

int do_sit(string arg)
{     
      object me;

      me=this_player();

        if ( !arg || ((arg != "seat")&&(arg != "deng")&&(arg != "table") ))
                return notify_fail("你要坐在什么上面？\n");

        if (this_player()->query_temp("marks/sit"))
                return notify_fail("你已经坐下了。\n");
      
      if ( arg != "seat"&&arg != "deng")
              return notify_fail("坐桌子上？太不雅观了吧。\n");
        
        this_player()->set_temp("marks/sit", 1);
        message_vision("$N轻轻巧巧地坐上了小木凳。\n",me);
      return 1;
}
int do_stand(string arg)
{
      object me;

      me=this_player();

      if (!this_player()->query_temp("marks/sit"))
          return notify_fail("你本来就站着。\n");

      this_player()->set_temp("marks/sit", 0);
      message_vision("$N伸了个懒腰，站了起来。\n", me);
      return 1;
}
int do_serve(string arg)
{
        object m,mm;
	if ((int)this_player()->query_temp("marks/sit") == 0)
		return notify_fail("如此良辰美景，何不坐下来小酌？\n");
        if((int)this_player()->query("food") >=
		(int)this_player()->max_food_capacity()*90/100)
        return notify_fail("这儿风景这么好，别光想着吃：）\n");
            
        if(present("xue li", this_player()) || 
		present("guihuageng", this_player()) ||
		present("xue li", environment(this_player()))
	)
        return notify_fail("不是还有吃的吗？\n");

        m=new(__DIR__"obj/xueli.c");
	mm=new(__DIR__"obj/guihuageng.c");
	
	message_vision("$N嘴里嘟囔了两句，木桌上立刻有摆满了果品点心．\n", this_player());

        m->move(environment(this_player()));
        mm->move(environment(this_player()));

return 1;
}

