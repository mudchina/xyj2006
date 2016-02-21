// room: /d/qujing/baigudong/xiashanlu1 
//create by smile 12/09/1998
inherit ROOM;

void create ()
{
  set ("short", "下坡路");
  set ("long", @LONG

    四周静悄悄的，没有一点声音，空气似乎凝集不动了，
没有一丝风气，死沉沉的。
    路旁葛藤缠绕，野草高深，一条蜥蜴从你脚上穿过，吓
了你一跳。
  
LONG);

  set("exits", ([
        "westdown"  : __DIR__"xiapolu3",
        "eastup"    : __DIR__"xiapolu1",
      ]));

  set("outdoors",__DIR__"");

  setup();
}
