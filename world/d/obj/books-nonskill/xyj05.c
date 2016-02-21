// xjy05.c
// created 7/7/1997 snowcat

inherit ITEM;
#include <ansi.h>

void init();

int do_read();
void create()
{
  set_name("《西游记》第五回", ({"xyj", "book"}));
  set_weight(200);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "本");
    set("long", " 《西游记》第五回  请用 read 阅读。");
    set("material", "paper");
  }
}

void init()
{
  add_action("read_book", "read");
}

int read_book(string arg)
{
  object me = this_player();
  object ob = this_object();
    
  if (!ob->id(arg))
      return notify_fail("你要读什么？\n");
  write("\n");
  me->start_more(read_file("/d/obj/books-nonskill/text/xyj05"));
  write("\n");
  return 1;
}

