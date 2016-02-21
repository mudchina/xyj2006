// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/longfeng.c

inherit ROOM;

void create ()
{
  set ("short", "龙凤阁");
  set ("long", @LONG

龙凤阁盘龙舞凤，阁内玉雕云绘层层叠叠富丽堂皇，多用金丝银
线攀绕而成。阁中有琼瑶翡翠花座，四周镶嵌玛瑙涟漪纹。这里
是宝象国礼待外宾的地方。

LONG);

  set("exits", ([
        "north"      : __DIR__"gongmen",
        "southup"    : __DIR__"yujie1",
      ]));
  set("objects", ([
         __DIR__"npc/dashi" : 1,
         __DIR__"npc/bing" : 2,
      ]));

  setup();
}

int valid_leave (object who, string dir)
{
  object dashi = present("da shi",environment(who));

  if (interactive(who) &&
      dir == "southup" &&
      dashi &&
      living(dashi) &&
      ! who->query("obstacle/baoxiang"))
    return notify_fail("阁门大使向你摇了摇手。\n");;
  return 1;
}

