// created by snowcat 10/05/1997
// room: /d/huanggong/fst.c

inherit ROOM;

#define MAXCATEGORY 5
#define MAXPOSITION 3

string *categories = ({
  "金榜",
  "银榜",
  "铜榜",
  "铁榜",
  "锡榜",
 });

string *positions = ({
  "状元",
  "榜眼",
  "探花",
 });

void create ()
{
  set ("short", "封榜堂");

  set ("long", @LONG

封榜堂里碧灯齐放，笙乐高奏，众官衣冠楚楚威武静坐。更有一
群宫女长袖轻飘徐徐而舞，正中是双龙双凤玛瑙台座，供设镶金
嵌银缀珠汉白玉精雕御批状元武榜。

LONG);

  set("exits", ([
        "north" : __DIR__"ywc5b",
        "southwest"  : __DIR__"yhy1a",
        "southeast"  : __DIR__"yhy1b",
      ]));

  set("objects", ([
//"/u/bear/npc/teacher" : 1,
         __DIR__"npc/pang"   : 1,
      ]));

  remove_call_out ("reset_long");
  call_out ("reset_long",1,this_object());
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
  int i, j, k;
  string str = @LONG

封神堂里碧灯齐放，笙乐高奏，众官衣冠楚楚威武静坐。更有一
群宫女长袖轻飘徐徐而舞，正中是双龙双凤玛瑙台座，供设镶金
嵌银缀珠汉白玉精雕御批状元武榜。

          －－－－－－－－－－－－－－－－－

LONG;

  seteuid(getuid());

  if (where == 0)
    where = this_object ();

  for (i = 1; i <= MAXCATEGORY; i++)
  {
    int found_player = 0;
    for (j = 1; j <= MAXPOSITION; j++)
    {
      string npc = __DIR__"npc/wu"+sprintf("%d%d",i,j);
      string s;
      object ob = find_object(npc);
      if (! ob ||
          ! ob->restore())
        ob = new (npc);
      if (ob)
      {
        string honor = categories[i-1]+positions[j-1];
        s = ob->query("current_player");
        if (s != "none of us")
        {
          honor = honor + " " + ob->query("name") + " " + s;
          for (k = strlen(honor); k < 30; k++)
            honor = honor + " ";
          str = str + "            " + honor + "   \n";
          found_player = 1;
        }
      }
    }
    if (found_player)
      str = str + "\n";
  }
  str = str + "          －－－－－－－－－－－－－－－－－\n\n";
  where->set("long",str);
}

int do_look ()
{
  object where = this_object();

  reset_long(where);
  return 0; // return 0 to invoke normal commands
}

int valid_leave (object me, string dir)
{
  if ((string)me->query("id")=="pang xuanling" &&
      (dir=="southeast" || dir=="southwest")) 
    return 0;
  return 1;
}

