// created by snowcat.c 5/23/1997
// room: /d/pantao/fengb.c

#define MAXPOSITION 7

inherit ROOM;

void create ()
{
  set ("short", "封神台");
  set ("long", @LONG

                      ◇封神台◇

封神灵台巍峨雄伟，金璧辉煌。只见琉璃碧沉沉，宝玉明幌幌，
天神、天圣、天尊、天王、左辅、右弼等两边伫立。龙旗鸾辂祥
光蔼，宝节幢幡瑞气飘。更有仙乐玄歌音韵美，凤箫玉管响声高。

LONG);

  set("exits", ([
        "north" : __DIR__"palace7",
        "west"  : __DIR__"fenga",
        "east"  : __DIR__"fengc",
      "out" :"/d/dntg/yaochi/wmj6",
      ]));

  set("objects", ([
         __DIR__"npc/male"   : 1,
         __DIR__"npc/female" : 1,
      ]));

  remove_call_out ("reset_long");
  call_out ("reset_long",1,this_object());
  remove_call_out ("drop_zishoulu");
  call_out ("drop_zishoulu",10);
  setup();
}

void reset_long (object where);

void init()
{
  add_action("do_look", "look");
  reset_long(this_object());
}

void reset_long (object where)
{
  int i, j;
  string str = @LONG

                      ◇封神台◇

封神灵台巍峨雄伟，金璧辉煌。只见琉璃碧沉沉，宝玉明幌幌，
天神、天圣、天尊、天王、左辅、右弼等两边伫立。龙旗鸾辂祥
光蔼，宝节幢幡瑞气飘。更有仙乐玄歌音韵美，凤箫玉管响声高。

          ≡≡≡≡≡≡≡封神榜≡≡≡≡≡≡≡
LONG;

  seteuid(getuid());
  if (where == 0)
    where = this_object ();

  for (i = 1; i <= MAXPOSITION; i++)
  {
    string npc = __DIR__"npc/tian"+sprintf("%d",i);
    string s;
    object ob = find_object(npc);
    if (! ob ||
        ! ob->restore())
      ob = new (npc);
    if (ob &&
        s = ob->query("short"))
    {
      string honor;
      sscanf(s, "%s(%s", honor, s);
      s = ob->query("current_player");
      if (s != "none of us")
      {
        honor = honor + " " + s;
        for (j = strlen(honor); j < 30; j++)
          honor = honor + " ";
        str = str + "            " + honor + "   \n";
      }
    }
  }
  str = str + "          ≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡\n\n";
  where->set("long",str);
}

int do_look ()
{
  object where = this_object();

  reset_long(where);
  return 0; // return 0 to invoke normal commands
}

void drop_zishoulu ()
{
  int i, j;
  object who;
  object *list;

  remove_call_out("drop_zishoulu");
  call_out("drop_zishoulu",random(7200)+7200);
  list = users();
  j = 100;
  while  (j--)
  {
    string there;

    i = random(sizeof(list));
    if (!environment(list[i]))
      continue;
    if (!living(list[i]))
      continue;

    who = list[i];
    break;
  }
  if (! who)
    return;
  //who = find_living ("snowcat");
  remove_call_out ("zishoulu_fly");
  call_out ("zishoulu_fly",2,who,"空中仿佛有什么紫色的东西飘荡……\n");
  call_out ("zishoulu_fly",6,who,"一条紫色缎带般的东西轻轻地飘了下来……\n");
  call_out ("zishoulu_fly",10,who,"徐徐地，紫色缎带飘到$N的头上。\n");
  remove_call_out ("zishoulu_drop");
  call_out ("zishoulu_drop",12,who);
}

void zishoulu_fly (object who, string msg)
{
  message_vision (msg,who);
}

void zishoulu_drop (object who)
{
  string str = __DIR__;
  object ob;

  ob = new (str+"obj/zishoulu");
  message_vision ("紫色缎带飘进$N的怀中。\n",who);
  ob->move(who);
}

