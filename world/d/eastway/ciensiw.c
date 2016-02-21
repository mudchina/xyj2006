// create by snowcat.c 4/20/1997
// room: /d/eastway/ciensiw.c

inherit ROOM;

void create ()
{
  set ("short", "慈恩寺外");
  set ("long", @LONG

你来到慈恩寺外，东面就是著名的慈恩寺，高大的寺门挺立，门两旁
还立了两个大石狮子。据说门上的横匾还是出自皇上的御笔。寺院内
的大雁塔高高耸立。向北是一条官道。
LONG);

  set("exits", ([
        "enter"     : __DIR__"ciensi",
        "north"     : __DIR__"guandao1",
      ]));
  set("outdoors", __DIR__);

  setup();
}






