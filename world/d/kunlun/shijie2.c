inherit ROOM;

void create ()
{
  set ("short", "Ê¯½×");
  set ("long", @LONG

    Ê¯½×ÏòÇ°ÑÓĞø£¬ÒşÒşÔ¼Ô¼ÒÑ¿É¿´¼ûÉ½¶¥ÔÆÏ¼ÃÔÂşÏÉÆø·Ç·²£¬
É½¶¥»¹²»Ê±´Ó´«À´ÕóÕóËĞ¾­µÄÉùÒô¡

£

LONG);

  set("exits", ([
        "north"   : __DIR__"lingyunge",
        "eastdown"   : __DIR__"shijie1",
      ]));
         set("outdoors", "xx" );  

  setup();
}
