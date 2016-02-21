// Room: create by smile 12/10/1998
#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short", HIR "Ñª³Ø" NOR);
  set ("long", @LONG

  [1;31mÑª³Ø[2;37;0mÊÇ°×¹Ç¾«Ò»¸ÉÑı¾«Æ½Ê±ÒûÓÃË®
µÄÀ´Ô´£¬Ô­±¾ÊÇÒ»¿ÚÓÀ²»¿İ½ßµÄÇåÈª£¬×Ô´Ó°×¹Ç¾«Õ¼¾İÁË
ÕâÀï×÷Îª¶´Ñ¨ºó£¬Í»È»¿ªÊ¼Á÷³öÑªºìµÄÈªË®£¬°×¹Ç¾«ÒÔÎª
ÊÇÌìÓÓÆäÈË,ÄËÃüÃûÎª[1;31mÑª³Ø[2;31;0m¡£\n
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "west": __DIR__"dongnei",
  ]));

  set("resource", ([ /* sizeof() == 1 */
                     "water" : 1,
                                 ]));

  set("outdoors", __DIR__"");                   
  setup();
}
