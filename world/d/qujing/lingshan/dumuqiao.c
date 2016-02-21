//Cracked by Roath
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "¶ÀÄ¾ÇÅ");
  set ("long", @LONG

¡­¡­¶ÀÄ¾ÇÅÒ¡Ò¡°Ú°Ú£¬Ä¾Í·ÉÏ³¤ÂúÁË»¬ÇàÌ¦¡­¡­

LONG);

  set("exits", ([
        "south"   : __DIR__"lingyun2",
        "northwest"   : __DIR__"lingyun1",
      ]));
  set("outdoors", __DIR__);

  setup();
}

void init ()
{
  call_out ("shaking",random(3)+1);
}

void shaking ()
{
  tell_room (this_object(),"¶ÀÄ¾ÇÅÍáÍáĞ±Ğ±µØ»Îµ´ÁËÒ»ÏÂ¡£\n");
}
