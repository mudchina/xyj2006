// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/cangjing.c

inherit ROOM;

void create ()
{
  set ("short", "藏经楼");
  set ("long", @LONG

藏经楼里古色古香，门边有一落地铜炉，正在冒着袅袅香烟，
门后墙头挂着一些铜铃，靠壁放有一排奇怪的檀香书柜。东南
方面有长道通向后殿。

LONG);

  set("exits", ([
        "southeast"    : __DIR__"houdian",
      ]));

  set("objects", ([
         "/d/obj/book/daode"    : 1,
      ]));
  setup();
}

void init ()
{
  add_action ("do_spell","spell");
}

int do_spell (string arg)
{
  object who = this_player();
  string suffix;

  if (! arg)
    return 0;

  if (arg == "shugui")
    suffix = "1";
  else if (arg == "shugui1")
    suffix = "1";
  else if (arg == "shugui2")
    suffix = "2";
  else if (arg == "shugui3")
    suffix = "3";
  else if (arg == "shugui4")
    suffix = "4";
  else if (arg == "shugui5")
    suffix = "5";
  else if (arg == "shugui6")
    suffix = "6";
  else if (arg == "shugui7")
    suffix = "7";
  else if (arg == "shugui8")
    suffix = "8";
  else if (arg == "shugui9")
    suffix = "9";
  else
    return 0;

  tell_object (who,"你悄声地对书柜念了几声咒语，一阵风将你带了过去。\n");
  who->move(__DIR__"miyuan"+suffix);
  return 1;
}
