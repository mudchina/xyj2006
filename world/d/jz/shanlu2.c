//Cracked by Roath
//  ÑıÉñÖ®Õù £±¡££°
//  happ@YSZZ 2000.4.2
// /d/jz/river.c

inherit ROOM;

void create ()
{
  set ("short", "[0;32mÉ½Â·[m");
  set("long", @LONG

ÍäÍäÇúÇúµÄÒ»ÌõÉ½Â·£¬Â·ÅÔ¾¡ÊÇĞ©»¨¶ù¡¢²İ¶ù£¬Äã²»½ûÉîÉîµÄ
ºôÁË¿ÚÆø£¬ÄãµÄ½ÅÏÂÊÇÎå²ÊµÄ¶ìÂÑÊ¯¡£
LONG);
        set("exits",([
                "westup": __DIR__"shanmen",
                "eastdown": __DIR__"shanlu1",
                ]));
        set("outdoors","jz");
 setup();

}
