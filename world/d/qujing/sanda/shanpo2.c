//Cracked by Roath

//  妖神之争 １。０
//  by happ@YSZZ 2000.4.14

inherit ROOM;

void create ()
{
  set ("short", "山坡");
  set ("long", @LONG

走在山坡上，你觉得大山象一个怪物似的盯着你，在山坡向阳的一面
有一些农人开垦好的梯田，里面整整齐齐的种着谷子一类的很普通的
庄稼，有些田中还有些农民正在忙活着。

LONG);

  set("exits", ([
        "westup"     : __DIR__"shanpo3",
        "eastdown"   : __DIR__"shanpo1",
      ]));
  set("outdoors",1);
  setup();
}
