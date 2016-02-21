//Cracked by Roath

//  妖神之争 １。０
//  by happ@YSZZ 2000.4.14

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "山顶");
  set ("long", @LONG

山顶上尽是些阴凉，根本就看不到天空，鸟儿在树林中欢快的歌唱
着，似乎根本不知道这世界上存在很多的危险，还有一些小的动物
经常从你的脚边跑过，你不禁童心大发，在你旁边还有一棵大桃树。
你可以试着爬上去看看。

LONG);

  set("exits", ([
        "northwest"     : __DIR__"shanding2",
        "eastdown"   : __DIR__"shanpo3",
      ]));
  setup();
}

void init()
{
        add_action("do_climb","climb");
}

int do_climb(string arg)
{
        object ob = this_player();

         if ( ! arg || arg != "up" )
          {
         write("你要向哪爬？\n");
          return 1;
          }
        if( ob->query("kee") < 50 )
          {
         write("你一个不小心从树上摔了下来。\n");
         return 1;
          }
         message_vision(HIC"只见$N象个猴子似的呼哧呼哧向上爬去。\n"NOR,ob);
         ob->move(__DIR__"tree");
         ob->add("kee", -50);
         return 1;
}
