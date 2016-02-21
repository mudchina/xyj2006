// Room: /u/mimi/zhuziguo/yuhuayan.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "御花园");
  set ("long", @LONG

御花园已经被封多年，园中池塘已经干枯，雕栏红漆尽褪。往日的
奇花异草久不经修理，已被乱草埋没，惟有墙角的一棵芭蕉树长的
茂盛(bajiao)，比众花木不同。
LONG);

  set("outdoors", __DIR__"");                   
  set("item_desc", ([ /* sizeof() == 1 */
    "bajiao" : "一种灵苗秀，天生体性空。翠缕千条细，丹心一点红。\n"+
               "青隐遮秀户，碧影上廉栊。愧无桃李色，冷落粉墙东。\n",
    ]));
  set("exits", ([ /* sizeof() == 1 */
    "out" : __DIR__"huilang2.c",
  ]));

  setup();
}

void init()
{
  add_action("do_kan", "kan");
}

int do_kan(string arg)
{
  object me = this_player();
  object ob;

  if ((!arg) || !((arg == "bajiao") || (arg == "芭蕉")))
    return notify_fail("你要砍什么？\n");

  if (!(ob = me->query_temp("weapon")) ||
     (string)ob->query("skill_type") != "axe")
    return notify_fail("先去找把斧头吧！\n");

  if (sizeof(query("exits"))>1)
    return notify_fail("芭蕉树已经倒了！\n");
  
  message_vision("$N抡起大斧子朝芭蕉树砍去，芭蕉树晃了晃。\n",me);
  if (me->query("kee") <= 40)
    me->unconcious();
  me->add("kee",-40);
  if (random(50-me->query_kar()) < 5)
  {
    message_vision("只听轰的一声，芭蕉树倒了，地下露出一口井。\n",me);

    set("exits", ([ 
      "out" : __DIR__"huilang2.c",
      "down" : __DIR__"well",
    ]));
    return 1;
  }
  return 1;
}
