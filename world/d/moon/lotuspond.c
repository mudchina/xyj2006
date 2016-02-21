//Cracked by Roath
// Room: /moon/ontop.c
//cglaem...12/13/96.

inherit ROOM;

void create ()
{
  set ("short", "湖边");
  set ("long", @LONG

湖面绿波上飘着一叶小舟，一个绿衫少女手执双桨，缓缓划水而来，口中
唱着小曲，听那曲子是：“采莲人语隔秋烟，波静如横练。入手风光莫流
转，共留连，画船一笑春风面。江山信美，终非吾土，问何日是归年？”
歌声娇柔无邪，却有一丝淡淡的的伤感。两滩上衰草残菱（ｌｏｔｕｓ）
更助秋意。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "lotus" : "荷花已经谢了，莲梗上孤零零的吊着莲蓬。
",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/chimeng" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"rain",
]));

  setup();
}

void init()
{
  add_action("do_cai", "cai");
}

int do_cai(string arg)
{
  object me=this_player();
  object m; 

  if( (!arg) || !((arg == "lotus") || (arg == "lian")))
    return notify_fail("采什么？\n");
  message_vision("$N见那莲蓬诱人，便伸手去摘．\n", me);
 if (me->query("kee") < (int)(me->query("max_kee")/3))
	return notify_fail("您先歇歇吧，别那么馋:)\n");

 else if (random(6) < 1){
	message_vision("$N脚下一滑，扑通一声掉进了莲花池．\n",me);
	me->move(__DIR__"hudi");
	return 1;
	}
  else if (me->query("gender") == "男性")
	return notify_fail("你突然意识到采莲不免有失英雄本色，不禁又把手缩了回来\n");	
  else{
	if ((int)me->query_skill("moondance", 1)< 60){
          me->improve_skill("moondance", 40-me->query("str"));
	   message_vision(
		 "$N试着运用所学的轻功纵身跳上荷叶，发现不妙又赶紧跳了回来．\n", me);   
          tell_object(me, "你领悟出一些冷月凝香舞的技巧。\n");
	  this_player()->start_busy(1);
        }
      else
        {
          message_vision("$N双脚在莲叶上一点，身子轻轻在水上掠过，回来时手中已多了一只莲蓬。\n", me);
	  if(sizeof(all_inventory(this_player()))>30)
	      tell_object(me,"可是你身上已经装不下了。\n");
	  else {
            m = new(__DIR__"obj/lianzi.c");
	    m->move(this_player()); 
	    this_player()->start_busy(1);
	  }
	}
	}
       me->receive_damage("kee", 20);
	return 1;
}
