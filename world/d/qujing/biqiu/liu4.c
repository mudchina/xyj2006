// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "柳林坡");
  set ("long", @LONG

好一个柳林坡，只见柳树坡上坡下，密密成林荫，柳枝随风轻
轻缓缓地飘荡着。远处是一片农作物，正是那：万顷野田观不
尽，千堤柳烟隐无踪。

LONG);

  set("exits", ([
        "northwest"    : __DIR__"liu3",
        "south"    : __DIR__"xibei",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

